#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int maxn = 1e6+5;

int rmax[maxn] , rmin[maxn] , lmax[maxn], lmin[maxn];
string s;

int main(){
	//freopen("test.in","r",stdin);
	while(cin >> s) {
		memset(rmin,0,sizeof(rmin));
		memset(rmax,0,sizeof(rmax));
		memset(lmin,0,sizeof(lmin));
		memset(lmax,0,sizeof(lmax));
		int n = s.length();
		if(n % 2 != 0 || s[n-1] == '(' || s[0] == ')') { printf("None\n"); continue; }
		int flag = 1;
		s[n-1] = ')'; rmax[n-1] = 1; rmin[n-1] = 1;
		for(int i = n-2; i >= 0; i--){
			if(s[i] == ')'){
				rmax[i] = rmax[i+1] + 1;
				rmin[i] = rmin[i+1] + 1;
			}
			else if(s[i] == '('){
				if(rmax[i+1] == 0) { flag = 0; break; }
				rmax[i] = rmax[i+1] - 1;
				if(rmin[i+1] != 0) rmin[i] = rmin[i+1] - 1;
 			}
			else if(s[i] == '?')
			{
				if(rmax[i+1] == 0) s[i] = ')';
				else{
					rmax[i] = rmax[i+1] + 1;
					if(rmin[i+1] != 0)
						rmin[i] = rmin[i+1] - 1;
				}
			}
		}
		if(flag != 0 && rmin[0] == 0) flag = 1;
		else flag = 0;
		if(flag){
			s[0] = '('; lmax[0] = 1; lmin[0] = 1;
			for(int i = 1; i < n-1; i++){
				if(s[i] == '('){
					lmax[i] = lmax[i-1] + 1;
					lmin[i] = lmin[i-1] + 1;
				}
				else if(s[i] == ')'){
					if(lmax[i-1] == 0) { flag = 0; break; }
					lmax[i] = lmax[i-1] - 1;
					if(lmin[i-1] != 0) lmin[i] = lmin[i-1] - 1;
	 			}
				else if(s[i] == '?')
				{
					int u = lmax[i-1] , v = lmin[i-1];
					if(v + 1 <= rmax[i+1] &&  u - 1 >= rmin[i+1])
						flag = 2; break;
				}
			}
		}
		if(flag == 2) printf("Many\n");
		else if(flag == 1) printf("Unique\n");
		else printf("None\n");
	}
	return 0;
}
