#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 10;
int hash1[10010];
int a[maxn];
int ans[10010][2];
int print_ans[10010];

int s(int w)
{
	return 10000 - (100 - w)* (100 - w);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int caseno = 1; caseno <= T; caseno++){
		int n;
		scanf("%d", &n);
		memset(hash1, -1, sizeof(hash1));
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			hash1[s(a[i])] = 0;
		}
		for (int i = 0; i < n; i++){
			hash1[s(a[i])]++;
		}
		int count1 = 0;
		for (int i = 0; i < 10001; i++)
			if (hash1[i] != -1)
				count1++;
		int fail = 1;
		int len = 0;
		int max_ans = -1;
		for (int i = 0; i < 10001; i++)
		{
			if (hash1[i] != -1){
				ans[len][0] = hash1[i];
				ans[len++][1] = i;
				max_ans = max(hash1[i], max_ans);
			}
		}
		for (int j1 = 0; j1 < len; j1++)
			if (ans[j1][0] != max_ans)
			{
				fail = 0; break;
			}
		if (count1 == 1)
			fail = 0;
		printf("Case #%d:\n", caseno);
		if (fail)
			printf("Bad Mushroom\n");
		else
		{
			int len1 = 0;
			int now = max_ans;
			for (int j = 0; j < len; j++)
				if (now == ans[j][0])
				{
					print_ans[len1++] = j;
				}
			for (int k = 0; k < len1; k++)
				print_ans[k] = ans[print_ans[k]][1];
			sort(print_ans, print_ans + len1);
			for (int z = 0; z < len1 - 1; z++)
				printf("%d ", print_ans[z]);
			printf("%d\n", print_ans[len1 - 1]);
		}
	}
	return 0;
}