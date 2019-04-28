//
// Created by Hangyi Zhu on 2019-04-28.
//

#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"
#include "stdbool.h"

#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10   // 存储空间分配增量

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize; //用于栈顶指针
}SqStack;

Status visit(SElemType c)
{
    printf("%d ", c);
    return OK;
}

//构造一个空栈S
Status InitStack(SqStack *S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(S->base))
        exit(OVERFLOW); //存储分配失败
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//若栈S为空栈，则返回true，否则则返回false
Status StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return true;
    else
        return false;
}

// 把S置为空栈
Status ClearStack(SqStack *S)
{
    S->top = S->base;
    return OK;
}

//销毁栈S，S不再存在
Status DestroyStack(SqStack *S)
{
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;

    return OK;
}

/* 初始条件：单链表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status StackTraverse(SqStack S)
{
//    int i = 0;
    while(S.top > S.base)
    {
        visit(*--S.top);  //这样是逆序输出，非空栈中的栈顶指针始终在栈顶元素的下一个位置上
                          //所以S.top是空的，--S.top才是第一个元素
    }
    printf("\n");
    return OK;
}

Status StackTraverse2(SqStack S)
{
    SElemType *p = S.base;
    while (p<S.top)
        visit(*p++);

    return OK;
}

int StackLength(SqStack S)
{
    return S.top - S.base;
}

//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
Status GetTop(SqStack S, SElemType *e)
{
    if (S.top==S.base)
        return ERROR;

    *e = *(S.top - 1);
    return OK;
}

//插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e)
{
    if(S->top - S->base >= S->stacksize){ //栈满，增加存储空间
        S->base = (SElemType *) realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!S->base)
            exit(OVERFLOW); //储存分配失败
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;  //进栈先赋值，栈顶指针再自增
//    *(S->top)++ = e;
    return OK;
}

//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top == S->base)
        return ERROR;
    *e = * --S->top;
//    S->top--;
//    *e = *(S->top);
    return OK;
}

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