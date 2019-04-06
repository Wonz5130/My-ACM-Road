//
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int t;
    long long int a[3];
    scanf("%d",&t);
        for(int i = 0;i < t;i ++){
            scanf("%l64d%l64d%l64d",&a[0],&a[1],&a[2]);
            sort(a,a+3);
            long long int n = 0;
            long long int m = a[2];
            if(a[0]==a[1]&&a[1]==a[2]){
                printf("%l64d\n",n);
            }
            else if(a[0]==a[1]){
                if((m-a[0])%2==1){
                    n+=(m-a[0])/2*2;
                    n++;
                    printf("%l64d\n",n);
                }
                else{
                    n+=(m-a[0])/2*2;
                    printf("%l64d\n",n);
                }
            }
            else if(a[1]==a[2]){
                if((m-a[0])%2==1){
                    n+=(m-a[0])/2;
                    n+=2;
                    printf("%l64d\n",n);
                }
                else{
                    n+=(m-a[0])/2;
                    printf("%l64d\n",n);
                }
            }
            else{
                if((m-a[0])%2==0&&(m-a[1])%2==0){
                    n+=(m-a[0])/2;
                    n+=(m-a[1])/2;
                    printf("%l64d\n",n);
                }
                else if((m-a[0])%2!=0&&(m-a[1])%2!=0){
                    n+=(m-a[0])/2;
                    n+=(m-a[1])/2;
                    n++;
                    printf("%l64d\n",n);
                }
                else{
                    n+=(m-a[0])/2;
                    n+=(m-a[1])/2;
                    n+=2;
                    printf("%l64d\n",n);
                }
            }
        }
    return 0;
}



/*
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int t;
    long long a[3],n = 0;
    while(scanf("%d",&t)!=EOF){
        for(int i = 0;i < t;i ++){
            scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
            sort(a,a+3);
            long long m = a[2];




            if(((m-a[0])%2==0&&(m-a[1])%2==1)){
                if(a[0]<m){
                    n=(m-a[0])/2;
                    if(a[1]<m){
                        n+=(m-a[1])/2;
                        n+=2;
                    }
                }
            }
            else if((m-a[0])%2==1&&(m-a[1])%2==0){
                if(a[1]==a[2]){
                    n=(m-a[0])/2;
                    n+=2;
                }
                else{
                    if(a[0]<m){
                        n=(m-a[0])/2;
                        n++;
                    }
                    if(a[1]<m){
                        n+=(m-a[1])/2;
                        n++;
                    }
                }
            }
            else if((m-a[0])%2==1&&(m-a[1])%2==1){
                if(a[0]<m){
                    n=(m-a[0])/2;
                    if((m-a[0])%2==1){
                        n++;
                    }
                }
                if(a[1]<m){
                    n+=(m-a[1])/2;
                }
            }
            else{
                if(a[0]<m){
                    n=(m-a[0])/2;
                }
                if(a[1]<m){
                    n+=(m-a[1])/2;
                }
            }
            printf("%d\n",n);
        }
            
        }
    }
    return 0;
}
*/
