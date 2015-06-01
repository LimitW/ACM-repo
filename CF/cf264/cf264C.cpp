/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.8.30
 * Source:
 * Note:
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

int n;
long long chessboard[2010][2010];
long long dollar[2010][2010];
long long right1[2010];
long long left1[4010];

int legal(int x,int y){
	return x > 0 && x <= n && y > 0 && y <= n;
}

int main(){
	cin >> n;
	int i,j,k;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%I64d",&chessboard[i][j]);
	memset(dollar,0,sizeof(dollar));
	memset(left1,0,sizeof(left1));
	memset(right1,0,sizeof(right1));
	for(k = 1 - n; k < n; k++){
		for(i = 1; i <= n; i++){
		    if(i + k <= n && i + k > 0)
                right1[k+n] += chessboard[i][i+k];
		}
	}
	for(k = 2; k <= 2*n; k++){
		for(i = 1; i <= n; i++){
			if(k - i <= n && k - i > 0)
				left1[k] += chessboard[i][k-i];
		}
	}
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++){
			dollar[i][j] = right1[j-i+n] + left1[j+i] - chessboard[i][j];
		}
	long long ans1 = 0,ans2 = 0;
	int ansi1,ansj1,ansi2,ansj2;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if((i + j) % 2 == 0 && dollar[i][j] > ans1){
				ans1 = dollar[i][j];
				ansi1 = i; ansj1 = j;
			}
			if((i + j) % 2 == 1 && dollar[i][j] > ans2){
				ans2 = dollar[i][j];
				ansi2 = i; ansj2 = j;
			}
		}
	if(ans1 + ans2 == 0){
		ansi1 = 1; ansj1 = 1; ansi2 = 1; ansj2 = 2;
	}
	printf("%I64d\n",ans1+ans2);
	printf("%d %d %d %d\n",ansi1,ansj1,ansi2,ansj2);
	return 0;
}