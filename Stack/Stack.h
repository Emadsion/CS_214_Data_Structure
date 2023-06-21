#ifndef STACK_H
#define STACK_H
//#define MAX_STACK 100
//#define StackType LinkedBased

typedef char StackEntery;


//#if StackType == ArrayBased
/*
typedef struct stack{
	int entery[MAX_STACK];
	int top;
}Stack;
*/
//#elif StackType == LinkedBased

typedef struct stacknode{
	StackEntery entery;
	struct stacknode *next;
}StackNode;

typedef struct stack{
	StackNode * top;
	int size;
}Stack;
//#endif

void Init_Stack(Stack *ps);
void Push(StackEntery e, Stack *ps);
void Pop(StackEntery *pe, Stack *ps);
int StackFull(Stack *ps);
int StackEmpty(Stack *ps);
void StackTop(StackEntery *pe, Stack *ps);
int StackSize(Stack *ps);
void ClearStack(Stack *ps);
void TraverseStack(Stack *ps, void (*pf)(StackEntery));

#endif