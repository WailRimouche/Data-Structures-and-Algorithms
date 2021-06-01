#include <iostream>
#define empt -100000
using namespace std;
/* POINTER IMPLEMENTATION OF BINARY SEARCH TREES */
typedef struct treenode
{
    int element;
    treenode* Lchild;
    treenode* Rchild;
}treenode;
typedef treenode* tree;
tree BST;
void init_tree(tree &BST)
{
    BST =  nullptr;
}
void tree_insert(tree &BST, int number)
{
    if(BST == nullptr)
    {
        BST =  new treenode;
        BST->element = number;
        BST->Lchild = nullptr;
        BST->Rchild = nullptr;
    }else
    {
        tree tmp = BST;
        while(1)
        {
        if(number > tmp->element)
        {
            if(tmp->Lchild == nullptr)
            {
                treenode* tmpnode = new treenode;
                tmpnode->element =  number;
                tmp->Lchild = tmpnode;
                tmp = tmpnode;
                return;
            }else
            {
               tmp = tmp->Lchild;
            }
        }else
        {
            if(tmp->Rchild == nullptr)
            {
                treenode* tmpnode = new treenode;
                tmpnode->element =  number;
                tmp->Rchild = tmpnode;
                tmp = tmpnode;
                return;
            }else
            {
                tmp = tmp->Rchild;
            }
        }
        }
        
    }
}
void inorder_traversal(tree &BST)
{
    tree tmp =  BST;
    if(tmp!= nullptr)
    {
    inorder_traversal(tmp->Lchild);
    cout<<tmp->element<<endl;
    inorder_traversal(tmp->Rchild);
    }
}
void postorder_traversal(tree &BST)
{
    tree tmp =  BST;
    if(tmp!= nullptr)
    {
    postorder_traversal(tmp->Lchild);
    postorder_traversal(tmp->Rchild);
    cout<<tmp->element<<endl;
    }
}
void pretorder_traversal(tree &BST)
{
    tree tmp =  BST;
    if(tmp!= nullptr)
    {
    cout<<tmp->element<<endl;
    pretorder_traversal(tmp->Lchild);
    pretorder_traversal(tmp->Rchild);
    }
}

/* ARRAY IMPLEMENTATION OF BINARY SEARCH TREES */
const int size = 20;
typedef int treearr[size];
void init_arrtree(treearr &t)
{
    for(int i=0; i<size;i++)
    {
        t[i] = empt;
    }
}
void insert_arrtree(treearr &t, int number)
{
    int i = 0;
    while(t[i] != empt && i< size)
    {
        if(t[i] > number)
        {
            i = 2*i +1;
        }else
        {
            i = 2*i+2;
        }
    }
    if (i > size)
    {
        cout<<"Tree is Full"<<endl;
    }else
    {
        t[i] = number;
    }
}
void inorder_arr(treearr &t,int i)
{
    if(t[i] != empt && i< size)
    { 
        inorder_arr(t, i*2+1);
        cout<<t[i]<<endl;
        inorder_arr(t, i*2+2);

    }
}
void postorder_arr(treearr &t,int i)
{
    if(t[i] != empt && i< size)
    {
        postorder_arr(t, i*2+1);
        postorder_arr(t, i*2+2);
        cout<<t[i]<<endl;

    }
}
void preorder_arr(treearr &t,int i)
{
    if(t[i] != empt && i< size)
    {
        cout<<t[i]<<endl;
        preorder_arr(t, i*2+1);
        preorder_arr(t, i*2+2);
       
    }
}

int main()
{
    treearr tarr;
    tree t;
    init_tree(t);
    init_arrtree(tarr);
    char op;
    int number;
    cout<<"Type A for array implementation of BST or P for pointer implementation"<<endl;
    cin>>op;
    switch (op)
    {
        case 'A':
        while(op != 'q')
        {
        cout<<"Chose from the following list what to do:"<<endl;
        cout<<"a- insert a new element into the tree"<<endl;
        cout<<"b- inorder traverse the Binary tree"<<endl;
        cout<<"c- postorder traverse the Binary tree"<<endl;
        cout<<"d- preorder traverse the Binary tree"<<endl;
        cout<<"q- Quit"<<endl;
        cin>>op;
        switch(op)
        {
            case 'a':
            cout<<"Plase type the number you wish to insert onto the tree"<<endl;
            cin>>number;
            tree_insert(t,number);
            break;
            case 'b':
            inorder_traversal(t);
            break;
            case 'c':
            postorder_traversal(t);
            break;
            case 'd':
            pretorder_traversal(t);
            break;
            default:
            cout<<"Command not available"<<endl;
            break;
        }
        }
        case 'P':
        while(op !='q')
        {
        cout<<"Chose from the following list what to do:"<<endl;
        cout<<"a- insert a new element into the tree"<<endl;
        cout<<"b- inorder traverse the Binary tree"<<endl;
        cout<<"c- postorder traverse the Binary tree"<<endl;
        cout<<"d- preorder traverse the Binary tree"<<endl;
        cout<<"q- Quit"<<endl;
        cin>>op;
         switch(op)
        {
            case 'a':
            cout<<"Plase type the number you wish to insert onto the tree"<<endl;
            cin>>number;
            insert_arrtree(tarr,number);
            break;
            case 'b':
            inorder_arr(tarr,0);
            break;
            case 'c':
            postorder_arr(tarr,0);
            break;
            case 'd':
            preorder_arr(tarr,0);
            break;
            default:
            cout<<"Command not available"<<endl;
            break;
        }
        }

    }

    return 0;

}