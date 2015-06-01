#define mod 100000007

long long quickpow(long long m,long long n){
	long long ans = 1;
	while(n){
		if(n&1) ans = ans * m % mod;
		n >>= 1;
		m = m * m % mod;
	}
	return ans;
}

//矩阵快速幂

matrix quickpow(matrix m,int n){
	matrix ans;
	while(n){
		if(n & 1) ans = ans * m;
		n >>= 1; m = m * m;
	}
	return ans;
}
