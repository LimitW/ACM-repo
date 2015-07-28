#include <cstdio>
#include <iostream>

using namespace std;

int a[7];

int main(){
	for(int i = 1; i <= 6; i++)
		cin >> a[i];
	bool flag = 0;
	if(a[1] >= a[3] + a[5] && a[2] >= max(a[4],a[6])) flag = 1;
	else if(a[1] >= a[3] + a[6] && a[2] >= max(a[4],a[5])) flag = 1;
	else if(a[1] >= a[4] + a[5] && a[2] >= max(a[3],a[6])) flag = 1;
	else if(a[1] >= a[4] + a[6] && a[2] >= max(a[3],a[5])) flag = 1;
	else if(a[2] >= a[3] + a[5] && a[1] >= max(a[4],a[6])) flag = 1;
	else if(a[2] >= a[3] + a[6] && a[1] >= max(a[4],a[5])) flag = 1;
	else if(a[2] >= a[4] + a[5] && a[1] >= max(a[3],a[6])) flag = 1;
	else if(a[2] >= a[4] + a[6] && a[1] >= max(a[3],a[5])) flag = 1;
	if(flag) puts("YES");
	else puts("NO");
    return 0;
}

