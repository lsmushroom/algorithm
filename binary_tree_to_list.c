#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct __node
{
    int key;
    struct __node* left;
    struct __node* right;
    struct __node* parent;
}node;

node* successor(node* n)
{
    if(! n)
        return NULL;

    node* p = n->right;

    while(p && p->left) {
        p = p->left;
    }

    if(!p) {
        while(n->parent && n->parent->right == n) {
            n = n->parent;
        }

        if(! n->parent) {
            p = NULL;
        } else if(n->parent->left == n) {
            p = n->parent;
        }
    }

    return p;
}

node* s = NULL;
node* del = NULL;

void __del_node(node** root , node* node)
{
    if(!root || ! *root || !node)
        return ;

    if(!node->left || !node->right) {
        del = node;
    } else {
        del = successor(node);
    }

    if(del != node) {
        node->key = del->key;
    }

    if(del->left)
        s = del->left;
    else
        s = del->right;
    
    if(s)
        s->parent = del->parent;

    if(del->parent) {
        if(del->parent->left == del)
            del->parent->left = s;
        else
            del->parent->right = s;
    } else {
        *root = s;
    }

    printf("delete [%d]\n" , del->key);
//    delete del;
    free(del);
}

void add(node** root , int key)
{
    node* curr = *root;
    node* parent = NULL;

    while(curr)
    {
        if(curr->key > key) {
            parent = curr;
            curr = curr->left;
        } else if(curr->key < key) {
            parent = curr;
            curr = curr->right;
        } else {
            return ;
        }
    }

//    node* p = new node();
    node* p = malloc(sizeof(node));
    p->key = key;
    p->parent = parent;

    if(parent) {
        if(parent->key < key) {
            parent->right = p;
        } else {
            parent->left = p;
        }
        printf("insert new key [%d]\n" , key);
    } else if(! (*root) ) {
        *root = p;
        printf("root NULL insert key [%d]\n" , key);
    }
}

void inter_walk_tree(node* p)
{
    if(! p )
        return ;

    inter_walk_tree(p->left);
    printf("[%d] " , p->key);
    inter_walk_tree(p->right);
}

node* find(node** root , int key)
{
    node* curr = *root;

    while(curr)
    {
        if(curr->key > key) {
            curr = curr->left;
        } else if(curr->key < key) {
            curr = curr->right;
        } else {
            break;
        }
    }

    return curr;
}

void del_node(node** root , int key)
{
    if(! *root )
        return ;

    node* curr = NULL;
    curr = find(root , key);

    if(curr) {
        __del_node(root , curr);
    }
}

node* __convert(node* n , node** __last)
{
    if(!n)
        return NULL;

    node* last;
   
    __convert(n->left , __last);
    
    last = *__last;
    n->left = last;
    if(last)
        last->right = n;
    *__last = n;

    __convert(n->right , __last);
}

node* convert(node* head)
{
    if(! head ) 
        return NULL;

    node* last = NULL;
    __convert(head , &last);

    node* listhead = last;
    while(listhead && listhead->left)
        listhead = listhead->left;

    return listhead;
}

int main(int argc , char** argv)
{
    int arr[MAX];
    int i;
    node* root = NULL;

    for(i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 100;
    }

    for(i = 0; i < MAX; i++)
    {
        add(&root , arr[i]);
    }

    inter_walk_tree(root);
    printf("\n");

    /*test case succesor*/
//  node* tmp = find(&root , atoi(argv[1]));
    /*node* tmp = find(&root , 49);
    printf("[%d]\n" , tmp->key);
    node* s = successor(tmp);
    if(s)
        printf("[%d] [%d]\n" , tmp->key , s->key);*/
    /*test case*/

    node* tmp = convert(root);
    while(tmp) {
        printf("[%d] " , tmp->key);
        tmp = tmp->right;
    }
    printf("\n");
    
    /*test delete node*/
/*    for(i = 0; i < MAX; i++)
    {
        del_node(&root , arr[i]);
        inter_walk_tree(root);
        printf("\n");
    }*/

    return 0;
}
