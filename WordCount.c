#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//这是修改版本1.0
int main(int argc, char *argv[])
{

	FILE *fp;//文件指针
	char *filename;
	int wordcount = 0;//字符个数
	int charcount = 0;//单词个数
	//如果参数不对 则退出程序
	if (argc != 3)
	{
		printf("%s", "参数错误 程序即将退出!");
		exit(1);
	}
	strcpy(filename, argv[2]);
	//如果指定文件不存在 则退出程序
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("%s", "指定的文件不存在 程序即将退出!");
		exit(1);
	}
	printf("文件成功打开！\n");
	//如果是计算单词的
	if (argv[1][0] == 'w')
	{
		int ch;
		while ((ch = fgetc(fp)) != EOF)
		{
			if (ch == '#')
			{
				wordcount++;
			}
		}
		wordcount++;
		printf("%s%d", "单词个数为:", wordcount);
	}
	//如果是计算字符的
	else if (argv[1][0] == 'c')
	{
		int ch;
		//还没有读取到文件末尾
		while ((ch = fgetc(fp)) != EOF)
		{
			charcount++;
		}
		printf("%s%d", "字符个数为:", charcount);
	}

	fclose(fp);
	return 0;
}