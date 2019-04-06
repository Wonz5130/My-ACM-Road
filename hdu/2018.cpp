#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int a[100],n;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	//´ò±í 
	for (int i = 4; i < 55; i++) {
		a[i] = a[i - 1] + a[i - 3];
	}
	while (scanf("%d", &n) != EOF && n != 0) {
		printf("%d\n", a[n]);
	}
	return 0;
}
