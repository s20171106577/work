#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<malloc.h>
#define MAX 3 
#define FILE_PATH "C:/��˿��������/work/work/001.csv" 
#define BUFF_LEN 256 //���� ���� 
int txt[10005];
//void output(struct str out[10000]);
struct ostudent{
	char num[20];//ѧ�� 
	double jidian;//ƽ������ 
	int pass;//��ҵ��
	double add_spoint;//ѧ�����
	double add_credit;//�γ�ѧ�ֺ� 
}o[10005];
struct instudent{
	char innum[15];//ѧ��
	double ingrade;//�ɼ� 
	double credit;//ѧ��
	double sjidian;	//����
	double spoint;//ѧ���� 
	struct ostudent add;//��ҵѧ������ 
}student;
//����ѧ���� 
void spoint()
{
	student.sjidian=student.ingrade/10-5;
	if(student.spoint<0)
	{
		student.spoint=0;
	}
	student.spoint=student.sjidian*student.ingrade; 
}  
//ÿ��ѧ����ѧ�ֺ���ѧ����
void innum() 
{
    int a=11;
    int j=(student.innum[a-4]-'0')*1000+(student.innum[a-3]-'0')*100+(student.innum[a-2]-'0')*10+(student.innum[a-1]-'0');
    if(txt[j]==-1)
	{
		txt[j] = 1;
		strcpy(o[txt[j]].num,student.innum);
	}
	o[txt[j]].add_credit+=student.credit;
	o[txt[j]].add_spoint+=student.spoint;
}
//���ļ�
 
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
		printf("\n%s",line);//���line��ָ������ 
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);//�ر�fpָ���ļ���
	}
	return 0;
}

