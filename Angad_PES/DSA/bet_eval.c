#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

typedef struct node {
	char info;
	struct node *left, *right;
} NODE;

typedef struct tree {
	NODE *root;
} TREE;

typedef struct stack {
	NODE *s[MAX];
	int top;
} STACK;

void init_tree(TREE *pt) {
	pt->root = NULL;
}

void init_stack(STACK *ps) {
	ps->top = -1;
}

int push(STACK *ps, NODE *e) {
	if (ps->top == MAX - 1)
		return 0;
	ps->top++;
	ps->s[ps->top] = e;
	return 1;
}

NODE* pop(STACK *ps) {
	if (ps->top == -1)
		return NULL;
	NODE *t = ps->s[ps->top];
	ps->top--;
	return t;
}

// Expression Tree Evaluation
float eval(NODE *r) {
	switch (r->info) {
		case '+': return eval(r->left) + eval(r->right);
		case '-': return eval(r->left) - eval(r->right);
		case '*': return eval(r->left) * eval(r->right);
		case '/': return eval(r->left) / eval(r->right);
		default: return r->info - '0';      // subtracting '2' from '0' returns ascii(2)
	}
}

float eval_tree(TREE *pt) {
	return eval(pt->root);
}

int main() {
	char postfix[MAX];
	STACK sobj;
	TREE tobj;
	NODE *temp;

	init_stack(&sobj);
	init_tree(&tobj);

	printf("Enter a valid postfix expression\n");
	scanf("%s", postfix);

	int i = 0;
	while (postfix[i] != '\0') {
		temp = (NODE*) malloc(sizeof(NODE));
		temp->info = postfix[i];
		temp->left = NULL;
		temp->right = NULL;

		if (isdigit(postfix[i])) {
			push(&sobj, temp);
		} else {
			temp->right = pop(&sobj);
			temp->left = pop(&sobj);
			push(&sobj, temp);
		}
		i++;
	}

	tobj.root = pop(&sobj);
	printf("%f\n", eval_tree(&tobj));

	return 0;
}