# Standard IO

using '<' for input redirection

ex
```C
#include <stdio.h>
#include <ctype.h>
int main(int argc, char** argv) {
  char c;
  while((c = getchar()) != EOF) {
    putchar(c);
  }
}
```

uppercase
```C
#include <stdio.h>
#include <ctype.h>
int main(int argc, char** argv) {
  char c;
  while((c = getchar()) != EOF) {
    putchar(toupper(c));
  }
}
```

Redirecting input output
```bash
./p1 > file.txt # redirect output
./p2 < file.txt # redirect input
```

Pipe to next binary call
```bash
./p1 | ./p2 # pass stdout of p1 to p2
```

fscanf - scan a file
sscanf - scan a string
scanf - read chars from stdin

```C
int m, d, y;
char* date = "10 25 2022";
if(sscanf(date, "%d %d %d", &m, &d, &y) == 3) // return val of sscanf is how many converters have successfully converted their values
```

printf returns how many characters it has printed

`strtok(input, [])` input can be regex


```C
int main (void) {
  char line[1000];
  int temp;
  while(1) {
    if(!scanf("%[^\n]\n", line))
      break;
    while(sscanf(line, "%d,%s", &temp, line) == 2) {
      printf("%e\t", (double) temp);
    }
    printf("%e\n", (double) temp);
  }
  return 0;
}
