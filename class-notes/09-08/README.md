# Program Input Commands

```C
"()()()" // balanced
"( () ( () () ))) ()" // not balanced
```

store opening parenthesis in stack, whenever a close parenthesis is found, pop an opening parenthesis from the stack

popping from empty stack is an error case, program ends and there is still stuff in the stack is unbalanced
