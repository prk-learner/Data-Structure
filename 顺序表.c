#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20//�洢�ռ��ʼ��
typedef int ElementType;
typedef struct LNode* list;
typedef struct LNode {
	ElementType Data[MAXSIZE];
	int last;//last�����һ��Ԫ�ص��±ꣻ
}Sqlist;



list MakeEmpty();//��ʼ�����Ա�
ElementType FindKth(int K,list L);//����λ��K��������Ӧ��Ԫ�أ�
int Find(ElementType X,list L);//�ҵ�Ԫ�����ڵ�λ�ã���һ�γ��֣�
void insert(ElementType X, int i, list L);//����λ��i����iǰ����һ��Ԫ��
void Delete(int i, list L);//�ҵ�λ��i��Ԫ�ز��ҽ���ɾ������
int Length(list L);
void Myprintf(list Ptrl);


//����һ���յ�˳���
list MakeEmpty()
{
	list Ptrl;
	Ptrl = (list)malloc(sizeof(Sqlist));
	Ptrl->last = -1;
	return Ptrl;
}

//����
int Find(ElementType X, list Ptrl)
{
	int i = 0;
	while (i <= Ptrl->last && Ptrl->Data[i] != X)
	{
		i++;
	}
	if (i > Ptrl->last) return -1;
	else return i;
}


ElementType FindKth(int K, list Ptrl)
{
	if (K < 0 && Ptrl->last < K)
	{
		return 0;
	}
	else return Ptrl->Data[K];
}


void insert(ElementType X, int i, list Ptrl)
{
	int j;
	
	if (Ptrl->last == MAXSIZE) {       //�ж�һ�±��Ƿ���
		printf("full");
		return;
	}
	if (i<1 || i>Ptrl->last + 2)      //����Ƿ�ɱ�����
	{
		printf("λ�ò��Ϸ�");
		return;
	}
	for (j = Ptrl->last; j >= i - 1; j--)//����i�Լ��Ժ��Ԫ��ȫ��������Ųһλ
	{
		Ptrl->Data[j + 1] = Ptrl->Data[j];
	}

	Ptrl->Data[i - 1] = X;
	Ptrl->last++;
}


void Delete(int i, list Ptrl)
{
	int j;
	if (i < 1 || i>Ptrl->last) {
		printf("error");
		return;
	}
	for (j = i; j < Ptrl->last; j++) {
		Ptrl->Data[j - 1] = Ptrl->Data[j];
	}
	Ptrl->last--;
	return;
}


void Myprintf(list Ptrl)
{
	if (Ptrl->last == -1) {
		printf("���");
		return;
	}
	int i = 0;

	while (Ptrl->last != -1)
	{
		printf("\t%d\n", Ptrl->Data[i]);
		i++;
		Ptrl->last--;
	}
}

void write(list Ptrl)
{
	int n;
	printf("����������Ҫ��������ݸ���\n");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		if (Ptrl->last == MAXSIZE-1) {
			printf("������");
			return;
		}
		printf("�������������");
		scanf("%d", &Ptrl->Data[i]);
		Ptrl->last++;
	}

}

int main()
{
	list Ptrl = MakeEmpty();


	write(Ptrl);


	//Myprintf(Ptrl);
	int a;
	int K,X;
	printf("��������Ҫʲô������1.���� 2.���� 3.ɾ��");
	scanf("%d", &a);
	switch (a)
	{
	case 1:printf("������Ҫ���ҵ���ţ��±꣩");
		scanf("%d", &K);
		printf("%d", FindKth(K, Ptrl)); break;
	case 2:printf("����������Ҫ����ڼ�����ǰ��");
		scanf("%d", &K);
		printf("����������Ҫ�����Ԫ��");
		scanf("%d", &X);
		insert(X, K, Ptrl); break;
	case 3:printf("����������Ҫɾ�������");
		scanf("%d", &K);
		Delete(K, Ptrl);
	default:
		break;
	}

	Myprintf(Ptrl);

	return 0;
}