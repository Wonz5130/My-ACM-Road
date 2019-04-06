#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
int price[30001],weight[30001],money[30001];
int dp[50000];
int n,m,result=2;


int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i){
		cin >> price[i] >> weight[i];
		money[i] = price[i] * weight[i];  //�����ܼ�ֵ 
		//price[i] = x;
		//weight[i] = y;
	}
	//sorted(weight,weight+m);
	memset(dp,0,sizeof(dp)); 
	for(int i = 1; i <= m; ++i){
		for(int j = n; j >= price[i]; --j){  //j����Ǯ��n��ʼ�ݼ� 
			dp[j] = max(dp[j], dp[j-price[i]]+money[i]);  //��̬�滮ת�Ʒ��̣�ȡ��ȡi��Ʒ 
		} 
	}
	cout << dp[n] << endl;
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
