//
// Created by Hangyi Zhu on 2019-04-28.
// 严书 算法3.1

#include <stdio.h>
#include "../04栈与队列/01顺序栈_Stack.h"

void conversion(int N) {
    //对于输入的任意一个非负十进制整数，打印输出与其等值的八进制数
    SqStack S;
    SElemType e;
    InitStack(&S); //构造空栈
    while (N) {
        Push(&S, N % 8);
        N = N / 8;
    }
    while (!StackEmpty(S))
    {
        Pop(&S, &e);
        printf("%d", e);
    }
}

int main(int argc, char **argv)
{
    int i = 1348;
    printf("将十进制数%d转换为八进制数...\n", i);
    conversion(i);
    printf("\n\n");
    return OK;
}