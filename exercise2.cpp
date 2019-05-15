/*
Nama		: Salma Alifia Shafira
NPM			: 140810180058
Kelas		: B
Tanggal		: 15/05/2019
Exercise	: Exercise 2 (TREE)
*/

#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

void createNode(node* &newNode, int data);
void insertBST(node* &root, node* newNode);
void printPreOrder(node *root);
void printInOrder(node *root);
void printPostOrder(node *root);
int height(node* root);
void printByLevel(node* root, int level);
void printLevelOrder(node* root);
void printChildren(node* root);

int main(){
    node *tree=NULL, *newNode;
    int pil,temp; bool loop=true;
    createNode(newNode, 7);
    insertBST(tree, newNode);
    createNode(newNode, 11);
    insertBST(tree, newNode);
    createNode(newNode, 3);
    insertBST(tree, newNode);
    createNode(newNode, 4);
    insertBST(tree, newNode);
    createNode(newNode, 5);
    insertBST(tree, newNode);
    createNode(newNode, 9);
    insertBST(tree, newNode);
    createNode(newNode, 12);
    insertBST(tree, newNode);
    createNode(newNode, 15);
    insertBST(tree, newNode);
    createNode(newNode, 1);
    insertBST(tree, newNode);
    createNode(newNode, 10);
    insertBST(tree, newNode);
    createNode(newNode, 2);
    insertBST(tree, newNode);
    createNode(newNode, 25);
    insertBST(tree, newNode);
    createNode(newNode, 8);
    insertBST(tree, newNode);
    createNode(newNode, 14);
    insertBST(tree, newNode);
    createNode(newNode, 19);
    insertBST(tree, newNode);
    
    while(loop){
        system("CLS");
        cout<<"1. InsertBST"<<endl;
		cout<<"2. Kedalaman"<<endl;
        cout<<"3. PreOrder"<<endl;
		cout<<"4. Level"<<endl;
        cout<<"5. InOrder"<<endl;
		cout<<"6. Anak"<<endl;
        cout<<"7. PostOrder"<<endl;
		cout<<"8. Exit"<<endl;
        do cin>>pil; while(pil<1 || pil>8);
        
        switch(pil){
            case 1:
                cout<<endl<<"Node baru : ";cin>>temp;
                createNode(newNode,temp);
                insertBST(tree, newNode);
                cout<<endl<<"InsertBST berhasil"<<endl;
                break;
            case 2:
            	cout<<endl<<"Kedalaman : "
                <<height(tree)-1;
                break;
            case 3:
            	cout<<endl<<"Pre-Order : "<<endl;
                printPreOrder(tree);
                break;
            case 4:
            	cout<<endl<<"Level : "
                <<height(tree);
                break;
            case 5:
            	cout<<endl<<"In-Order : "<<endl;
                printInOrder(tree);
                break;
            case 6:
                cout<<endl<<"Jumlah Anak : "<<endl;
                printChildren(tree);
                break;
            case 7:
                cout<<endl<<"Post-Order : "<<endl;
                printPostOrder(tree);
                break;
            case 8:
                cout<<endl<<"TERIMA KASIH :))"<<endl;
                loop=false;
                break;
        }
        cout<<endl<<endl;system("pause");
    }
}

void createNode(node* &newNode, int data){
    newNode = new node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
}

void insertBST(node* &root, node* newNode){
    if (root==NULL) root=newNode;
    else if (root->data>newNode->data) insertBST(root->left, newNode);
    else insertBST(root->right, newNode);
}

void printPreOrder(node *root){
    if(root!=NULL){
        cout<<root->data<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printInOrder(node *root){
    if(root!=NULL){
        printInOrder(root->left);
        cout<<root->data<<" ";
        printInOrder(root->right);
    }
}

void printPostOrder(node *root){
    if(root!=NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int height(node* root){
    if(root==NULL){
        return 0;
    }else{
        int lheight=height(root->left);
        int rheight=height(root->right);
        if (lheight>rheight) return (lheight+1);
        else return (rheight+1);
    }
}

void printByLevel(node* root, int level){
    if(root==NULL) return;
    else if(level==1) cout<<root->data<<" ";
    else{
        printByLevel(root->left, level-1);
        printByLevel(root->right, level-1);
    }
}

void printLevelOrder(node* root){
    int h=height(root);
    for(int i=1; i<=h; i++) printByLevel(root, i);
}

void printChildren(node* root){
    int h=height(root);
    for(int i=3; i<=h; i++) printByLevel(root, i);
}
