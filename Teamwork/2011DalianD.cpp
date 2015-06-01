/************************************************
 * Title:
 * Author:LimitW
 * Date:2014.10.7
 * Source:2011 Dalian Onsite D
 * Note:签到题 输入输出
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
#include <iomanip>

using namespace std;

const int INF = 0x3f3f3f3f;

int main(){
	string ori_text;
	while(getline(cin,ori_text)){
		int n = ori_text.length();
		string dump[5000],text[5000];
		int linen = n / 16 + 1;
		if(n % 16 == 0) linen--;
		int printaddr = 0;
		for(int addr = 0; addr < linen; ++addr){
			printf("%04x: ",printaddr);
			int now_char = 0;
			dump[addr] = "";
			text[addr] = "";
			for(int i = 0; i < 16; ++i)
			{
			    if(addr*16 + i < n){
                    dump[addr] += ori_text[i+addr*16];
                    now_char++;
					if(ori_text[i+addr*16] <= 'Z' && ori_text[i+addr*16] >= 'A')
						text[addr] += ori_text[i+addr*16] + 32;
					else if(ori_text[i+addr*16] <= 'z' && ori_text[i+addr*16] >= 'a')
						text[addr] += ori_text[i+addr*16] - 32;
                	else text[addr] += ori_text[i+addr*16];
			    }
			}
			int flag = 0;
			for(int i = 0; i < now_char; ++i)
			{
			    if(flag == 2)
                {
                    printf(" "); flag = 0;
                }
				printf("%02x",dump[addr][i]);
				flag++;
			}
			for(int i = 0; i < 16 - now_char; ++i)
            {
                if(flag == 2)
                {
                    printf(" "); flag = 0;
                }
                printf("  ");
                flag++;
            }
            printf(" ");
			cout << text[addr] << endl;
			printaddr += 16;
		}
	}
	//system("pause");
	return 0;
}