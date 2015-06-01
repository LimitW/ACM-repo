/*
ID: LimitW
PROG: gift1
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

int main(){
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n;
    fin >> n;
    map<string,int> mp;
    string c[10];
    for(int i = 0; i < n; i++)
    {
    	fin >> c[i];
    	mp[c[i]] = 0;
    }
    for(int j = 0; j < n; j++){
    	string giver;
    	fin >> giver;
    	int money,give_n;
    	fin >> money >> give_n;
    	if(money == 0 || give_n == 0)
    		continue;
    	int gift = money / give_n;
    	for(int i = 0; i < give_n; i++)
    	{
    		string reciever;
    		fin >> reciever;
    		mp[reciever] += gift;
    	}
    	mp[giver] -= gift * give_n;
	}
	for(int i = 0; i < n; i++)
    {
    	fout << c[i] <<' '<< mp[c[i]] << endl; 
    }
    return 0;
}