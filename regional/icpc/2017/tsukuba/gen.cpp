#include<bits/stdc++.h>

using namespace std;

int main()
{
	srand(time(NULL));
	int n=8,k=4;
	printf("%d %d\n",n,k);
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%c",rand()%2?'W':'B');
		printf("\n");
	}

	return 0;
}
