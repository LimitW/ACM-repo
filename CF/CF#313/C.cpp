#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long a[7];
    for(int i = 0; i < 6; ++i)
        cin >> a[i];
    cout << (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - (a[0]*a[0] + a[2]*a[2] + a[4]*a[4]) << '\n';
    return 0;
}
