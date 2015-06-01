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
#include <utility>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 110;

map<string,string> G;

int main(){
	int n , m; scanf("%d",&n);
	for(int i = 0; i < n; i++){
		string f,s; cin >> f >> s;
		G[s] = f;
	}
	scanf("%d",&m);
	for(int i = 0; i < m; i++){
		string p1,p2; cin >> p1 >> p2;
		//if(p1 == p2) { cout << G[p1] << endl; continue; }
		vector<string> a1,a2; a1.push_back(p1); a2.push_back(p2);
		while(G.find(p1) != G.end() || G.find(p2) != G.end()){
			if(G.find(p1) != G.end() ) { a1.push_back(G[p1]); p1 = G[p1]; }
			if(G.find(p2) != G.end() ) { a2.push_back(G[p2]); p2 = G[p2]; }
		}
		int p = -1;
		for(int j = 0;  j < a1.size(); j++){
			for(int k = 0; k < a2.size(); k++)
				if(a1[j] == a2[k]){
					p = j; break;
				}
			if(p != -1) break;
		}
		if(p < 0) cout << "-1" << endl;
		//else if(p == 0) cout << a1[1] << endl;
		else cout << a1[p] << endl;
	}
	return 0;
}
