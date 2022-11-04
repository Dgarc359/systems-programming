# Intro to Posix Threads

pthreads are hardware independent libraries

## Shared memory model
processors or cores run code; they interact with each other through shared memory

in unix, each processes follow a parent-child model, meaning it can have multiple child processes

## What are Threads
an independent flow of control

Operates within a process with other Threads

ex of multithreading
- UI Threads
  - general program logic
- converting a filetype to another file type

concurrent: parallel in software
parallel: parallel in hardware

multithreading is beneficial because whenever a thread is busy with the CPU, other threads can be busy performing other sys calls, like file access / memory access / other resources, thus increasing utilization as much as possible. Managing threads introduces some overhead, so the performance of multi threading could look somewhat like a bell curve

context switch overhead
saving the registers of one processors
restoring the registers of another processors

- pthread.h
- libpthread.a
- -pthread flag for gcc

```c
int pthread_create(
  pthread_t *tid; /* thread id */
  const pthread_attr_t *attr; /* thread attributes */
  void* (*start_routine) (void *); /* function pointer */
  void* arg; /* argument for function */
)
```

returns 0 if successful; returns error number
set tid as the new thread's ID (opaque)
  - thread ID is useful because it helps identify which thread is which
the attr param is used to set thread attrs, NULL is default
start routine is the C routine that the thread will start executing once it is created. It's a function ptr
single arg may be passed to start_routine via arg. It must be a void* you can use a data structure if you want to pass multiple arguments

## Thread Termination
- thread returns from starting routine
- thread calls pthread_exit()
- thread is canceled by another thread via pthread_cancel()
- the thread receives signal to terminate
- entire process is terminated

## Thread termination and joining
`void pthread_exit (void * status)`
- This fn is used by a thread to terminate. the return value is passed as a ptr

`int pthread_join(pthread_t tid, void** status)`
- The pthread_join subroutine blocks the calling thread until the specific thread tid terminates
- the fn returns 0 on succes, negative on failure
- the returned value is a pointer

joining: when the main thread spawns 5 threads, and each thread completes, when the thread is done, it will join with all the threads

## Hello World multithreading
```c
#include <pthread.h>
#include <stdio.h>

void* PrintHello(void* id) {
  printf("Thread%d: Hello World!\n", (int) id);
  pthread_exit(NULL); // not necessary
}

int main(int argc, char* argv[]) {
  pthread_t thread0, thread1;
  pthread_create(&thread0, NULL, PrintHello, (void*) 0);
  pthread_create(&thread1, NULL, printHello, (void*) 1);
  pthread_join(thread0, NULL);
  pthread_join(thread1, NULL);
  return 0;
}
```
the output of these threads is not guaranteed to output hello world from thread 0

## Class Activity
Given dict.txt containing the list of English words sorted alphabetically, write a multithreaded program that gets a sentence and spell-checks all the words in the sentence concurrently (once word is spell-checked by a separate thread concurrently).
```C
#define MAX_WORDS 100000


char* Dictionary[MAX_WORDS];

void* spellCheck(void* word) {

}

int main(int argc, char* argv[]) {
  pthread_t thread0, thread1;
  pthread_create(&thread0, NULL, spellCheck, (void*) 0);
  pthread_create(&thread1, NULL, spellCheck, (void*) 1);
  pthread_join(thread0, NULL);
  pthread_join(thread1, NULL);
  return 0;
}

```


