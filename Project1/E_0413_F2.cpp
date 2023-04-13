#include <stdio.h>

int factorial(int);
int Fibobacci(int);

int main()
{
	int num = 0;

	printf("���� �Է� : ");

	scanf_s("%d", &num);

	printf("%d! == %d", num, factorial(num));

	printf("\n\n");

	Fibobacci(num);

	return 0;
}

int factorial(int n)
{
	if (n == 0)
		return 1;

	return n * factorial(n - 1);
}

int  Fibobacci(int n)
{
	
	int f1 = 0, f2 = 1, f3 = 0;

	if (n == 1)
		printf("%d", f1);
	else
		printf("%d %d", f1, f2);

	for (int i = 2; i < n; i++)
	{
		f3 = f1 + f2;

		
		printf(" %d", f3);

		f1 = f2;
		f2 = f3;
	}
}