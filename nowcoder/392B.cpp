#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[10000],b[10000],mod[10000];
	for(int i = 0; i < n; ++i){
		cin >> a[i] >> b[i] >> mod[i];
		int result = (int)pow(a[i],b[i]) % mod[i];
		cout << result << endl;
	}
	return 0;
}
