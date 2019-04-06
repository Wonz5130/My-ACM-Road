#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int dp[100000];
int good[100000];

int main(){
	int v,n;
	memset(good,0,sizeof(good));
	scanf("%d%d",&v,&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&good[i]);
	}
	for(int i = 1; i <= n; ++i){
		for(int j = v; j >= 0; --j){
			if(j >= good[i]){
				dp[j] = max(dp[j], dp[j-good[i]]+good[i]);
			}
		}
	}
	printf("%d", v-dp[v]);
	return 0;
} 
