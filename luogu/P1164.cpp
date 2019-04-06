#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
int price[30001];
int dp[5000][5000];
int n,m;
int sum = 0;
int flag[1000];

/*
int main(){
	cin >> n >> m;  //n是菜种类数，m是钱
	for(int i = 1; i <= n; ++i){
		cin >> price[i];
	}
	//memset(dp,0,sizeof(dp));
	//int count = 1; 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){  //j从1递增到总钱数m
			if(j == price[i]){  //钱刚刚好，吃这个菜 
				dp[i][j] = dp[i-1][j]+1;  
			}
			else if(j > price[i]){  //钱多于这个菜，吃这个菜+不吃这个菜方法数之和 
				dp[i][j] = dp[i-1][j] + dp[i-1][j-price[i]];
			}
			else{  //钱不够，不吃这个菜 
				dp[i][j] = dp[i-1][j];
			}
		} 
	}
	cout << dp[n][m] << endl;
	return 0;
} 
*/

//DFS
void dfs(int k, int x){
	if(k > m){  //菜价格大于总钱数 
		return;
	}
	if(k == m){  //菜价格刚好等于总钱数 
		sum++;
		return;
	}
	for(int i = x+1; i <= n; ++i){  //从下一道菜开始选 
		if(flag[i] == 0){  //没选过这道菜 
			flag[i] = 1;
			dfs(k+price[i],i);  //价格+这道菜价格，选择第i道菜 
			flag[i] = 0;  //剪枝 
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		scanf("%d",&price[i]);
	}
	dfs(0,0);
	cout << sum << endl;
	return 0;
} 



/*
void random_swap(){
	for(int i = 1; i <= m; ++i){
		int temp = rand()%m+1;  //随机取1-n
		swap(price[0], price[temp]);
		swap(price[temp], price[i]);
		swap(weight[0], weight[temp]);
		swap(weight[temp], weight[i]);
	} 
}

//法二：随机
int main(){
	cin >> n >> m;
	for(int i = 0;i < m; ++i){
		scanf("%d %d",&price[i], &weight[i]);
	}
	//memset(dp,0,sizeof(dp));
	for(int i = 1; i <= 200000; ++i){
		int point1 = 0,point2 = 0;  //两个 
		random_swap();
		for(int j = 1; j <= m; ++j){  //一共要购买的数量 
			if(point1+price[j] <= n){  //小于总共的钱数 
				point1 += price[j];
				point2 += price[j]*weight[j];
			}
			result = max(result, point2);
		}
	}
	cout << result << endl;
	return 0;
} 
*/
