#include <iostream>
#include <vector>
using namespace std;

// the node structure in AVL Tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

int greaterElement(int a, int b){
    if (a>=b){
        return a;
    }
    else {
        return b;
    }
}

// function to get the height of the tree
int getHeight(Node *N)
{
    if (N == NULL){
        return 0;
    }
    else {
        return N->height;
    }
}

// to create a new node in AVL Tree
Node* getNewNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Height Update
    y->height = greaterElement(getHeight(y->left),getHeight(y->right)) + 1;
    x->height = greaterElement(getHeight(x->left),getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Height Update
    x->height = greaterElement(getHeight(x->left),   getHeight(x->right)) + 1;
    y->height = greaterElement(getHeight(y->left),getHeight(y->right)) + 1;

    return y;
}

int getBalance(Node *root)
{
    if (root == NULL){
        return 0;
    }
    else {
        return getHeight(root->left) - getHeight(root->right);
    }
}

Node* insertElement(Node* root, int x)
{

    if (root == NULL){
        return(getNewNode(x));
    }

    if (x < root->data){
        root->left = insertElement(root->left, x);

    }
    else if (x > root->data){
        root->right = insertElement(root->right, x);

    }

    else {
        return root;
    }


    root->height =  greaterElement(getHeight(root->left),getHeight(root->right)) + 1;


    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && x < root->left->data)
        return rightRotate(root);

    // Right Right
    if (balance < -1 && x > root->right->data)
        return leftRotate(root);

    // Left Right
    if (balance > 1 && x > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left
    if (balance < -1 && x < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

static int counter = 0;
bool found = false;

void leftSubCount(Node*root,Node* tempNode){
    if(root->left == NULL){return;}
    else {
        counter++;
        leftSubCount(root->left,tempNode);
        if(root->right == NULL){return;}
        else{
            if(root->data== tempNode->data){
                return;
            }
            counter++;
            leftSubCount(root->right,tempNode);
        }
    }
}

void searchIndex(Node* root , int x){
    if (root == NULL){
        return;
    }
    if (root->data == x){
        found = true;
        leftSubCount(root,root);
        return;
    }
    else if (root->data > x){
        searchIndex(root->left,x);
    }
    else {
        counter++;
        leftSubCount(root,root);
        searchIndex(root->right,x);
    }
}


int main()
{
    int numQueries,query,x;
    Node *root = NULL;
    vector<int> output;

    cin >> numQueries;

    for (int i = 0 ; i < numQueries ; i++){
        cin >> query >> x;

        if (query==1){
            root = insertElement(root,x);
        }
        else if(query==2){
            searchIndex(root,x);
            if (!found){
                output.push_back(-1);
            }
            else {
                output.push_back(counter+1);
            }
            counter=0;
            found = false;
        }
    }

    for (int i = 0 ; i < output.size() ; i++){
        cout << output[i] << " ";
    }

}