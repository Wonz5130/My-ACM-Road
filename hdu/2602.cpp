#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dp[10010];
struct goods{
	int value;
	int volume;
}good[10010];

int main(){
	int t;
	memset(dp,0,(sizeof(dp)));
	scanf("%d",&t);
	for(int i = 1; i <= t; ++i){
		int n,v;
		scanf("%d%d",&n,&v);
		for(int j = 1; j <= n; ++j){
			scanf("%d",&good[j].value);
		}
		for(int k = 1; k <= n; ++k){
			scanf("%d",&good[k].volume);
		}
		for(int k = 1; k <= n; ++k){
			for(int j = v; j >= good[k].volume; --j){  //终止条件是当前容量 >= 第 k 件物品的体积 
				dp[j] = max(dp[j], dp[j-good[k].volume]+good[k].value);
			}
		}
		printf("%d\n", dp[v]);
	} 
	return 0;
} 

//WA
