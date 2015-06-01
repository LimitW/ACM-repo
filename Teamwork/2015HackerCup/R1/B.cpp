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

LL ans;

struct TrieNode{
	TrieNode* child[26];
	TrieNode(){
		for(int i = 0; i < 26; i++){
			child[i]=NULL;
		}
	}
};

struct Trie{
	Trie(){
		pRoot=new TrieNode();
	}
	void AddTrie(char* s);
	TrieNode* pRoot;
};

void Trie::AddTrie(char *s){
	TrieNode *p = pRoot;
	int i = 0 , k;
	bool ok = 0;
	while(s[i]){
		k = s[i++] - 'a';
		if(p->child[k] == NULL){
			p->child[k] = new TrieNode();
			if(!ok) ans += i;
			ok = 1;
		}
		p = p->child[k];
	}
	if(!ok) ans += strlen(s);
}

int main(){
	freopen("autocomplete.txt","r",stdin);
	freopen("B.txt","w",stdout);
	int T; scanf("%d",&T);
	for(int kase = 1; kase <= T; kase++)
	{
		ans = 0; Trie root;
		int n; scanf("%d",&n);
		char s[1000010];
		for(int i = 0; i < n; i++)
		{
			scanf("%s",s);
			root.AddTrie(s);
		}
		printf("Case #%d: %d\n",kase,ans);
	}
    return 0;
}
