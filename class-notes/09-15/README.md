# Gnu DeBugger (GDB)

-g flag in makefile allows you to run GDB

run gdb with

`gdb ./balance`

char str[15] = "hello world!";

if you say `str` it's a pointer pointing to the beginning of the array

# Call by value and call by reference
call by value: when you pass the params to a function, you get a copy of the value, so original values stay the same

call by reference: the object itself is passed and therefore that object can be changed as its passed around

```C

void swap (int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

main() {
  int a = 4;
  int b = 7;
  swap(a, b);
}

```

the above is naive, the only thing that happens is the values of x and y get changed and when the function goes out of scope, the values of x and y are garbage collected, a and b are never changed

to simulate call by reference, you need to pass addresses

```C
void swap (int* x, int* y) {
  int temp;
  temp = *x; // deref x
  *x = *y;
  *y = temp;
}

main () {
  int a = 5;
  int b = 7;
  swap(&a, &b);
}

```

```C
int add (int num1, int num2) {
  return num1 + num2;
}

int arithmetic (int num1, int num2, int* sum int* diff, int* prod, int* quo) {
  *sum = num1 + num2;
  *diff = num1 - num2;
  *prod = num1 * num2;
  if(num2 == 0)
    return 1; // error code
  *quo = num1 / num2;
  return 0;
}

struct info {
  int sum;
  int diff;
  int prod;
  int quo;
};

struct info arithmetic2(int num1, int num2) {
  struct info rv;
  rv.sum = num1 + num2;
  // ..
  return rv;
}
int main() {
  printf("%d\n", add(1,2));
  int sum, diff, prod, quo, num1 = 7, num2 = 5;
  if(!arithmetic(num1, num2, &sum, &diff,  &diff, &prod, &quo));
    print("%d+%d=%d, %d-%d=%d, %d*%d=%d, %d/%d=%d\n", num1, num2, sum, num1, num2, diff, num1, num2, prod, num1, num2, quo);
  else
    print("%d+%d=%d, %d-%d=%d, %d*%d=%d, %d/%d=NaN\n", num1, num2, sum, num1, num2, diff, num1, num2, prod, num1, num2);
    return 0; //no error
}

```

allocating memory using `malloc`, freeing memory using `free`

people don't like storing data in stack because when data goes out of scope it's gone

when you allocate memory in the heap, the program allows you store more an more data, you can allocate whenever you want and free whenever you want.

Heap keeps track of dynamic memory allocation that someone wants


```C
main () {
  // char str[5000];
  // char str[1000][5000]; // this creates 5MB of memory in the stack u can never get rid of, DO NOT DO THIS
  char* sentence[1000];
  for (int i = 0; i < 1000; i++) {
    get_line(str, 5000);
    sentence[i] = (char*) malloc ((1 + strlen(str)) *sizeof(char)); // add one for null at the end
    int j = 0;
    // while(sentence[i][j] = str[j])
    //   j++;
    strcpy(sentence[i], str);
  }
  for (int i = 0; i< 1000; i++)
    free(sentence[i]);
}
```