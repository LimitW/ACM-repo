#include <bits/stdc++.h>
using namespace std;

class LengthUnitCalculator{
public:
	double calc(int amount, string fromUnit, string toUnit){
		string names[] = {"in", "ft", "yd", "mi"};
		double v[] = {1.0, 12.0, 3.0, 1760.0};
		int i, j;
		for(i = 0; i < 4; ++i) if(fromUnit == names[i]) break;
		for(j = 0; j < 4; ++j) if(toUnit == names[j]) break;
		double ans = 1.0 * amount;
		while(i < j){
			ans /= v[j];
			--j;
		}
		while(i > j){
			ans *= v[i];
			--i;
		}
		return ans;
	}
};
