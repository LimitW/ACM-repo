/*
 * Title:
 * Author:LimitW
 * Date:2014.8.9
 * Source:Codeforces Round 260 Div2 B
 * Note:
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
#include<iostream> 
#include<string> 
#include<iomanip> 
#include<algorithm> 
using namespace std; 

int mod(char a[], int b)
{
	long _try_ = 0;
	int i;
	int l = strlen(a);
	for(i = 0; i < l; ++i)
	{
	 	_try_ = _try_ * 10 + (int)(a[i] - '0'); 
	 	if(_try_ > b)
	  	{
	  		_try_ = _try_ % b;
	  	}
	}
	if(_try_ == b) _try_ = 0;
	return _try_;
}

int main(){
	char a[1000000+10];
	cin>>a;
	int k = mod(a,4);
	int ans = 0;
	if(k == 0)
		ans = 4;
	cout<<ans<<endl;
}