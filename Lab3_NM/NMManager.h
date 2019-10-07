#pragma once
#include <vector>
#include <cmath>
#include "RK4.h"
#include "ToolSet.h"

const double R = 10.0L;
const double m = 10.0L;
const double a1 = 1.0;
const double a2 = .5;

using namespace std;
typedef long double longd;

longd function0(longd x, longd u) {
	return -(a1 * u + a2 * powl(u, 2)) / m;
}
longd function1(longd x, longd u) {
	// Вариант 4
	// u(0) = u0
	const int var = 4;
	return (longd)(pow(-1, var) * var / 2) * u;
}
longd function1_k(longd x, longd u0) {
	return u0 * expl(2*x);
}
longd function2(longd x, longd u) {
	longd f = (longd)(powl(x, 3) + 1) / (longd)(powl(x, 5) + 1);
	longd ur = f * powl(u, 2) + u - powl(u, 3) * sinl(10 * x);

	return ur;
}

class NMManager {
	RK4 RK;
	longd(*function_koshi)(longd, longd);

	enum { error = 0, steps = 1, point = 2, exact = 3, method = 4 };

	vector<long double> aE;	// Локальные погрешности
	vector<long double> aH;	// Шаг численного метода
	vector<long double> aP;	// Точки
	vector<long double> aU;	// Значения точного решения
	vector<long double> aV;	// Значения численного метода

	vector<long double>* Data[5] = {&aE, &aH, &aP, &aU, &aV};
	
	longd inputData[4];		// Значения e0, h0, x0, u0, v0; которые были переданы в класс 

	longd maxE = 1e-5;		// Верхний предел локальной погрешности
	longd minE = maxE / 16; // Нижний предел локальной погрешности

	size_t countHUp = 0;	// Количество удвоений
	size_t countHDown = 0;	// Количество делений
	size_t innerSize = 0;	// Количество построенных точек


	//Параметры рассчета
	size_t taskNumber = 0;	// Номер задачи
	bool corr_control = 1;	// Включение - выключение корректировки шага
	size_t calc_mode = 0;	// 0 - двойной шаг, 1 - коши
	const size_t mode_count = 2; // Количество способов рассчета

	// Возвращает локальную погрешность
	longd local_error(longd u, longd v) {
		return abs(u - v);// / 15;// 15 ?? 
	}

	// Возвращает обновленное значение шага
	longd h_correction(longd err, longd h) {
		if (!corr_control) {
			return h;
		}

		if (err > maxE) {
			return h * .5;	// Уменьшаем шаг в 2 раза
		}
		if (err < minE) {
			return h * 2.0;	// Увеличиваем шаг в 2 раза
		}
		return h;			// Все хорошо, продолжаем

		//return  h * ((err > maxE) * .5 + (err < minE) * 2.0 + (err >= minE && err <= maxE));
	}

	inline void data_clear() {
		for (auto D : Data) D->clear();
		innerSize = countHDown = countHUp = 0;
	}

	template<typename ...Args>
	void data_push(Args&& ... args){
		size_t k = 0;
		(Data[k++]->push_back(args), ...);
		innerSize++;
	}

	longd vector_max(vector<longd> &v){
		longd max = v[0];
		for(auto m : v)
			if (m > max) max = m;
		return max;
	}

	inline void function_switcher(size_t NUMBER) {
		if (NUMBER == taskNumber) return;
		switch (NUMBER) {
		case 0:
			taskNumber = 0;
			RK.setFunction(function0);
			function_koshi = function0;	// Потому что нет функции Коши
			return;
		case 1:
			taskNumber = 1;
			RK.setFunction(function1);
			function_koshi = function1_k;
			return;
		case 2:
			taskNumber = 2;
			RK.setFunction(function2);
			function_koshi = function2;	// Потому что нет функции Коши
			return;
		default:
			return;
		}
	}

	longd calculation(longd x, longd u, longd h) {
		longd u0;
		longd v_1_2;
		switch (calc_mode) {
		case 0: // Двойной шаг
			v_1_2 = RK.nextValue(x, u, h * .5);
			return RK.nextValue(x + h * .5, v_1_2, h * .5);
		case 1: // Точное решение
			u0 = aU[0];
			return function_koshi(x, u0);
		default: return 0;
		}
	}

public:
	NMManager() {
		longd _ce0 = 0;
		longd _ih0 = .1L;
		longd _iu0 = 1;
		longd _ix0 = 0;

		RK.setFunction(function0);

		setStartData(0, _ih0, _ix0, _iu0);
	}

	void setStartData(longd inputE0, longd inputH0, longd inputX0, longd inputU0) {

		inputData[error] = inputE0;	// Локальная погрешность изначально = 0
		inputData[steps] = inputH0;
		inputData[point] = inputX0;
		inputData[exact] = inputU0;

		//аргументы data_push должны быть именно в таком порядке
		data_push(inputE0, inputH0, inputX0, inputU0, inputU0);
	}

	void turnCorrectionControl(bool turn_on) {
		corr_control = turn_on;
	}

	void setMode(size_t mode = 0) {
		calc_mode = mode % mode_count;
	}

	long double nextValue() {
		longd x;
		longd h;
		longd v;
		longd hc;
		longd h0;
		longd newU;
		longd newV;
		longd lerror;

		h0 = hc = aH[aH.size() - 1];
		x = aP[aP.size() - 1];
		v = aV[aV.size() - 1];

		do {
			h = hc;
			//
			newU = calculation(x, v, h);
			//
			newV = RK.nextValue(x, v, h);
			//
			lerror = local_error(newU, newV);
			hc = h_correction(lerror, h);
		} while (hc != h);

		if (h0 != h) {
			if (h > h0){
				countHUp += h / h0;
			}
			else if (h < h0) {
				countHDown += h0 / h;
			}
		}

		//аргументы data_push должны быть именно в таком порядке
		data_push(lerror, h, x + h, newU, newV);
		
		return newV;
	}

	void Build(size_t count_N, size_t task_number = 0) {
		function_switcher(task_number);

		data_clear();
		data_push(
			inputData[error],
			inputData[steps],
			inputData[point],
			inputData[exact],
			inputData[exact]
		);

		forc(0, count_N - 1) {
			nextValue();
		}

		return;
	}

	vector<longd>& getPoints()	{return aP;}
	vector<longd>& getMethod()	{return aV;}
	vector<longd>& getExact()	{return aU;}
	size_t& size()				{return innerSize;}
	longd XMax()				{return vector_max(aP);}
	longd YMethodMax()			{return vector_max(aV);}
	longd YExactMax()			{return vector_max(aU);}
};

