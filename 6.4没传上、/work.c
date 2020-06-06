#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/韩丝媛相关软件/work/work/选课表.csv" 
#define BUFF_LEN 256
int main()
{
	FILE *fp = NULL;
	char *file = FILE_PATH;
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"r"))) )
	{
		printf("open %s failed\n",file);
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )
	{
		printf("the content of each line is:\n%s",line);
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);
	}
	return 0;
}

