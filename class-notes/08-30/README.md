# 8-30 Notes

#### Char Arrays
strings are stored as an array of characters 
"hello" = ["h", "e", "l", "l", "o", "\n", "\0"] OR each char's ascii code
   
"\0" is used to determine when the string ends, which informs us what the length of the array is


#### i++ vs ++i
```C
int i;
i = 0;
printf("%d", i++); // prints 0 sets i equal to 1;
i = 0;
printf("%d", ++i); // sets i equal to 1 and prints 1

