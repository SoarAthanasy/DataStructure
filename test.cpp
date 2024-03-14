#include "SList.cpp"

struct SListNode* reverse(struct SListNode* head) {
    struct SListNode* newhead = NULL;
    struct SListNode* fast = head;
    struct SListNode* slow = NULL;
    while (fast) {
        slow = fast;
        fast = fast->next;
        slow->next = newhead;
        newhead = slow;
    }   return newhead;
}

bool isPalindrome(struct SListNode* head) {
    if (!head || !(head->next)) return true;
    struct SListNode* fast = head;   struct SListNode* slow = head;
    while (fast && fast->next) {
        slow = slow->next;   fast = fast->next->next;
    }
    struct SListNode* newhead = reverse(slow);
    struct SListNode* p2 = newhead;   struct SListNode* p1 = head;
    struct SListNode* list1Tail = NULL;
    while (p1 && p2) {
        if (p1->data != p2->data) { return false; }
        p1 = p1->next;  p2 = p2->next;
    }   reverse(newhead);
    return true;
}

void TestSList() {
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);  SListPushBack(&pList, 2);  SListPushBack(&pList, 5);  SListPushBack(&pList, 2);  SListPushBack(&pList, 1);
	SListPrint(pList);
    if (isPalindrome(pList)) { printf("是回文链表\n"); }
    SListPrint(pList);
}

int main() {
	TestSList();
    system("pause");
}