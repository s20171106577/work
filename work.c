#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct {
	char id[10];
	double score;
	char isOk[4];
}ST;

//���ļ�
 
int readFile()
{
	ST *st=(ST*)malloc(sizeof(ST));
	st->score = 0;
	FILE* fp = NULL;
}
//���ļ� 
int main()
{
	readFile();
	return 0;
}	 
