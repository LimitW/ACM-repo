#include <bits/stdc++.h>

using namespace std;

int a[100010];
int n, k;
multiset<int> st;

bool check(int x){
    st.clear();
    int tmp = k;
    for(int i = 0; i < n; ++i)
        st.insert(a[i]);
    while(!st.empty()){
        --tmp;
        multiset<int>::iterator u = st.begin(), v;
        int val = *u;
        if(val > x)
            return false;
        st.erase(u);
        if(st.empty())
            break;
        v = st.upper_bound(x - val);
        if(v != st.begin())
            --v;
        if(v != st.end() && *v + val <= x)
            st.erase(v);
    }
    return tmp >= 0;
}

int main(){
    cin >> n >> k;
    int mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int ans, l = 1, r = 2 * mx;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << '\n';
    return 0;
}
