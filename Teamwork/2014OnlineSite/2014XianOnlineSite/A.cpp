/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
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

const int INF = 0x3f3f3f3f;

int main(){
	string str;
	while(getline(cin,str)){
        int n = str.length();
		for(int i = 0; i < n - 3; i++)
		{
			if(i < n - 4 && str[i] == 'A' && str[i+1] == 'p' && str[i+2] == 'p' && str[i+3] == 'l' && str[i+4] == 'e')
				printf("MAI MAI MAI!\n");
			if(str[i] == 'i' && str[i+1] == 'P'){
				switch(str[i+2]){
					case 'h':
					{
						if( i < n - 5 && str[i+3] == 'o' && str[i+4] == 'n' && str[i+5] == 'e')
							printf("MAI MAI MAI!\n");
						break;
					}
					case 'o':
					{
						if(str[i+3] == 'd')
							printf("MAI MAI MAI!\n");
						break;
					}
					case 'a':
					{
						if(str[i+3] == 'd')
							printf("MAI MAI MAI!\n");
						break;
					}
				}
			}
			if(str[i] == 'S' && str[i+1] == 'o' && str[i+2] == 'n' && str[i+3] == 'y')
				printf("SONY DAFA IS GOOD!\n");
		}
	}
	return 0;
}
