#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<malloc.h>
#define FILE_PATH "C:/Users/修百会/Desktop/ff/001.csv" 
#define BUFF_LEN 256 //长度 缓冲 
int y=0;//用来计数 
int txt[10005];
//void output(struct str out[10000]);
struct ostudent{
	char num[20];//学号 
	double jidian;//平均绩点 
	int pass;//毕业否？
	double add_spoint;//学绩点和
	double add_credit;//课程学分和 
	double agv_grade;//平均成绩
}o[10005];
struct instudent{
	char innum[15];//学号
	double ingrade;//成绩 
	double credit;//学分
	double sjidian;	//绩点
	double spoint;//学绩点 
	struct ostudent add;//毕业学生个数 
}student;
//计算学绩点 
void spoint()
{
	student.sjidian=student.ingrade/10-5;
	if(student.spoint<0)
	{
		student.spoint=0;
	}
	student.spoint=student.sjidian*student.ingrade; 
}  
//每个学生总学分和总学绩点
void innum() 
{
    int a=11;
    
    int j=(student.innum[a-4]-'0')*1000+(student.innum[a-3]-'0')*100+(student.innum[a-2]-'0')*10+(student.innum[a-1]-'0');
    if(txt[j]==-1)
	{
		txt[j] = ++y;
		strcpy(o[txt[j]].num,student.innum);
	}
	o[txt[j]].add_credit+=student.credit;
	o[txt[j]].add_spoint+=student.spoint;
}
//写文件
void w_file()
{
	FILE *outPut=FILE_PATH;			//写文件 
	if(outPut==NULL)
	{
		printf("output File open error!\n");
		exit(0);
	}
	fprintf(outPut,"学号,平均成绩，平均学绩点,是否能毕业\n"); 
//计算单个学生绩点成绩，判断是否可以毕业 
	int x=1;
	for(x<=y;x++)
	{
		o[x].jidian=o[txt[j]].add_credit / o[x].add_credit;	
		o[x].agv_grade=o[x].add_spoint / x;	
		if(o[x].jidian>=2)
		{
			strcpy(o[x].pass,"是 ");
		} 
		else
		{
			strcpy(o[x].pass,"否");
		}
		fprintf(outPut,"%s,%2lf,%.2lf,%s\n",o[x].num,o[x].agv_grade,o[x].jidian,o[x].pass); 
	}
	fclose(outPut);
} 
//开文件
 
int main()
{ 
	int temp;
	int oldPos;
	FILE *fp = NULL; //声明一个文件类型指针，赋值为空
	char *file = FILE_PATH;//声明一个字符类型指针
	char *line = (char *)malloc(BUFF_LEN * sizeof(char));//申请了一个char line[256]   #define BUFF_LEN 256  
	if( (0 != access(file,R_OK|F_OK)) || (NULL==(fp=fopen(file,"w"))) )//两个库函数access和fopen（打开文件）  存在文件access为0，不存在回—1 
	// R_OK是否有写入权限F_OK判断文件是否存在 
	{
		printf("open %s failed\n",file);//输出file所指内容 
		return -1;
	}
	while( fgets(line, BUFF_LEN, fp) != NULL )//逐行读取数据，fgets(buf,n,fp);表示从 fp 指向的文件中 读取n个字符放到 buf 字符数组中去。 
	{
		printf("\n%s",line);//输出line所指的内容 
	}
	printf("open %s failed\n",file);
	if(fp!=NULL)
	{
		fclose(fp);//关闭fp指的文件夹
	}
	return 0;
}

