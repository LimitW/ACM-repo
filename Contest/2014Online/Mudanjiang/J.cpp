/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.9.7
 * Source:2014 Mudanjiang Online J
 * Note:字符串暴力枚举
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

int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
        string ori_str;
        getline(cin,ori_str);
        string str = "";
        for(int i = 0; i < ori_str.length(); i++){
            if( (ori_str[i] <= 'z' && ori_str[i] >= 'a') || (ori_str[i] <= 'Z' && ori_str[i] >= 'A') )
                str += ori_str[i];
        }
        int len = str.length();
        if(len < 5){
            printf("No\n");
            continue;
        }
        int ok = 0;
        for(int i = 1; i < len; i++)
            for(int j = 1; j < len; j++)
            {
                string a,b;
                for(int j1 = 0; j1 < i; j1++)
                    a += str[j1];
                if(a == "") continue;
                for(int j2 = i; j2 < i + j && j2 < len; j2++)
                    b += str[j2];
                if(b == "" || a == b) continue;
                string tmp = a + b + a + b + a;
                if(tmp == str) { ok = 1; break;	}
            }
        for(int i = 2; i < len; i++){//a+b len
            string a,b,c;
            for(int j = 1; j < i; j++){ //a len
                a = "";
                for(int j1 = 0; j1 < j; j1++)
                    a += str[j1];
                if(a == "") continue;
                b = "";
                for(int j2 = j; j2 < i; j2++)
                    b += str[j2];
                if(b == "" || b == a) continue;
                for(int k = 1; k + 2*i < len; k++){//c len
                    c = "";
                    for(int j3 = 2*i; j3 < k + 2*i && j3 < len; j3++)
                        c += str[j3];
                    if(c == "" || a == c || b == c) continue;
                    string tmp = a + b + a + b + c + a + b;
                    if(tmp == str) { ok = 1; break; }
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
	return 0;
}