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
			if(j >= good[i].t){  //ҩ��ʱ�䲻������ʱ�� 
				dp[j] = max(dp[j], dp[j-good[i].t]+good[i].w);
			}
			//if(j >= good[i].t)
		}
	}
	printf("%d",dp[T]);  //ע����T������m 
	return 0; 
}
 
