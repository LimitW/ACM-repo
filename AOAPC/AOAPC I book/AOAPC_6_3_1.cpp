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

/*const int maxd = 20;
int s[1<<maxd]; // 开关

int main(){
	int D,I;
	while(scanf("%d%d",&D,&I) != EOF){
		int k,n = (1<<D) -1;//n为最大编号
		int i;
		for(i=0;i<I;i++){
			k = 1;
			while(1){//模拟小球下落
				s[k] = !s[k];
				k = s[k] ? 2*k : 2*k +1; //leftchild num=2k,rightchild num=2k+1
				if(k>n) break;
			}
			printf("%d\n",k/2);
		}
	}
	return 0;
}*/ //直接模拟

//优化
int main(){
	int D,I;
	while(scanf("%d%d",&D,&I) != EOF){
		int k=1;
		int i;
		for(i=0;i<D-1;i++)
			if(I%2){k = k*2; I = (I+1)/2;}
			else{k = k*2+1; I /= 2;}
			printf("%d\n",k);
	}
	return 0;
}
