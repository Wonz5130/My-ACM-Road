#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dp[10010];
struct goods{
	int value;
	int size;
	int weight;
}good[10010];

int maxx(int a,int b)
{
    return a>b?a:b;
}

//完全背包 
void CompletePack(int v, int w, int m){
	for(int i = v; i <= m; ++i){
		dp[i] = maxx(dp[i], dp[i-v]+w);
	}
}

//01背包
void ZeroOnePack(int v, int w, int m){
	for(int i = m; i >= v; --i){
		dp[i] = maxx(dp[i], dp[i-v]+w);
	}
} 

//多重背包
void MultiPack(int v, int w, int m,int c){
	if(v*c >= m){
		CompletePack(v,w,m);	
	}
	else{
		int k = 1;
		while(k < c){
			ZeroOnePack(k*v,k*w,m);
			c -= k;
			k *= 2;
		}
		ZeroOnePack(c*v, c*w, m);
	}
} 


int main(){
	memset(dp,0,(sizeof(dp)));
	int n,m;
	while((scanf("%d%d",&n,&m)!=EOF)){
		if(n == 0 && m == 0){
			break;
		}
		for(int j = 1; j <= n; ++j){
			scanf("%d",&good[j].value);  //物品的体积，也是价值
			good[j].size = good[j].value;
		}
		for(int k = 1; k <= n; ++k){
			scanf("%d",&good[k].weight);  //物品的重量 
		}
		for(int k = 1; k <= n; ++k){
			MultiPack(good[k].value, good[k].size, m, good[k].weight);
		}
		int count = 0;
		for(int j = 1; j <= m; ++j){
			if(dp[j] == j){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}


/*
int main(){
	memset(dp,0,(sizeof(dp)));
	int n,m;
	while((scanf("%d%d",&n,&m)!=EOF) && n != 0 && m != 0){
		for(int j = 1; j <= n; ++j){
			scanf("%d",&good[j].value);  //物品的体积，也是价值
			good[j].size = good[j].value;
		}
		for(int k = 1; k <= n; ++k){
			scanf("%d",&good[k].weight);  //物品的重量 
		}
		for(int k = 1; k <= n; ++k){
			//flag[0] = 1;
			//dp[0] = 1;
			if(good[k].value*good[k].weight >= m){  //不能完全装完，等价于有无穷件物品，转化成完全背包 
				for(int j = good[k].value; j <= m; ++j){
					dp[j] = max(dp[j],dp[j-good[k].value]+good[k].size);
				}
			}
			else{  //转化成 01 背包 
				int cnt = 1;
				while(cnt < good[k].weight){  //二进制优化 
					for(int j = m; j >= cnt*good[k].value; --j){  //容量 
						dp[j] = max(dp[j], dp[j-cnt*good[k].value] 
						+ cnt*good[k].value);
					}
					good[k].weight -= cnt;
					cnt *= 2;
				} 
				for(int j = m; j >= good[k].weight*good[k].value; --j){
					dp[j] = max(dp[j], dp[j-good[k].weight*good[k].value]
					 + good[k].weight*good[k].size);
				}
				//return 0;
			}
		}
		int count = 0;
		for(int j = 1; j <= m; ++j){
			if(dp[j] == j){
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;	
} 
*/
