#include <iostream>

using namespace std;

struct TrieNode{
	int nCount;
	TrieNode* child[26];
	TrieNode():nCount(0){
		int i;
		for(i=0;i<26;i++){
			child[i]=NULL;
		}
	}
};

struct Trie{
	Trie(){
		pRoot=new TrieNode();
	}
	void AddTrie(char* s);
	int SearchTrie(char* s);
	TrieNode* pRoot;
};

void Trie::AddTrie(char *s){
	TrieNode *p = pRoot;
	int i=0,k;
	while (s[i]){
		k=s[i++]-'a';
		if(p->child[k] == NULL){
			p->child[k] = new TrieNode();
		}
		p=p->child[k];
		p->nCount++;
	}
}

int Trie::SearchTrie(char *s){
	int i,k;
	i=0;
	TrieNode *p = pRoot;
	while(s[i]){
		k=s[i++]-'a';
		if(p->child[k] == NULL){
			return 0;
		}
		p=p->child[k];
	}
	return p->nCount;
}

int main(){
	Trie root;
	int dicN;
	cin >> dicN;
	char word[11];
	int n = 0;
	while (dicN--){
		cin >> word;
		root.AddTrie(word);
	}
	int questionN;
	cin >> questionN;
	char question[11];
	while (questionN--){
		cin >> question;
		cout << root.SearchTrie(question) << endl;
	}
	return 0;
}
