#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dp[10010];

int main(){
	int n;
	memset(dp,0,(sizeof(dp)));
	dp[1] = 2;
	dp[2] = 7;
	for(int i = 3; i <= 10010; ++i){
		dp[i] = 2*i*i-i+1;  //���ƹ�ϵ���۽ǵĵط�������ֻ�ָܷ���һ��ƽ�棬�߶ο��Էֳ�����ƽ�� 
	} 
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		int num;
		scanf("%d", &num);
		printf("%d\n", dp[num]);
	}
	return 0;
}
