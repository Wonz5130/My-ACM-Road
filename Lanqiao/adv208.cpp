#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main(){
	int ai,aj;
	scanf("%d%d",&ai,&aj);
	ll a[ai][aj];
	for(int i = 0; i < ai; ++i){
		for(int j = 0; j < aj; ++j){
			scanf("%lld",&a[i][j]);
		}
	}
	int bi,bj;
	scanf("%d%d",&bi,&bj);
	ll b[bi][bj];
	for(int i = 0; i < bi; ++i){
		for(int j = 0; j < bj; ++j){
			scanf("%lld",&b[i][j]);
		}
	}
	for(int i = 0; i < ai; ++i){
		ll result = 0;
		for(int j = 0; j < bj; ++j){
			for(int k = 0; k < aj; ++k){
				result += a[i][k]*b[k][j];
			}
			printf("%lld",result);
			if(j != bj-1){
				printf(" ");
			}	
		}
		printf("\n");
	}
	return 0;
}
