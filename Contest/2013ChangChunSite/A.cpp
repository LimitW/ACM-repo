/*
 * Title:Hard Code
 * Author:LimitW
 * Date:2014.7.25
 * Source:2013 ChangChunSite A
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

int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		int i,j;
		int t = 0;
		for(j = 0;j < a;j++){
			for(i = t; i < b+t && s[i]; i++){
				cout<<s[i];
			}
			t += b;
			cout<<endl;
		}
	}
	return 0;
}