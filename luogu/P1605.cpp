#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int barrier[10][10];
int walkx[5] = {0,0,0,1,-1};  //x方向可以走的选择
int walky[5] = {0,-1,1,0,0};  //y方向可以走的选择
int n,m,t,sx,sy,fx,fy;  //n行，m列，t障碍数，sx,sy起点坐标，fx,fy终点坐标 
int result = 0;
int flag[10][10];

void dfs(int x, int y){
	if(x == fx && y == fy){
		result++;
		return;  //返回 
	}
	else{
		for(int i = 1; i <= 4; ++i){  //上下左右四个方向可以走 
			if(flag[x+walkx[i]][y+walky[i]] == 0
			 && barrier[x+walkx[i]][y+walky[i]] == 1){  //是否已走过 && 是否有障碍 
				flag[x][y] = 1;  //原先的标记为已走过 
				dfs(x+walkx[i],y+walky[i]);
				flag[x][y] = 0;  //回溯 
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			barrier[i][j] = 1;  //初始化为地图都不为障碍，即都可以走 
		}
	}
	int barrierx,barriery;
	for(int i = 1; i<= t; ++i){
		scanf("%d%d",&barrierx,&barriery);
		barrier[barrierx][barriery] = 0;  //更新障碍处 
	}
	dfs(sx,sy);  //从起点开始深搜 
	printf("%d\n",result);
	return 0;
}
