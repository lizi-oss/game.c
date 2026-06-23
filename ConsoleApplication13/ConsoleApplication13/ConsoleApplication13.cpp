#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h"
#include "string.h"

//实验定义常量
#define SizeOfBlock 128
#define M 4
#define SizeOfPage 7

//页表结构体：标志位、主存块号、磁盘位置
struct PageTable
{
    int flag;    // 1=在主存，0=不在
    long block;  // 主存块号
    long disk;   // 磁盘位置
} pagelist[SizeOfPage];

// FIFO队列
long page_queue[M];
int head;

// 初始化
void init_system() {
    head = 0;
    page_queue[0] = 0;
    page_queue[1] = 1;
    page_queue[2] = 2;
    page_queue[3] = 3;

    memset(pagelist, 0, sizeof(pagelist));

    // 0号页
    pagelist[0].flag = 1;
    pagelist[0].block = 5;
    pagelist[0].disk = 011;

    // 1号页
    pagelist[1].flag = 1;
    pagelist[1].block = 8;
    pagelist[1].disk = 012;

    // 2号页
    pagelist[2].flag = 1;
    pagelist[2].block = 9;
    pagelist[2].disk = 013;

    // 3号页
    pagelist[3].flag = 1;
    pagelist[3].block = 1;
    pagelist[3].disk = 021;

    // 4 5 6页
    pagelist[4].disk = 022;
    pagelist[5].disk = 023;
    pagelist[6].disk = 121;
}

// 地址转换
void address_translate() {
    long page_num;
    long unit_num;
    char exit_str[10];
    int stop = 0;

    printf("===== 分页式虚拟存储地址转换模拟 =====\n");
    printf("输入格式：页号 单元号（输入 exit 退出程序）\n\n");

    do {
        printf("请输入指令的页号、单元号：");

        if (scanf("%ld%ld", &page_num, &unit_num) != 2) {
            scanf("%s", exit_str);
            if (strcmp(exit_str, "exit") == 0) {
                stop = 1;
            }
            else {
                printf("输入格式错误！请重新输入！\n");
                fflush(stdin);
            }
        }
        else {
            if (page_num < 0 || page_num >= SizeOfPage || unit_num < 0 || unit_num >= SizeOfBlock) {
                printf("地址非法！页号0-6 单元号0~127\n");
                continue;
            }

            if (pagelist[page_num].flag == 1)
            {
                long absolute_addr = pagelist[page_num].block * SizeOfBlock + unit_num;
                printf("绝对地址 = %ld\n", absolute_addr);
            }
            else {
                printf("*%ld (发生缺页中断)\n", page_num);

                int old_page = page_queue[head];
                printf("淘汰页号：%d\n", old_page);
                printf("装入页号：%ld\n", page_num);

                pagelist[old_page].flag = 0;
                pagelist[page_num].block = pagelist[old_page].block;
                pagelist[page_num].flag = 1;

                page_queue[head] = page_num;
                head = (head + 1) % M;
            }
        }
        printf("------------------------------------\n");
    } while (!stop);

    printf("\n===== 最终FIFO页面队列状态 =====\n");
    for (int i = 0; i < M; i++)
    {
        printf("page_queue[%d] = %ld\n", i, page_queue[i]);
    }
}

int main() {
    init_system();
    address_translate();
    return 0;
}