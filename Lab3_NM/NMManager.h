#pragma once
#include <vector>
#include <cmath>
#include "RK4.h"

#define pb push_back 

constexpr auto R = 10.0L;
constexpr auto m = 10.0L;
constexpr auto C0 = .01L;
constexpr auto a1 = 99.0L;
constexpr auto a2 = 1.0L;
constexpr auto u0 = 0.0L;
constexpr auto h0 = .01L;

//constexpr auto M_E = 2.71828182845904523536L;

using namespace std;
typedef long double longd;

longd FKoshi(longd t, longd C) {
	longd p = expl(-a1 / m * t);
	longd u = (a1 / a2 * C * p) / (1.0L - C * p);
	return u;
}

longd FKoshiC(longd u, longd t) {
	longd p = expl(a1 / m * t);
	longd C = (u * p) / (a1 / a2 + u);

	return C;
}

longd F(longd x, longd v) {
	return -(a1 * v + a2 * v * v) / m;
}

class NMManager {

	enum{error = 0, steps = 1, point = 2, exact = 3, method = 4};

	longd(*function_koshi)(longd, longd);
	longd(*function_koshi_C)(longd, longd);
	longd(*function)(longd, longd);

	RK4 RK;

	vector<long double> aE;	// ��������� �����������
	vector<long double> aH;	// ��� ���������� ������
	vector<long double> aP;	// �����
	vector<long double> aU;	// �������� ������� �������
	vector<long double> aV;	// �������� ���������� ������

	vector<long double>* Data[5] = {&aE, &aH, &aP, &aU, &aV};
	
	longd inputData[4];		// �������� e0, h0, x0, u0, v0; ������� ���� �������� � ����� 
	longd constKoshi;		// C0 �� �� ������ ����;

	longd maxE = .01L;		// ������� ������ ��������� �����������
	longd minE = .0000001L;	// ������ ������ ��������� �����������


	size_t countHUp = 0;	// ���������� ��������
	size_t countHDown = 0;	// ���������� �������
	size_t innerSize = 0;	// ���������� ����������� �����

	// ���������� ��������� �����������
	longd local_error(longd u, longd v) {
		return abs(u - v);
	}

	// ���������� ����������� �������� ����
	longd h_correction(longd lerror, longd h) {
		if (lerror > maxE) {
			return h * .5;	// ��������� ��� � 2 ����
		}
		if (lerror < minE) {
			return h * 2.0;	// ����������� ��� � 2 ����
		}
		return h;			// ��� ������, ����������
	}

	longd K(longd x) {
		return function_koshi(x, constKoshi);
	}

	inline void data_clear() {
		for (auto D : Data) D->clear();
		innerSize = countHDown = countHUp = 0;
	}

	template<typename ...Args>
	void data_push(Args&& ... args){
		char i = 0;
		auto list = {(args)...};
		for (auto item : list) Data[i++]->push_back(item);
		innerSize++;
	}

public:
	NMManager() {
		longd _ce0 = 0;
		longd _ih0 = .1L;
		longd _iu0 = 1;
		longd _ix0 = 0;

		function_koshi = FKoshi;
		function = F;
		function_koshi_C = FKoshiC;

		RK.setFunction(function);

		setStartData(0, _ih0, _ix0, _iu0);
	}

	void setStartData(longd inputE0, longd inputH0, longd inputX0, longd inputU0) {

		inputData[error] = inputE0;	// ��������� ����������� ���������� = 0
		inputData[steps] = inputH0;
		inputData[point] = inputX0;
		inputData[exact] = inputU0;

		//��������� data_push ������ ���� ������ � ����� �������
		data_push(inputE0, inputH0, inputX0, inputU0, inputU0);

		constKoshi = FKoshiC(inputU0, inputX0);
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

			newU = K(x + h);
			newV = RK.nextValue(x, v, h);

			lerror = local_error(newU, newV);
			
			hc = h_correction(lerror, h);
		} while (hc != h);

		if (h0 != h) {
			if (h > h0) {
				countHUp++;
			}
			else if (h < h0) {
				countHDown++;
			}
		}

		//��������� data_push ������ ���� ������ � ����� �������
		data_push(lerror, h, x + h, newU, newV);
		
		return newV;
	}

	void Build(size_t N) {
		data_clear();
		data_push(inputData[error], inputData[steps], inputData[point], inputData[exact], inputData[exact]);

		if (N == 0) {
			return;
		}

		for (int i = 0; i < N - 1; i++) {
			nextValue();
		}

		return;
	}

	vector<longd> getPoints() {
		return aH;
	}

	vector<longd> getMethod() {
		return aV;
	}

	vector<longd> getExact() {
		return aU;
	}

	size_t size() {
		return innerSize;
	}
};