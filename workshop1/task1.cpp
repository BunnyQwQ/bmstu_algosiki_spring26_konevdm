#include  <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* searchIntersectionNode(ListNode* headA, ListNode* headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode* ptrA = headA;
    ListNode* ptrB = headB;
    while (ptrA != ptrB) {
        if (ptrA != NULL) {
            ptrA = ptrA->next;
        }
        else {
            ptrA = headB;
        }
        if (ptrB != NULL) {
            ptrB = ptrB->next;
        }
        else {
            ptrB = headA;
        }
    }
    return ptrA;
}


void printList(ListNode *head) {
    ListNode *current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

ListNode* createNode(int val) {
    return new ListNode(val);
}

void deleteIntersectionLists(ListNode* &headA, ListNode* &headB)
{
    if (!headA && !headB) return;

    // Находим пересечение
    ListNode* intersection = searchIntersectionNode(headA, headB);

    if (!intersection) {
        while (headA) {
            ListNode* temp = headA;
            headA = headA->next;
            delete temp;
        }
        while (headB) {
            ListNode* temp = headB;
            headB = headB->next;
            delete temp;
        }
        return;
    }

    // удаляем в обоих списках до пересечения и потом 1 само пересечение
    while (headA != intersection) {
        ListNode* temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB != intersection) {
        ListNode* temp = headB;
        headB = headB->next;
        delete temp;
    }
    while (intersection) {
        ListNode* temp = intersection;
        intersection = intersection->next;
        delete temp;
    }
    headA = nullptr;
    headB = nullptr;
}

int main() // простенький тест
{
    ListNode *common = createNode(8);
    common->next = createNode(4);
    common->next->next = createNode(5);

    ListNode *headA = createNode(4);
    headA->next = createNode(1);
    headA->next->next = common;

    ListNode *headB = createNode(5);
    headB->next = createNode(6);
    headB->next->next = createNode(1);
    headB->next->next->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    ListNode *intersection = searchIntersectionNode(headA, headB);

    cout << "Intersection val: " << intersection->val << endl;
    cout << "Intersection: " << intersection << endl;

    deleteIntersectionLists(headA, headB);

    return 0;
}
