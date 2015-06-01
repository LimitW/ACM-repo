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

int get_next(int x);

int main(){
	int num[2000],count;
	scanf("%d",&num[0]);
	printf("%d",num[0]);
	count = 1;
	while(1){
		num[count] = get_next(num[count - 1]);
		printf(" -> %d",num[count]);
		int found = 0;
		int i;
		for(i = 0; i < count; i++){
			if(num[i] == num[count])
				found = 1;
		}
		if(found) break;
		count++;
	}
	printf("\n");
	system("pause");
	return 0;
}

int get_next(int x){
	int a,b,n;
	char s[10];
	sprintf(s,"%d",x);
	n = strlen(s);
	int i,j;
	for(i = 0;i < n; i++)
		for(j = i + 1; j < n; j++){
			if (s[i] > s[j]){
				char t = s[i];
				s[i] = s[j]; s[j] = t;
			}
		}
	sscanf(s,"%d",&b);
	for(i = 0; i < n / 2; i++){
		char t = s[i];
		s[i] = s[n - 1 - i]; s[n - 1 - i] = t;
	}
	sscanf(s,"%d",&a);
	return a - b;
}