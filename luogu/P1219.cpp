#include <iostream>
using namespace std;
int n;
int sum = 0;
int a[100] = {0};  //行 
int b[100] = {0};  //列 
int c[100] = {0};  //左下到右上 
int d[100] = {0};  //右下到左上 

void dfs(int count){
	if(count > n){
		if(sum <= 2){  //只输出前三个解
			for(int i = 1; i <= n; ++i){
				cout << a[i] << " ";
			}
			cout << endl;
		}
		sum++;
		return;
	}
	else{
		for(int j = 1; j <= n; ++j){
			if(!b[j] && !c[count+j] && !d[count-j+n]){  //判断皇后位置 
				a[count] = j;  //第 count 行，第 j 列为皇后 
				b[j] = 1; //j 行不允许其他皇后 
				c[count+j] = 1;  //对角线不允许其他皇后 
				d[count-j+n] = 1;  //对角线不允许其他皇后 
				dfs(count+1);
				b[j] = 0;  //回溯 
				c[count+j] = 0;  //回溯 
				d[count-j+n] = 0;  //回溯 
			}
		}
	}
	//return;
}

int main(){
	cin >> n;
	dfs(1);  //找到第一个皇后位置 
	cout << sum << endl;
	return 0;
} 
