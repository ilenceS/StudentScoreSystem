/**************
version	   :	2
author     :	黄月
Student ID :	20140810128
**************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Student{
	char num[100];
	char name[200];
	int score[3];	//score[0]为语文;score[1]为数学;score[2]为英语.
	struct  Student *next;
}student;
student *head=NULL;
student *temp=NULL;

/* 函数初始区 */
void guideAll();
void guide();
void guideInput();
student* Init();
void insertStudent();
int count();
void deletStudent();
void searchStudent();
void destory();
void destoryAll();
char * s_gets(char * st,int n);
void outputStuInfo();
void date();

/* 函数区 */
int main(){
	system("clear");
	guide();
	guideInput();
	return 0;
}
void guideAll(){
	while(1){
		outputStuInfo();
		guide();
		guideInput();
	}
}
void guide(){
		printf("\n");
		printf("**** 欢迎来到学生成绩系统 ****\n\n");
		printf("***** 输入 1  ：建立链表  ****\n");
		printf("***** 输入 2  ：插入学生  ****\n");
		printf("***** 输入 3  ：查找学生  ****\n");
		printf("***** 输入 4  ：添加学生  ****\n");
		printf("***** 输入 5  ：删除学生  ****\n");
		printf("***** 输入 6  ：销毁链表  ****\n");
		printf("***** 输入其他：  退出    ****\n\n");
		printf("******************************\n");
}
void guideInput(){
	int input;
	printf("请输入:");
	scanf("%d",&input);
	switch(input){
		case 1:head=Init();system("clear");guideAll();
		case 2:date();system("clear");guideAll();
		case 3:searchStudent();
		case 4:insertStudent();
		case 5:deletStudent();
		case 6:destoryAll();
		default:exit(0);
	}
}
student* Init(){
	student *head;
	head=(student*)malloc(sizeof(student));
	head->next=NULL;
	return head;
}
int count(){
	int counts=0;
	temp=head;
	while(temp=temp->next){
		counts++;
	}
	return counts;
}

void deletStudent(){
	if(head==NULL){
		system("clear");
		printf("\n没有建立链表，请重新选择:\n");
		guide();
		guideInput();
		exit(0);
	}
	getchar();
	if(count()<=0){
		system("clear");
		printf("\n\n对不起，系统中没有学生，无法删除\n");
		printf("已返回原界面\n");
		guideAll();
	}
	char numhelp[11];
	temp=head;
	int deletHelp=0;
	printf("请输入需要删除学生的学号:");
	scanf("%s",numhelp);	
	while(temp->next){
		if(strcmp(temp->next->num,numhelp)==0){
			temp->next=temp->next->next;	//该节点已存在
			deletHelp=1;
			break;
		}
		temp=temp->next;
	}
	if(deletHelp==0){
		printf("\n对不起，没有该学生，请重新输入！");
		deletStudent();
	}
	else{
		system("clear");
		guideAll();	

	}
}
void insertStudent(){
	if(head==NULL){
		system("clear");
		printf("\n没有建立链表，请重新选择:\n");
		guide();
		guideInput();
		exit(0);
	}
		getchar();    //吸收一个换行
	student * p;
	p=(student*)malloc(sizeof(student));
	printf("输入学生学号:");
	scanf("%s",p->num);
	temp=head;
	while(temp->next){
		temp=temp->next;
	}
	printf("输入学生姓名:");
	scanf("%s",p->name);
	printf("请输入语文成绩:");
	scanf("%d",&p->score[0]);
	printf("请输入数学成绩:");
	scanf("%d",&p->score[1]);
	printf("请输入英语成绩:");
	scanf("%d",&p->score[2]);
	temp->next=p;
	p->next=NULL;
	system("clear");
	guideAll();
}
void searchStudent(){
	if(head==NULL){
		system("clear");
		printf("\n没有建立链表，请重新选择:\n");
		guide();
		guideInput();
		exit(0);
	}
	if(count()<=0){
		system("clear");
		printf("\n\n对不起，系统中没有学生，无法查询\n");
		printf("已返回原界面\n");
		guideAll();
	}
	student *temp1=head;
	char search[11];
	int searchHelp=0;
	printf("请输入学生学号:");
	scanf("%s",search);
	while(temp1=temp1->next){
		if(strcmp(temp1->num,search)==0){
			searchHelp=1;
			break;
		}
	}
	if(searchHelp==0){
		printf("\n对不起，没有该学生，请重新输入！");
		searchStudent();
	}
	else{
		system("clear");
		outputStuInfo();
		printf("\n%s  %s	%d	%d	%d\n",temp1->num,temp1->name,temp1->score[0],temp1->score[1],temp1->score[2]);
		guide();
		guideInput();
	}
}
void destory(student * p){
	if(p->next!=NULL)
		destory(p->next);
	free(p);
	p=NULL;		//防止野指针

}
void destoryAll(){
	if(head==NULL){
		system("clear");
		printf("\n没有建立链表，请重新选择:\n");
		guide();
		guideInput();
		exit(0);
	}
	if(head->next!=NULL)
		destory(head->next);
	head=NULL;
	system("clear");
	guide();
	guideInput();
}
void outputStuInfo(){
	temp=head;
	printf("\n\n学号 	     姓名	语文	数学	英语	\n");
	while(temp=temp->next){
		printf("%s  %s	%d	%d	%d\n",temp->num,temp->name,temp->score[0],temp->score[1],temp->score[2]);
	}
}
void date(){
	if(head==NULL){
		system("clear");
		printf("\n没有建立链表，请重新选择:\n");
		guide();
		guideInput();
		exit(0);
	}
	student* a=(student*)malloc(sizeof(student));
	strncpy(a->num,"20140810010",12);
	strncpy(a->name,"吴十",10);
	a->score[0]=50;a->score[1]=60;a->score[2]=70;
	a->next=head->next;head->next=a;
	student* b=(student*)malloc(sizeof(student));
	strncpy(b->num,"20140810009",12);
	strncpy(b->name,"杨九",10);
	b->score[0]=50;b->score[1]=60;b->score[2]=70;
	b->next=head->next;head->next=b;
	student* c=(student*)malloc(sizeof(student));
	strncpy(c->num,"20140810008",12);
	strncpy(c->name,"孙八",10);
	c->score[0]=50;c->score[1]=60;c->score[2]=70;
	c->next=head->next;head->next=c;
	student* d=(student*)malloc(sizeof(student));
	strncpy(d->num,"20140810007",12);
	strncpy(d->name,"钱七",10);
	d->score[0]=50;d->score[1]=60;d->score[2]=70;
	d->next=head->next;head->next=d;
	student* e=(student*)malloc(sizeof(student));
	strncpy(e->num,"20140810006",12);
	strncpy(e->name,"赵六",10);
	e->score[0]=50;e->score[1]=60;e->score[2]=70;
	e->next=head->next;head->next=e;
	student* f=(student*)malloc(sizeof(student));
	strncpy(f->num,"20140810005",12);
	strncpy(f->name,"王五",10);
	f->score[0]=50;f->score[1]=60;f->score[2]=70;
	f->next=head->next;head->next=f;
	student* g=(student*)malloc(sizeof(student));
	strncpy(g->num,"20140810004",12);
	strncpy(g->name,"李四",10);
	g->score[0]=50;g->score[1]=60;g->score[2]=70;
	g->next=head->next;head->next=g;
	student* h=(student*)malloc(sizeof(student));
	strncpy(h->num,"20140810003",12);
	strncpy(h->name,"张三",10);
	h->score[0]=50;h->score[1]=60;h->score[2]=70;
	h->next=head->next;head->next=h;
	student* i=(student*)malloc(sizeof(student));
	strncpy(i->num,"20140810002",12);
	strncpy(i->name,"黄二",10);
	i->score[0]=50;i->score[1]=60;i->score[2]=70;
	i->next=head->next;head->next=i;
	student* j=(student*)malloc(sizeof(student));
	strncpy(j->num,"20140810001",12);
	strncpy(j->name,"陈一",10);
	j->score[0]=50;j->score[1]=60;j->score[2]=70;
	j->next=head->next;head->next=j;
}
