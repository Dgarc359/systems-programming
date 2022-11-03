
```C
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum { INT, DOUBLE, STRING } type;
char* round_down(char* value, int n){
  char* rv;
  int point_index = 0;
  while(value[point_index] != '.' && value[point_index] != '\0')
    point_index++;
  rv = (char*) malloc(point_index + n + 2);
  for(int i = 0; i < point_index + n + 1;i++){
    if (i == point_index)
      rv[i] = '.';
    else if(i < strlen(value))
      rv[i] = value[i];
    else
      rv[i] = '0';
  }
  rv[point_index + n + 1] = '\0';
  return rv;
}
struct node{
  int val;
  struct node* next;
};
typedef struct node node;
void duplicate(node* head){
  if(head == NULL)//base case
    return;
  node* dup = (node*)malloc(sizeof(node));
  dup->val = head->val;
  dup->next = head->next;
  head->next = dup;
  duplicate(dup->next);
}
void duplicate2(node* head){
  node* temp;
  for(temp = head; temp != NULL; temp = temp->next->next){
    node* dup = (node*)malloc(sizeof(node)); 
    dup->val = temp->val;
    dup->next = temp->next;
    temp->next = dup;
  }
}
char* to_str(node* head){
  if(head == NULL)
    return "";
  char* delim = (head->next)?"->":"";
  char* out = (char*)malloc(100);
  sprintf(out, "%d%s%s",head->val, delim, to_str(head->next));
  return out;
}
char *normalizer(char *input) {
  char *output = (char *)malloc(26);
  double double_value;
  int int_value;
  type input_type = INT;
  int i = 0;
  if (input[0] == '-' || input[0] == '+')
    i++;
  for (; i < strlen(input); i++)
    if (!isdigit(input[i])) {
      input_type = DOUBLE;
      break;
    }
  if (input_type == INT)
    sscanf(input, "%d", &int_value);
  else {
    if (sscanf(input, "%lf", &double_value))
      input_type = DOUBLE;
    else
      input_type = STRING;
  }
  if (input_type == INT)
    sprintf(output, "%25x", int_value);
  else if (input_type == DOUBLE)
    sprintf(output, "%25e", double_value);
  else
    sprintf(output, "%25.5s", input);
  return output;
}

int main(void) {
  printf("%s\n", normalizer("12"));
  printf("%s\n", normalizer("12.32"));
  printf("%s\n", normalizer("Hello World!"));
  printf("%s\n", round_down("123.9876543", 12));
  node* head = (node*) malloc(sizeof(node));
  head->val = 1;
  head->next = (node*) malloc(sizeof(node));
  head->next->val = 2;
  head->next->next = (node*) malloc(sizeof(node));
  head->next->next->val = 3;
  head->next->next->next = NULL;
  printf("%s\n", to_str(head));
  duplicate2(head);
  printf("%s\n", to_str(head));
  duplicate2(head);
  printf("%s\n", to_str(head));
  return 0;
}
```
