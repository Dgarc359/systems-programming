# Synchronization / Mutex Locks and Hash Tables

## Basic thread Synchronization

```c
amount = 10000;
void deposit(x) {
  amount += x;
}

void withdraw(y) {
  amount -= y;
}

void jason(void* arg) {
  deposit(1000);
}

void jasonsWife(void* arg) {
  withdraw(200);
}

pthread_create(&t0, NULL, jason, 0);
pthread_create(&t1, NULL, jasonswife, 0);
```

```C
#include <stdio.h>
#include <pthread.h>
int balance = 10000;

void* deposit(void* args) {
  balance += (int) args;
}

void* withdraw(void* args) {
  balance -= (int) args;
}

int main(void) {
  pthread_t t[2];
  printf("Initial Balance: %d\n", balance)
  pthread_create(t, NULL, deposit, (void*) 1000);
  pthread_create(t + 1, NULL, withdraw, (void*) 200);

  pthread_join(t[0], NULL);
  pthread_join(t[1], NULL);
  printf("Final Balance: %d\n", balance);
  return 0;
}
```

pthread can switch contexts between deposit / withdraw threads in the middle of the execution of a thread. We can avoid accessing shared resources by creating a Locks

## Race Conditions
* Read + Read: no problem
* Read + Write: no problem, Read result depends on ordering (app semantics)
* Write + Write: uh oh
* Multiple Writes: Result will b non-deterministic

## Mutex

```c
pthread_mutex_t mutex;
int pthread_mutex_init(pthread_mutex_t* mutex, pthread_mutexattr_t* att);
int pthread_mutex_destroy(pthread_mutex_t* mutex); // free space of mutex lock
```

## Locking / Unlocking

```C
int pthread_mutex_lock(pthread_mutex_t* mutex);
int pthread_mutex_unlock(pthread_mutex_t* mutex);
int pthread_mutex_trylock(pthread_mutex_t* mutex);
```

* lock routine is used by a thread to acquire a lock on the specified mutex var. The thread blocks if the mutex is already locked by another thread.
* unlock will unlock a mutex; must be called by owning thread
* trylock will attempt to lock a mutex. However, if mutex is already locked, the routine will return immediately with a 'busy' error code.


Hash Tables
```c
struct nlist { // table entry
  struct nlist *next; // next entry in chain
  char* name; // defined name
  char* defn; // replacement text
}

#define HASHSIZE 101
static struct nlist* hashtab[HASHSIZE]; // pointer table

// hash: form has value for string s
unsigned hash(char* s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE; // remainder of unsigned num by some other num is always less than HASHSIZE
}

struct nlist* lookup(char* s) {
  struct nlist *np ;

  for (np = hashtab[hash(s)]; np != NULL; np = np -> next)
    if (strcmp(s, np -> name) == 0)
      return np; // found
  return NULL; // not found
}

// install: put name, defn in hashtab
struct nlist* install(char* name, char* defn) {
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name)) == NULL) { // not found
    np = (struct nlist*) malloc(sizeof(*np));
    if(np == NULL || (np -> name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
  }
}
```


## Hashset
only keys, no vals
```C
#define HASH_SIZE 101
#include <stdio.h>
#include <string.h>
struct node {
  char* key;
  struct node* next; // ptr to next node
}

typedef struct node node;
node hashtable[HASH_SIZE];
unsigned hash(char* key) {
  unsigned hashval = 0;
  
}

int search(char* target) {

};

int 
```

