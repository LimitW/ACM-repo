#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

char mirror_1[] = {"AEHIJLMOSTUVWXYZ12358"};
char mirror_2[] = {"A3HILJMO2TUVWXY51SEZ8"};

bool palindrome(char *s);
bool mirror(char *s);

int main(){
	//freopen("out.txt","w",stdout);

	char s[31];
	while(scanf("%s",&s) != EOF){
		printf("%s -- ",&s);
		if(palindrome(s) && mirror(s))
			printf("is a mirrored palindrome.\n");
		if(!palindrome(s) && mirror(s))
			printf("is a mirrored string.\n");
		if(palindrome(s) && !mirror(s))
			printf("is a regular palindrome.\n");
		if(!palindrome(s) && !mirror(s))
			printf("is not a palindrome.\n");
		printf("\n");
	}
	//fclose(stdout);
	return 0;
}

bool palindrome(char *s){
	int i;
	int len = strlen(s);
	for(i = 0;i < len / 2;i++){
		if(s[i] != s[len-i-1])
			return 0;
	}
	return 1;
}

bool mirror(char *s){
	int i,j;
	int flag;
	int len = strlen(s);
	int k = len >= 2 ? (len / 2) : 1;
	for(i = 0;i < k;i++){
		flag = 0;
		for(j = 0;mirror_1[j];j++){
			if(s[i] == mirror_1[j] && s[len-i-1] == mirror_2[j]){
				flag = 1;
				break;
			}
		}
		if(j == strlen(mirror_1) && flag == 0)
			return 0;
	}
	return 1;
}