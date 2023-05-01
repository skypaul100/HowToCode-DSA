//create BT + insert data elements into BT
//level order + inorder +preorder + postorder

#include <iostream>
#include<queue>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *createTree(node *root)
{
    int data;
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    cout << "Enter the data :";
    cin >> data;

    root = new node(data); // dynamic allocation

    if (data == -1) // to insert null in a node i/p -1
    {
        return NULL;
    }

    // insert elements in node in LST
    cout << "Enter data for Inserting in Left of Node (" << data<<") " << endl;
    root->left = createTree(root->left);

    // insert elements in node in RST
    cout << "Enter data for Inserting in Right of Node (" << data<<") "<< endl;
    root->right = createTree(root->right);

    return root;
}
void levelOrder(node* root){
//use a queue and push all elements of tree in queue
queue<node*> q;
q.push(root);

while(!q.empty()){
    node *temp=q.front(); // front data  first node
    cout<<temp->data<< " ";//print the data
    q.pop();     //when printed then pop the data

    //elt in left st push in q
    if(temp->left){
        q.push(temp->left);
    }
    if(temp->right){
        q.push(temp->right);
    }

}
    
}

//Left -> RootNode -> Right
void inOrder(node* root){
    if(root==NULL)
      return;

    //traverse the left child
    inOrder(root->left);

    //print the DATA of present node
    cout<<root->data<< " ";

    //traverse the right child
    inOrder(root->right);
     
}

//RootNode -> Left -> Right
void preOrder(node* root){

    if(root==NULL)
      return;

     //print the DATA of present node
    cout<<root->data<< " ";

    //traverse the left child
    preOrder(root->left);

   
    //traverse the right child
    preOrder(root->right);
     
}

//Left -> Right -> RootNode 
void postOrder(node* root){

    if(root==NULL)
      return;

    //traverse the left child
    postOrder(root->left);

   //traverse the right child
    postOrder(root->right);

    //print the DATA of present node
    cout<<root->data<< " ";
     
}

int main()
{
    node *root = NULL;

    // create a BT
    root = createTree(root);

    //level order
    cout<<"Printing Level order traversal: "<<endl;
    levelOrder(root);

    //inOrder traversal
    cout<<endl<<"Inorder traversal: "<<endl;
    inOrder(root);

    //preOrder traversal
    cout<<endl<<"Preorder traversal: "<<endl;
    preOrder(root);

    //postOrder traversal
    cout<<endl<<"Postorder traversal: "<<endl;
    postOrder(root);

    return 0;
}
