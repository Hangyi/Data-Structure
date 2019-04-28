//
// Created by Hangyi Zhu on 2019-04-28.
//

#ifndef DATA_STRUCTURE_01顺序栈_STACK_H
#define DATA_STRUCTURE_01顺序栈_STACK_H


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

Status visit(SElemType c);


//构造一个空栈S
Status InitStack(SqStack *S);


//若栈S为空栈，则返回true，否则则返回false
Status StackEmpty(SqStack S);


// 把S置为空栈
Status ClearStack(SqStack *S);


//销毁栈S，S不再存在
Status DestroyStack(SqStack *S);


/* 初始条件：单链表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status StackTraverse(SqStack S);


Status StackTraverse2(SqStack S);


int StackLength(SqStack S);


//若栈不为空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
Status GetTop(SqStack S, SElemType *e);


//插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e);


//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK;否则返回ERROR
Status Pop(SqStack *S, SElemType *e);


#endif //DATA_STRUCTURE_01顺序栈_STACK_H

