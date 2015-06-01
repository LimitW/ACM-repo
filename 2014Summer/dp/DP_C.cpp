/*
 * Title:Brackets
 * Author:LimitW
 * Date:2014.8.7
 * Source:poj 2955
 * Note:区间dp
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
//
using namespace std;
const int maxn = 100 + 10;
int dp[maxn][maxn]; // i - j的最大匹配数
string str;

bool check(char x,char y){
	return (x == '(' && y == ')') || (x == '[' && y == ']');
}

int main(){
	while(cin >> str && str != "end"){
		memset(dp,0,sizeof(dp));
		int len = str.length();
		int i,j,k,l;
		for(l = 1; l < len; l++){//区间长度 j - i
			for(i = 0,j = l; j < len; i++,j++){
				if(check(str[i],str[j]))
					dp[i][j] = dp[i+1][j-1] + 2;
				for(k = i; k < j; k++)
					dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
		cout<<dp[0][len-1]<<endl;
	}
	return 0;
}