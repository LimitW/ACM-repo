/*
 * Title:
 * Author:LimitW
 * Date:2014.8.9
 * Source:Codeforces Round 260 Div2 A
 * Note:
*/

##include <iostream>
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
struct In
{
	int p,q;
}laptop[100010],laptop1[10010];

int flag;

int cmp(In a,In b){
	if((a.p < b.p && a.q > b.q) || (a.p > b.p && a.q < b.q)) flag = 1;
	return 0;
}

int main(){
    int n;
    cin>>n;
    flag = 0;
    int i,j;
    for(i=0;i<n;i++)
    scanf("%d%d",&laptop[i].p,&laptop[i].q);
    sort(laptop,laptop+n,cmp);
    if(flag)
    	cout<<"Happy Alex"<<endl;
    else
    	cout<<"Poor Alex"<<endl;
    return 0;
}