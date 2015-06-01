/*
 * Title:A0APC_7_3.cpp
 * Author:LimitW
 * Date:2014.8.7
 * Source:AOAPC I 
 * Note:位运算 枚举
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

// 打印0 - n-1 的子集
void print_subset(int n,int s){
	int i,flag=0;
	for(i = 0; i < n; i++)
		if(s & (1 << i)){ // 1<<i = pow(2,i)-1（二进制11111……，n位) s&(1<<i) 即取s补集
			printf("%d ",i);
			flag = 1;
		}
	if(flag) printf("\n");
}

int main(){
	int i;
	int n;
	cin>>n;
	for(i = 0; i < (1<<n); i++){
		print_subset(n,i);
	}
	system("pause");
	return 0;
}