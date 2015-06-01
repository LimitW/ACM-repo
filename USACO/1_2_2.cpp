/*
ID: LimitW
PROG: transform
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

char a[12][12],b[12][12];
char t[12][12];

bool check(char a[12][12],int n){
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != t[i][j])
				return 0;
	return 1;
}

void ninety(char a[12][12],char b[12][12],int n){
	char tmp[12][12];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[j][n-i-1] = a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			b[i][j] = tmp[i][j];
}

void reflect(char a[12][12],char b[12][12],int n){
	char tmp[12][12];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			tmp[i][n-j-1] = a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			b[i][j] = tmp[i][j];
}

bool op1(int n);
bool op2(int n);
bool op3(int n);
bool op4(int n);
bool op5(int n);

int main(){
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		fin >> a[i][j];
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		fin >> t[i][j];
    int ans = -1;
    if(op1(n)) ans = 1;
    else if(op2(n)) ans = 2;
    else if(op3(n)) ans = 3;
    else if(op4(n)) ans = 4;
    else if(op5(n)) ans = 5;
    else if(check(a,n)) ans = 6;
    else ans = 7;
    fout << ans << endl;
    return 0;
}

bool op1(int n){
	ninety(a,b,n);
	return check(b,n);
}

bool op2(int n){
	ninety(a,b,n);
	ninety(b,b,n);
	return check(b,n);
}

bool op3(int n){
	ninety(a,b,n);
	ninety(b,b,n);
	ninety(b,b,n);
	return check(b,n);
}

bool op4(int n){
	reflect(a,b,n);
	return check(b,n);
}

bool op5(int n){
	reflect(a,b,n);
	ninety(b,b,n);
	if(check(b,n)) return 1;
	else{
		ninety(b,b,n);
		if(check(b,n)) return 1;
		else{
			ninety(b,b,n);
			if(check(b,n)) return 1;
			else return 0;
		}
	}
}