#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char chess[10][10];
int flag[10];
int ans;
int n,k;

void dfs(int x, int y){
	if(y >= k){  //大于等于 k 个棋子 
		ans++;  //放完所有棋子，ans+1 
		return;
	}
	for(int i = x; i < n; ++i){  //行数从 row 开始 
		for(int j = 0; j < n; ++j){
			if(chess[i][j] == '#' && flag[j] == 0){  //'#'处可以放棋子 
				flag[j] = 1;
				dfs(i+1, y+1);  //数量+1，行数+1 
				flag[j] = 0;
			}
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		if(n == -1 && k == -1){
			break;
		}
		getchar();
		memset(flag,0,sizeof(flag));
		memset(chess,0,sizeof(chess)); 
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%c",&chess[i][j]);	
			}
		}
		ans = 0;  //全局变量 
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
