/*
 * Title:AOAPC7_4_2.cpp
 * Author:LimitW
 * Date:2014.8.7
 * Source:AOAPC I
 * Note:1-n集合、可重集全排 字典序
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
//1-n全排 字典序
void print_permutation(int n,int *a,int cur){
	int i,j;
	if(cur == n){
		for(i = 0; i < n; i++) printf("%d",a[i]);
		printf("\n");
	}
	else 
		for(i = 1; i <= n; i++){
			int ok = 1;
			for(j = 0; j < cur; j++)
				if(a[j] == i) ok = 0;
			if(ok){
				a[cur] = i;
				print_permutation(n,a,cur+1);
			}
		}
}
//可重集全排 字典序
void print_permutation(int n,int *a,int *p,int cur){
	int i,j;
	if(cur == n){
		for(i = 0; i < n; i++)
			printf("%d",a[i]);
		printf("\n");
	}
	else for(i = 0; i <= n; i++)
		if(!i || p[i] != p[i-1]){
			int c1 = 0,c2 = 0;
			for(j = 0; j < cur; j++) if(a[j] == p[i]) c1++;
			for(j = 0; j < n; j++) if(p[i] == p[j]) c2++;
			if(c1 < c2){
				a[cur] = p[i];
				print_permutation(n,a,p,cur+1);
			}
		}
}
int main(){
	//freopen("out.txt","w",stdout);
	int a[4] = {1,2,3,4};
	print_permutation(4,a,1);
	int p[3] = {1,1,1};
	print_permutation(3,a,p,1);
	//fclose(stdout);
	system("pause");
	return 0;
}