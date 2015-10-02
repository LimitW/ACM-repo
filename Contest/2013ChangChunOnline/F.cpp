/*
 * Title:Stone
 * Author:LimitW
 * Date:2014.8.15
 * Source:2013 ChangChunSite online F
 * Note:线性棋 逆推必胜位必输位
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
int check(int n,int k){
	return (n % (k + 1) == 1);
}
int main(){
	int N,K;
	while(cin>>N>>K && (N || K)){
		if(check(N,K))
			cout<<"Jiang"<<endl;
		else
			cout<<"Tang"<<endl;
	}
	return 0;
}