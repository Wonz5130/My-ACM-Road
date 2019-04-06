#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	int x,y;
	for(int i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		printf("%d\n",y+y-x);
	}
	return 0;
} 
