#include "SList.h"

SListNode* CreateSListNode(SListDataType value) { // 创建结点
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->data = value;  newnode->next = NULL;
	return newnode;
}

void SListPrint(SListNode* phead) { // 打印
	SListNode* cur = phead;
	while (cur != NULL) {
		printf("%d -> ", cur->data);
		cur = cur->next;
	}   printf("NULL\n");
}

void SListPushBack(SListNode** pphead, SListDataType value) { // 尾插
	SListNode* newnode = CreateSListNode(value);
	if ((*pphead) == NULL) { *pphead = newnode; }
	else {
		SListNode* Tail = *pphead;
		while (Tail->next != NULL) { Tail = Tail->next; }
		Tail->next = newnode;
	}
}

void SListPopBack(SListNode** pphead) { // 尾删
	if (*pphead == NULL) return; 
	else if ((*pphead)->next == NULL) { free(*pphead); *pphead = NULL; }
	else { // 1.空 | 2.一个结点 | 3.多个结点
		SListNode* prev = NULL;   SListNode* tail = *pphead;
		while (tail->next != NULL) { prev = tail;  tail = tail->next; }   
		free(tail->next);  prev->next = NULL;
	}
}

void SListPushFront(SListNode** pphead, SListDataType x) { // 头插
	SListNode* newnode = CreateSListNode(x);
	newnode->next = *pphead;  *pphead = newnode;
}
void SListPopFront(SListNode** pphead) { // 头删
	if (*pphead == NULL) return; // 1.空 | 2.一个结点 + 多个结点
	else { SListNode* cur = *pphead;   *pphead = cur->next;   free(cur); }
}

SListNode* SListFind(SListNode* phead, SListDataType x) { // 单链表查找
	SListNode* cur = phead;
	while (cur != NULL) {
		if (cur->data == x) { return cur; }
		cur = cur->next;
	}   return cur;
}

void SListInsertAfter(SListNode* pos, SListDataType x) { // 单链表在pos位置之后插入x
	assert(pos);   SListNode* newnode = CreateSListNode(x);
	newnode->next = pos->next;   pos->next = newnode;
}

void SListEraseAfter(SListNode* pos) { // 删除pos位置之后的结点
	assert(pos);
	if (pos->next) { 
		SListNode* Next = pos->next;  pos->next = Next->next;  free(Next);
	}
}