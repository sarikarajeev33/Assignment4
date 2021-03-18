#ifndef CARDLIST_H
#define CARDLIST_H

#include "card.h"

typedef struct node_s{
  Card data;
  struct node_s* next;
} Node;

typedef struct list_s{
  Node* head;
  Node* tail;
} List;

List create_list();
int add_start(List *list, Card new_card);
int add_end(List *list, Card new_card);
Card list_find(List list, Card needle);
void list_delete(List *list, Card to_delete);
void free_list(List *list);
void print_list(List list);

#endif
