#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//ͳ���ļ��ַ���
int getChar(FILE *fp)
{
    char ch;
    int num=0;
    while((ch=fgetc(fp)) != EOF)  //���û�ж����һֱ�� 
    {
        num++;
    }
    rewind(fp);  //ָ��ص���ͷ 
    return num;
}

//ͳ���ļ�������
int getWord(FILE *fp)
{
    char s[1024];
    int num = 0;
    while (fscanf(fp, "%s", s) != EOF)  //�Ƚ������ַ����տո�ֿ� 
    {
        num ++;  // ÿ��һ���ͼ�һ 
        for (int i = 1; i < strlen(s) - 1; i ++)  //�����ַ���������ж��Ŵ����м䣬��ô˵�����е��ʣ����һ 
            if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                num ++;
    }
    return num;
}


int main(int argc, char*argv[])
{
    FILE *fp;

    if(argc==3) //�����в��������ж�
    {

        fp = fopen(argv[2], "r"); //��ȡ�ļ�������

        if(fp == NULL) //��ʧ��
        {
            printf("�����޷���%s\n",argv[2]);
            exit(1);
        }


        //�Բ�������ƥ�䣬��Ϊ"c"��ͳ���ַ���Ŀ����Ϊ"w"��ͳ�Ƶ�����Ŀ�����������򱨴�
        if(!strcmp(argv[1],"-c"))
            printf("�ַ���Ϊ��%d\n",getChar(fp));

        else if(!strcmp(argv[1], "-w"))
            printf("������Ϊ��%d\n", getWord(fp));
        
        else
            printf("�������� ��");
        

    }
    else
        printf("���󣺲��������������������\n");
    
}
