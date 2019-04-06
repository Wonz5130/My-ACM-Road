#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
long long int dp[10010];  //改成 long long 型，后面大小会超 int 型 

int main(){
	int n;
	memset(dp,0,sizeof(dp));
	//dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 2;
	for(int i = 4; i < 10010; ++i){
		dp[i] = dp[i-1] + dp[i-2];
	} 
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int start,end;
		scanf("%d%d",&start,&end);
		printf("%lld\n", dp[end-start+1]);
	}
	return 0;
}  
