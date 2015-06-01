/*
 * Title:Mega Mans Missions
 * Author:LimitW
 * Date:2014.8.21
 * Source:Uvaoj 11795
 * Note:状态压缩dp
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

char robot[20];
int robot2[20];
int weapon[(1<<16)+10];
long long f[(1<<16)+10];

//destory the i-th robot with the j-th robot's weapon

int main(){
	int T;
	scanf("%d",&T);
	int CaseNo = 1;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i = 0; i <= n; i++){
			scanf("%s",robot);
			robot2[i] = 0;
			for(int j = 0; robot[j]; j++)
				if(robot[j] == '1')	robot2[i] |= (1 << j); //状态压缩
		}
		int maxstate = (1 << n) - 1; //状态数
		weapon[0] = robot2[0]; //mega man
		for(int k = 1; k <= maxstate; k++){
			weapon[k] = robot2[0];
			for(int i = 0; i < n; i++)
				if((k >> i) & 1) weapon[k] |= robot2[i+1];//逐位判断是否为1
		}
		f[0] = 1;
		for(int k = 1; k <= maxstate; k++){
			f[k] = 0;
			for(int i = 0; i < n; i++)
				if( (weapon[k^(1<<i)] >>i ) & 1)// k^(1<<i) 存在消灭新机器人的武器，且在武器集合内
					f[k] += f[k^(1<<i)];//f[k] = sum{{所有的{k-1}且其获得的武器能摧毁新机器人}
		}
		printf("Case %d: %lld\n",CaseNo++,f[maxstate]);
	}
	return 0;
}