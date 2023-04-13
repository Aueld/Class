//#include <stdio.h>
//
//int main()
//{
//	int n;
//
//	scanf_s("%d", &n);
//	getchar();
//
//
//	for (int i = 0; i < n / 2 + 1; i++)
//	{
//		for (int j = i; j <= n / 2 + 1; j++)
//		{
//			printf(" ");
//		}
//
//		for (int k = i; k < i * 2 + 1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	for (int i = (n / 2 + 1) - 1; i > 0; i--)
//	{
//		for (int j = i; j <= n / 2 + 1; j++)
//		{
//			printf(" ");
//		}
//
//		for (int k = 0; k < (i - 1) * 2; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}