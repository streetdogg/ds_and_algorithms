// Uses GPL v3 license

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node{
  int data;
  struct __node* next;
} node;

void add_to_list(node **head) {
  node *temp_node;

  temp_node = (node *) malloc (sizeof(node));
  temp_node->next = *head;

  printf("Enter the value to add to the list: ");
  scanf("%d", &temp_node->data);
  
  *head = temp_node;
}

void print_list(node *head) {
  if (!head)
    return;
  printf("%d -> ", head->data);
  print_list(head->next);
}

node *reverse_list(node *cur, node **head) {
  node *temp;
  int  original_head = 0;

  if (cur == *head)
    original_head = 1;

  if (!cur->next) {
    *head = cur;
    return cur;
  }

  temp = reverse_list(cur->next, head);
  temp->next = cur;

  if (original_head) {
    cur->next = NULL;
    return *head;
  }

  return cur; 
}

void clean_up(node *head) {
  if (!head)
    return;
  clean_up(head->next);
  free(head);
}

void main(){
  int choice;
  node *head = NULL;

  do {
    printf("0: Add data, 1: Prints the list, 2: Reverses list, >2: Cleans memory and exits\nchoose: ");
    scanf("%d", &choice);

    switch(choice) {
      case 0:
        add_to_list(&head);
        break;

      case 1:
        print_list(head);
        break;

      case 2:
        head = reverse_list(head, &head);
        break;

      default:
        clean_up(head);
        return;
    }
  } while (1);
}