#include "common.h"

#include <stdio.h>
#include <stdlib.h>

Node* create_list (unsigned int n) {
    Node* head = NULL;
    Node* tail = NULL;

    for (unsigned int i = 1; i<=n; i++) {
        Node* d = (Node*)malloc(sizeof(Node));
        d->data = i;
        d->next = NULL;

        if (head == NULL) head = d;
        if (tail == NULL) tail = d;

        tail->next = d;
        tail = d;
    }

    return head;
}

void destroy_list (Node* head) {
    while (head != NULL) {
        Node* next = head->next;
        free (head);
        head = next;
    }
}

void print_list(Node* head) {
    printf("[");
    while (head != NULL) {
        if(head->next == NULL) printf("%d", head->data);
        else printf("%d, ", head->data);
        head = head->next;
    }
    printf("]\n");
}

#if 0
int main () {
    Node* h = create_list(10);
    print_list(h);
    destroy_list(h);
}
#endif
