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
}good[100][3];  //0Ϊ������1Ϊ����1��2Ϊ����2 
int flag[100],dp[1000000];

int main(){
	memset(flag,0,sizeof(flag));
	scanf("%d%d",&n, &m);
	for(int i = 1; i <= m; ++i){  //��1��ʼ 
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z == 0){  //��ʾ������ 
			good[i][0].v = x;
			good[i][0].w = x*y;
		}
		else{  //�Ǹ��� 
			if(flag[z] == 0){
				good[z][1].v = x;  //ע�⣺��һά�±���z����������˰��Сʱ�� 
				good[z][1].w = x*y;
				flag[z] = 1;  //��ʾ�Ƿ���ʹ� 
			}
			else{
				good[z][2].v = x;
				good[z][2].w = x*y;
				//flag[z] = 1; 
			}
		}
	}
	for(int i = 1; i <= m; ++i){  //i <= ��ѡ����Ʒ���࣬��1��ʼ 
		for(int j = n; j >= 0; --j){  //j = ��Ǯ�� 
			if(j >= good[i][0].v){  //ֻѡ���� 
				dp[j] = max(dp[j], dp[j-good[i][0].v]+good[i][0].w);  //��ѡ��ǰ����ѡ��ǰ������Ҫ���ѵ�ǰ��Ʒ�ķ��ã��ټ����ܼ�ֵ 
			}
			if(j >= good[i][0].v+good[i][1].v){  //ѡ����+����1 
				dp[j] = max(dp[j], dp[j-good[i][0].v-good[i][1].v] + 
				good[i][0].w+good[i][1].w); 
			}
			if(j >= good[i][0].v+good[i][2].v){  //ѡ����+����2 
				dp[j] = max(dp[j], dp[j-good[i][0].v-good[i][2].v] + 
				good[i][0].w+good[i][2].w);
			}
			if(j >= good[i][0].v+good[i][1].v+good[i][2].v){  //��ѡ 
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
}a[67][3];//������Ʒ�Լ����Ƿ�Ϊ�������б�� 
int vis[67],f[320004]; //vis[]�ж��Ǹ������ĵڼ������� 
int main(){
memset(vis,0,sizeof(vis));//��ʼ����һ��ɺ��ԣ� 
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
}//���� 
for(int i=1;i<=m;i++){//m�Ǽ�����ö�ٴ�1����m���⼸����� 
    for(int j=n;j>=0;j--){//ö�ٿռ��С 
        if(j>=a[i][0].v){
            f[j]=max(f[j],f[j-a[i][0].v]+a[i][0].w);
        }//ֻѡ���� 
        if(j>=a[i][0].v+a[i][1].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][1].v]+a[i][0].w+a[i][1].w);
        }//ѡ�����͸���һ 
        if(j>=a[i][0].v+a[i][2].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][2].v]+a[i][0].w+a[i][2].w);
        }//ѡ�����͸����� 
        if(j>=a[i][0].v+a[i][1].v+a[i][2].v){
            f[j]=max(f[j],f[j-a[i][0].v-a[i][2].v-a[i][1].v]+a[i][0].w+a[i][2].w+a[i][1].w);
        }//��ѡ 
    }
}
 printf("%d",f[n]);
return 0;
} 
*/
