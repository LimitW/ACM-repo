
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
	double n,p;
	while(cin>>n>>p){
		printf("%d\n",(int)(pow(p,1/n)+0.5));
	}
	return 0;
}