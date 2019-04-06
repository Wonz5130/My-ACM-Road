#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long LL;
const int m = 1000000009;
LL dp[10000];
LL result[1000000000000000000];

LL binaryPow(LL a, LL b){
	LL ans = 1;
	while(b > 0){
		if(b & 1){
			ans = ans*a % m;
		}
		a = a*a % m;
		b >>= 1;
	}
	return ans;
}

void num(){
	result[0] = 0;
	for(int i = 1; i <= binaryPow(10,18); ++i){
		result[i] = 2*result[i-1] + binaryPow(i,2);
	}
	return;
}


int main(){
	int n;
	memset(dp,0,sizeof(dp));
	num();
	while(scanf("%d", &n) != EOF){
		//for(int i = n; i>= 1; --i){
		//	dp[n] = dp[n-1] + binaryPow(n,2);
		//}
		printf("%lld\n",result[n]);
	}
} 
