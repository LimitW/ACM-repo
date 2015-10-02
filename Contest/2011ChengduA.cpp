/*
 * Title:Alice and Bob
 * Author:LimitW
 * Date:2014.7.20
 * Source:2011 ChengDuSite A
 * Note:dp
*/


/*
Question:
有N个数,现有Alice和Bob博弈,每个人每次可以进行两个操作中的一个:
1.某个数减一(为0则删去)
2.合并某两数为一数
如轮到某人无操作判负.输出赢家姓名.Alice先进行操作.
*/

/*
Solution:
1.若所有数大于1,结果和全部合并成一堆再依次减一的情况相同.
则原本的胜者(与奇偶有关)会尽力合并各数且负者无法阻止(每个数都大于1)
2.若存在1,原本的负者可以通过减去那些1来改变局面.
合并相当于2步,去掉仅需1步.
dp[i][j]表示有i个数为1，其他数合并后再减完的步数为j.值为1胜者为Alice,为0胜者为Bob.
由必败找必胜点
*/

#include <cstdio>
#include <iostream>

using namespace std;

int dp[55][60000];
int a[55];

int DP(int i,int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(j == 1)
		return dp[i][j] = DP(i + 1,0);//只剩单独的1,加入其他1中.
	dp[i][j] = 0;
	if(i >= 1 && !DP(i - 1,j))//直接去掉一个1
		dp[i][j] = 1;
	if(i >= 1 && j && !DP(i - 1,j + 1)) //将1合到其他数中
		dp[i][j] = 1;
	if(i >= 2 && (( j && !DP(i - 2,j + 3) ) || ( j == 0 && !DP(i - 2,2) )))//将两个1合并
		dp[i][j] = 1;
	if(j >= 2 && !DP(i,j - 1)) //减小1
		dp[i][j] = 1;
	return dp[i][j];
}

int main(){
	memset(dp,-1,sizeof(dp));
	int t,test = 1,n,i,j,k;
	cin>>t;
	while(t--){
		cin>>n;
		for(j=0,k=0,i=0;i<n;i++){
			cin>>a[i];
			if(a[i] == 1)
				j++;
			else 
				k += a[i] + 1;//需要合并,多一步
		}
		if(k) k--; //合并的次数多算了一次
		DP(j,k);
		printf("Case #%d: ",test++);
		if(dp[j][k])
			cout<<"Alice"<<endl;
		else
			cout<<"Bob"<<endl;
	}
	return 0;
}