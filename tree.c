#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} NODE;

typedef struct tree {
    NODE *root;
} TREE;

TREE *create_tree() {
    TREE *t = (TREE *)malloc(sizeof(TREE));
    if (t == NULL)
        return t;
    t->root = NULL;
    return t;
}

void add(NODE *root, NODE *p) {
    if (root->data > p->data) {
        if (root->left == NULL)
            root->left = p;
        else
            add(root->left, p);
    } else if (root->data < p->data) {
        if (root->right == NULL)
            root->right = p;
        else
            add(root->right, p);
    }
}

void add_node(TREE *t, int value) {
    if (t == NULL)
        return;

    NODE *p = (NODE *)malloc(sizeof(NODE));
    if (p == NULL)
        return;
    p->left = p->right = NULL;
    p->data = value;

    if (t->root == NULL)
        t->root = p;
    else
        add(t->root, p);
}

void destroy(NODE *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void destroy_tree(TREE *t) {
    if (t == NULL)
        return;
    destroy(t->root);
    free(t);
}

NODE *search(NODE *t, int data) {
    if (t == NULL || t->data == data)
        return t;

    if (t->data < data)
        return search(t->right, data);

    return search(t->left, data);
}

void pr(NODE *root) {
    if (root != NULL) {
        pr(root->left);
        printf("%d ", root->data);
        pr(root->right);
    }
}

void printree(TREE *t) {
    if (t == NULL) {
        printf("NULL\n");
        return;
    }

    printf("{");
    pr(t->root);
    printf("}");
    printf("\n");
}

int main() {
    TREE *t;
    t = create_tree();
    int i = 0;
    while (i <= 10) {
        add_node(t, i);
        i++;
    }
   
   int num;
	printf("Give me any number for search: ");
	scanf("%d", &num);
	

    if (search(t->root,num ) != NULL) {
        printf("%d found\n",num);
    } else {
        printf("%d not found\n",num);
    }

    printf("TREE ELEMENTS\n");
    printree(t);

    destroy_tree(t);
    return 0;
}
