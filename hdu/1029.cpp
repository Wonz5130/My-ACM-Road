#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    int x;
    int temp = 0;
    int flag[1000000];
	while((scanf("%d",&n)) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%d",&x);
			flag[x]++;
			if(flag[x] >= (n+1)/2 && flag[x] > temp){
				temp = flag[x];
			}
		}
		cout << temp;
	} 	
	return 0;
}
