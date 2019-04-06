#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	int n,m;
	cin >> n;
	//string s;
	int s[10000];
	memset(s,0,sizeof(s));
	for(int i = 0; i < n; ++i){
		cin >> m;
		//getline(cin,s);
		//getchar();
		//int len = s.length();
		//int count = 0;
		int flag = 1;
		for(int j = 0;j < m; ++j){
			cin >> s[j];
			if(s[j] != 3 && s[j] != 6){
				//cout << s[j]+1;
				printf("%s%d",flag==1?"":" ",s[j]+1);
				flag = 0;
				//count++;
				
			}
		}
		cout << endl;
	}
	return 0;
}
