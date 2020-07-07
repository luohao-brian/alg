#include "list.h"
#include "common.h"

#include <stdio.h>


/*
 * https://zhuanlan.zhihu.com/p/86745433
 */
Node* reverse_list (Node *head) {
    if (head->next == NULL) return head;
    Node* last = reverse_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}


int main () {
    Node* head = create_list(10);
    printf("Before list_reverse\n");
    print_list(head);
    head = reverse_list(head);
    printf("After list_reverse\n");
    print_list(head);
    destroy_list(head);

    return 0;
}
