#include "list.h"
#include "common.h"

#include <stdio.h>


/*
 * 递归方式：
 * https://zhuanlan.zhihu.com/p/86745433
 */
Node* list_reverse (Node *head) {
    if (head->next == NULL) return head;
    Node* last = list_reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

/*
 * 双指针方式:
 * https://zhuanlan.zhihu.com/p/75576160
 */
Node* list_reverse2 (Node *head) {
    Node* pre = NULL;
    Node* cur = head;

    while (cur != NULL) {
        Node* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}

int main () {
    Node* head = list_create(10);
    printf("Before list_reverse\n");
    list_print(head);
    head = list_reverse2(head);
    printf("After list_reverse\n");
    list_print(head);
    list_destroy(head);

    return 0;
}
