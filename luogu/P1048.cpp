#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int dp[10000];
struct goods{
	int t,w;
}good[10000];

int main(){
	memset(dp,0,sizeof(dp));
	int T,m;
	scanf("%d%d",&T,&m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d",&good[i].t,&good[i].w);
	}
	for(int i = 1; i <= m; ++i){
		for(int j = T; j >= 0; --j){
			if(j >= good[i].t){  //药草时间不超过总时间 
				dp[j] = max(dp[j], dp[j-good[i].t]+good[i].w);
			}
			//if(j >= good[i].t)
		}
	}
	printf("%d",dp[T]);  //注意是T，不是m 
	return 0; 
}
 
