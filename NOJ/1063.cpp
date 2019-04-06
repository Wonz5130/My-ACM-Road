#include<cstdio>
#include<algorithm>
using namespace std;
#define N 1000
int main(){
    int n;
    int a[N];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Source:\n");
    printf("(");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf(")");
    printf("\nBubble Sort:\n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
        printf("(");
        for(int k=0;k<n;k++){
            printf("%d",a[k]);
            if(n-i-2==k){
                printf(")");
            }
            if(k!=n-1){
            printf(" ");
            }
        }
        printf("\n");
    }
    printf("Result\n(");
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf(")\n");
    return 0;
}