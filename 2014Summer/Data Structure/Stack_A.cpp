/*
 * Title:Rails
 * Author:LimitW
 * Date:2014.8.2
 * Source:poj 1363
 * Note:数据结构 栈
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
const int maxn = 1e3 + 10;

int main(){
	int N;
	while(cin>>N && N){
		int i,j;
		int a[maxn];
		int target[maxn];
		while(cin>>a[0] && a[0]){
			for(i=1;i<N;i++)
				cin>>a[i];
			stack<int> s;
			j = 1;
			for(i = 0;i < N;i++){
                if(j > N) break;
                if(j < N && j == a[i]){
					j++; continue;
				}
				else if(!s.empty() && s.top() == a[i]){
					s.pop(); continue;
				}
				else if(j < N){
					s.push(j); j++; i--;
				}
			}
			if(s.empty() && i == N)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cout<<endl;
	}
	return 0;
}