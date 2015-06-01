/************************************************
 * Title:K Smallest Sums
 * Author:LimitW
 * Date:2014.10.4
 * Source:UVa 11997
 * Note:priority queue
*************************************************/

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

const int maxn = 800;

int A[maxn][maxn];

struct item
{
	int s,b;
	item(int s,int b):s(s),b(b){};
	bool operator < (const item & a) const{
		return  s > a.s;
	}
};

void merge(int* A,int* B,int* C,int n){
	priority_queue<item> q;
	for(int i = 0; i < n; i++)
		q.push(item(A[i]+B[0],0));
	for(int i = 0; i < n; i++)
	{
		item it = q.top(); q.pop();
		C[i] = it.s;
		int b = it.b;
		if(b + 1 < n)
			q.push(item(it.s-B[b]+B[b+1],b+1));
	}
}

int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0; i < n; i++)
		{	
			for(int j = 0; j < n; j++)
				scanf("%d",&A[i][j]);
			sort(A[i],A[i]+n);
		}
		for(int i = 1; i < n; i++)
			merge(A[0],A[i],A[0],n);
		for(int i = 0; i < n - 1; i++)
			printf("%d ", A[0][i]);
		printf("%d\n",A[0][n-1]);
	}
	//system("pause");
	return 0;
}