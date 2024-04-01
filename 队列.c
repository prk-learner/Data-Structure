#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//�ܲ���Լ�������Ա�һ�˳�����һ���룻Queue
//һ����ԣ�������ʵ���߼�����һ����״��
// 
// 
 /*��ʵ�ܲ������һ����ǵ��պ�����ʱ��front == rear�������
 Ҳ����˵�޷��жϿջ�������ô����Ҫ���ְ취
 1.ʹ�ö���ı�� size����tag����size++����size--,
 ��tag=1����tag=0��tag�������һ�β����������Ǽ�
 2.ֻʹ��n-1������ռ�*/
 
 /*
//˳��洢��ʽ
#define MaxSize 20
typedef int ElementType;
typedef struct Queue* Queue;
typedef struct Queue {
	ElementType Data[MaxSize];
	int front;
	int rear;
}QNode;
//Queue CreatQueue(int MaxSize); //:���ɳ���ΪMaxSize�Ŀն���;
//int IsFulIQ(Queue Q, int MaxSize); //:�ж϶���Q�Ƿ�����;
void AddQ(Queue Q, ElementType item);// :������Ԫ��item�������Q��;
int IsEmptyQ(Queue Q);// :�ж϶���Q�Ƿ�Ϊ��;
ElementType DeleteQ(Queue Q);// :����ͷ����Ԫ�شӶ�����ɾ�������ء�


void AddQ(Queue PtrQ, ElementType item)
{
	if ((PtrQ->rear + 1) % MaxSize == PtrQ->front) {
		printf("Queue is full");
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue PtrQ)
{
	if (PtrQ->front == PtrQ->rear)
	{
		printf("empty"); return;
	}
	else {
		PtrQ->front = (PtrQ->front + 1) % MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
}

void Myprintf(Queue Q)
{
	if (Q->front == Q->rear) {
		printf("Queue is empty");
		return;
	}
	int i = Q->front+1;
	while (i != Q->rear+1) { // ��iָ���βʱֹͣ����
		printf("%d ", Q->Data[i]); // �������Ԫ��
		i = (i + 1) % MaxSize; // ��i����һλ
	}
	printf("\n");
}

int main()
{
	Queue PtrQ=(Queue)malloc(sizeof(QNode));
	PtrQ->front = 0;
	PtrQ->rear = 0;
	int x;
	while (1)
	{
		scanf("%d", &x);
		if (x == 0) {
			break;
		}
		AddQ(PtrQ, x);
	}

	printf("�Ƿ�Ҫ����");
	scanf("%d", &x);
	if (x == 1)
	{
		DeleteQ(PtrQ);
	}

	Myprintf(PtrQ);

	return 0;
}

*/



//��ʽ�洢
//ͬ����frontֻ���ڱ�ͷ����rearҲֻ����β�ͣ���Ϊβ���������ף�����ɾ����
typedef int ElementType;
typedef struct QNode* Queue;

typedef struct Node {
	ElementType Data;
	struct Node* Next;
}Node;

typedef struct QNode {
	Node* rear;
	Node* front;
}QNode;


Queue init_queque()
{
	Queue Q=(Queue)malloc(sizeof(QNode));
	Q->front = Q->rear = NULL;
	return Q;
}

int is_empty(Queue Q)
{
	return Q->front == NULL;
}

void AddQ(Queue Q, ElementType x)
{
	Node* new = (Node*)malloc(sizeof(Node));
	if (!new) {
		printf("�ڴ����ʧ��"); return;
	}
	new->Data = x;
	new->Next = NULL;
	if (is_empty(Q)) {
		Q->front=Q->rear = new;
	}
	else {
		Q->rear->Next = new;
		Q->rear = new;
	}
}

int DeleteQ(Queue Q)
{
	ElementType FrontELem;
	if (is_empty(Q)) {
		printf("empty");
		return 0;
	}
	Node* FrontCell = Q->front;
	if (Q->front == Q->rear) {
		Q->front = Q->rear = NULL;
	}
	else {
		Q->front = Q->front->Next;
		
	}
	FrontELem = FrontCell->Data;
	free(FrontCell);
	return FrontELem;
}


void Myprintf(Queue Q)
{
	if (is_empty(Q)) {
		printf("empty");
		return;
	}
	while (Q->front)
	{
		printf("%d  ", Q->front->Data);
		Q->front = Q->front->Next;
	}
}
int main()
{
	Queue Q = init_queque();

	//if (is_empty(Q)) printf("empty\n");


	int x;
	while (1) {
		scanf("%d", &x);
		if (x == 0) break;
		AddQ(Q, x);
	}

	printf("�Ƿ�Ҫ����");
	scanf("%d", &x);
	if (x == 1) DeleteQ(Q);

	Myprintf(Q);
	return 0;
}