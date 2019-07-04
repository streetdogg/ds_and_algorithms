/*
 * Implementation of a Binary search tree.
 * Operations: Add, Search, Delete
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _node {
    uint32_t data;
    struct _node *l_child;
    struct _node *r_child;
} node;

void print_tree(node *root) {
    if (!root)
        return;
    
    print_tree(root->l_child);
    printf(" %u ", root->data);
    print_tree(root->r_child);
}

uint32_t add(node **root, uint32_t element) {

    if (!(*root)) {
        node *entry = (node *) malloc(sizeof(node));

        entry->data = element;
        entry->l_child = NULL;
        entry->r_child = NULL;

        *root = entry;
        return 0;
    }

    if (element <= (*root)->data)
        return add(&(*root)->l_child, element);
    else
        return add(&(*root)->r_child, element);
}

int32_t search(const node *root, uint32_t element) { 
    if (!root)
        return -1;
    else if (root->data == element)
        return 0;
    
    return (element < root->data) ? search(root->l_child, element) : search(root->r_child, element);        
}

void delete(node *root, uint32_t element) {
    if (!root)
        return;

    // TODO :)
}

int32_t main() {
    node *root = NULL;

    add(&root, 5);
    add(&root, 1);
    add(&root, 6);
    add(&root, 3);

    print_tree(root);
    printf ("\n");

    printf("looking for 3: %d\n", search(root, 3));
    printf("looking for 13: %d\n", search(root, 13));

    return 0;
}
