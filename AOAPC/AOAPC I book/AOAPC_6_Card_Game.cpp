
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

//queue:First In First Out

int main(){
	queue<int> q;
	int n;
	cin >> n;
	int i;
	for(i = 0; i < n; i++){
		q.push(i+1);
	}
	while(!q.empty()){
		printf("%d ",q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	system("pause");
	return 0;
}