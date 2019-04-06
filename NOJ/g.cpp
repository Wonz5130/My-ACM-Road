#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int a[3];
    while(scanf("%d%d%d",&a[0],&a[1],&a[2])!=EOF){
        sort(a,a+3);
        if(a[0]==1){
            if(a[1]==2){
                if(a[2]==5||a[2]==6){
                    printf("3\n");
                }
                else printf("0\n");
            }
            else if(a[1]==3){
                if(a[2]==4||a[2]==6){
                    printf("2\n");
                }
                else printf("0\n");
            }
            else if(a[1]==4){
                if(a[2]==6){
                    printf("2\n");
                }
                else printf("0\n");
            }
            else if(a[1]==5){
                printf("3\n");
            }
        }
        else if(a[0]==2){
            if(a[1]==3){
                if(a[2]==4||a[2]==5){
                    printf("1\n");
                }
                else printf("0\n");
            }
            if(a[1]==4){
                if(a[2]==5){
                    printf("1\n");
                }
                else printf("0\n");
            }
            else if(a[1]==5){
                printf("3\n");
            }
        }
        else if(a[0]==3){
            if(a[1]==4){
                if(a[2]==5){
                    printf("1\n");
                }
                else if(a[2]==6){
                    printf("2\n");
                }
            }
            else printf("0\n");
        }
        else printf("0\n");
    }
    return 0;
}