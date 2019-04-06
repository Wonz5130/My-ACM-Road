#include <cstdio>
using namespace std;
int n;
int map[32][32];

void search(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == 0){
				map[i][j] = 2;
			}
		}
	}
}

void bfs(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(map[i][j] == 2 && (i == 0 || j == 0)){
				map[i][j] = 0;  //边界的 0 不算在内 
			}
		}
	}
	int cnt = 9;
	while(cnt--){
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				if(map[i][j] == 2 && i > 0 && j > 0){
					if(map[i-1][j] == 0 || map[i+1][j] == 0 || map[i][j-1] == 0
					 || map[i][j+1] == 0)  //不在圈内的0 
					 {
					 	map[i][j] = 0;	
					 }
				}
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			scanf("%d",&map[i][j]);
		}
	}
	search();
	bfs();
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d",map[i][j]);
			if(j != n-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
} 
