#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/��˿��������/work/work/001.csv" 
#define BUFF_LEN 256 //���� ���� 
//void output(struct str out[10000]);
typedef struct outstudent{
	char num[15];//ѧ�� 
	double jidian;//ƽ������ 
	int pass;//��ҵ��
};
typedef struct instudent{
	char innum[15];//ѧ��
	double ingrade;//�ɼ� 
	double sjidian;	//����
	double spoint;//ѧ���� 
}; 
void spont()
{
	instudent.sjidian=instudent.ingrade/10-5;
	if(student.spoint<0)
	{
		student.spoint=0;
	}
	student.spoint=student.sjidian*student.ingrade; 
} 
int main()
{	 
	int temp;
	int oldPos;
	FILE *fp = NULL; //����һ���ļ�����ָ�룬��ֵΪ��
	char *file = FILE_PATH;//����һ���ַ�����ָ��
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));//������һ��char line[256]   #define BUFF_LEN 256  
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"r"))) )//�����⺯��access��fopen�����ļ���  �����ļ�accessΪ0�������ڻء�1 
	// R_OK�Ƿ���д��Ȩ��F_OK�ж��ļ��Ƿ���� 
	{
		printf("open %s failed\n",file);//���file��ָ���� 
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )//���ж�ȡ���ݣ�fgets(buf,n,fp);��ʾ�� fp ָ����ļ��� ��ȡn���ַ��ŵ� buf �ַ�������ȥ�� 
	{
/*	fscanf(fp,"%s",str);
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

