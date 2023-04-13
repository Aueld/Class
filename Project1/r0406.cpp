//#include <stdio.h>
//
//int main()
//{
//	char ch;
//
//	printf("알파벳 문자를 입력해주세요 : ");
//
//	scanf_s("%c", &ch, sizeof(ch));
//
//	if (ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a'))
//		printf("알파벳 문자가 아닙니다.\n");
//	else
//	{
//		if ('A' <= ch && ch <= 'Z')
//			ch += 32;
//		else
//			ch -= 32;
//
//		printf("변환 되었습니다 : %c\n", ch);
//	}
//
//	return 0;
//}