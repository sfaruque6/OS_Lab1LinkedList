#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
  printf("Tests for linked list implementation\n");
  list_t* MyList;
  MyList = list_alloc();
  list_print(MyList);
  list_remove_from_back(MyList);
  list_remove_from_front(MyList);
  list_add_to_front(MyList, 10);
  list_add_to_front(MyList, 153);
  list_add_to_front(MyList, 14);
  list_add_to_front(MyList, 666);
  list_print(MyList);
  list_add_to_back(MyList, 23);
  list_print(MyList);
  list_add_at_index(MyList, 78, 2);
  list_print(MyList);
  list_add_at_index(MyList, 44, 100);
  list_print(MyList);
  list_remove_from_back(MyList);
  list_print(MyList);
  list_remove_from_front(MyList);
  list_print(MyList);
  list_remove_at_index(MyList, 2);
  list_print(MyList);
  bool val = list_is_in(MyList, 18);
  printf("%d\n", val);
  bool val2 = list_is_in(MyList, 10);
  printf("%d\n", val2);
  elem g = list_get_elem_at(MyList, 2);
  printf("%d\n", g);
  elem h = list_get_elem_at(MyList, 8);
  printf("%d\n", h);
  elem v = list_get_index_of(MyList, 14);
  printf("%d\n", v);
  elem w = list_get_index_of(MyList, 7);
  printf("%d\n", w);
  
  /*
  list_add_to_back(MyList, 2);
  list_print(MyList);
  int s = list_length(MyList);
  printf("Length of MyList is %d\n",s);
  list_print(MyList);
  */

  return 0;
}
