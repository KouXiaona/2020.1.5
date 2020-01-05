#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#pragma warning (disable:4996)

/*1. 有一个二维数组，数组的每行从左到右是递增的，每列从上到下是递增的，在这样的数组中查找一个数字是否存在。
1 3 5
2 5 7
3 7 9
要求：时间复杂度小于O(N);
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
			printf("找到这个数了，是->");
			return n;
		}
	}
	printf("没有找到这个数。\n");
	return 0;
}

int main()
{
	int n = 0;
	int a[3][3] = { 1, 3, 5,
		            2, 5, 7,
		            3, 7, 9 };
	printf("请输入你要查找的数->");
	scanf("%d", &n);
	printf("%d\n", lookup(a, 3, 3, n));
	system("pause");
	return 0;
}
*/





/*
2. 实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB

思路：
在我看来，这个题有三种实现方法。
第一种，也是最简单的：用一个二重循环，外部循环控制循环的次数即左旋的个数，内部循环控制每次的循环（即先将第一个保存在tmp中，
                                                                                                  然后将后面的依次放到前面，
                                                                                                  最后把tmp中的数放在最后一个数的位置， 
																								  此时一次左旋完成。）
第二种：用拼接的方法
        先开辟一个空间，将所要左旋的数剩下的数拷贝(用strcpy)进去，然后把要左旋的几个数拼接（用strncat)到后面，完成
*/

void left_move_easy(char *str, int n,int a)
{
	
	    a %= n;
		for (int i = 0; i < a; i++)//外部循环，控制你想循环的个数
		{
			int tmp = str[0];//把第一个数保存在新开辟的空间tmp中
			for (int j = 0; j < n-1 ;j++)//内部循环，一个循环要挪几个数，本来有n个，少了一个，则为n-1个，j又是从0开始，所以为j<n-1
			{                      
				str[j] = str[j+1]; //依次将之后的往前挪一位
			}
			str[n - 1] = tmp;//把新开辟空间tmp中的数保存在原来最后一个数的空间中
		}
		printf("%s\n", str);

}

void left_move_medium(char *str, int n,int a)
{
	a %= n;
	char *tmp = (void *)calloc(400, sizeof(char));
	strcpy(tmp, str + a);//先把后面的几个copy到tmp中
	strncat(tmp, str, a);//把要左旋的几个拼接到已经有后面几个数据的tmp中
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
	printf("请输入你想要左旋的个数->");
	scanf("%d", &a);
	//printf("%d", n);
	left_move_easy(str,n,a);
	left_move_medium(str, n,a);
	left_move_difficult(str, n,a);
	system("pause");
	return 0;
}

/*
3.写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
思路：asdfg12548xyzfjhjk
       g12548xyzfjhjkasdf
	   最简单的方法就是将字符串复制一份的原来的字符串后面，如这样，asdfg12548xyzfjhjk asdfg12548xyzfjhjk
	   字符串无论旋转几个都在上面的新字符串中。
int main()
{




	system("pause");
	return 0;
}*/


/*
4. 练习使用库函数，qsort排序各种类型的数据
*/

/*
5. 模仿qsort的功能实现一个通用的冒泡排序
*/




