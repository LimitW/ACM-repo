//============================================================================
// Name        : B.cpp
// Author      : LimitW
// Date        : 2014.11.1
// Version     :
// Copyright   : 2014 Anshan Onsite
// Description : Implementation
//============================================================================

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

map<int,bool> mp;
map<int,LL> chat;

int q[5010];
int front = 0 , rear = 0;
int is_top = -1;

void Add(int);
void Close(int);
void Chat(int);
void Rotate(int);
void Prior();
void Choose(int);
void Top(int);
void Untop();

int main(){
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        mp.clear(); chat.clear();
        front = 0; rear = 0; is_top = -1;
        memset(q,0,sizeof(q));
        int n; scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            printf("Operation #%d: ",i);
            char op[10]; int u;
            scanf("%s",&op);
            if(op[0] == 'A'){
                scanf("%d",&u); Add(u);
            }
            else if(op[0] == 'C' && op[1] =='l'){
                scanf("%d",&u); Close(u);
            }
            else if(op[0] == 'C' && op[1] == 'h' && op[2] == 'o' && op[3] == 'o'){
                scanf("%d",&u); Choose(u);
            }
            else if(op[0] == 'R'){
                scanf("%d",&u); Rotate(u);
            }
            else if(op[0] == 'P') Prior();
            else if(op[0] == 'C' && op[1] == 'h' && op[2] == 'a'){
                scanf("%d",&u); Chat(u);
            }
            else if(op[0] == 'T'){
                scanf("%d",&u); Top(u);
            }
            else Untop();
        }
        if(is_top != -1 && chat[is_top])
        {
            printf("Bye %d: %I64d\n",is_top,chat[is_top]);
            mp[is_top] = false;
        }
        for(int i = front; i < rear; i++)
        {
            if(mp[q[i]] == true && chat[q[i]])
            {
                printf("Bye %d: %I64d\n",q[i],chat[q[i]]);
            }
        }
    }
    return 0;
}

void Add(int u){
    if(mp[u] == true) { printf("same priority.\n"); return; }
    mp[u] = true; chat[u] = 0;
    q[rear++] = u;
    printf("success.\n");
    return;
}

void Close(int u){
    if(mp[u] == false) { printf("invalid priority.\n"); return; }
    for(int i = front; i < rear; i++)
    {
        if(q[i] == u){
            for(int j = i; j < rear - 1; j++)
                q[j] = q[j+1];
           rear--;  break;
        }
    }
    mp[u] = false;
    if(u == is_top) is_top = -1;
    printf("close %d with %I64d.\n",u,chat[u]);
    return;
}

void Chat(int w){
    if(is_top != -1) chat[is_top] += (LL) w;
    else if( rear > front ) chat[q[front]] += (LL) w;
    else { printf("empty.\n"); return; }
    printf("success.\n");
    return;
}

void Rotate(int x){
    if(x < 1 || front + x - 1 >= rear){ printf("out of range.\n"); return; }
    int pre = q[front + x - 1];
    for(int i = front + x - 1; i >= front; i--)
        q[i] = q[i-1];
    q[front] = pre;
    printf("success.\n");
    return;
}

void Prior(){
    if(rear == front) { printf("empty.\n"); return; }
    int ma = -1 , pos = -1;
    for(int i = front; i < rear; i++)
        if(q[i] > ma){
            ma = q[i]; pos = i;
        }
    for(int j = pos; j > front ; j--)
        q[j] = q[j-1];
    q[front] = ma;
    printf("success.\n");
    return;
}

void Choose(int u){
    if(mp[u] == false) { printf("invalid priority.\n"); return; }
    for(int i = front; i < rear; i++)
    {
        if(q[i] == u){
            for(int j = i; j >= front + 1; j--)
                q[j] = q[j-1];
            q[front] = u;
        }
    }
    printf("success.\n");
    return;
}

void Top(int u)
{
    if(mp[u] == false) { printf("invalid priority.\n"); return; }
    is_top = u;
    printf("success.\n");
    return;
}

void Untop(){
    if(is_top == -1) {
        printf("no such person.\n"); return;
    }
    is_top = -1;
    printf("success.\n");
    return;
}