#include <iostream>
#include <iomanip>
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
#include <utility>
#include <bitset>
#include <functional>
#include <algorithm>
#include <fstream>

using namespace std;

#define LL long long

const int INF = 0x3f3f3f3f;

int main(){
	int n;  scanf("%d",&n); getchar();
	string s;
	stack<char> br; vector<char> var;
	map< char , pair<int,int> > init_var_pos[3000];
	vector<char> scope[3000];
	int vis[3000][26];
	int head = 0;
	for(int line = 1; line <= n; line++)
	{
		getline(cin,s);
		int l = s.length();
		for(int i = 0; i < l; i++)
		{
			char c = s[i];
			if(c == ' ') continue;
			else if(c >= 'a' && c <= 'z') {
				int flag = 1;
				for(int sear = head; sear >= 0; sear--){
					if(vis[sear][c-'a']){
						printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",line,i+1,c,init_var_pos[sear][c].first,init_var_pos[sear][c].second);
						scope[head].push_back(c);
						init_var_pos[head][c] = make_pair(line,i+1); vis[head][c-'a'] = 1;
						flag = 0; break;
					}
				}
				if(flag){
					var.push_back(c);
					scope[head].push_back(c);
					init_var_pos[head][c] = make_pair(line,i+1);
					vis[head][c-'a'] = 1;
				}
			}
			else if(c == '{') { br.push(c); head++; }
			else if(c == '}') {
				for(int k = 0; k < scope[head].size(); k++)
				{
					if(vis[head][scope[head][k] - 'a']) vis[head][scope[head][k] - 'a'] = 0;
				}
				br.pop(); head--;
			}
		}
	}
	return 0;
}
