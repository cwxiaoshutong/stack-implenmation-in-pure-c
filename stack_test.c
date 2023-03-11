#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "oop_stack_private.h"
#include "print.h"

typedef struct point {
    int x;
    int y;
    int z;
} _point;

Stack stack;

int main(int argc, char const *argv[]) {
    stack = new Stack();
    for (int i = 0; i < 20; ++i) {
        _point* p = (_point*)malloc(sizeof(_point));
        p->x = i;
        p->y = rand() % 50;
        p->z = i + 1;
        stack.push(p);
        printf("x: %d, y: %d, z: %d\n", p->x, p->y, p->z);
    }

    print("----------------");
    for(int i = 0; i < 20; ++i) {
        _point* p = stack.top();
        printf("top -> x: %d, y: %d, z: %d\n", p->x, p->y, p->z);
    }

    printf("stack size: %d, isEmpty: %d \n", stack.size(), stack.isEmpty());

    print("----------------");

    for (int i = 0; i < 20; ++i) {
        _point* p = stack.pop();
        printf("x: %d, y: %d, z: %d\n", p->x, p->y, p->z);
    }

    printf("stack size: %d, isEmpty: %d \n", stack.size(), stack.isEmpty());

    stack.destroy();
}