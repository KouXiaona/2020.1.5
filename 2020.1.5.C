#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#pragma warning (disable:4996)

/*1. ��һ����ά���飬�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ����ģ��������������в���һ�������Ƿ���ڡ�
1 3 5
2 5 7
3 7 9
Ҫ��ʱ�临�Ӷ�С��O(N);
int lookup(int (*a)[3],int x,int y,int n)
{
	int i = 0; int j = 2;
	while (i<3&&j>=0)
	{
		if (a[i][j] > n)
		{
			j--;
		}
		else if (a[i][j] < n)
		{
			i++;
		}
		else
		{
			printf("�ҵ�������ˣ���->");
			return n;
		}
	}
	printf("û���ҵ��������\n");
	return 0;
}

int main()
{
	int n = 0;
	int a[3][3] = { 1, 3, 5,
		            2, 5, 7,
		            3, 7, 9 };
	printf("��������Ҫ���ҵ���->");
	scanf("%d", &n);
	printf("%d\n", lookup(a, 3, 3, n));
	system("pause");
	return 0;
}
*/





/*
2. ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB

˼·��
���ҿ����������������ʵ�ַ�����
��һ�֣�Ҳ����򵥵ģ���һ������ѭ�����ⲿѭ������ѭ���Ĵ����������ĸ������ڲ�ѭ������ÿ�ε�ѭ�������Ƚ���һ��������tmp�У�
                                                                                                  Ȼ�󽫺�������ηŵ�ǰ�棬
                                                                                                  ����tmp�е����������һ������λ�ã� 
																								  ��ʱһ��������ɡ���
�ڶ��֣���ƴ�ӵķ���
        �ȿ���һ���ռ䣬����Ҫ��������ʣ�µ�������(��strcpy)��ȥ��Ȼ���Ҫ�����ļ�����ƴ�ӣ���strncat)�����棬���
*/

void left_move_easy(char *str, int n,int a)
{
	
	    a %= n;
		for (int i = 0; i < a; i++)//�ⲿѭ������������ѭ���ĸ���
		{
			int tmp = str[0];//�ѵ�һ�����������¿��ٵĿռ�tmp��
			for (int j = 0; j < n-1 ;j++)//�ڲ�ѭ����һ��ѭ��ҪŲ��������������n��������һ������Ϊn-1����j���Ǵ�0��ʼ������Ϊj<n-1
			{                      
				str[j] = str[j+1]; //���ν�֮�����ǰŲһλ
			}
			str[n - 1] = tmp;//���¿��ٿռ�tmp�е���������ԭ�����һ�����Ŀռ���
		}
		printf("%s\n", str);

}

void left_move_medium(char *str, int n,int a)
{
	a %= n;
	char *tmp = (void *)calloc(400, sizeof(char));
	strcpy(tmp, str + a);//�ȰѺ���ļ���copy��tmp��
	strncat(tmp, str, a);//��Ҫ�����ļ���ƴ�ӵ��Ѿ��к��漸�����ݵ�tmp��
	strcpy(str,tmp);
	printf("%s", str);
	free(tmp);

}
void left_move_difficult(char *str, int n,int a)
{

}

int main()
{
	char str[] = "ABCDEFGHIJK";
	int n = strlen(str);
	int a = 0;
	printf("����������Ҫ�����ĸ���->");
	scanf("%d", &a);
	//printf("%d", n);
	left_move_easy(str,n,a);
	left_move_medium(str, n,a);
	left_move_difficult(str, n,a);
	system("pause");
	return 0;
}

/*
3.дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
˼·��asdfg12548xyzfjhjk
       g12548xyzfjhjkasdf
	   ��򵥵ķ������ǽ��ַ�������һ�ݵ�ԭ�����ַ������棬��������asdfg12548xyzfjhjk asdfg12548xyzfjhjk
	   �ַ���������ת����������������ַ����С�
int main()
{




	system("pause");
	return 0;
}*/


/*
4. ��ϰʹ�ÿ⺯����qsort����������͵�����
*/

/*
5. ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
*/



