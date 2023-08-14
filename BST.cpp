#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    Node *rchild;
    int data;
} *root = NULL;

void Insert(int key)
{
    Node *t = root;
    Node *r = NULL, *p;

    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

void Inroder(Node *p)
{
    if (p)
    {
        Inroder(p->lchild);
        cout << p->data << " ";
        Inroder(p->rchild);
    }
}
Node *Search(int key)
{
    Node *t = root;
    while (t != NULL)
    {
        if (key == t->data)
            return t;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    return NULL;
}

Node *RInsert(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    return p;
}

int Height(Node *p)
{
    int x,y;
    if(p == NULL)
    return 0;
    x= Height(p->lchild);
    y= Height(p->rchild);
    return x+y+1;

}

Node *InPre(Node *p)
{
    while(p && p->rchild != NULL)
    p = p->rchild;

    return p;
}
Node *InSucc(Node *p)
{
    while(p && p->lchild != NULL)
    p = p->lchild;

    return p;
    re
}
Node *Delete(Node *p, int key)
{
    Node *q;
    if(p== NULL)
    return NULL;

    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
        root == NULL;
        free(p);
        return NULL;
    }

    if(key<p->data)
    {p->lchild = Delete(p->lchild, key);}
    else if(key > p->data)
    {p->rchild = Delete(p->rchild, key);}

    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {

        
        q = InPre(p->lchild);
        p->data = q->data;
        p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q  = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}
int main()
{
    Node *t;
    root = RInsert(root, 10);
    root = RInsert(root, 5);
    root = RInsert(root, 30);
    root = RInsert(root, 4);
    root = RInsert(root, 50);

    Delete(root, 5);
    Inroder(root);
    cout << endl;

    // t = Search(20);
    // if(t!=NULL)
    // cout<<"Element 20 iss found";
    // else
    // cout<<"Nod";
    return 0;
}