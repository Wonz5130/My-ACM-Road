#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
double dp[10010];
struct goods{
	int million;
	double proba;
	int pro;
}good[10010];

int main(){
	int t;
	memset(dp,0,(sizeof(dp)));
	scanf("%d",&t);
	for(int i = 1; i <= t; ++i){
		double p;
		int n;
		scanf("%lf%d",&p,&n);
		int sum = 0;
		for(int j = 1; j <= n; ++j){
			scanf("%d%lf",&good[j].million, &good[j].proba);
			//good[j].pro = good[j].proba * 100;
			sum += good[j].million;
		}
		for(int k = 1; k <= n; ++k){
			for(int j = sum; j >= good[k].million; --j){
				dp[j] = max(dp[j], dp[j-good[k].million]*(1-good[k].proba));
			}
		}
		for(int j = sum; j >= 0; --j){
			if(dp[j] > (1-p)){
				printf("%d\n", j);
				break;
			}
		}
		/*
		// 总概率不是简单的加 
		for(int k = 1; k <= n; ++k){
			for(int j = p*100; j >= good[k].pro; --j){  //终止条件是当前容量 >= 第 k 件物品的体积 
				dp[j] = max(dp[j], dp[j-good[k].pro]*good[k].million);
			}
		}
		int result = p * 100;
		printf("%d\n", dp[result]);
		*/
	} 
	return 0;
} 
