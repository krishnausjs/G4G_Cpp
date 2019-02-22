//Compare and check if two binary trees are same
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node*  newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int identicalTrees(struct node *a, struct node *b) {
    //if both trees are empty then return 1
    if( a == NULL && b == NULL) {
        return 1;
    }
    
    //If both trees are not empty
    if(  a != NULL && b != NULL ) {
        return 
        (
            //Check if data of the root nodes are  equal
            //Check left subtrees recursively 
            //Check right subtrees recursively
            //If all are true then return 1
            (a->data == b->data) &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }    
    //One empty and other one is not - false
    return 0;
}

int main() { 
    struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    
    if(identicalTrees(root1, root2)) {
        std::cout <<"Both trees are identical" << std::endl;
    } else {
        std::cout << "Both trees are not identical" << std::endl;
    }
    
    getchar();
    return 0;
}