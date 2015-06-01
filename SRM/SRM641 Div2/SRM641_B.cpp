/************************************************
 * Title:
 * Author:LimitW
 * Date:
 * Source:
 * Note:
*************************************************/

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

using namespace std;

const int INF = 0x3f3f3f3f;

class TrianglesContainOriginEasy{
public:
    struct Vector
    {
        int x,y;
        Vector(int fx, int fy):x(fx), y(fy){}
        Vector operator - (const Vector& v) const{
            return Vector(x - v.x, y - v.y) ;
        }
        int Dot(const Vector& v) const{
            return x * v.x + y * v.y;
        }
        int CrossProduct(const Vector& v) const{
            return abs(v.x * y - x * v.y);
        }
    };
	int count(vector <int> x, vector <int> y){
		int ans = 0 , n = x.size();
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
				{
					int dx1 = x[i] - x[j] , dx2 = x[i] - x[k] , dy1 = y[i] - y[j] , dy2 = y[i] - y[k];
					if(dy1 * dx2 == dy2 * dx1) continue;
					Vector A(x[i],y[i]);
					Vector B(x[j],y[j]);
					Vector C(x[k],y[k]);
					Vector P(0,0);
					Vector AB = B-A , BC = B-C;
					Vector PA = P-A , PB = P-B , PC = P-C;
					if(PA.CrossProduct(PC) + PA.CrossProduct(PB) + PB.CrossProduct(PC) == AB.CrossProduct(AC)) ans++;
				}
		return ans;
	}
};