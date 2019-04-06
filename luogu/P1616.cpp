#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[100010];
struct goods{
	int t,w;
}good[10010];

int main(){
	memset(dp,0,sizeof(dp));
	int T,m;
	scanf("%d%d",&T,&m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d",&good[i].t,&good[i].w);
	}
	for(int i = 1; i <= m; ++i){
		for(int j = good[i].t; j <= T; ++j){  //完全背包：顺序 
			//if(j >= good[i].t){  //药草时间不超过总时间 
				dp[j] = max(dp[j], dp[j-good[i].t]+good[i].w);
			//}
		}
	}
	int result = 0;
	for(int i = 1; i <= T; ++i){
		result = max(dp[i], result);
	}
	printf("%d",result);  //注意是result
	return 0; 
}
 
