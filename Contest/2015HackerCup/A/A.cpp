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

int main(){
	freopen("cooking_the_books.txt","r",stdin);
	freopen("A.txt","w",stdout);
	int T; cin >> T;
	for(int kase = 1; kase <= T; kase++){
		string s; cin >> s;
		int n = s.length();
		string smax = s , smin = s;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				string tmp = s;
				swap(tmp[i],tmp[j]);
				if(tmp[0] == '0') continue;
				smax = max(smax,tmp);
				smin = min(smin,tmp);
			}
		cout << "Case #" << kase << ": " << smin << " " << smax << '\n';
	}
    return 0;
}
