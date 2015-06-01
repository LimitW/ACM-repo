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

int mat1[801][801] , mat2[801][801] , ans[801][801];
int main(){
	freopen("test.in","r",stdin);
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&mat1[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&mat2[i][j]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					ans[i][j] += (mat1[i][k] * mat2[k][j]) % 3;
				}
				ans[i][j] %= 3;
			}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				printf("%d%c",ans[i][j],j == n-1 ? '\n' : ' ');
	}
	return 0;
}
