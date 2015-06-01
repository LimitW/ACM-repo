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

int f(char s){
	if(s <= 'Z' && s >= 'A'){
			s -= 'A';
	}
	else s -= 'a';
	switch(s){
	case ('q'-'a') : return 9;
	case ('r'-'a'): return 5;
	case ('b'-'a'): return 3;
	case ('n'-'a'): return 3;
	case ('p'-'a'): return 1;
	case ('k'-'a'): return 0;
	}
	return 0;
}

int main(){
	string s;
	int w = 0, b = 0;
	for(int i = 0; i < 8; i++){
		cin >> s;
		for(int j = 0; j < s.length(); j++){
			if(s[j] == '.') continue;
			else if(s[j] <= 'Z' && s[j] >= 'A') w += f(s[j]);
			else b += f(s[j]);
		}
	}
		if(w > b) printf("White\n");
		else if( w == b) printf("Draw\n");
		else printf("Black\n");
    return 0;
}
