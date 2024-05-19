#include<stdio.h>
#include<string.h>
#include <stdlib.h>

//统计文件字符数
int getChar(FILE *fp)
{
    char ch;
    int num=0;
    while((ch=fgetc(fp)) != EOF)  //如果没有读完就一直读 
    {
        num++;
    }
    rewind(fp);  //指针回到开头 
    return num;
}

//统计文件单词数
int getWord(FILE *fp)
{
    char s[1024];
    int num = 0;
    while (fscanf(fp, "%s", s) != EOF)  //先将所有字符按照空格分开 
    {
        num ++;  // 每有一个就加一 
        for (int i = 1; i < strlen(s) - 1; i ++)  //遍历字符串，如果有逗号处于中间，那么说明还有单词，则加一 
            if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                num ++;
    }
    return num;
}


int main(int argc, char*argv[])
{
    FILE *fp;

    if(argc==3) //命令行参数个数判断
    {

        fp = fopen(argv[2], "r"); //读取文件的内容

        if(fp == NULL) //打开失败
        {
            printf("错误：无法打开%s\n",argv[2]);
            exit(1);
        }


        //对参数进行匹配，若为"c"则统计字符数目，若为"w"则统计单词数目，若都不是则报错
        if(!strcmp(argv[1],"-c"))
            printf("字符数为：%d\n",getChar(fp));

        else if(!strcmp(argv[1], "-w"))
            printf("单词数为：%d\n", getWord(fp));
        
        else
            printf("参数错误 ！");
        

    }
    else
        printf("错误：参数输入错误，请重新输入\n");
    
}
