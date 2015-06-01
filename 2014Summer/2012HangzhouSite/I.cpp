/*
 * Title:The Power of Xiangqi
 * Author:LimitW
 * Date:2014.8.4
 * Source:2012 HangZhouSite I
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

int power(char c){
	switch(c){
		case 'A': return 16;
		case 'B': return 7;
		case 'C': return 8;
		case 'D': return 1;
		case 'E': return 1;
		case 'F': return 2;
		case 'G': return 3;
	}
	return 0;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int red=0,black=0;
		char tmp;
		int ma=0,pao=0;
		int n;
		int i;
		scanf("%d ",&n);
		for(i=0;i<n-1;i++){
			scanf("%c ",&tmp);
			red += power(tmp);
			if(tmp == 'B')
				ma = 1;
			if(tmp == 'C')
				pao = 1;
		}
		scanf("%c",&tmp);
		red += power(tmp);
		if(tmp == 'B')
			ma = 1;
		if(tmp == 'C')
			pao = 1;
		if((ma != 1 || pao != 1) && red > 1)
			red--;
		ma=0;
		pao=0;
		scanf("%d ",&n);
		for(i=0;i<n-1;i++){
			scanf("%c ",&tmp);
			black += power(tmp);
			if(tmp == 'B')
				ma = 1;
			if(tmp == 'C')
				pao = 1;
		}
		scanf("%c",&tmp);
		black += power(tmp);
		if(tmp == 'B')
			ma = 1;
		if(tmp == 'C')
			pao = 1;
		if((ma != 1 || pao != 1) && black > 1)
			black--;
		if(red==black)
			cout<<"tie"<<endl;
		if(red>black)
			cout<<"red"<<endl;
		if(red<black)
			cout<<"black"<<endl;
	}
	return 0;
}