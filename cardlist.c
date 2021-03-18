#include <stdlib.h>
#include <stdio.h>

#include "card.h"
#include "cardlist.h"
#include "heapmgr.h"

List create_list(){

  List new_list;
  new_list.head=NULL;
  new_list.tail=NULL;

  return new_list;
}

static Node* create_node(Card new_card, Node *next){
  Node *new_node = (Node *) my_malloc(sizeof(Node));
  if (new_node == NULL){
    perror("malloc");
    return NULL;
  }

  new_node->data=new_card;
  new_node->next=next;
  return new_node;
}

int add_start(List *list, Card new_card){

  list->head = create_node(new_card,list->head);
  if (list->head == NULL){
    return 0;
  }

  if (list->tail == NULL){
    list->tail = list->head;
  }

  return 1;
}

int add_end(List *list, Card new_card){

  Node *new_node = create_node(new_card,NULL);  

  if(new_node == NULL){
    return 0;
  }

  if (list->tail == NULL){
    list->tail = new_node;
    list->head = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }

  return 1;
}

Card list_find(List list, Card needle){
  
  for( Node *curr=list.head; curr != NULL; curr = curr->next){
    if(card_compare(curr->data,needle)==0){
      return curr->data;
    }
  }
  
  return INVALID_CARD;
}

void list_delete(List *list, Card needle){

  Node *prev=NULL;
  Node *curr;

  for( curr=list->head; curr != NULL; curr = curr->next){
    
    if(card_compare(curr->data,needle)==0){
      break;
    }
    prev = curr;
  }

  if (curr == NULL){
    return;
  }

  if (prev == NULL){
    list->head = curr->next;
    prev=list->head;
  } else {
    prev->next = curr->next;
  }

  if (prev == NULL || prev->next == NULL){
    list->tail = prev;
  }

  my_free(curr);
  
}

void free_list(List *list){
  Node *prev=NULL;
  
  for( Node *curr=list->head; curr != NULL; curr = curr->next){
    my_free(prev);
    prev = curr;
  }

  my_free(prev);

}

void print_list(List list){
  
  for( Node *curr=list.head; curr != NULL; curr = curr->next){
    card_print(curr->data);
    printf(",");
  }


}
