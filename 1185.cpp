#include<stdio.h>
#include<iostream>
using namespace std;

void sort(int *a)
{
	int i, j, temp;
	for(i = 0;i < 2; i ++)
	{
		for(j = i + 1; j < 3; j ++)
		{
			if(a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
int main()
{
	int a[3];
	scanf("%d %d %d ", &a[0], &a[1], &a[2]);
	sort(a);
	char order[3];
	getchar();
	scanf(" %c%c%c", &order[0], &order[1], &order[2]);
	// getchar();
    // printf("%d %d %d\n", a[0], a[1], a[2]);
    // printf("%c%c%c\n",order[0],order[1],order[2]);
	printf("%d %d %d", a[order[0]-'A'], a[order[1]-'A'], a[order[2]-'A']);
    // system ("pause");
	return 0 ;
}