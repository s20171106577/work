#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/��˿��������/work/work/001.csv" 
#define BUFF_LEN 300 

int main()
{
	char num[20];
	
	char str[100];
	char strtemp[100];
	float grade[20];//���� 
	char class_quality[20];//�γ����� 
	float class_grade;//ѧ�� 
	int temp;
	int oldPos;
	FILE *fp = NULL; //����һ���ļ�����ָ�룬��ֵΪ��
	
	char *file = FILE_PATH;//����һ���ַ�����ָ��
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));//������һ��char line[256]   #define BUFF_LEN 300  
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"r"))) )//�����⺯��access��fopen�����ļ���  �����ļ�accessΪ0�������ڻء�1 
	// R_OK�Ƿ���д��Ȩ��F_OK�ж��ļ��Ƿ���� 
	{
		printf("open %s failed\n",file);//���file��ָ���� 
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )//���ж�ȡ���ݣ�fgets(buf,n,fp);��ʾ�� fp ָ����ļ��� ��ȡn���ַ��ŵ� buf �ַ�������ȥ�� 
	{
	fscanf(fp,"%s",str);
	temp=strchr(str,',')-str;
	strncpy(num,str,temp);
	oldPos=temp;
	temp=/*��������*/strchr(str+oldPos+1,',')-str;
	strncpy(num,str+oldPos+1,temp-oldPos-1);
/*	student.num[temp-oldPos-1]=0;
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(student.years,str+oldPos+1,temp-oldPos-1);
	student.years[2]='\0';
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(student.scl,str+oldPos+1,temp-oldPos-1);
	student.scl[temp-oldPos]='\0';
	oldPos=temp;*/ 
		printf("\n%s",line);//���line��ָ������ 
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);//�ر�fpָ���ļ���
	}
	return 0;
}

