#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;

//求 a^b % m，迭代写法
LL binaryPow(LL a, LL b, LL m){
	LL ans = 1;
	while(b > 0){
		if(b & 1){  //位运算，比模2运算快 
			ans  = ans*a%m;
		}
		a = a*a%m;
		b >>= 1;
	}
	return ans;
} 
int main(){
	LL b,p,k;
	scanf("%lld%lld%lld",&b,&p,&k);
	LL result = binaryPow(b,p,k);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,result);
	return 0;
} 
