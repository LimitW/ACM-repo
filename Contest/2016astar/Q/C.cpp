#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct node{
    int n;
    node* nxt[30];
    node(){
        n = 1;
        memset(nxt, 0, sizeof(nxt));
    }
};

void insert(node* cur, char* s){
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(cur->nxt[s[i]-'a'] == NULL)
            cur->nxt[s[i]-'a'] = new node();
        else
            cur->nxt[s[i]-'a']->n++;
        cur = cur->nxt[s[i]-'a'];
    }
}

int exists(node* cur, char* s){
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(cur->nxt[s[i]-'a'] == NULL)
            return 0;
        else if(cur->nxt[s[i]-'a']-> n == 0)
            return 0;
        else cur = cur->nxt[s[i]-'a'];
    }
    return cur->n;
}

void del(node* cur, char *s, int v){
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        cur->nxt[s[i]-'a']->n -= v;
        if(i == len - 1) cur->nxt[s[i]-'a'] = NULL;
        else cur = cur->nxt[s[i]-'a'];
    }
}

bool search(node* cur, char *s){
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(cur->nxt[s[i]-'a'] == NULL)
            return false;
        else if(cur->nxt[s[i]-'a']->n == 0)
            return false;
        cur = cur->nxt[s[i]-'a'];
    }
    return true;
}

char s1[100], s2[100];

int main(){
    int n; scanf("%d", &n);
    node* T = new node();
    int cnt;
    for(int i = 0; i < n; ++i){
        scanf("%s %s", s1, s2);
        if(s1[0] == 'i') insert(T, s2);
        else if(s1[0] == 'd' && (cnt = exists(T, s2)))
            del(T, s2, cnt);
        else if(s1[0] == 's')
            puts(search(T, s2) ? "Yes" : "No");
    }
    return 0;
}
