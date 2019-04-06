#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char chess[10][10];
int flag[10];
int ans;
int n,k;

void dfs(int x, int y){
	if(y >= k){  //���ڵ��� k ������ 
		ans++;  //�����������ӣ�ans+1 
		return;
	}
	for(int i = x; i < n; ++i){  //������ row ��ʼ 
		for(int j = 0; j < n; ++j){
			if(chess[i][j] == '#' && flag[j] == 0){  //'#'�����Է����� 
				flag[j] = 1;
				dfs(i+1, y+1);  //����+1������+1 
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
		ans = 0;  //ȫ�ֱ��� 
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
