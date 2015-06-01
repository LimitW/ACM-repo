/*
ID: LimitW
PROG: palsquare
LANG: C++11
*/

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
#include <fstream>

using namespace std;

const int INF = 0x3f3f3f3f;

int mpow(int x,int n){
	int ans = 1;
	while(n--)
	{
		ans *= x;
	}
	return ans;
}

int getbit(int x,int base){
    int ans = 0;
    while(x > 0){
        x /= base;
        ans++;
    }
    return ans;
}

string baseChange(int x,int base){
	string ans = "";
	for(int bitn = getbit(x,base); bitn > 0; bitn--){
        int nowbit = x / mpow(base,bitn-1);
        x -= nowbit * mpow(base,bitn-1);
		char nowbit_ = nowbit < 10 ? nowbit + '0' : nowbit - 10 + 'A';
		ans += nowbit_;
	}
	return ans;
}

bool is_pal(string str)
{
	int n  = str.length();
	if(n % 2 == 0)
	{
		for(int i = 0; i < n / 2; i++)
			if(str[i] != str[n-1-i])
				return 0;
		return 1;
	}
	else
	{
		for(int i = 0; i < n / 2; i++)
			if(str[i] != str[n-1-i])
				return 0;
		return 1;
	}
}

int main(){
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    fin >> base;
    for(int i = 1; i <= 300; i++)
    {
    	if(is_pal(baseChange(i*i,base)))
    		fout << baseChange(i,base) << ' ' << baseChange(i*i,base) << endl;
    }
    //system("pause");
    return 0;
}