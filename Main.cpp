//D.Flemmings
//Project 4
#include <iostream>
#include "BSTNode.hpp"
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to find minimum in a tree
Node* FindMin(Node * root)
{
    while(root -> left != NULL)
    root = root -> left;
    return root;
}

//Function to determine if a specific node is in tree  
bool ifNodeExists(Node* root, int num)
{
    if (root == NULL)
        return false;
 
    if (root->data == num)
        return true;
 
    /* then recur on left subtree */
    bool answ1 = ifNodeExists(root->left, num);
    // node found, no need to look further
    if(answ1) return true;
 
    /* node is not found in left,
    so recur on right subtree */
    bool answ2 = ifNodeExists(root->right, num);
 
    return answ2;
}

//Function to search a delete a value from tree
struct Node* Delete(struct Node* root, int data)
{
    if(root == NULL)
    return root;
    else if(data < root -> data)
    root -> left = Delete(root -> left, data);
    else if(data > root -> data)
    root -> right = Delete(root -> right, data);
    
    //Case 1: No child
    else
    {
        if(root -> left == NULL && root -> right == NULL)
        {
        delete root;
        root = NULL;
        }
    
    //Case 2: One child
    else if(root -> left == NULL)
    {
        struct Node* temp = root;
        root = root -> right;
        delete temp;
    }
    
    else if(root -> right == NULL)
    {
        struct Node* temp = root;
        root = root -> left;
        delete temp;
    }
    
    //Case 3: 2 children
    else
    {
        struct Node* temp = FindMin(root -> right);
        root -> data = temp -> data;
        root -> right = Delete(root -> right, temp -> data);
    }
  }
 return root;
 }
 
 //Function to visit nodes in Inorder
 void Inorder(Node* root)
 {
     if(root == NULL)
     return;
     
     Inorder(root -> left);
     cout << " " << root -> data;
     Inorder(root -> right);
 }
 
 //Function to visit nodes in Preorder
 void Preorder(Node* root)
 {
     if(root == NULL)
     return;
     
     cout << " " << root -> data;
     Preorder(root -> left);
     Preorder(root -> right);
 }
 
 //Function to visit nodes in Postorder
 void Postorder(Node* root)
 {
     if(root == NULL)
     return;
     
     Postorder(root -> left);
     Postorder(root -> right);
     cout << " " << root -> data;
 }

//Function to Insert Node in a Binary Search Tree  
 Node* Insert(Node* root, char data)
 {
     if(root == NULL)
     {
         root = new Node();
         root -> data = data;
         root -> left = root -> right = NULL;
     }
     else if(data <= root -> data)
     root -> left = Insert(root -> left, data);
     else
     root -> right = Insert(root -> right, data);
     return root;
 }

int main()
{
    Node* root = NULL;
    int node;
    BSTList list;
    //(1) Prompt the user to enter at least
    //16 integer numbers
    for(int i = 1; i <= 16; i++)
    {
        cout << "Enter Node #" << i << ": ";
        cin >> node;
        root = Insert(root, node);
    }
    
    //Print Nodes in Inorder
    cout << "\nInorder Tree:\t";
    Inorder(root);
    
    //Print Nodes in Preorder
    cout << "\nPreorder Tree:\t";
    Preorder(root);
    
    //Print Nodes in Inorder
    cout << "\nPostorder Tree:\t";
    Postorder(root);
    
    //(5) a. Search for a specific node
    int so;
    cout << "\n\nsearch: ";
   cin >> so;
 if (ifNodeExists(root, so))
        cout << "YES " << so << " is in tree";
    else
        cout << "NO " << so << " is not in tree";
    
    //(5) b. Add a node
    cout << "\n\ninsert: ";
    cin >> so;
    list.insertNode(so);
    
    cout << "Inorder Tree after insertion:\t";
    Inorder(Insert(root, so));
    
    cout << "\nPreorder Tree after insertion:\t";
    Preorder(root);
    
    cout << "\nPostorder Tree after insertion:\t";
    Postorder(root);
    
    //(5) c. Delete a node
    cout << "\n\ndelete: ";
    cin >> so;
    list.deleteNode(so);
    
    cout << "Inorder Tree after deletion:\t";
    Inorder(Delete(root, so));
    
    cout << "\nPreorder Tree after deletion:\t";
    Preorder(Delete(root, so));
    
    cout << "\nPostorder Tree after deletion:\t";
    Postorder(Delete(root, so));
}
