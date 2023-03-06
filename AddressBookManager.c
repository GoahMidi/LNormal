#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct
{
    char num[5];    //编号
    char name[10];  //姓名
    char sex[3];    //性别
    char phone[15]; //电话
    char addr[30];  //地址
} Datatype;

typedef struct
{
    Datatype tx[SIZE];
    int last;
} Tx_Seqlist;

int menu_select(void);
Tx_Seqlist *Tx_SqListset(void);
int Tx_SqLempty(Tx_Seqlist *L);
void Tx_SqListInsert(Tx_Seqlist *L);
void Tx_SqListDelete(Tx_Seqlist *L);
void Tx_SqListGet(Tx_Seqlist *L);
void Tx_SqListPrintf(Tx_Seqlist *L);

int main()
{
    Tx_Seqlist *L;
    while (1)
    {
        switch (menu_select())
        {
        case 1:
            printf("通讯录表的建立\n");
            L = Tx_SqListset();
            break;
        case 2:
            printf("通讯者的插入\n");
            Tx_SqListInsert(L);
            break;
        case 3:
            printf("通讯者的删除\n");
            Tx_SqListDelete(L);
            break;
        case 4:
            printf("通讯者的查询\n");
            Tx_SqListGet(L);
            break;
        case 5:
            printf("通讯表的输出\n");
            Tx_SqListPrintf(L);
            break;
        case 0:
            printf("再见\n");
            exit(0);
        }
    }
    return 0;
}

int menu_select()
{
    int sn;
    printf("通讯录管理系统\n");
    printf("==================\n");
    printf("1 通讯录表的建立\n");
    printf("2 通讯者的插入\n");
    printf("3 通讯者的删除\n");
    printf("4 通讯者的查询\n");
    printf("5 通讯录表的输出\n");
    printf("0 退出管理系统\n");
    printf("==================\n");
    printf("请 选 择 0-5:\n");
    while (1)
    {
        scanf("%d", &sn);
        if (sn < 0 || sn > 5)
            printf("\n\t 输入错误，重选 0-5:\n");
        else
            break;
    }
    return sn;
}

Tx_Seqlist *Tx_SqListset(void)
{
    int n, i;
    Tx_Seqlist *L;
    L = (Tx_Seqlist *)malloc(SIZE * sizeof(Tx_Seqlist));
    L->last = -1;
    printf("请输入通讯者的总数:");
    scanf("%d", &n);
    rewind(stdin);
    for (i = 0; i < n; i++)
    {
        printf("请输入第%d位通讯者的信息\n", i + 1);
        printf("编号：");
        gets(L->tx[i].num);
        printf("姓名：");
        gets(L->tx[i].name);
        printf("性别：");
        gets(L->tx[i].sex);
        printf("电话：");
        gets(L->tx[i].phone);
        printf("地址：");
        gets(L->tx[i].addr);
        L->last++;
    }
    return L;
}

int Tx_SqLempty(Tx_Seqlist *L)
{
    if (L->last + 1 >= SIZE)
        return 1;
    else
        return 0;
}

void Tx_SqListInsert(Tx_Seqlist *L)
{
    int x, i;
    if (Tx_SqLempty(L) == 1)
    {
        printf("通讯表已满,无法插入新的通讯者");
    }
    printf("请输入新的通讯者要插入的位置:");
    do
    {
        scanf("%d", &x);
        if (x < 1 || x > L->last + 2)
            printf("插入位置有误,请重新插入:");
        else
            break;
    } while (1);
    rewind(stdin);
    for (i = L->last; i >= x - 1; --i)
        L->tx[i + 1] = L->tx[i];
    printf("请输入新的通讯者的信息\n");
    printf("编号：");
    gets(L->tx[i + 1].num);
    printf("姓名：");
    gets(L->tx[i + 1].name);
    printf("性别：");
    gets(L->tx[i + 1].sex);
    printf("电话：");
    gets(L->tx[i + 1].phone);
    printf("地址：");
    gets(L->tx[i + 1].addr);
    L->last++;
}

void Tx_SqListDelete(Tx_Seqlist *L)
{
    int i;
    char num[5];
    if (L->last < 0)
    {
        printf("通讯录表为空，无法删除通讯者\n");
        exit(0);
    }
    else
    {
        printf("请输入要删除的通讯者的编号：");
        rewind(stdin);
        do
        {
            gets(num);
            for (i = 0; i <= L->last; i++)
                if (strcmp(num, L->tx[i].num) == 0)
                    break;
            if (i > L->last)
                printf("通讯录表中无此人编号，请重新输入：");
            else
                break;
        } while (1);
        for (; i < L->last; i++)
            L->tx[i] = L->tx[i + 1];
        L->last--;
    }
}

void Tx_SqListGet(Tx_Seqlist *L)
{
    int i, number;
    char num[5], name[10], sex[3], phone[15], addr[30];
    printf("查询的通讯者的方式有共有4种方式: 1:编号、2:姓名、3:电话、4:地址,请输入相对应的一个数字进行选择:");
    scanf("%d", &number);
    if (number < 1 || number > 4)
        printf("查询方式有误,请重新输入查询方式:");
    else
    {
        switch (number)
        {
        case 1:
            printf("请输入要查询的通讯者的编号：");
            rewind(stdin);
            do
            {
                gets(num);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(num, L->tx[i].num) == 0)
                        break;
                if (i > L->last)
                    printf("通讯录表中无此人编号，请重新输入：");
                else
                    break;
            } while (1);
            break;
        case 2:
            printf("请输入要查询的通讯者的姓名：");
            rewind(stdin);
            do
            {
                gets(name);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(name, L->tx[i].name) == 0)
                        break;
                if (i > L->last)
                    printf("通讯录表中无此人姓名,请重新输入:");
                else
                    break;
            } while (1);
            break;
        case 3:
            printf("请输入要查询的通讯者的电话：");
            rewind(stdin);
            do
            {
                gets(phone);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(phone, L->tx[i].phone) == 0)
                        break;
                if (i > L->last)
                    printf("通讯表中无此人电话,请重新输入:");
                else
                    break;
            } while (1);
            break;
        case 4:
            printf("请输入要查询的通讯者的地址：");
            rewind(stdin);
            do
            {
                gets(addr);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(addr, L->tx[i].addr) == 0)
                        break;
                if (i > L->last)
                    printf("通讯表中无此人地址,请重新输入:");
                else
                    break;
            } while (1);
            break;
        }
    }
    /*    rewind(stdin);
        do
        {
            gets(num);
            for (i = 0; i <= L->last; i++)
                if (strcmp(num, L->tx[i].num) == 0)
                    break;
            if (i > L->last)
                printf("通讯录表中无此人编号，请重新输入：");
            else
                break;
        } while (1);*/
    printf("编号\t姓名\t性别\t电话\t\t地址\n");
    printf("%s\t%s\t%s\t%s\t\t%s\n", L->tx[i].num, L->tx[i].name, L->tx[i].sex, L->tx[i].phone, L->tx[i].addr);
}

void Tx_SqListPrintf(Tx_Seqlist *L)
{
    int i;
    if (L->last == -1)
    {
        printf("通讯录表为空\n");
        exit(0);
    }
    else
    {
        printf("编号\t姓名\t性别\t电话\t地址\n");
        for (i = 0; i <= L->last; i++)
            printf("%s\t%s\t%s\t%s\t%s\n", L->tx[i].num, L->tx[i].name, L->tx[i].sex, L->tx[i].phone, L->tx[i].addr);
    }
}