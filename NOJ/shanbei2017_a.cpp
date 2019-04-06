#include<stdio.h>
#include<string.h>
int main(){
	int n;
	char str[110];
	char name[110][110];
	scanf("%d",&n);
	for(int i = 0;i < n; ++i){
		//scanf("%[^\n]", str);
		gets(str);
		int k = 0;
		int r = 0;
		for(int j = 0;j < strlen(str); ++j){
			if(str[j] != ' '){
				name[r][k++] = str[j];
			}
			else{
				name[r][k] = '\0';
				r++;
				k = 0;
			}
		}
		if(name[0][0] == name[2][0] && name[1][0] == 'c'){
			printf("%s",str);
			printf("\n");
		}
	}
	return 0;
}