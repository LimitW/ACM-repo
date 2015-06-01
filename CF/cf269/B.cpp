/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int a[2010];
vector<int> vec[2010];

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= 2010; i++)
		vec[i].clear();
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		vec[a[i]].push_back(i);
	}
	int c = 1;
	for(int i = 1; i <= 2000; i++)
	{
		if(vec[i].size())
			c *= vec[i].size();
		if(c >= 3) break;
	}
	if(c < 3){
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(int t = 0; t < 3; t++){
        int printn = 0;
        if(t != 0)
            for(int i = 1; i <= 2000; i++){
                if(next_permutation(vec[i].begin(),vec[i].end()) == 1) break;
                else continue;
            }
		for(int i = 1; i <= 2000; i++)
		{
			if(printn == n)
                break;
			if(vec[i].size() > 0)
			{
			    printn += vec[i].size();
			    if(printn != n){
                    for(int z = 0; z < vec[i].size(); z++)
                        printf("%d ",vec[i][z]);
			    }
			    else{
                    for(int z = 0; z < vec[i].size()-1; z++)
                        printf("%d ",vec[i][z]);
                    printf("%d",vec[i][vec[i].size()-1]);
			    }
			}
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}