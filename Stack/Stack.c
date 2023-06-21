#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"


#if StackType == ArrayBased

void Init_Stack(Stack *ps)
{
	ps->top = 0;
}

void Push(StackEntery e, Stack *ps)
{
	ps->entery[ps->top] = e;
	ps->top++;
}

void Pop(StackEntery *pe, Stack *ps)
{
	*pe = ps->entery[--ps->top];
}

int StackFull(Stack *ps)
{
	return (ps->top >= MAX_STACK);
}

int StackEmpty(Stack *ps)
{
	return !ps->top; 
}

void StackTop(StackEntery *pe, Stack *ps)
{
	*pe = ps->entery[ps->top-1];
}

int StackSize(Stack *ps)
{
	return ps->top;
}

void ClearStack(Stack *ps)
{
	ps->top = 0;
}

void TraverseStack(Stack *ps, void (*pf)(StackEntery))
{
	for(int i=ps->top ; i>0 ; i--)
	{
		(*pf)(ps->entery[i-1]);
	}
}

#elif StackType == LinkedBased

void Init_Stack(Stack *ps)
{
	ps->top = NULL;
	ps->size = 0;
}

void Push(StackEntery e, Stack *ps)
{
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
	pn->entery = e;
	pn->next = ps->top;
	ps->top = pn;
	ps->size++;
}

void Pop(StackEntery *pe, Stack *ps)
{
	StackNode *pn;
	*pe = ps->top->entery;
	pn = ps->top;
	ps->top = ps->top->next;
	free(pn);
}

int StackFull(Stack *ps)
{
	return 0;
}

int StackEmpty(Stack *ps)
{
	return ps->top == NULL;
}

void StackTop(StackEntery *pe, Stack *ps)
{
	*pe = ps->top->entery;
}

int StackSize(Stack *ps)
{
	return ps->size;
}

void ClearStack(Stack *ps)
{
	StackNode* pn = ps->top;
	while(pn)
	{
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
}

void TraverseStack(Stack *ps, void (*pf)(StackEntery))
{
	StackNode* pn = ps->top;
	while(pn)
	{
		(*pf)(pn->entery);
		pn = pn->next;
	}
}

#endif
