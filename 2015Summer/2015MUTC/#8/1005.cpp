#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
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
#include <algorithm>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const int mod = 258280327;
const int maxn = 1e5 + 3;
//const int maxm = maxn * maxn;

char st[10010], keywords[10010];
vector<string> ss;
int n,m;
map<string,int> mp;
int num[maxn];

struct Trie
{
    int next[maxn][26],fail[maxn],end[maxn];
    int root,L;
    int newnode()
    {
        for(int i = 0;i < 26;i++)
            next[L][i] = -1;
        end[L++] = -1;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    void insert(char* s,int id)
    {
        int len = strlen(s);
        int now = root;
        for(int i = 0;i < len;i++)
        {
            if(next[now][s[i]-'a'] == -1)
                next[now][s[i]-'a'] = newnode();
            now = next[now][s[i]-'a'];
        }
        end[now] = id;
    }
    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0;i < 26;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < 26;i++)
                if(next[now][i] == -1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    int query(string buf)
    {
    	int ans = 0;
        int len=buf.length();
        int now=root;
        for(int i=0;i<len;i++)
        {
            now=next[now][buf[i]-'a'];
            int temp = now;
            while( temp != root )
            {
                if(end[temp] != -1){
                   ans += num[end[temp]];
                }
                temp = fail[temp];
            }
        }
        return ans;
    }

};

Trie ac;

int main(){
	int T; scanf("%d", &T);
 	while(T--){
 		mp.clear();
 		ss.clear();
 		memset(num,0,sizeof(num));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%s", keywords);
            ss.push_back((string)(keywords));
        }
        ac.init();
        for(int i = 0; i < m; ++i){
        	scanf("%s", st);
        	ac.insert(st,i);
        	string x = (string)(st);
        	if(mp.find(x) == mp.end()){
        		mp[x] = i;
        		++num[i];
        	}
        	else{
        		num[i] = num[mp[x]] + 1;
        		num[mp[x]] = 0;
        		mp[x] = i;
        	}
        }
        ac.build();
        for(int i = 0; i < n; ++i){
        	printf("%d\n",ac.query(ss[i]));
        }
    }
    return 0;
}

