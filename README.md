# stack-implenmation-in-pure-c

##A C++ like stack implenmention in c with a member function that has a "this pointer"

```
Stack stack;
stack = new Stack();

int* i = (int*)malloc(sizeof(int));

*i = 1;

stack.push(i);
stack.top();
stack.pop();
stack.size();
stack.desroy();
stack.isEmpty();

```
