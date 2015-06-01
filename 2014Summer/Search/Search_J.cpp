/*
 * Title:Sticks
 * Author:LimitW
 * Date:2014.8.5
 * Source:poj 1011
 * Note:dfs+强剪枝
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

int n;
int sum;
int sticks[65];
int used[65];

int dfs(int key,int nowLen,int nowN){
    if(nowN == sum/key)
        return 1;
    int i;
    for(i=n-1;i>=0;i--){
        if(used[i])
            continue;
        else{
            if(nowLen + sticks[i] == key){
                used[i] = 1;
                if(dfs(key,0,nowN+1))
                    return 1;
            }
            if(nowLen + sticks[i] < key){
                used[i] = 1;
                if(dfs(key,nowLen+sticks[i],nowN))
                    return 1;
            }
            used[i] = 0;
            while(i > 0 && sticks[i]==sticks[i-1])
                i--;
        }
        if(nowLen + sticks[i] == key|| nowLen == 0)
        	break;
    }
    return 0;
}

int main(){
	while(cin>>n && n){
		int i;
		sum = 0;
		for(i=0;i<n;i++){
			cin>>sticks[i];
			sum += sticks[i];
		}
		sort(sticks,sticks+n);
		int left = sticks[n-1],right = sum;
		for(i=left;i<=sum;i++){
			if(sum % i != 0)
				continue;
			memset(used,0,sizeof(used));
			if(dfs(i,0,0)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}