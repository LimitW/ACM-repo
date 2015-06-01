#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>

using namespace std;

#define MAXN 1000

class bign{
	int num[MAXN];
	int len;
public:
	bign(){
		len = 0;
		memset(num,0,sizeof(num));
	}
	bign(int num){
		*this = num;
	};
	bign(const char* num){
		*this = num;
	};
	bign operator = (const char* num);
	bign operator = (int num);
	bool operator != (int num){
		bign b(num);
		if(str() != b.str())
			return true;
		else
			return false;
	}
	string str() const;
	bign operator + (const bign& b) const;
};

bign bign::operator = (const char* s){
	memset(num,0,sizeof(num));
	int i;
	len = strlen(s);
	for(i = 0;i < len;i++){
		num[i] = s[len-i-1] - '0';
	}
	return *this;
}

bign bign::operator = (int n){
	memset(num,0,sizeof(num));
	char s[MAXN];
	sprintf(s,"%d",n);
	*this = s;
	return *this;
}
string bign::str() const{
	string res = "";
	int i;
	for(i = 0;i < len;i++){
		res = (char)(num[i] + '0') + res;
	}
	if(res == "")
		res = "0";
	return res;
}

istream& operator >> (istream& in,bign& x){
	string s;
	in >> s;
	x = s.c_str();
	return in;
}

ostream& operator << (ostream& out,const bign& x){
	out << x.str();
	return out;
}

bign bign::operator + (const bign& b) const{
	bign c;
	int t = 0;
	int i;
	int mlen = len > b.len ? len : b.len;
	for(i = 0;t || i < mlen;i++){
		c.num[i] = num[i] + b.num[i] + t;
		t = c.num[i] / 10;
		c.num[i] %= 10;
	}
	c.len = mlen;
	if(c.num[mlen] != 0)
		c.len++;
	return c;
}

int main(){

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	bign a,b;
	while((cin >> a) && (a != 0)){
		b = (b + a);
	}
	cout<<b<<endl;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}