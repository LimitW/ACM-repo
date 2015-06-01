
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

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m<n)
		n=m;
	if(n%2)
		puts("Akshat");
	else 
		puts("Malvika");
}
 