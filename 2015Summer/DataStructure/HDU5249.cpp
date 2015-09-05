#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

struct Node {
    Node *ch[2];
    int r, v, s;
    Node(int v):v(v){
        ch[0] = ch[1] = NULL;
        r = rand();
        s = 1;
    }
    bool operator < (const Node& rhs) const{
        return r < rhs.r;
    }
    int cmp(int x) const {
        if(x == v) return -1;
        return x < v ? 0 : 1;
    }
    void maintain(){
        s = 1;
        if(ch[0] != NULL) s += ch[0]->s;
        if(ch[1] != NULL) s += ch[1]->s;
    }
};

void rotate(Node* &o,int d){
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o = k;
}

void insert(Node* &o,int x){
    if(o == NULL) o = new Node(x);
    else{
        int d = (x < o->v ? 0 : 1);
        insert(o->ch[d],x);
        if(o->ch[d]->r > o->r) rotate(o,d^1);
    }
    o->maintain();
}

void remove(Node* &o,int x){
    int d = o->cmp(x);
    if(d == -1){
        if(o->ch[0] == NULL) o = o->ch[1];
        else if(o->ch[1] == NULL) o = o->ch[0];
        else{
            int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
            rotate(o,d2);
            remove(o->ch[d2],x);
        }
    }
    else remove(o->ch[d],x);
    if(o != NULL) o->maintain();
}

int getK(Node* o,int x){
    if(o->ch[0] == NULL){
        if(x == 1) return o->v;
        else return getK(o->ch[1],x-1);
    }
    else if(o->ch[1] == NULL){
        if(x == o->ch[0]->s + 1) return o->v;
        else return getK(o->ch[0],x);
    }
    if(x > o->ch[0]->s + 1) return getK(o->ch[1],x-o->ch[0]->s-1);
    else if(x == o->ch[0]->s + 1) return o->v;
    else return getK(o->ch[0],x);
}

int find(Node* o,int x){
    while(o != NULL){
        int d = o->cmp(x);
        if(d == -1) return 1;
        else o = o->ch[d];
    }
    return 0;
}

int main(){
    int n, kase = 0;
    while(~scanf("%d",&n)){
    	printf("Case #%d:\n",++kase);
    	Node* root = NULL;
    	queue<int> que;
    	for(int i = 0; i < n; ++i){
    		char s[6]; scanf("%s",s);
    		if(s[0] == 'i'){
    			int tmp; scanf("%d",&tmp);
    			insert(root,tmp);
    			que.push(tmp);
    		}
    		else if(s[0] == 'o'){
    			remove(root,que.front());
    			que.pop();
    		}
    		else printf("%d\n",getK(root,floor(que.size()/2)+1));
    	}
    }
    return 0;
}
