/*
 * Title:AOAPC7_4_1.cpp
 * Author:LimitW
 * Date:2014.8.7
 * Source:AOAPC I hdoj 2553
 * Note:N皇后问题 AOAPC I回溯法 hdoj不打表进行预处理会超时
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
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

//回溯法 AOAPC I

int tot;
int C[1000];
int vis[3][1000];//列、主对角线、副对角线

/*void search(int cur,int n){
	int i,j;
	if(cur == n)
		tot++;
	else{
		for(i=0;i<n;i++){
            int ok = 1;
            C[cur] = i;
            for(j = 0;j < cur; j++){
                if(C[cur] == C[j] || cur - C[cur] == j - C[j] || cur + C[cur] == j + C[j]){
                        ok = 0; break;
                }
            }
            if(ok) search(cur+1,n);
		}
	}
}*/

void search(int cur,int n){
	int i,j;
	if(cur == n)
		tot++;
	else{
		for(i=0;i<n;i++){
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]){ //格子(x,y) x+y的值标志主对角线,x-y标记负对角线,可能为负需+n
				C[cur] = i;
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
				search(cur+1,n);
				vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
			}
		}
	}
}

int main(){
	memset(vis,0,sizeof(vis));
	memset(C,0,sizeof(C));
	int n;
	int i;
	int ans[11];
	for(i = 0; i <= 10; i++){
		tot = 0;
		search(0,i);
		ans[i] = tot;
	}//不预处理会超时
	while(cin>>n && n){
		cout<<ans[n]<<endl;
	}
	return 0;
}

