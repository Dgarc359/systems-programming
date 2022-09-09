#include <string.h>

main () {
  char temp[20];

  /**
   * press ctrl + d to close buffer without inputting newline ('\n') 
   */
  while(1){
    scanf("%s", temp); // until you press enter, data is in buffer stream
    if (strcmp(temp, "quit") == 0) 
      // printf("quit\n");
      break;
    else if (strcmp(temp, "check") == 0)
      printf("check\n");
    else if (strcmp(temp, "pair") == 0)
      printf("pair\n");
  }
}