#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
	char* line, * record;
	char buffer[1024];
	double num=0;
	int n=0;
	if ((fp = fopen("001.csv", "at+")) != NULL)
	{
	
		char delims[] = ",";
	
		int j = 0;
		printf("ѧ��\t    ƽ���ɼ���\t�Ƿ��ҵ\n");
		while ((line = fgets(buffer, sizeof(buffer), fp)) != NULL)
		{
			record = strtok(line, ",");
			while (record != NULL)
			{
				if (strcmp(record," ") == 0)
					return 0;
					
				if (j==0)
				{
					if (strcmp(st->id,record))
					{
						if (n!=0)
						{
							if (st->score / n>1.90)
							{
								printf("%s\t%0.2f\t��\n", st->id, st->score / n);
							}
							else
							{
								printf("%s\t%0.2f\t��\n", st->id, st->score / n);
							}							
						}
						n = 0;
						st->score = 0;
						strcpy(st->id, record);
					}
				}
				else if (j == 9)
				{
					if (!strcmp(st->isOk, "����"))
					{
						if (!strcmp(record,"����"))
						{
							num = 60;
						}
						
						else
						{
						//	printf("%s\t", record);
							num = atof(record);
						}
						
						
					}
				}
				else if(j==11)
				{
					//printf("%s\t", record);
					strcpy(st->isOk, record);
				}
				else if (j == 13)
				{
					//printf("%s\t", record);
					if (!strcmp(st->isOk,"����"))
					{
						int  s= atof(record);
						st->score += s * (num / 10 - 5);
						n++;
					}
				}
					
				record = strtok(NULL, ",");
				//����ȡ����ÿһ�����ݴ�ӡ����
				if (j == 22)  //ֻ���ȡǰ22��
					break;
				
				j++;
			}
			j = 0;
		 } 
		 fclose(fp);
		fp = NULL;
	} 
	
	return 0;
	 

}
//���ļ� 
int main()
{
	readFile();
	return 0;
}	 
