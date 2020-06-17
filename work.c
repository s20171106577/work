#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/韩丝媛相关软件/work/work/001.csv" 
#define BUFF_LEN 256
int main()
{
	FILE *fp = NULL; //声明一个文件类型指针，赋值为空
	char *file = FILE_PATH;//声明一个字符类型指针
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));//申请了一个char line[256]   #define BUFF_LEN 256  
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"r"))) )//两个库函数access和fopen（打开文件）  存在文件access为0，不存在回—1 
	// R_OK是否有写入权限F_OK判断文件是否存在 
	{
		printf("open %s failed\n",file);//输出file所指内容 
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )//逐行读取数据，fgets(buf,n,fp);表示从 fp 指向的文件中 读取n个字符放到 buf 字符数组中去。 
	{
		printf("the content of each line is:\n%s",line);//输出line所指的内容 
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);//关闭fp指的文件夹
	}
	return 0;
}

