#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
int n,m;
struct goods{
	int v,w;
}good[100][3];  //0为主件、1为附件1、2为附件2 
int flag[100],dp[1000000];

int main(){
	memset(flag,0,sizeof(flag));
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= m; ++i){  //从1开始 
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z == 0){  //表示是主件 
			good[i][0].v = x;
			good[i][0].w = x*y;
		}
		else{  //是附件 
			if(flag[z] == 0){
				good[z][1].v = x;  //注意：第一维下标是z，这个错找了半个小时。 
				good[z][1].w = x*y;
				flag[z] = 1;  //表示是否访问过 
			}
			else{
				good[z][2].v = x;
				good[z][2].w = x*y;
				//flag[z] = 1; 
			}
		}
	}
	for(int i = 1; i <= m; ++i){  //i <= 可选的物品种类，从1开始 
		for(int j = n; j >= 0; --j){  //j = 总钱数 
			if(j >= good[i][0].v){  //只选主件 
				dp[j] = max(dp[j], dp[j-good[i][0].v]+good[i][0].w);  //不选当前件，选择当前件所以要花费当前物品的费用，再加上总价值 
			}
			if(j >= good[i][0].v+good[i][1].v){  //选主件+附件1 
				dp[j] = max(dp[j], dp[j-good[i][0].v-good[i][1].v] + 
				good[i][0].w+good[i][1].w); 
			}
			if(j >= good[i][0].v+good[i][2].v){  //选主件+附件2 
				dp[j] = max(dp[j], dp[j-good[i][0].v-good[i][2].v] + 
				good[i][0].w+good[i][2].w);
			}
			if(j >= good[i][0].v+good[i][1].v+good[i][2].v){  //都选 
				dp[j] = max(dp[j], dp[j-good[i][0].v-good[i][1].v-good[i][2].v]
				 + good[i][0].w+good[i][1].w+good[i][2].w);
			} 
		}
	}
	printf("%d", dp[n]);
	return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
int n,m;
struct aa{
int v,w; 
}a[67][3];//定义物品以及对是否为附件进行标记 
int vis[67],f[320004]; //vis[]判断是该主件的第几个附件 
int main(){
memset(vis,0,sizeof(vis));//初始化（一般可忽略） 
scanf("%d%d",&n,&m);
for(int i=1;i<=m;i++){
    int aa,bb,cc;
    scanf("%d%d%d",&aa,&bb,&cc);
    if(cc==0){
        a[i][0].v=aa;
        a[i][0].w=aa*bb;
    }else{
        if(!vis[cc]){
            a[cc][1].v=aa;
            a[cc][1].w=aa*bb;
            vis[cc]=1;
        }else{
            a[cc][2].v=aa;
            a[cc][2].w=aa*bb;
        }
    }       
}//读入 
for(int i=1;i<=m;i++){//m是件数，枚举从1件到m件这几种情况 
    for(int j=n;j>=0;j--){//枚举空间大小 
        if(j>=a[i][0].v){
            f[j]=max(f[j],f[j-a[i][0].v]+a[i][0].w);
        }//只选主件 
        if(j>=a[i][0].v+a[i][1].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][1].v]+a[i][0].w+a[i][1].w);
        }//选主件和附件一 
        if(j>=a[i][0].v+a[i][2].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][2].v]+a[i][0].w+a[i][2].w);
        }//选主件和附件二 
        if(j>=a[i][0].v+a[i][1].v+a[i][2].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][2].v-a[i][1].v]+a[i][0].w+a[i][2].w+a[i][1].w);
        }//都选 
    }
}
 printf("%d",f[n]);
return 0;
} 
*/
