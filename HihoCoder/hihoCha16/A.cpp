#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;

double f(double a, double b, double c){
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a)) * sqrt((p - b) * (p - c));
}

int main(){
	double a, b, c, l;
	int T; cin >> T;
	while(T--){
		cin >> a >> b >> c >> l;
		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
		if(a > b) swap(a, b);
		double s = a + b + c + l;
		double ans;
		if(3 * c > s){
			double mid, midmid;
			double L = 0, R = l;
			while(R - L > eps){
				mid = L + R; mid /= 2.0;
				midmid = mid + R; midmid /= 2.0;
				double midmidv = f(a + midmid, b + l - midmid, c), midv = f(a + mid, b + l - mid, c);
				if(midmidv < midv) R = midmid;
				else L = mid;
			}
			ans = f(a + L, b + l - L, c);
		}
		else ans = s * s / 12.0 / sqrt(3.0);
		printf("%.10f\n", ans);
	}
	return 0;
}

