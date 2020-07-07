#include "list.h"
#include "common.h"

#include <stdio.h>


/*
 * 递归方式：
 * https://zhuanlan.zhihu.com/p/86745433
 */
Node* reverse_list (Node *head) {
    if (head->next == NULL) return head;
    Node* last = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

/*
 * 双指针方式:
 * https://zhuanlan.zhihu.com/p/75576160
 */
Node* reverse_list2 (Node *head) {
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
    Node* head = create_list(10);
    printf("Before list_reverse\n");
    print_list(head);
    head = reverse_list2(head);
    printf("After list_reverse\n");
    print_list(head);
    destroy_list(head);

    return 0;
}
