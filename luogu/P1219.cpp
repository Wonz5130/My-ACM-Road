#include <iostream>
using namespace std;
int n;
int sum = 0;
int a[100] = {0};  //�� 
int b[100] = {0};  //�� 
int c[100] = {0};  //���µ����� 
int d[100] = {0};  //���µ����� 

void dfs(int count){
	if(count > n){
		if(sum <= 2){  //ֻ���ǰ������
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
			if(!b[j] && !c[count+j] && !d[count-j+n]){  //�жϻʺ�λ�� 
				a[count] = j;  //�� count �У��� j ��Ϊ�ʺ� 
				b[j] = 1; //j �в����������ʺ� 
				c[count+j] = 1;  //�Խ��߲����������ʺ� 
				d[count-j+n] = 1;  //�Խ��߲����������ʺ� 
				dfs(count+1);
				b[j] = 0;  //���� 
				c[count+j] = 0;  //���� 
				d[count-j+n] = 0;  //���� 
			}
		}
	}
	//return;
}

int main(){
	cin >> n;
	dfs(1);  //�ҵ���һ���ʺ�λ�� 
	cout << sum << endl;
	return 0;
} 
