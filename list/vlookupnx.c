#include "list.h"
#include "common.h"

#include <stdio.h>


/*
 * 双指针方式:
 */
Node* list_vlookup_nx (Node *head, unsigned int n) {
    Node* pre = head;
    Node* cur = head;

    for (unsigned int i=0; i<n; i++) {
        if (cur != NULL) cur = cur->next;
    }

    while (cur != NULL) {
        pre = pre->next;
        cur = cur->next;
    }

    return pre;
}

int main () {
    unsigned int nx = 7;
    Node* head = list_create(10);
    list_print(head);
    Node* res = list_vlookup_nx(head, nx);
    printf("nx=%d, data=%d\n", nx, res->data);
    list_destroy(head);

    return 0;
}
