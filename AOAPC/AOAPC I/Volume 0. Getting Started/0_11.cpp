#include<iostream>
#include<cstdio>

using namespace std;


int Collatz(int A,int limit){
	int ans = 1;
	while(A != 1 && A < limit){
		if(A % 2 != 0){
			ans++;
			A = 3*A + 1;
		}
		else{
			ans++;
			A/=2;
		}
	}
	return ans;
}

int main(){
	int A,limit;
	int t = 0;
	while((cin >> A >> limit) && !((A == -1) && (limit == -1))){
		t++;
		printf("Case %d: A = %d, limit = %d, number of terms = %d\n",t,A,limit,Collatz(A,limit));
	}
	return 0;
}
