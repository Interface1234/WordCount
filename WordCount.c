#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����޸İ汾1.0
int main(int argc, char *argv[])
{

	FILE *fp;//�ļ�ָ��
	char *filename;
	int wordcount = 0;//�ַ�����
	int charcount = 0;//���ʸ���
	//����������� ���˳�����
	if (argc != 3)
	{
		printf("%s", "�������� ���򼴽��˳�!");
		exit(1);
	}
	strcpy(filename, argv[2]);
	//���ָ���ļ������� ���˳�����
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("%s", "ָ�����ļ������� ���򼴽��˳�!");
		exit(1);
	}
	printf("�ļ��ɹ��򿪣�\n");
	//����Ǽ��㵥�ʵ�
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
		printf("%s%d", "���ʸ���Ϊ:", wordcount);
	}
	//����Ǽ����ַ���
	else if (argv[1][0] == 'c')
	{
		int ch;
		//��û�ж�ȡ���ļ�ĩβ
		while ((ch = fgetc(fp)) != EOF)
		{
			charcount++;
		}
		printf("%s%d", "�ַ�����Ϊ:", charcount);
	}

	fclose(fp);
	return 0;
}