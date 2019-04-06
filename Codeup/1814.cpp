#include<stdio.h>
int main(){
    int L,M,a[100],b[100],i;
    while(scanf("%d %d",&L,&M)!=EOF){
        for(i=0;i<M;i++){
            scanf("%d %d",&a[i],&b[i]);
            if(a[i]<a[0]){
                a[0]=a[i];
            }
            if(b[i]>b[0]){
                b[0]=b[i];
            }
        }
        if(a[0]==0&&b[0]==0){
            break;
        }
        else printf("%d",L+1-(b[0]-a[0]+1));
    }
    return 0;
}