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
	cin >> n >> m;  //n�ǲ���������m��Ǯ
	for(int i = 1; i <= n; ++i){
		cin >> price[i];
	}
	//memset(dp,0,sizeof(dp));
	//int count = 1; 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){  //j��1��������Ǯ��m
			if(j == price[i]){  //Ǯ�ոպã�������� 
				dp[i][j] = dp[i-1][j]+1;  
			}
			else if(j > price[i]){  //Ǯ��������ˣ��������+��������˷�����֮�� 
				dp[i][j] = dp[i-1][j] + dp[i-1][j-price[i]];
			}
			else{  //Ǯ��������������� 
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
	if(k > m){  //�˼۸������Ǯ�� 
		return;
	}
	if(k == m){  //�˼۸�պõ�����Ǯ�� 
		sum++;
		return;
	}
	for(int i = x+1; i <= n; ++i){  //����һ���˿�ʼѡ 
		if(flag[i] == 0){  //ûѡ������� 
			flag[i] = 1;
			dfs(k+price[i],i);  //�۸�+����˼۸�ѡ���i���� 
			flag[i] = 0;  //��֦ 
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
		int temp = rand()%m+1;  //���ȡ1-n
		swap(price[0], price[temp]);
		swap(price[temp], price[i]);
		swap(weight[0], weight[temp]);
		swap(weight[temp], weight[i]);
	} 
}

//���������
int main(){
	cin >> n >> m;
	for(int i = 0;i < m; ++i){
		scanf("%d %d",&price[i], &weight[i]);
	}
	//memset(dp,0,sizeof(dp));
	for(int i = 1; i <= 200000; ++i){
		int point1 = 0,point2 = 0;  //���� 
		random_swap();
		for(int j = 1; j <= m; ++j){  //һ��Ҫ��������� 
			if(point1+price[j] <= n){  //С���ܹ���Ǯ�� 
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
