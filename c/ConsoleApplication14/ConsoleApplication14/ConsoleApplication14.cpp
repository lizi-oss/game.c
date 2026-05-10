#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getpch(type) (type*)malloc(sizeof(type))

// PCB 定义
typedef struct PCB {
    char name[10];
    char state;
    int super;
    int ntime;
    int rtime;
    struct PCB* link;
} PCB;

PCB* ready = NULL;
PCB* p = NULL;

// 按优先级排序（降序）
void sort() {
    if (ready == NULL || ready->link == NULL)
        return;

    PCB* i;
    PCB* j;
    for (i = ready; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->super < j->super) {
                // 交换数据字段
                char tname[10];
                char tstate;
                int tsuper, tntime, trtime;

                strcpy(tname, i->name);
                tstate = i->state;
                tsuper = i->super;
                tntime = i->ntime;
                trtime = i->rtime;

                strcpy(i->name, j->name);
                i->state = j->state;
                i->super = j->super;
                i->ntime = j->ntime;
                i->rtime = j->rtime;

                strcpy(j->name, tname);
                j->state = tstate;
                j->super = tsuper;
                j->ntime = tntime;
                j->rtime = trtime;
            }
        }
    }
}

// 输入 PCB
void input() {
    int i, num;
    printf("请输入进程数量：");
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        p = getpch(PCB);
        if (p == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }

        printf("\n进程号 No.%d\n", i + 1);
        printf("输入进程名：");
        scanf("%s", p->name);
        printf("输入优先级：");
        scanf("%d", &p->super);
        printf("输入运行时间：");
        scanf("%d", &p->ntime);

        p->rtime = 0;
        p->state = 'W';
        p->link = NULL;

        if (ready == NULL) {
            ready = p;
        }
        else {
            PCB* temp = ready;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = p;
        }
        sort();
    }

    while (getchar() != '\n'); // 清缓冲
}

// 就绪队列长度
int space() {
    int len = 0;
    PCB* pr = ready;
    while (pr != NULL) {
        len++;
        pr = pr->link;
    }
    return len;
}

// 显示 PCB 信息
void disp(PCB* pr) {
    printf("%s\t%c\t%d\t%d\t%d\n", pr->name, pr->state, pr->super, pr->ntime, pr->rtime);
}

// 查看状态（增加空指针判断）
void check() {
    if (p != NULL) {
        printf("\n**** 当前运行的进程 ****\n");
        printf("进程名\t状态\t优先级\t总时间\t已运行\n");
        disp(p);
    }

    printf("\n**** 当前就绪队列 ****\n");
    PCB* pr = ready;
    if (pr == NULL) {
        printf("(空)\n");
        return;
    }
    printf("进程名\t状态\t优先级\t总时间\t已运行\n");
    while (pr != NULL) {
        disp(pr);
        pr = pr->link;
    }
}

// 销毁 PCB
void destroy() {
    printf("\n进程 [%s] 已完成！\n", p->name);
    free(p);
    p = NULL; // 释放后置空，避免野指针
}

// 运行一个时间片
void running() {
    p->rtime++;

    if (p->rtime == p->ntime) {
        destroy();
    }
    else {
        p->super--;
        p->state = 'W';
        p->link = ready;
        ready = p;
        sort();
    }
}

// 主函数
int main() {
    int len, h = 0;

    input();
    len = space();

    while (len != 0 && ready != NULL) {
        h++;
        printf("\n====================================");
        printf("\n第 %d 次调度运行", h);
        printf("\n====================================\n");

        p = ready;
        ready = p->link;
        p->link = NULL;
        p->state = 'R';

        check();
        running();

        len = space();
        printf("\n按回车继续...");
        getchar();
    }

    printf("\n\n所有进程运行完毕！\n");
    return 0;
}