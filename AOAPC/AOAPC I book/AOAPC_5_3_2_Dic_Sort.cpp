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

int cmp_char(const void* _a,const void* _b){
	char * a = (char*) _a;
	char * b = (char*) _b;
	return *a - *b;
}

int cmp_string(const void* _a,const void* _b){
	char* a = (char*) _a;
	char* b = (char*) _b;
	return strcmp(a,b);
}

int main(){
	int n = 0;
	char word[2000][10],sorted[2000][10];
	for(;;){
		scanf("%s",word[n]);
		if(word[n][0] == '*')
			break;
		n++;
	}
	qsort(word,n,sizeof(word[0]),cmp_string);
	int i;
	for(i = 0; i < n; i++){
		strcpy(sorted[i],word[i]);
		qsort(sorted[i],strlen(sorted[i]),sizeof(char),cmp_char);
	}
	char s[10];
	while(scanf("%s",s) == 1){
		qsort(s,strlen(s),sizeof(char),cmp_char);
		for(i = 0; i < n; i++){
			int found = 0;
			if(strcmp(sorted[i],s) == 0){
				found = 1;
				printf("%s ",word[i]);
			}
			if(!found)
				printf(":(");
		}
		printf("\n");
	}
	return 0;
}
