#ifndef _ALG_LIST_COMMON_H
#define _ALG_LIST_COMMON_H

#include "list.h"

extern Node*    list_create (unsigned int n);
extern void     list_destroy (Node* head);
extern void     list_print (Node* head);

#endif
