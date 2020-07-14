#include "list.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * 递归方式：
 * https://zhuanlan.zhihu.com/p/86745433
 */
Node* list_reverse_recursive (Node *head) {
    if (head->next == NULL) return head;
    Node* last = list_reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return last;
}

/*
 * 双指针方式:
 * https://zhuanlan.zhihu.com/p/75576160
 */
Node* list_reverse (Node *head) {
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


static void __list_reverse (Node** begin, Node** end) {
    Node* listBegin = *begin;
    Node* listEnd = *end;
    if(listBegin->next == NULL || *end == NULL || listBegin->next == listEnd)
        return;
    Node* reserveEnd = listBegin->next;
    while(listBegin->next != listEnd)
    {
        Node* tmp = listBegin->next;
        listBegin->next = reserveEnd->next;
        reserveEnd->next = reserveEnd->next->next; 
        listBegin->next->next = tmp;
    }
}

/*
 * 每隔n个元素反转, 比如链表1→2→3→4→5→6:
 * 若k=2，翻转后2→1→4→3→6→5，
 * 若k=3, 翻转后3→2→1→6→5→4，
 * 若k=4，翻转后4→3→2→1→5→6。
 *
 * Ref: https://blog.csdn.net/qq_17550379/article/details/80696835
 */
Node* list_reverse_every_nx (Node *head, unsigned int n) {
    Node* listHead = malloc(sizeof(Node));
    listHead->data = -1;
    listHead->next = head;

    Node* begin = NULL;
    Node* end = NULL;
    Node* cur = listHead;

    while (cur != NULL) {
        unsigned int k = n;
        begin = cur;
        //begin->next为翻转后的末尾值
        Node* reserveEnd = begin->next;
        while(cur != NULL &&  k > 0)
        {
            cur = cur->next;
            --k;
        }
        end = cur;

        __list_reverse(&begin, &end);
        if(cur != NULL)
            cur = reserveEnd;
    }

    Node* retNode = listHead->next;
    free(listHead);
    return retNode;
}

/*
 * K 个一组翻转链表
 */

/*
 * 链表部分翻转(从第m个至第n个)
 */

int main () {
    Node* head = list_create(10);
    printf("Before list_reverse\n");
    list_print(head);
    head = list_reverse_every_nx(head, 2);
    printf("After list_reverse\n");
    list_print(head);
    list_destroy(head);

    return 0;
}
