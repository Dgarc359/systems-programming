# 10-13

Reverse Linked List
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
  char* rv = (char*) malloc(13 /* size of rv(10 chars + 1 for '\0') + -> (2 chars) */ + strlen(rest));
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
void reverse_and_update(node** head_ptr) {
  if (*head_ptr == NUll || HEAD -> NEXT == NULL)
    return;
  node* prev;
  node* cur;
  node* next;
  for(prev = *head_ptr, cur = head -> next; cur != NULL; prev = cur, cur = next) {
    next = cur -> next;
    cur -> next = prev;
  }
  (*head_ptr) -> next = NULL;
  *head_ptr = prev;
  return;
    // printf("pref: %d, cur: %d\n", prev -> value, cur -> value);
}

node* reverse(node* head) {
  if (head == NUll || HEAD -> NEXT == NULL)
    return head;
  node* prev;
  node* cur;
  node* next;
  for(prev = head, cur = head -> next; cur != NULL; prev = cur, cur = next) {
    next = cur -> next;
    cur -> next = prev;
  }
  head -> next = NULL;
  return prev;
    // printf("pref: %d, cur: %d\n", prev -> value, cur -> value);
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

Binary Trees

```C
#include <stdio.h>
#include <stdlib.h>
struct t_node {
  int value;
  struct t_node* left;
  struct t_node* right;
};
typedef struct t_node t_node;

// create tree of height 2, fill with values, print inorder

void in_order(t_node* root) {
  if(root == NULL)
    return;
  in_order(root -> left);
  printf(" %d ", root -> value);
  in_order(root -> right);
}

/**
 *      [1]
 *   [2]    [3]
 * [4][5]  [6][7]
 * 
 * */

int main() {
  t_node *root = (t_node*) malloc(sizeof(t_node));
  root -> value = 1;
  root -> left = (t_node*) malloc(sizeof(t_node));
  root -> right = (t_node*) malloc(sizeof(t_node));
  root -> left -> value = 2;
  root -> right -> value = 3;

  root -> left -> left = (t_node*) malloc(sizeof(t_node));
  root -> left -> right = (t_node*) malloc(sizeof(t_node));

  root -> left -> left -> value = 4;
  root -> left -> right -> value = 5;
  
  root -> right -> left -> value = 6;
  root -> right -> right -> value = 7;

  root -> left -> left -> left = NULL;
  root -> left -> left -> right = NULL;
  root -> left -> right -> left = NULL;
  root -> left -> right -> right = NULL;
  root -> right -> left -> left = NULL;
  root -> right -> left -> right = NULL;
  root -> right -> right -> left = NULL;
  root -> right -> right -> right = NULL;

  in_order(root);

}

```

## Class Activity
Write a C function that receives the root of a binary tree as its only input parameter and prints its members using post-order traversal.

The root is an instance of the following C structure:

struct t_node{

    int value;

    struct node* left;

    struct node* right;

};

typedef struct t_node t_node;

```C
#include <stdio.h>
#include <stdlib.h>
struct t_node {
  int value;
  struct t_node* left;
  struct t_node* right;
};
typedef struct t_node t_node;

// create tree of height 2, fill with values, print inorder

void post_order(t_node* root) {
  if(root == NULL)
    return;
  post_order(root -> right);
  printf(" %d ", root -> value);
  post_order(root -> left);
}

/**
 *      [1]
 *   [2]    [3]
 * [4][5]  [6][7]
 * 
 * */

int main() {
  t_node *root = (t_node*) malloc(sizeof(t_node));
  root -> value = 1;
  root -> left = (t_node*) malloc(sizeof(t_node));
  root -> right = (t_node*) malloc(sizeof(t_node));
  root -> left -> value = 2;
  root -> right -> value = 3;

  root -> left -> left = (t_node*) malloc(sizeof(t_node));
  root -> left -> right = (t_node*) malloc(sizeof(t_node));

  root -> left -> left -> value = 4;
  root -> left -> right -> value = 5;
  
  root -> right -> left -> value = 6;
  root -> right -> right -> value = 7;

  root -> left -> left -> left = NULL;
  root -> left -> left -> right = NULL;
  root -> left -> right -> left = NULL;
  root -> left -> right -> right = NULL;
  root -> right -> left -> left = NULL;
  root -> right -> left -> right = NULL;
  root -> right -> right -> left = NULL;
  root -> right -> right -> right = NULL;

  post_order(root);

}

```

## Enumerators
```C
enum CLAS {
    MATCH = 1,
    CASE = 2,
    PARTIAL = 4,
    REVERSE = 8,
    SORTED = 16
}

int flags = 0;
if (-m is in CLA) 
  flags |= MATCH;
if (-c in CLAS)
  flags |= CASE;
//...

if (flags & SORTED)
  my_qsort(/* ... */);


```
