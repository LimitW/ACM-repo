/*
ID: LimitW
PROG: namenum
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

char code[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};

string getInt(string t){
	string a = "";
	for(int i = 0; i < t.length(); i++)
		a += code[t[i]-'A'];
	return a;
}

int main(){
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream fin2 ("dict.txt");
    string num;
    fin >> num;
    string tmp;
    int fail = 1;
    while(fin2 >> tmp)
    {
    	string t = getInt(tmp);
    	if(t == num)
    	{
    		fail = 0;
    		fout << tmp << endl;
    	}
    }
    if(fail) fout << "NONE" << endl;
    return 0;
}