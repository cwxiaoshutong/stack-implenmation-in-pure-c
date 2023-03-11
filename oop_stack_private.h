#ifndef __OOP_STACK_H__
#define __OOP_STACK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define new

typedef struct Stack {
    int (*push)(void*);
    void* (*pop)();
    void* (*top)();
    size_t (*size)();
    bool (*isEmpty)();
    void (*destroy)();
} Stack;

typedef struct StackNode {
    void* data;
    struct StackNode* next;
} StackNode;

typedef struct _Stack {
    StackNode* top;
    size_t size;
} _Stack;

#define Stack() ({                                                  \
    static Stack* stack;                                            \
    stack = (Stack*)malloc(sizeof(Stack));                          \
    static _Stack* _stack;                                          \
    _stack = (_Stack*)malloc(sizeof(_Stack));                       \
    _stack->size = 0;                                               \
    volatile int push(void* data) {                                 \
        StackNode* node = (StackNode*)malloc(sizeof(StackNode));    \
        node->data = data;                                          \
        node->next = _stack->top;                                   \
        _stack->top = node;                                         \
        _stack->size++;                                             \
        return 0;                                                   \
    }                                                               \
    volatile void* pop() {                                          \
        if (_stack->size == 0) {                                    \
            return NULL;                                            \
        }                                                           \
        StackNode* node = _stack->top;                              \
        _stack->top = node->next;                                   \
        _stack->size--;                                             \
        void* data = node->data;                                    \
        if(node) {                                                  \
            free(node);                                             \
            node = NULL;                                            \
        }                                                           \
        return data;                                                \
    }                                                               \
    volatile void* top() {                                          \
        if (_stack->size == 0) {                                    \
            return NULL;                                            \
        }                                                           \
        return _stack->top->data;                                   \
    }                                                               \
    volatile size_t size() {                                        \
        return _stack->size;                                        \
    }                                                               \
    volatile bool isEmpty() {                                       \
        return _stack->size == 0;                                   \
    }                                                               \
    volatile void destroy() {                                       \
        while (_stack->size > 0) {                                  \
            pop();                                                  \
        }                                                           \
        if(_stack) {                                                \
            free(_stack);                                           \
            _stack = NULL;                                          \
        }                                                           \
        if(stack) {                                                 \
            free(stack);                                            \
            stack = NULL;                                           \
        }                                                           \
    }                                                               \
    stack->push = push;                                             \
    stack->pop = pop;                                               \
    stack->top = top;                                               \
    stack->size = size;                                             \
    stack->isEmpty = isEmpty;                                       \
    stack->destroy = destroy;                                       \
    *stack;                                                         \
});

#ifdef __cplusplus
}
#endif

#endif // __OOP_STACK_H__