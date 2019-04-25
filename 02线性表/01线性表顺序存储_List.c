//
// Created by Hangyi Zhu on 2019-04-24.
//
#include "stdio.h"

#include "stdlib.h"
#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 //储存空间初始分配量

typedef int Status;  /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType; /* ElemType类型根据实际情况而定，这里假设为int */

Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}


typedef struct
{
    ElemType data[MAXSIZE];    //数组，存储数据元素
    int length;                //线性表当前程度
}SqList;

// 初始化顺序线性表
Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)  //这里只需要获取L的表长，不需要修改本身，所以L就行了
{
    if(L.length == 0)
        return TRUE;
    else
        return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
    return L.length;
}


//获得元素操作
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i<1 || i>L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e)
{
    int i;
    if (L.length==0)
        return 0;
    for(i=0; i<L.length; i++)
    {
        if (L.data[i]==e)
            break;
    }
    if(i>=L.length)
        return 0;
    return i+1;    //因为返回的是位序，所以得i+1
}

//插入元素操作
Status ListInsert(SqList *L,int i, ElemType e) {
    int k;
    if (L->length == MAXSIZE)  //length是线性表表长
    {
        printf("表满");
        return ERROR;
    }
    if (i<1 || i>L->length+1)  //可以插到最后一个元素的后面，所以length+1
    {
        printf("位序不合法");
        return ERROR;
    }
    if (i <= L->length) //若插入位置不在表尾
    {
        for(k=L->length-1;k>=i-1;k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i, ElemType *e) //这里要对e操作（删除）所以用指针
{
    int k;
    if (L->length == 0)
    {
        printf("表空");
        return ERROR;
    }
    if (i<1 || i>L->length)
    {
        printf("位序不合法");
        return ERROR;
    }
    *e = L->data[i-1];
    if (i<L->length)   //如果删除位置不是最后位置
    {
        for (k = i; k < L->length; k++)
        {
            L->data[k-1] = L->data[k];  //直接覆盖了，无需删除
//            L->data[k] = L->data[k+1];  //❗️这里要注意，这个是删除第i+1个元素
        }
    }
    L->length--;
    return OK;
}


/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
    int i;
    for(i=0; i<L.length; i++)
    {
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}


//将所有的线性表Lb中但不在La中的数据元素插入到La中
void unionL(SqList *La, SqList Lb) {
    int La_len, Lb_len, i;
    ElemType e;   //声明与La和Lb相同的数据元素
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e))
            ListInsert(La, ++La_len, e);
    }
}



int main()
{

    SqList L;
    SqList Lb;

    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);

    for(j=1;j<=5;j++)
        i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
        ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
        k=LocateElem(L,j);
        if(k)
            printf("第%d个元素的值为：%d\n",k,j);
        else
            printf("没有值为%d的元素\n",j);
    }


    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
        i=ListDelete(&L,j,&e); /* 删除第j个数据 */
        if(i==ERROR)
            printf("删除第%d个数据失败\n",j);
        else
            printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L);

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    //构造一个有10个数的Lb
    i=InitList(&Lb);  //将线性表表长置零
    for(j=6;j<=15;j++)
        i=ListInsert(&Lb,1,j);

    printf("依次输出Lb的元素：");
    ListTraverse(Lb);

    unionL(&L,Lb);

    printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L);

    return 0;
}