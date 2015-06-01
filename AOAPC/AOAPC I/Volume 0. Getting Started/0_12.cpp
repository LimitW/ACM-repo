#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int cell[50][42];

void print(int x){
	switch(x){
		case 0:
		cout<<" ";
		break;
		case 1:
		cout<<".";
		break;
		case 2:
		cout<<"x";
		break;
		case 3:
		cout<<"W";
		break;
	}
}

int main(){
	int T;
	cin>>T;
	memset(cell,0,sizeof(cell));
	cell[0][20] = 1;
	while(T--){
		int DNA[10];
		int i,j;
		for(i = 0;i < 10;i++){
			cin>>DNA[i];
		}
		for(i = 1;i < 50;i++)
			for(j = 1;j < 41;j++)
				cell[i][j] = DNA[ cell[i-1][j-1] + cell[i-1][j+1] + cell[i-1][j] ];
		for(i = 0;i < 50;i++){
			for(j = 1;j < 41;j++)
				print(cell[i][j]);
			cout<<endl;
		}
		if(T)
			cout<<endl;
	}
	return 0;
}