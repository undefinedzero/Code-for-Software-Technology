#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP    100
#define NUMBER   '0'    // signal that a number was found
#define EMPTY    0

int getop(char []);

int main()
{
	int c;
	int i=0,k=0,max1,max2,n=0;
	char s[MAXOP];
	char opter[MAXOP];
	int num[MAXOP];

	while ((c = getop(s)) != EOF) 
	{
		switch (c) 
		{
			case NUMBER:
				printf("%d\n", atoi(s));
				num[i] = atoi(s);
				i++;
				break;
			case '+':
				max1=k;
				while(opter[k-1]!='(' && k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i-1] / num[i];
					else if(opter[k-1]=='+')
						num[(--i)-1] = num[i] + num[i-1];
					else if(opter[k-1]=='-')
						num[(--i)-1] = num[i-1] - num[i];
					k--;	
				}

				opter[k++] = '+';
				printf("%c\n", c);
				break;
					        // + �� - ���ȼ���ͣ��ѳ��� '(' �����ȫ����������������ջ
			case '-':
				while(opter[k-1]!='(' && k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i-1] / num[i];
					else if(opter[k-1]=='+')
						num[(--i)-1] = num[i] + num[i-1];
					else if(opter[k-1]=='-')
						num[(--i)-1] = num[i-1] - num[i];
					k--;	
				}

				opter[k++] = '-';
				printf("%c\n", c);
				break;
			case '*':
				n=0;
				while(opter[k-1]!='(' && k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i] / num[i-1];
					else if(opter[k-1]=='+')
						n++;
					else if(opter[k-1]=='-')
						n++;					
					k--;	
				}
				k=k+n;
				opter[k++] = '*';
				printf("%c\n", c);
				break;	              // �˳����ȼ���ߣ�����ͬ���ȼ��ĳ˺ͳ���������ջ
			case '/':
				n=0;
				while(opter[k-1]!='(' && k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i] / num[i-1];
					else if(opter[k-1]=='+')
						n++;
					else if(opter[k-1]=='-')
						n++;
					k--;	
				}
				k=k+n;
				opter[k++] = '/';
				printf("%c\n", c);
				break;
			case '(':        // '(' �������㣬ֱ�ӷ���optorջ��
				opter[k] = '(';
				k++;
				printf("%c\n", c);
				break;
			case ')':        // �� '(' ֮ǰ��ȫ�������������������� '(' Ҳ����
				while(opter[k-1]!='(' && k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i-1] / num[i];
					else if(opter[k-1]=='+')
						num[(--i)-1] = num[i] + num[i-1];
					else if(opter[k-1]=='-')
						num[(--i)-1] = num[i-1] - num[i];
					k--;	
				}
				k--;
				printf("%c\n", c);
				break;
			case '\n':        // �����µĲ�����ȫ�������������������
				while(k!=0){
					if(opter[k-1]=='*')
						num[(--i)-1] = num[i] * num[i-1];
					else if(opter[k-1]=='/')
						num[(--i)-1] = num[i-1] / num[i];
					else if(opter[k-1] == '+')
						num[(--i)-1] = num[i] + num[i-1];
					else if(opter[k-1]=='-')
						num[(--i)-1] = num[i-1] - num[i];
					k--;	
				}

				printf("%d\n",num[0]);
				printf("%c", c);
				i=0;
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	return 0;
}


int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getchar()) == ' ' || c == '\t');
	s[1] = '\0';
	
	if (!isdigit(c) && c != '.')
		return c; 
	
	i = 0;
	if (isdigit(c)) 
		while (isdigit(s[++i] = c = getchar())) ;
	
	if (c == '.') 
		while (isdigit(s[++i] = c = getchar()))  ;
	
	s[i] = '\0';
	
	if (c != EOF)  ungetc(c, stdin);
	return NUMBER;
}

