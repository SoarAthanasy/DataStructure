#include "SeqList.h"

void SeqListInit(SeqList* ps) { // 初始化
	ps->Array = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->Array == NULL) { printf("申请内存失败\n");  exit(-1); }
	ps->size = 0;   ps->capacity = 4;
}

void SeqListDestory(SeqList* ps) { // 销毁
	free(ps->Array);  ps->Array = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps) { // 打印
	assert(ps);
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->Array[i]);
	}   printf("\n");
}

void SeqListCheckCapacity(SeqList* ps) { // 检查是否应该扩容
	if (ps->size >= ps->capacity) {
		ps->capacity *= 2;
		ps->Array = (SLDataType*)realloc(ps->Array, sizeof(SLDataType) * ps->capacity);
		if (ps->Array == NULL) { printf("增容失败\n");  exit(-1); }
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x) { // 尾插
	SeqListInsert(ps, ps->size, x);
} // 增容倍数要合适：增大了容易造成浪费，增小了容易造成频繁增容

void SeqListPopBack(SeqList* ps) { // 尾删
	SeqListErase(ps, ps->size - 1);
}

void SeqListPushFront(SeqList* ps, SLDataType x) { // 头插
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps) { // 头删
	SeqListErase(ps, 0);
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x) { // 任意位置插入
	assert(ps);  assert(pos >= 0 && pos <= ps->size);
	int end = ps->size - 1;   SeqListCheckCapacity(ps);
	while (end >= pos) {
		ps->Array[end + 1] = ps->Array[end];
		end--;
	}   ps->Array[pos] = x;  ps->size++;
}

void SeqListErase(SeqList* ps, int pos) { // 任意位置删除
	assert(ps);   assert(pos >= 0 && pos < ps->size);
	int end = ps->size - 1;   int cur = pos;
	while (cur < end) {
		ps->Array[cur] = ps->Array[cur + 1];
		cur++;
	}   ps->Array[end] = 0;  ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType target) { // 顺序表查找
	assert(ps);  int end = ps->size - 1;  int pos = 0;
	for (; pos <= end; pos++) {
		if (ps->Array[pos] == target) {
			printf("顺序表中找到元素%d，位序为%d\n", target, pos);
			return pos;
		}
	}   printf("顺序表中未找到元素%d\n", target);   return -1;
}

void SeqListSort(SeqList* ps) { // 顺序表排序
	assert(ps);   int end = ps->size - 1;
	for (int i = end; i >= 0; i--) {
		int ifexchange = 0;
		for (int j = 0; j < i; j++) {
			if (ps->Array[i] < ps->Array[j]) {
				int temp = ps->Array[i];
				ps->Array[i] = ps->Array[j];
				ps->Array[j] = temp;
				ifexchange = 1;
			}
		}
		if (ifexchange == 0)  return;
	}
}

// 顺序表二分查找
int SeqListBinaryFind(SeqList* ps, SLDataType target) {
	assert(ps);   SeqListSort(ps);
	int left = 0;  int right = ps->size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (ps->Array[mid] > target) { right = mid - 1; }
		else if (ps->Array[mid] < target) { left = mid + 1; }
		else {
			printf("顺序表中二分查找到元素%d，位序为%d\n", target, mid);
			return mid;
		}
	}   printf("顺序表中未二分查找到元素%d\n", target);  return -1;
}
