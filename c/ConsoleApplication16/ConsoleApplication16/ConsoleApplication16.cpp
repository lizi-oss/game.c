#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//结构体与指针
struct student {
	char name[20];
	char num[20];
	int age;
	float score;
};
int main() {
	//利用指针，以达到指向整个结构体。
		struct student s1 = {"Alice", "001", 20, 95.5},s2;
		struct student* p, * q;//出错了但是我知道了，定义什么类型的指针就要用什么类型的指针变量来接收。
		p = &s1;
		q = &s2;
		*q = *p;
		printf("姓名\t学号\t年龄\t成绩\n");
		printf("% s\t % s\t % d\t % .2f\n", s2.name, s2.num, s2.age, s2.score);
		//利用指针间接访问成员
		struct student s3, * r;//*r=&s3,这里的*是初始化r而不是s3的地址赋值给*r
		r = &s3;
		printf("请输入学号：");
		fgets(r->num, 20, stdin);//如果是输入字符串一般用fgets

		printf("请输入姓名：");
		fgets(r->name, 20, stdin);

		printf("请输入年龄：");
		scanf("%d", &r->age);

		printf("请输入成绩：");
		scanf("%f", &r->score);

		printf("\n输入的信息为：\n");

		printf("姓名：%s", r->name);
		printf("学号：%s", r->num);
		printf("年龄：%d\n", r->age);
		printf("成绩：%.2f\n", r->score);
		return 0;
}