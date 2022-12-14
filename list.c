/*
// list/list.c
// 
// Implementation for linked list.
//
// worked with 

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_alloc() { 
  list_t* list = (list_t*)malloc(sizeof(list_t));
  list -> head = NULL;
  return list; 
}

node_t *node_alloc(elem value){
  node_t *node = (node_t*)malloc(sizeof(node_t));
  node -> value = value;
  node -> next = NULL;
  return node;
}

void node_free(node_t *n){
  free(n);
}

void list_free(list_t *l) {
  node_t *cur = l -> head;
  node_t *temp;
  if (l -> head != NULL){
    while (cur != NULL){
        temp = cur -> next;
        node_free(cur);
        cur = temp;
    }
  }
  free(l);
}

void list_print(list_t *l) {
  node_t* curr = l->head;
  if (curr == NULL){
    printf("Empty list\n");
    return;
  }
  else{
    while (curr != NULL){
      printf("%d ", curr->value);
      curr = curr->next;
    }
    printf("\n");
  }
}
int list_length(list_t *l) {
  if (l == NULL){
    printf("Empty list");
    return;
  }
  int count = 0;
  node_t* curr = l->head;
  if (curr == NULL){
    printf("Empty list\n");
    return;
  }
  while (curr != NULL){
    count++;
    curr = curr-> next;
  }
  return count;

}

void list_add_to_front(list_t *l, elem value) {
  node_t* new_node;
  node_t* curr = l->head;
  new_node = node_alloc(value);
  new_node -> next = curr;
  l -> head = new_node;
}

void list_add_to_back(list_t *l, elem value) {
  node_t* new_node;
  node_t* curr = l -> head;
  new_node = node_alloc(value);
  while (curr -> next != NULL){
    curr = curr -> next;
  }
  curr -> next = new_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
  node_t* new_node;
  node_t* curr = l -> head;
  new_node = node_alloc(value);
  if (curr == NULL){
    l -> head = new_node;
  }
  else{
    int count = 1;
    while (curr != NULL && count < index){
      curr = curr -> next;
      count ++;
    }
    if (count < index){
      list_add_to_back(l, value);
    }
    else{
      new_node -> next = curr -> next;
      curr -> next = new_node;
    }
  }
}


elem list_remove_from_back(list_t *l) {
  node_t* curr = l -> head;
  if (curr == NULL){
    printf("Empty list\n");
    return;
  }
  else if (curr -> next == NULL){
    node_t* temp = curr;
    curr = NULL;
    return temp -> value;
  }
  node_t* prev = NULL;
  while (curr -> next != NULL){
    prev = curr;
    curr = curr -> next;
  }
  prev -> next = NULL;
  return curr -> value;
  
  }
elem list_remove_from_front(list_t *l) { 
  node_t *curr = l -> head;
  if (curr == NULL){
    printf("Empty list\n");
    return;
  }
  node_t* head = l -> head;
  l -> head = head -> next;
  return head -> value;
}
elem list_remove_at_index(list_t *l, int index) {
  node_t* curr = l -> head;
  if (curr == NULL){
    printf("Empty list");
    return;
  }
  else if (index == 0){
    node_t* head = l -> head;
    l -> head = head -> next;
    return head -> value;
  }
  else{
    node_t* prev;
    int count = 0;
    while (curr != NULL && count < index){
      prev = curr;
      curr = curr -> next;
      count = count + 1;
    }
    prev -> next = prev -> next -> next;
    return curr -> value;   
  }
  }

bool list_is_in(list_t *l, elem value) { 
  node_t* curr = l->head;
  if (curr == NULL){
    printf("Empty list");
    return;
  }
  while (curr != NULL){
    if (curr->value == value){
      return true;
    }
    curr = curr -> next;
  }
  return false; 
}
elem list_get_elem_at(list_t *l, int index) { 
  node_t* curr = l->head;
  if (curr == NULL){
    printf("Empty list");
    return;
  }
  int count = 0;
  if (count == index){
    return curr -> value;
  }
  while (curr != NULL){
    if (count == index){
      return curr -> value; 
    }
    count++;
    curr = curr->next;
  }
  return -1;
}
int list_get_index_of(list_t *l, elem value) {
  if (l == NULL){
    printf("Empty list");
    return;
  }
  node_t* curr = l->head;
  if (curr == NULL){
    printf("Empty list");
    return;
  }
  int count = 0;
  while (curr !=NULL){
    if (curr -> value == value){
      return count;
    }
    count++;
    curr = curr -> next;
  }
  return -1; 
}