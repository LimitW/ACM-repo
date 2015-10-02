/*
 * Title:Zhuge Liang's Password
 * Author:LimitW
 * Date:2014.8.1
 * Source:2013 HangZhouSite C
 * Note:签到题
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

using namespace std;


const int maxn = 30 + 5;

int card1[maxn][maxn],card2[maxn][maxn];

int check(int a[35][35],int b[35][35],int n){
	int i,j;
	int ans = 0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(a[i][j] == b[i][j])
				ans++;
		}
	return ans;
}

//矩阵旋转90度代码
void turn(int a[35][35],int n){
	int i,j;
	int s;
	int t;
	for(i=0;i<n/2;i++){
		s=n-1-2*i;
		for(j=i;j<s+i;j++){
			t=a[j][i];
			a[j][i]=a[i+s][j];
			a[i+s][j]=a[n-j-1][i+s];
			a[n-j-1][i+s]=a[i][n-j-1];
			a[i][n-j-1] = t;
		}
	}
}

int main(){
	int N;
	while(cin>>N && N){
		int i,j;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++){
				cin>>card1[i][j];
			}
		for(i=0;i<N;i++)
			for(j=0;j<N;j++){
				cin>>card2[i][j];
			}
		int ans=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				int k = check(card1,card2,N);
				ans=max(ans,k);
				turn(card2,N);
			}
			turn(card1,N);
		}
		cout<<ans<<endl;
	}
	return 0;
}