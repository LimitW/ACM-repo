//============================================================================
// Name        : H.cpp
// Author      : LimitW
// Date        : 2014.11.8
// Version     :
// Copyright   : 2013 Chengdu Onsite H
// Description : =_=
//============================================================================
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;
double mpow(int n){
	double ans = 1.0;
	for(int i = 0; i < n; i++)
	{
		ans *= 1.024;
	}
	return ans;
}

int main(){
	int T; cin >> T;
	for(int t = 1; t <= T; t++){
		string s;
		cin >> s;
		double ans = 1.0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '['){
				i++;
				if(s[i] == 'B') ans /= mpow(0);
				if(s[i] == 'K') ans /= mpow(1);
				if(s[i] == 'M') ans /= mpow(2);
				if(s[i] == 'G') ans /= mpow(3);
				if(s[i] == 'T') ans /= mpow(4);
				if(s[i] == 'P') ans /= mpow(5);
				if(s[i] == 'E') ans /= mpow(6);
				if(s[i] == 'Z') ans /= mpow(7);
				if(s[i] == 'Y') ans /= mpow(8);
				double x = 1.0;
				ans = 100 * (x - ans);
				printf("Case #%d: %.2lf%%\n",t,ans);
				break;
			}
		}
	}
	return 0;
}
