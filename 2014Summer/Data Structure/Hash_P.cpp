/*
 * Title:Eqs
 * Author:LimitW
 * Date:2014.8.2
 * Source:poj 1840
 * Note:数据结构 hash
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

short hash[25000001];

int main(){
	int a1,a2,a3,a4,a5;
	while(cin>>a1>>a2>>a3>>a4>>a5){
		memset(hash,0,sizeof(hash));
		int x1,x2,x3,x4,x5;
		int sum=0;
		for(x1=-50;x1<=50;x1++){
			if(x1==0) continue;
			for(x2=-50;x2<=50;x2++){
				if(x2==0) continue;
				sum = (-1)*(a1*x1*x1*x1 + a2*x2*x2*x2);
				if(sum<0) sum+=25000000;
				hash[sum]++;
			}
		}
		int ans=0;
		for(x3=-50;x3<=50;x3++){
			if(x3==0) continue;
			for(x4=-50;x4<=50;x4++){
				if(x4==0) continue;
				for(x5=-50;x5<=50;x5++){
					if(x5==0) continue;
					sum = a3*x3*x3*x3 + a4*x4*x4*x4 + a5*x5*x5*x5;
					if(sum<0)
						sum+=25000000;
					if(hash[sum]) ans += hash[sum];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}