#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char id[10];
	double score;
	char isOk[4];
}ST;

//开文件
 
int readFile()
{
	ST *st=(ST*)malloc(sizeof(ST));
	st->score = 0;
	FILE* fp = NULL;
	char* line, * record;
	char buffer[1024];
	double num=0;
	if ((fp = fopen("001.csv", "at+")) != NULL)
	{
		fseek(fp, 170L, SEEK_SET); 
		char delims[] = ",";
		char* result = NULL;
		printf("学号\t    平均成绩点\t是否毕业\n");
		while ((line = fgets(buffer, sizeof(buffer), fp)) != NULL)
		{
			record = strtok(line, ",");
			while (record != NULL)
			{
				if (strcmp(record," ") == 0)
				return 0;
			}
		 } 
	} 
	 

}
//读文件 
int main()
{
	readFile();
	return 0;
}	 
