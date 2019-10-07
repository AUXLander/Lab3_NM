#pragma once

typedef long double longd;

using namespace std;
constexpr auto defPoint = -19262454.937311;
constexpr auto defValue = -92132454.134111;

longd function(longd x, longd u);

class RK4 {
	longd(*function)(longd, longd);
	void checkFunction(longd(*userfunction)(longd, longd)) {
		if (*userfunction == nullptr) {
			throw userfunction;
		}
		function = userfunction;
	}
public:
	RK4() {};

	RK4(longd(*userfunction)(longd, longd)) {
		checkFunction(userfunction);
	}

	void setFunction(longd(*userfunction)(longd, longd)) {
		checkFunction(userfunction);
	}
	longd nextPoint(longd _point, longd _H) {
		double point = _point + _H;
		return point;
	}

	longd nextValue(longd _Point, longd _Value, longd _H, longd(*f)(longd, longd) = nullptr) {
		if (*f == nullptr) {
			f = function;
		}
		longd k1 = f(
						_Point,
						_H
					);
		
		longd k2 = f(
						_Point + _H * .25,
						_Value + _H * .25 * k1
					);

		longd k3 = f(
						_Point + _H * .50,
						_Value + _H * .50 * k2
					);

		longd k4 = f(
						_Point + _H,
						_Value + _H * (k1 - k2 - k2 + k3 + k3)
					);

		longd newValue = _Value + (_H / 6) * (k1 + 4 * k3 + k4);

		return newValue;
	}
};