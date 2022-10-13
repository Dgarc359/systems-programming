# Linked Lists

(a) Given the following structure, write a C function with signature node* construct_list(int arr[], int len) that makes a linked list of elements stored in an array (called arr) with length len.



```C
#include <stdio.h>
struct node{

    int value;

    struct node* next;

};

typedef struct node node;

node* construct_list(int arr[], int len) {
  // if len(0) return ;
  node* head = (node*) malloc(sizeof(node));
  head -> value = arr[0];
  head -> next = NULL;
  if len(0)
    return head;
  else
    for (int i = 1; i < len; i++)
      append(&head, arr[i]);
}

void append(node** head, int value) { // assume list is not empty
  if((*head) == NULL) {
    (*head) = (node*) malloc(sizeof(node));
    (*head) -> value = value;
    (*head) -> next = NULL;
    return;
  }
  while((*head) -> next) {
    (*head) = (*head) -> next;
  }
  (*head) -> next = (node*) malloc(sizeof(node));
  (*head) -> next -> value = value;
  (*head) -> next -> next = NULL;
}

int main() {
  // empty linked list
  node * head = NULL;

  // LL size 1 containing 1 elem of value 10
  node * head = (node*) malloc(sizeof(node));
  head -> value = 10;
  head -> next = NULL;

  // append 15 to previous list
  // append(head, 15);
  append(&head, 15); // pass by ref
}
```

(b) Write a C function with signature void reverse(node* list) that reverses a given linked list.
```C

```

## Teacher Solution
```C
char* to_str(node* head) {
  if (head == NULL)
    return "";
  if(head -> next == NULL) {
    char* rv = (char*) malloc(11); // biggest int takes 10 chars + 1 for '\0'
    sprintf(rv, "%d", head -> value);
    return rv;
  }
  
  char* rest = to_str(head -> next);
  char* rv = (char*) malloc(13 /* size of rv + -> (2 chars) */ + strlen(rest));
  sprintf(rv, "%d->%s", head -> value, rest);
  return rv;
}

main() {
  head = (node*) malloc(sizeof(node));
  int value = 1;
  for(node* temp = head; value <= 5; value++) {
    temp -> value = value;
    temp -> next = (value == 5)
      ? NULL 
      : (node*) malloc (sizeof(node));
    temp = temp -> next;
    
  }
  prinft("%s", to_str(head));
  // head -> value = 1;
  // head -> next = (node*) malloc(sizeof(node));
  // head -> next -> value = 2;
}

node* construct_list(int arr[], int len) {
  node* head = (node*) malloc(sizeof(node));
  for(node* temp = head, i = 0; i < len, i++, temp = temp -> next) {
    temp -> value = arr[i];
    temp -> next = ((i == len - 1) ? null : (node*) malloc(sizeof(node)));
    temp = temp -> next;
  }
  return head;
}
```

2nd question
2 pointers, previous, current,switch current to refer to previous
