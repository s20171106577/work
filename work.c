#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/韩丝媛相关软件/work/work/001.csv" 
#define BUFF_LEN 300 
int main()
{
	char num[20];
	char str[100];
	char strtemp[100];
	float grade[20];//分数 
	char classes_quality[20];//课程性质 
	float classes_grade;//学分 
	int temp;
	int oldPos;
	FILE *fp = NULL; //声明一个文件类型指针，赋值为空
	char *file = FILE_PATH;//声明一个字符类型指针
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));//申请了一个char line[256]   #define BUFF_LEN 300  
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"r"))) )//两个库函数access和fopen（打开文件）  存在文件access为0，不存在回—1 
	// R_OK是否有写入权限F_OK判断文件是否存在 
	{
		printf("open %s failed\n",file);//输出file所指内容 
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )//逐行读取数据，fgets(buf,n,fp);表示从 fp 指向的文件中 读取n个字符放到 buf 字符数组中去。 
	{
	fscanf(fp,"%s",str);
	temp=strchr(str,',')-str;
	strncpy(num,str,temp);
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(grade,str+oldPos+1,temp-oldPos-1);
	num[temp-oldPos-1]=0;
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(classes_quality,str+oldPos+1,temp-oldPos-1);
	classes_quality[2]='\0';
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(classes_grade,str+oldPos+1,temp-oldPos-1);
	class_grade[temp-oldPos]='\0';
	oldPos=temp;
		printf("\n%s",line);//输出line所指的内容 
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);//关闭fp指的文件夹
	}
	return 0;
}

