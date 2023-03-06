#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct
{
    char num[5];    //���
    char name[10];  //����
    char sex[3];    //�Ա�
    char phone[15]; //�绰
    char addr[30];  //��ַ
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
            printf("ͨѶ¼��Ľ���\n");
            L = Tx_SqListset();
            break;
        case 2:
            printf("ͨѶ�ߵĲ���\n");
            Tx_SqListInsert(L);
            break;
        case 3:
            printf("ͨѶ�ߵ�ɾ��\n");
            Tx_SqListDelete(L);
            break;
        case 4:
            printf("ͨѶ�ߵĲ�ѯ\n");
            Tx_SqListGet(L);
            break;
        case 5:
            printf("ͨѶ������\n");
            Tx_SqListPrintf(L);
            break;
        case 0:
            printf("�ټ�\n");
            exit(0);
        }
    }
    return 0;
}

int menu_select()
{
    int sn;
    printf("ͨѶ¼����ϵͳ\n");
    printf("==================\n");
    printf("1 ͨѶ¼��Ľ���\n");
    printf("2 ͨѶ�ߵĲ���\n");
    printf("3 ͨѶ�ߵ�ɾ��\n");
    printf("4 ͨѶ�ߵĲ�ѯ\n");
    printf("5 ͨѶ¼������\n");
    printf("0 �˳�����ϵͳ\n");
    printf("==================\n");
    printf("�� ѡ �� 0-5:\n");
    while (1)
    {
        scanf("%d", &sn);
        if (sn < 0 || sn > 5)
            printf("\n\t ���������ѡ 0-5:\n");
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
    printf("������ͨѶ�ߵ�����:");
    scanf("%d", &n);
    rewind(stdin);
    for (i = 0; i < n; i++)
    {
        printf("�������%dλͨѶ�ߵ���Ϣ\n", i + 1);
        printf("��ţ�");
        gets(L->tx[i].num);
        printf("������");
        gets(L->tx[i].name);
        printf("�Ա�");
        gets(L->tx[i].sex);
        printf("�绰��");
        gets(L->tx[i].phone);
        printf("��ַ��");
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
        printf("ͨѶ������,�޷������µ�ͨѶ��");
    }
    printf("�������µ�ͨѶ��Ҫ�����λ��:");
    do
    {
        scanf("%d", &x);
        if (x < 1 || x > L->last + 2)
            printf("����λ������,�����²���:");
        else
            break;
    } while (1);
    rewind(stdin);
    for (i = L->last; i >= x - 1; --i)
        L->tx[i + 1] = L->tx[i];
    printf("�������µ�ͨѶ�ߵ���Ϣ\n");
    printf("��ţ�");
    gets(L->tx[i + 1].num);
    printf("������");
    gets(L->tx[i + 1].name);
    printf("�Ա�");
    gets(L->tx[i + 1].sex);
    printf("�绰��");
    gets(L->tx[i + 1].phone);
    printf("��ַ��");
    gets(L->tx[i + 1].addr);
    L->last++;
}

void Tx_SqListDelete(Tx_Seqlist *L)
{
    int i;
    char num[5];
    if (L->last < 0)
    {
        printf("ͨѶ¼��Ϊ�գ��޷�ɾ��ͨѶ��\n");
        exit(0);
    }
    else
    {
        printf("������Ҫɾ����ͨѶ�ߵı�ţ�");
        rewind(stdin);
        do
        {
            gets(num);
            for (i = 0; i <= L->last; i++)
                if (strcmp(num, L->tx[i].num) == 0)
                    break;
            if (i > L->last)
                printf("ͨѶ¼�����޴��˱�ţ����������룺");
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
    printf("��ѯ��ͨѶ�ߵķ�ʽ�й���4�ַ�ʽ: 1:��š�2:������3:�绰��4:��ַ,���������Ӧ��һ�����ֽ���ѡ��:");
    scanf("%d", &number);
    if (number < 1 || number > 4)
        printf("��ѯ��ʽ����,�����������ѯ��ʽ:");
    else
    {
        switch (number)
        {
        case 1:
            printf("������Ҫ��ѯ��ͨѶ�ߵı�ţ�");
            rewind(stdin);
            do
            {
                gets(num);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(num, L->tx[i].num) == 0)
                        break;
                if (i > L->last)
                    printf("ͨѶ¼�����޴��˱�ţ����������룺");
                else
                    break;
            } while (1);
            break;
        case 2:
            printf("������Ҫ��ѯ��ͨѶ�ߵ�������");
            rewind(stdin);
            do
            {
                gets(name);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(name, L->tx[i].name) == 0)
                        break;
                if (i > L->last)
                    printf("ͨѶ¼�����޴�������,����������:");
                else
                    break;
            } while (1);
            break;
        case 3:
            printf("������Ҫ��ѯ��ͨѶ�ߵĵ绰��");
            rewind(stdin);
            do
            {
                gets(phone);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(phone, L->tx[i].phone) == 0)
                        break;
                if (i > L->last)
                    printf("ͨѶ�����޴��˵绰,����������:");
                else
                    break;
            } while (1);
            break;
        case 4:
            printf("������Ҫ��ѯ��ͨѶ�ߵĵ�ַ��");
            rewind(stdin);
            do
            {
                gets(addr);
                for (i = 0; i <= L->last; i++)
                    if (strcmp(addr, L->tx[i].addr) == 0)
                        break;
                if (i > L->last)
                    printf("ͨѶ�����޴��˵�ַ,����������:");
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
                printf("ͨѶ¼�����޴��˱�ţ����������룺");
            else
                break;
        } while (1);*/
    printf("���\t����\t�Ա�\t�绰\t\t��ַ\n");
    printf("%s\t%s\t%s\t%s\t\t%s\n", L->tx[i].num, L->tx[i].name, L->tx[i].sex, L->tx[i].phone, L->tx[i].addr);
}

void Tx_SqListPrintf(Tx_Seqlist *L)
{
    int i;
    if (L->last == -1)
    {
        printf("ͨѶ¼��Ϊ��\n");
        exit(0);
    }
    else
    {
        printf("���\t����\t�Ա�\t�绰\t��ַ\n");
        for (i = 0; i <= L->last; i++)
            printf("%s\t%s\t%s\t%s\t%s\n", L->tx[i].num, L->tx[i].name, L->tx[i].sex, L->tx[i].phone, L->tx[i].addr);
    }
}