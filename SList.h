#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SListNode;

SListNode* CreateSSListNode(SListDataType value); // 创建结点
void SListPrint(SListNode* phead); // 打印
void SListPushBack(SListNode** pphead, SListDataType value); // 尾插
void SListPopBack(SListNode** pphead); // 尾删
void SListPushFront(SListNode** pphead, SListDataType value); // 头插
void SListPopFront(SListNode** pphead); // 头删
SListNode* SListFind(SListNode* plist, SListDataType x); // 单链表查找
void SListInsertAfter(SListNode* pos, SListDataType x); // 单链表在pos位置之后插入x
void SListEraseAfter(SListNode* pos); // 删除pos位置之后的结点