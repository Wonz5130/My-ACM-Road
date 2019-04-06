#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int barrier[10][10];
int walkx[5] = {0,0,0,1,-1};  //x��������ߵ�ѡ��
int walky[5] = {0,-1,1,0,0};  //y��������ߵ�ѡ��
int n,m,t,sx,sy,fx,fy;  //n�У�m�У�t�ϰ�����sx,sy������꣬fx,fy�յ����� 
int result = 0;
int flag[10][10];

void dfs(int x, int y){
	if(x == fx && y == fy){
		result++;
		return;  //���� 
	}
	else{
		for(int i = 1; i <= 4; ++i){  //���������ĸ���������� 
			if(flag[x+walkx[i]][y+walky[i]] == 0
			 && barrier[x+walkx[i]][y+walky[i]] == 1){  //�Ƿ����߹� && �Ƿ����ϰ� 
				flag[x][y] = 1;  //ԭ�ȵı��Ϊ���߹� 
				dfs(x+walkx[i],y+walky[i]);
				flag[x][y] = 0;  //���� 
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			barrier[i][j] = 1;  //��ʼ��Ϊ��ͼ����Ϊ�ϰ������������� 
		}
	}
	int barrierx,barriery;
	for(int i = 1; i<= t; ++i){
		scanf("%d%d",&barrierx,&barriery);
		barrier[barrierx][barriery] = 0;  //�����ϰ��� 
	}
	dfs(sx,sy);  //����㿪ʼ���� 
	printf("%d\n",result);
	return 0;
}
