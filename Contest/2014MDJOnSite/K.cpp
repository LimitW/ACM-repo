//============================================================================
// Name        : K.cpp
// Author      : LimitW
// Date        : 2014.10.31
// Version     :
// Copyright   : 2014 Mudanjiang Onstie K
// Description : Greedy , String
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

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        char s[1010];
        scanf("%s",&s);
        int len = strlen(s);
        int total_star = 0;
        for(int j = 0 ; j < len ; j++)
        {
            if( s[j] == '*' ) total_star++;
        }
        if(total_star == 0) { printf("0\n"); continue; }
        int total_insert = 0 , total_swap = 0;
        if(total_star * 2 >= len) total_insert += (2 * total_star + 1 - len);
        int now_star = 0 , now_number = total_insert;
        for(int j = 0 ; j < len ; j++)
        {
            if(s[j] == '*'){
                now_star++;
                if(now_star + 1 > now_number){
                        total_swap++ ;
                        now_star-- ; now_number++ ;
                        for(int k = len - 1 ; k > j ; k-- )
                        {
                            if(s[k] != '*') { s[k] = '*'; break; }
                        }
                 }
            }
            else now_number++;
        }
        if(s[len-1] != '*') total_insert++;
        printf("%d\n",total_swap + total_insert);
    }
    return 0;
}
