nclude <bits/stdc++.h>
using namespace std;

double f[51][51][51];

class ShortestPathWithMagic{
public:
	double getTime(vector <string> dist, int k){
		int n = dist.size();
		for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		for(int m = 0; m <= k; ++m)
			f[i][j][m] = 1e9;
		for(int i = 0; i < n; ++i){
			for(int j = 0;j < n; ++j){
				f[i][j][0] = (double)(dist[i][j] - '0');
				f[i][j][1] = f[i][j][0] / 2.0;
			}
		}
		for(int m = 0; m < n; ++m)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j){
					for(int k1 = 0; k1 <= k; ++k1)
						for(int k2 = 0; k2 + k1 <= k; ++k2){
							f[i][j][k1+k2] = min(f[i][j][k1+k2], f[i][m][k1] + f[m][j][k2]);
						}
				}
		double ans = 1e9;
		for(int i = 0; i <= k; ++i)
			ans = min(ans, f[0][1][i]);
		return ans;
	}

