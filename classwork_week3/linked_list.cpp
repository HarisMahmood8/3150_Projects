#include <iostream>

#include "linked_list.h"


struct node * build_linked_list(int elements) {
  int k = 0;
  struct node * linked_list = new node;
  struct node * root = linked_list;
  
  for( int i = 0; i < elements; i++) {
    linked_list->number = k++;
    linked_list->next = new node;
    linked_list = linked_list->next;
    linked_list->jumper = linked_list->next;    
  }

  linked_list->next = linked_list;
  linked_list->jumper = linked_list;
  
  return root;
}


struct node * pointer_jump_linked_list(struct node * linked_list, int elements) {
  int k = 0;
  struct node * root = linked_list;
  
  for( int i = 0; i < elements; i++) {
    linked_list->jumper = linked_list->next->next;
    linked_list->next = linked_list->next->next;    
    //linked_list = traverse_elt->next;
  }

  return root;
}


struct node * array_ptrs_to_each_element_in_linked_list(struct node * origional_list, int elements) {
  int k = 0;
  struct node * array_of_elts_linked_list = new node[elements];
  struct node * root = array_of_elts_linked_list;
  
  for( int i = 0; i < elements; i++) {
    array_of_elts_linked_list[i].number = origional_list->number;
    array_of_elts_linked_list[i].next = origional_list->next;    
    origional_list = origional_list->next;
  }

  return root;
}


int sum_values_in_linked_list(struct node * list, int elements) {

  int sum = 0;
  
  struct node * my_node = list;
  for (int i =0; i < elements; i++) {
    sum += my_node->number;
    my_node = my_node->next;
  }

  return sum;
}


void print_linked_list(struct node * list, int elements) {
  using namespace std;
  
  struct node * my_node = list;
  for (int i =0; i < elements; i++) {
    cout << my_node->number << " " << endl;
    my_node = my_node->next;
  }
}

int delete_linked_list(struct node * list, int elements) {
  int count = 0;
  
  struct node * my_node = list;
  for (int i =0; i < elements; i++) {
    struct node * prev_node = my_node;
    my_node = my_node->next;

    delete prev_node;
    count++;
  }

  return count;
}
  
