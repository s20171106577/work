#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu_info
{
    char num[20];
    char years[20];
	char scl[20];
	char place[20];
	char classes[20];
	char class_num[20];
	char class_name[20];
	char class_plan[20];
	float grade[20];
	float start_grade[20];
	char class_quality[20];//性质 
	char class_nature[20];//属性 
	float time [20];
	float class_grade;
	char class_place[20];
	char person[20];
	char classes_nature[20];	
	char test[20];
	char test_way[20];
	char classes_again[20];
	char classes_classes[20];//学位课程
	char classes_assisst[20]; //辅修课程 
};

int main()
{
	FILE *fp;
	struct stu_info student;
	char str[100];
	char strtemp[100];
	int temp;
	int oldPos;
	fp=fopen("C:/韩丝媛相关软件/work/work/001.csv","r");
	if(!fp){
		printf("文件打开失败！");
		exit(1); 
	}
	
	fscanf(fp,"%s",str);
	printf("%s\n",str);
	temp=strchr(str,',')-str;
	strncpy(student.num,str,temp);
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(student.num,str+oldPos+1,temp-oldPos-1);
	student.num[temp-oldPos-1]=0;
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(student.years,str+oldPos+1,temp-oldPos-1);
	student.years[2]='\0';
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(student.scl,str+oldPos+1,temp-oldPos-1);
	student.scl[temp-oldPos]='\0';
	oldPos=temp;
	temp=strchr(str+oldPos+1,',')-str;
	strncpy(strtemp,str+oldPos+1,temp-oldPos-1);
	strtemp[temp-oldPos-1]='\0';
	student.place=atof(strtemp);
	oldPos=temp;
	strncpy(strtemp,str+oldPos+1,temp-oldPos-1);
	strtemp[temp-oldPos-1]='\0';
	student.classes=atof(strtemp);
	//printf("%s %s %s %s %f %f\n",student.num,student.years,student.scl,student.place,student.classes,student.class_num,student.class_name,student.class_plan,student.grade,student.start_grade,student.class_quality,student.class_nature,);
	
   
	

	 
	fclose(fp);
	return 0;
}
