//#include <stdio.h>
//
//int main()
//{
//	char ch;
//
//	printf("���ĺ� ���ڸ� �Է����ּ��� : ");
//
//	scanf_s("%c", &ch, sizeof(ch));
//
//	if (ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a'))
//		printf("���ĺ� ���ڰ� �ƴմϴ�.\n");
//	else
//	{
//		if ('A' <= ch && ch <= 'Z')
//			ch += 32;
//		else
//			ch -= 32;
//
//		printf("��ȯ �Ǿ����ϴ� : %c\n", ch);
//	}
//
//	return 0;
//}