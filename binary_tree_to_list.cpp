#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 6

typedef struct __node
{
    int key;
    struct __node* left;
    struct __node* right;
    struct __node* parent;

    int leftmax;
    int rightmax;
    int max;
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
    node* p = (node*)malloc(sizeof(node));
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

void inter_walk_loop(node* p)
{
    if(!p)
        return ;

    node* curr = p;
    stack<node*> nodes; 

    while(curr)
    {
        if(curr->left)
        {
            nodes.push(curr);
            curr = curr->left;
            continue;
        }
R: 
        printf("[%d] " , curr->key);
    
        if(curr->right)
        {
            curr = curr->right;
            continue;
        }

        if(!nodes.empty()) {
            curr = nodes.top();
            nodes.pop();
            goto R;
        } else {
            break;
        }
    }
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

/* 在二元树中找出和为某一值的所有路径
 * 输入一个整数和一棵二元树。从树的根结点开始往下访问一直到叶结点所经过
 * 的所有结点形成一条路径。打印出和与输入整数相等的所有路径
 *
 * 递归实现
 * */
void caculate(node* p , const int val , int &cnt , vector<node*> &path)
{
    if(!p)
        return ;

    bool isLeaf = true;
    cnt += p->key;
    path.push_back(p);

    if(p->left) {
        isLeaf = false;
        caculate(p->left , val , cnt , path);
    }

    if(p->right) {
        isLeaf = false;
        caculate(p->right , val , cnt , path);
    }

    if(isLeaf && cnt == val) {
        vector<node*>::iterator itr = path.begin();
        for(; itr < path.end(); itr++)
        {
            cout << (*itr)->key << " " ;
        }
        cout << endl;
    }

    cnt -= p->key;
    path.pop_back();
}

/*
 * 非递归实现
 * */
void caculate_loop(node* root , const int val)
{
    if(!root)
        return ;

    vector<node*> nodes;
    node* p = root;
    int cnt = 0;

    while(p)
    {
        cnt += p->key;
        nodes.push_back(p);
        
        if(p->left)
        {
            p = p->left;
            continue;
        }
R:
        if(p->right)
        {
            p = p->right;
            continue;
        }

        if(cnt == val)
        {
            vector<node*>::iterator itr = nodes.begin();
            for(; itr < nodes.end(); itr++)
            {
                cout << (*itr)->key << " " ;
            }
            cout << endl;
            //back to grandpa
            if( !nodes.empty() ) {
                itr = --nodes.end();
                cnt -= (*itr)->key;
                nodes.pop_back();
            }

            if( !nodes.empty() ) {
                itr = --nodes.end();
                cnt -= (*itr)->key;
                nodes.pop_back();
            }

            if( !nodes.empty() ) {
                p = nodes.back();
                goto R;
            }
             
            break;
        }
        else
        {
            cnt -= p->key;
            //vector<node*> itr = find(nodes.begin(), nodes.end() , p);
            //nodes.erase(itr);

            if( !nodes.empty() ) {
                nodes.pop_back();
                p = nodes.back();
                goto R;
            }
            break;
        }
    }
}

void height(node* node , int* max , int h)
{
    if(!node)
        return ;

    height(node->left , max , h + 1);
    height(node->right , max , h + 1);

    if(h > *max)
        *max = h;

    return ;
}

//求二元查找树的镜像
void mirror(node* p)
{
    if(!p)
        return ;

    node* tmp = NULL;

    tmp = p->left;
    p->left = p->right;
    p->right = tmp;

    mirror(p->left);
    mirror(p->right);
}

/*
 * 求二叉树中距离最远的两个点
 * */
//void distance(node* p , int* max , int leftmax , int rightmax)
void distance(node* p , int* max)
{
    if(!p)
        return;

    if(! p->left) {
        p->leftmax = 0;
    }
    
    if(! p->right) {
        p->rightmax = 0;
    }

    if(p->left)
    {
        distance(p->left , max);
        p->leftmax = p->left->max + 1;
    }
    
    if(p->right)
    {
        distance(p->right , max);
        p->rightmax = p->right->max + 1;
    }

    if(p->leftmax > p->rightmax)
    {
        p->max = p->leftmax;
    }
    else
    {
        p->max = p->rightmax;
    }

    if(p->rightmax + p->leftmax > *max)
        *max = p->rightmax + p->leftmax;

    return ;
}

void walk_tree(node* p)
{
    if(!p)
        return ;

    node* tmp = NULL;
    queue<node*> q;

    q.push(p);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();

        printf("[%d] " , tmp->key);
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    printf("\n");
}

int main(int argc , char** argv)
{
    int i;
    node* root = NULL;
//    int arr[MAX] = {10 , 5 , 12, 4 , 7 };
    int arr[MAX] = {9 , 6, 7, 3, 4, 13};

/*  for(i = 0; i < MAX; i++)
    {
        arr[i] = rand() % 50;
    }*/

    for(i = 0; i < MAX; i++)
    {
        add(&root , arr[i]);
    }

//    inter_walk_tree(root);
    inter_walk_loop(root);
    printf("\n");

    mirror(root);
   
    printf("mirror:\n");
    inter_walk_loop(root);
    printf("\n");
    /*test case succesor*/
//  node* tmp = find(&root , atoi(argv[1]));
    /*node* tmp = find(&root , 49);
    printf("[%d]\n" , tmp->key);
    node* s = successor(tmp);
    if(s)
        printf("[%d] [%d]\n" , tmp->key , s->key);*/
    /*test case*/

    //caculate(root , );

    //逐层遍历树
 
    printf("walk tree:");
    walk_tree(root);

    //计算树的高度
    int h = 0;
    height(root , &h , 0);
    printf("tree height:%d\n" , h);

    //计算树中结点间的最大距离
    int max = 0;
    distance(root , &max);
    printf("max distance in a tree: %d\n" , max);
   
    int cnt = 0;
    vector<node*> path;
    caculate(root , 22 , cnt , path);

//    caculate_loop(root , 22);
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
