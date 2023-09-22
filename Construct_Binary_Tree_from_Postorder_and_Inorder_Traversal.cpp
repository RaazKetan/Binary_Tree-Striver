//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* Build(int in[], int Is, int Ie, int post[], int Ps, int Pe, map<int,int>&mp){
    if(Is>Ie || Ps>Pe)
    return NULL;

    Node *root = new Node(post[Pe]);
    int inRoot = mp[root->data];
    int NumLeft  = inRoot-Is;

    root->left = Build(in, Is, inRoot-1,post,Ps,Ps+NumLeft-1,mp);
    root->right = Build(in, inRoot+1,Ie,post,Ps+NumLeft,Pe-1,mp);
    return root;

}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
     map<int,int>mp;

     for (int i = 0; i < n; i++)
     {
        mp[in[i]] = i;
     }
     Node *root= Build(in, 0, n-1, post,0,n-1,mp);
     return root;
     
}
// in[] = 4 8 2 5 1 6 3 7
// post[] =8 4 5 2 6 7 3 1
// Output: 1 2 4 8 5 3 6 7