#pragma once
#include <vector>
#include <cmath>
#include "RK4.h"


constexpr auto R = 10.0L;
constexpr auto m = 10.0L;
constexpr auto C0 = .01L;
constexpr auto a1 = 99.0L;
constexpr auto a2 = 1.0L;
constexpr auto u0 = 0.0L;
constexpr auto h0 = .01L;

constexpr auto M_E = 2.71828182845904523536L;

using namespace std;
typedef long double longd;

longd FKoshi(longd t, longd C) {
	longd p = powl(M_E, (-a1 / m * t));
	longd u = (a1 / a2 * C * p) / (1.0L - C * p);
	return u;
}

longd FKoshiC(longd u, longd t) {
	longd p = powl(M_E, (a1 / m * t));
	longd C = (u * p) / (a1 / a2 + u);

	return C;
}

longd F(longd x, longd v) {
	return -(a1 * v + a2 * v * v) / m;
}

class NMManager {
	longd(*function_koshi)(longd, longd);
	longd(*function_koshi_C)(longd, longd);
	longd(*function)(longd, longd);

	RK4 RK;
	
	vector<long double> aP;	// Точки
	vector<long double> aV;	// Значения численного метода
	vector<long double> aU;	// Значения точного решения
	vector<long double> aH;	// Шаг численного метода
	vector<long double> aE;	// Локальные погрешности

	double maxE = .001L;		// Верхний предел локальной погрешности
	double minE = .000003125L;	// Нижний предел локальной погрешности

	longd constKoshi;		// C0 из НУ задачи Коши;

	size_t counthUp = 0;	// Количество удвоений
	size_t counthDown = 0;	// Количество делений

	// Возвращает локальную погрешность
	inline longd local_error(longd u, longd v) {
		return abs(u - v);
	}

	// Возвращает обновленное значение шага
	longd h_correction(longd lerror, longd h) {
		if (lerror > maxE) {
			return h * .5;	// Уменьшаем шаг в 2 раза
		}
		if (lerror < minE) {
			return h * 2.0;	// Увеличиваем шаг в 2 раза
		}
		return h;	// Все хорошо, продолжаем
		// if( h == h_correction ) => continue
		//	else перерасчет значения
	}

	longd K(longd x) {
		return function_koshi(x, constKoshi);
	}

	

public:
	NMManager() {

		longd _iu0 = 1;
		longd _ix0 = 0;
		longd _ih0 = .1L;

		function_koshi = FKoshi;
		function = F;
		function_koshi_C = FKoshiC;

		constKoshi = FKoshiC(_iu0, _ix0);

		longd L = K(0);

		aP.push_back(_ix0);	// x0
		aU.push_back(_iu0);	// u0
		aV.push_back(_iu0);	// u0
		aH.push_back(_ih0);	// h0
		aE.push_back(0);	// Локальная погрешность изначально = 0

		RK.setFunction(F);
	}

	longd nextPoint() {
		return 0;
	}

	long double nextValue() {
		longd hc;
		longd h0;
		longd lerror;
		longd x;
		longd h;
		longd v;
		longd newU;
		longd newV;

		h0 = hc = aH[aH.size() - 1];
		x = aP[aP.size() - 1];
		v = aV[aV.size() - 1];

		do {
			h = hc;

			newU = K(x + h);
			newV = RK.nextValue(x, v, h);

			lerror = local_error(newU, newV);
			
			hc = h_correction(lerror, h);
		} while (hc != h);

		if (h0 != h) {
			if (h > h0) {
				counthUp++;
			}
			else if (h < h0) {
				counthDown++;
			}
		}
		
		aH.push_back(h);
		aE.push_back(lerror);
		aP.push_back(x + h);
		aV.push_back(newV);
		aU.push_back(newU);
		
		return newV;
	}

	void n(size_t N) {
		for (int i = 0; i < N - 1; i++) {
			nextValue();
		}

		return;
	}
};