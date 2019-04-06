// AC
/*
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2001
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int flag=1;
    long long a[N]={0};
    for(i = 0;i < n;i ++){
        scanf("%lld",&a[i]);
    }
    for(i = 0;i < n-1;i ++){
        for(j = 0;j < n-1;j ++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                a[j]++;
                a[j+1]--;
            }
        }
    }
    for(i = 0;i < n-1;i ++){
        if(a[i]<0||a[i+1]<0||a[i]>1e9||a[i+1]>1e9){
            flag=0;
            break;
        }
        else if(a[i]==a[i+1]){
            flag = 0;
            break;
        }
    }
    if(flag==0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(i = 0;i < n;i++){
            printf("%lld",a[i]);
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
*/


#include<cstdio>
#include<algorithm>
using namespace std;
#define N 2001
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int flag=1;
    long long a[N]={0};
    for(i = 0;i < n;i ++){
        scanf("%lld",&a[i]);
    }
    for(i = 0;i < n;i ++){
        for(j = 0;j < n-1;j ++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                a[j]++;
                a[j+1]--;
            }
        }
    }
    for(i = 0;i < n-1;i ++){
        if(a[i]<0||a[i+1]<0||a[i]>1e9||a[i+1]>1e9){
            flag=0;
            break;
        }
        else if(a[i]<a[i+1])
            flag=1;
        else{
            flag = 0;
            break;
        }
    }
    if(flag==0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(i = 0;i < n;i++){
            printf("%lld",a[i]);
            if(i!=n-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

/*
    for(i = 0;i < n-1;i ++){
        if(a[i]<0||a[i+1]<0||a[i]>1e9||a[i+1]>1e9){
            flag=0;
            break;
        }
        else if(a[i]<a[i+1])
            flag = 1;
        else if(a[i]==a[i+1]){
            flag = 0;
            break;

        }
    }
*/