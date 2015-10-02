/*
 * Title:Dressing
 * Author:LimitW
 * Date:2014.8.18
 * Source:2012 JinHuaSite J
 * Note:水题
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

bool pantsshoes[1010][1010];
bool clothespants[1010][1010];
int re1[1010],re2[1010];

int main(){
	int n,m,k;
	while(cin>>n>>m>>k && (n||m||k)){
		memset(pantsshoes,0,sizeof(pantsshoes));
		memset(clothespants,0,sizeof(clothespants));
		memset(re1,0,sizeof(re1));
		memset(re2,0,sizeof(re2));
		int p;
		cin>>p;
		int i,j,z;
		int sum = n*m*k;
		for(i=0;i<p;i++){
			char s1[10],s2[10];
			int num1,num2;
			scanf("%s %d %s %d",&s1,&num1,&s2,&num2);
			if(s1[0] == 'c'){
				if(!clothespants[num1][num2]){
					re1[num2]++;
					sum -= k;
					sum += re2[num2];
					clothespants[num1][num2] = 1;
				}
			}
			if(s1[0] == 'p'){
				if(!pantsshoes[num1][num2]){
					re2[num1]++;
					sum -= n;
					sum += re1[num1];
					pantsshoes[num1][num2] = 1;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}