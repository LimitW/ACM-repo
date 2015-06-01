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
	int n;
	cin>>n;
	int i,j,k;
	for(i=0;i<(n-1)/2;i++){
		for(j=i;j<(n-1)/2;j++)
			cout<<"*";
		for(k=0;k<2*i+1;k++)
		cout<<"D";
		for(j=i;j<(n-1)/2;j++)
			cout<<"*";
		cout<<endl;
	}
	for(i=0;i<n;i++)
		cout<<"D";
	cout<<endl;
		for(i=(n-1)/2 - 1;i>=0;i--){
		for(j=i;j<(n-1)/2;j++)
			cout<<"*";
		for(k=0;k<2*i+1;k++)
		cout<<"D";
		for(j=i;j<(n-1)/2;j++)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}