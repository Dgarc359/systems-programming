# Class Activity 17
Given dict.txt containing the list of English words sorted alphabetically, write a multithreaded program that

A. spawns 10 threads so that:
  1. each thread randomly chooses 10 words
  2. and add those words into a central hash table storing words

B. joins all 10 threads

C. spawns 5 new threads so that:
  1. each thread removes 20 words from the central hash table
  2. and prints them on the screen


# PA4
Main thread
1. read dict.txt & store it in an arr words (# of words: N)
2. spawns `n` producers
  2.1 producer #i needs to transfer words [ iN / n ... ((i + 1) N / n) - 1]
3. joins all producers
4. spawn in consumers
  4.1 consumer #i generates K/m passwords by:
    4.1.1 removing l random words from the central hash table
    4.1.2 produce password by concatenating all words into one 
5. Joins all consumers

# Ch.8 Unix System Interface
## Goals
* Learning I/O sys calls
* Learning sys calls related to File System
* Learning sys calls for storage allocation

## File Descriptors in Unix
* File descriptor 0 is reserved for STD_IN (file* stdin)
* File descriptor 1 is reserverd for STD_OUT (file* stdout)
* File descriptor 2 is reserved for STD_ERR (file* stderr)

## Low level I/O - R&W
### methods
* read(int fdm char* buf, int n) -- transfer data up to n bytes from fd to buf
* write(int fd, char* buf, int n) -- transfer data up to n bytes from buf to fd
* open()

```c
#include "syscalls.h"

main() {
  char buf[BUFSIZE];
  int n;

  while((n = read(0, buf, BUFSIZE)) > 0)
    write(1, buf, n);
  return 0;
}
```

1000 char x 1000 line arr
crossword puzzle, chunk the file, with some overlaps between the squares

# Notable methods
* fopen
* fclose
* fscanf
* fgets

