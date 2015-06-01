/*
ID: LimitW
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    char group[10];
    char comet[10];
    fin >> group;
    fin >> comet;
    long long t1 = 1, t2 = 1;
    for(int i = 0; i < strlen(group); i++)
    	t1 *= (long long)(group[i] - 'A' + 1);
    t1 %= 47;
    for(int i = 0; i < strlen(comet); i++)
    	t2 *= (long long)(comet[i] - 'A' + 1);
    t2 %= 47;
    if(t1 == t2)
    	fout << "GO" << endl;
    else
    	fout << "STAY" << endl;
    return 0;
}