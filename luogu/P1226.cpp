#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL;

//�� a^b % m������д��
LL binaryPow(LL a, LL b, LL m){
	LL ans = 1;
	while(b > 0){
		if(b & 1){  //λ���㣬��ģ2����� 
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
