//============================================================================
// Name        : I.cpp
// Author      : LimitW
// Date        : 2014.10.13
// Version     :
// Copyright   : 2014 Mudanjiang Onstie I
// Description : 
//============================================================================

#include <iostream>
#include <cstring>
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
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

double a[110];

int main(){
	int T;
	cin >> T;
	while(T--){
		double n; string op;
		cin >> n >> op;
		int x = -1;
		if(op[0] == 'b') x = 2;
		else if(op[0] = 'd') x = 10;
		for(int i = 0; i < n; i++)
			scanf("%lf",&a[i]);
        double ans = 0;
		for(int i = 0; i < n; i++){
            if(a[i] == 0) continue;
			if(x != -1)
                ans -= (a[i]*log(a[i]/100))/(log(x)*100);
			if(x == -1)
                ans -= (a[i]*log(a[i]/100))/(100);
		}
		printf("%.8lf\n",ans);
	}
	return 0;
}
