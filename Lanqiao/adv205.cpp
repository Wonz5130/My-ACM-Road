#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int dp[100000],flag[100000],prime[100000];
int cnt = 0;

void CreatePrime(){
	int len = sqrt(100000);
	for(int i = 2; i <= len; ++i){
		if(flag[i] == 0){  //是素数 
			prime[cnt++] = i;  //记录素数表 
			for(int j = i*i; j <= len; j=j+i){  //素数判断 
				flag[j] = 1;  //标记为不是素数 
			}
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	CreatePrime();
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < cnt; ++j){
			if(prime[j] > sqrt(i)){  //当前素数大于根号下i 
				break;
			}
			if(i % prime[j] == 0){  //
				dp[i] = max(dp[i], dp[i-2*prime[j]]+prime[j]);
			}
		}
	}
	printf("%d\n",dp[n]);
	return 0; 
}
