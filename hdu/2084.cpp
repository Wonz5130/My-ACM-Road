#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int dp[110][110];

int main(){
	int n;
	scanf("%d", &n);
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; ++i){
		int m;
		scanf("%d", &m);
		for(int j = 1; j <= m; ++j){
			for(int k = 1; k <= j; ++k){
				scanf("%d",&dp[j][k]);	
			}	
		}
		for(int j = m; j > 1; --j){
			for(int k = m; k > 1; --k){
				dp[j-1][k-1] += max(dp[j][k], dp[j][k-1]);
			}
		}
		printf("%d\n", dp[1][1]);
	}
	return 0;
} 
