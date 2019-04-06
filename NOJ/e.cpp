/*
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        char str1[101],str2[101];
        scanf("%s%s",str1,str2);
        int n1=n+2;
        int m1=m+2;
        int dp[n1][m1] = {0};
        for(int i = 0;i < n1;i ++){
            dp[i][0] = i;
        }
        for(int j = 0;j < m1;j ++){
            dp[0][j] = j;
        }
        for(int i = 1;i < n1;i ++){
            for(int j = 1;j < m1;j ++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        printf("%d\n",n1+m1-2*dp[n][m]);
    }
    return 0;
}
*/


 /*
    for(int i = 0;i < n;i ++){
        scanf("%c",&str1[i]);
    }
    for(int i = 0;i < m;i ++){
        scanf("%c",&str2[i]);
    }
    */

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m){
        swap(n,m);
    }
    char str1[100],str2[100];
    scanf("%s%s",str1,str2);
    if(str1==NULL||strlen(str1)==0){
        printf("%d",strlen(str2));
    }
    else if(str2==NULL||strlen(str2)==0){
        printf("%d",strlen(str1));
    }
    else if(str1==NULL&&str2==NULL){
        printf("0\n");
    }
    else{
    int n1=n+1;
    int m1=m+1;
    int dp[n1][m1]={0};
    for(int i = 0;i <= n;i ++){
        dp[i][0] = i;
    }
    for(int i = 0;i <= m;i ++){
        dp[0][i] = i;
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= m;j ++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + 1;
            }
        }
    }
    printf("%d\n",dp[n][m]);
    }
    return 0;
}

//dp[i][j] = min(min(dp[i-1][j-1]+1,dp[i-1][j] +1), dp[i][j-1]+1 );