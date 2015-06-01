//============================================================================
// Name        : A.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   : CF 273 A
// Description :
//============================================================================

#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int INF = 0x3f3f3f3f;

int A(){
	int c1,c2,c3,c4,c5;
	cin >> c1 >> c2 >> c3 >> c4 >> c5;
	int sum = c1 + c2 + c3 + c4 + c5;
	if(sum % 5 == 0 && sum != 0) cout << sum/5 << endl;
	else cout << -1 << endl;
    return 0;
}