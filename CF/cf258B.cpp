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

const int MAXN = 100010;

int comp(const void* a,const void* b){
	return*(int*)a-*(int*)b;
}

int check(int *a,int *b,int n,int key){
	int i;
	for(i=key;i<n;i++){
		if(a[i]!=b[i])
			return 0;
	}
	return 1;
}

int main(){
	std::ios::sync_with_stdio(false);
	int a[MAXN],c_a[MAXN];
	int cmp[MAXN];
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++){
		cin>>a[i];
		c_a[i]=a[i];
	}
	qsort(a,n,sizeof(int),comp);
	int left,right;
	int flag=0;
	for(i=0;i<n;i++){
		if(a[i] != c_a[i]){
			flag=1;
			left=i;
			for(j=i;!check(a,c_a,n,j);j++);
			right=j-1;
		    break;
		}
	}
	if(flag){
	int t=left;
	for(i=right;i>=left;i--){
		if(a[i] != c_a[t++]){
			cout<<"no"<<endl;
			return 0;
		}
	}
	cout<<"yes"<<endl;
	cout<<left+1<<" "<<right+1<<endl;
	}
	else{
		cout<<"yes"<<endl;
		cout<<1<<" "<<1<<endl;
	}
	return 0;
}