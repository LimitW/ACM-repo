#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
int comp(const void *a,const void *b){
	return *(int*) a - *(int*) b;
}

int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int CaseNo = 1;	
	int n;
	while(cin>>n && n){
		printf("Game %d:\n",CaseNo++);
		int code[1010];
		int guess[1010];
		int i,j;
		for(i = 0;i < n;i++){
			cin>>code[i];
		}
		while(1){
			int code_[1010];
			for(i = 0;i < n;i++)
				code_[i] = code[i];
			int flag = 0;
			for(i = 0;i < n;i++){
				cin>>guess[i];
				if(guess[i] != 0)
					flag = 1;
			}
			if(!flag)
				break;
			int right_n = 0,position_wrong_n = 0;
			for(i = 0;i < n;i++){
				if(code_[i] == guess[i]){
					right_n++;
					guess[i] = code_[i] = -1;
				}
			}
			qsort(code_,n,sizeof(int),comp);
			qsort(guess,n,sizeof(int),comp);
			for(i = right_n;i < n;i++)
				for(j = right_n;j < n;j++){
					if(guess[i] == code_[j]){
						position_wrong_n++;
						guess[i] = code_[j] = -1;
						qsort(code_,n,sizeof(int),comp);
						qsort(guess,n,sizeof(int),comp);
				}
			}
			printf("    (%d,%d)\n",right_n,position_wrong_n);
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}