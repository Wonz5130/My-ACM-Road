#included <iostream>
#include <algorithm>
using namespace std;
int left[10000],right[10000];

int main(){
	int n,m;
	cin >> n >> m;
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	for(int i = 0; i < m; ++i){
		cin >> left[i] >> right[i];
	}
	
} 
