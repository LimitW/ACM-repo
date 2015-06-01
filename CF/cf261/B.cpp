/*
 * Title:Pashmak and Flowers
 * Author:LimitW
 * Date:2014.8.16
 * Source:codeforces round 261 B
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

int main(){
	long long a[200010];
	long long n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long d = a[n-1]-a[0];
	long long x1=0,x2=n-1;
	while(x1<n-1){
		if(a[x1]!=a[x1+1]) break;
		x1++;
	}
	while(x2>0){
		if(a[x2]!=a[x2-1]) break;
		x2--;
	}
	x1++;
	x2 = n - x2;
	if(x1+x2<=n)
		cout<<d<<' '<<x1*x2<<endl;
	else
		cout<<d<<' '<<n*(n-1)/2<<endl;
	return 0;
}