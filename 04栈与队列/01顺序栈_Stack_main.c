//
// Created by Hangyi Zhu on 2019-04-28.
//
#include <stdio.h>
#include "01顺序栈_Stack.h"

int main()
{
    int j;
    SqStack s;
    int e;
    if(InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素逆序依次为：");
    StackTraverse(s);
    printf("栈中元素顺序依次为：");
    StackTraverse2(s);
    printf("\n");
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));

    return 0;
}