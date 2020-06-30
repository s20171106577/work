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
}
//读文件 
int main()
{
	readFile();
	return 0;
}	 
