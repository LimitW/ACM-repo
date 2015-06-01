//============================================================================
// Name        : Template.cpp
// Author      : LimitW
// Date        :
// Version     :
// Copyright   :
// Description :
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
#define pii pair<int,int>

const int INF = 0x3f3f3f3f;

int B[102][102]  , A[102][102]  , vis1[102] , vis2[102];

int main(){
    int m,n; cin >> m >> n;
    int fail = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            A[i][j] = 1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            cin >> B[i][j];
            if(B[i][j] == 0){
                for(int i1 = 0; i1 < m; i1++)
                    A[i1][j] = 0;
                for(int j1 = 0; j1 < n; j1++)
                    A[i][j1] = 0;
            }
        }
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            int now = 0;
            for(int k = 0; k < n; k++)
                now |= A[i][k];
            for(int k = 0; k < m; k++)
                now |= A[k][j];
            if(now != B[i][j]) {fail = 1; break;}
        }
    if(fail) { cout <<"NO"<<endl; return 0; }
    else cout << "YES" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << A[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
