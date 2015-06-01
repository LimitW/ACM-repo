#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char word[100];
	cin>>word;
	int i,j;
	int len=strlen(word);
	for(i = 1;i <= len;i++){
		if(len % i == 0){
			int ok = 1;
			for(j = i ;j < len;j++){
				if(word[j] != word[j % i]){
					ok = 0;
					break;
				}
				if(ok){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}