#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

// 顺序表的有效数组在数组中必须连续
// 动态顺序表设计 ( 大小可变、常用 )
typedef int SLDataType; // 顺序表中元素的数据类型

typedef struct SeqList {
	SLDataType* Array;
	size_t size;     // 有效数据的个数
	size_t capacity; // 容量
}SeqList;

// 初始化
void SeqListInit(SeqList* ps);
// 销毁
void SeqListDestory(SeqList* ps);
// 打印
void SeqListPrint(SeqList* ps);
// 检查是否应该扩容
void SeqListCheckCapacity(SeqList* ps);
// 尾插
void SeqListPushBack(SeqList* ps, SLDataType x);
// 尾删
void SeqListPopBack(SeqList* ps);
// 头插
void SeqListPushFront(SeqList* ps, SLDataType x);
// 头删
void SeqListPopFront(SeqList* ps);
// 任意位置插入
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
// 任意位置删除
void SeqListErase(SeqList* ps, int pos);
// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType target);
// 顺序表排序
void SeqListSort(SeqList* ps);
// 顺序表二分查找
int SeqListBinaryFind(SeqList* ps, SLDataType target);
