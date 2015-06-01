#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	if(!a && !b)
		return 0;
	int c = 0,ans = 0;
	int i;
	for(i = 9;i >= 0;i--){
		c = a % 10 + b % 10 + c > 9 ? 1 : 0;
		ans += c;
		a /= 10;
		b /= 10;
	}
	cout<<ans<<endl;
	getchar();
	return 0;
}