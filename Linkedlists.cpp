#include <iostream>
#include <string>
using namespace std;

// String Conversion to Upper Case
string convert_string(string s)
{  
    string s1 = "";                   
    for(int i=0;i<s.length();i++)
        s1 += toupper((1, s[i]));
    return s1;
}

 /* Linked Lists */
typedef struct Node
{
    string name;
    Node* next;  
}Node;

typedef Node* pNode;
pNode myList;

void init_linkedlist(pNode &p)
{
    p = 0;
}
void forward_traverse_linkedlist(pNode p )
{
pNode tmp = p;
while(tmp!= 0)
{
    cout<<tmp->name<<endl;
    tmp= tmp->next;
}
}

void back_traverse_linkedlist(pNode p)
{
    pNode tmp = p;
    if(tmp != 0)
{
    back_traverse_linkedlist(tmp->next);
    cout<<tmp->name<<endl;
}
}

void insert_linkedlist(pNode &p, string newname)
{
    if(p==0)    //empty list
    {
        p = new Node;
        p->name = newname;
        p->next =0;
    }
    else        //non-empty list
    {
            pNode tmp = p, prev = 0;
            // move through the list of names to find the position
            while(tmp != 0 && convert_string(tmp->name) < convert_string(newname))
            {
                prev = tmp;
                tmp = tmp->next;
            }
            //links the new node with the tmp position
            pNode insertnode =  new Node;
            insertnode->name = newname;
            insertnode->next = tmp;
            // Code seperating the cases of insert at the middle, the end or the beggening of the list
            if(tmp ==0) // inserting at the end
            {
                prev->next = insertnode;
            }else
            {
                if( prev!= 0)   //inserting in the middle
                {
                    prev->next = insertnode;
                }
                else    //inserting in the begining
                {
                    p = insertnode;
                }
            }


    }
}

int search_linkedlist(pNode &p, string name)
{
    pNode tmp = p;
    int pos = 1;
    while(tmp != 0)
    {
        if(convert_string(tmp->name) == convert_string(name))
        {
            return pos;
        }
        tmp= tmp->next;
        pos++;
    }
    return -1;
}

void delete_linkedlist(pNode &p, string name)
{
    pNode tmp = p, prv =0;
    while(tmp != 0 && convert_string(tmp->name) != convert_string(name))
    {
        prv = tmp;
        tmp = tmp->next;
    }
    if(tmp ==0)
    {
        cout<<"Name not found"<<endl;
    }else
    {
        if(prv !=0)
        {
            prv->next = tmp->next;
        }else
        {
            p = tmp->next;
        }
    }
    tmp = 0;
}

/* Array Lists */
const int size = 10;
typedef struct list 
{
    int length;
    string arr[size];
}list;
list arrlist;
void forward_array(list &arrlist)
{
    for(int i = 0; i< arrlist.length; i++)
    {
        cout<<arrlist.arr[i]<<endl;
    }
}

void backward_array(list &arrlist)
{
    for(int i = arrlist.length; i>0 ; i--)
    {
        cout<<arrlist.arr[i]<<endl;
    }
}
void init_arrlist(list &l)
{
    l.length = 0;

}

void insert_arr(list &arrlist, string name)
{
    if(arrlist.length == size)
    {
        cout<<"list is full"<<endl;
        return;
    }
    if(arrlist.length == 0)
    {
        arrlist.length = 1;
        arrlist.arr[0]= name;
        return;
    }
    for(int i= 0; i<arrlist.length ; i++)
    {
        if(convert_string(name) <= convert_string(arrlist.arr[i]) )
        {
            for(int j = (arrlist.length-1); j>=i; j--)
            {
                arrlist.arr[j+1] = arrlist.arr[j];
            }
            arrlist.arr[i] = name;
            arrlist.length++;
            return;

        }
    }
    arrlist.arr[arrlist.length] = name;
    arrlist.length++;
}

int search_arr(list &l, string name)
{
    for(int i = 0; i< l.length ; i++)
    {
        if(convert_string(name) == convert_string(l.arr[i]))
        {
            return i;
        }
    }
    cout<<"name not found"<<endl;
    return -1;
}

void delete_arr(list &l, string name)
{
    int s = search_arr(l,name);
    if (s!= -1)
    {
    for(int i =s ; i<l.length ;i ++)
    {
        l.arr[i]= l.arr[i+1];
    }
    l.length--;
    }
}

/* Main Function */
int main()
{
cout<<"Type A for Array list or P for pointer list"<<endl;
char choice;
string name;
init_linkedlist(myList);
init_arrlist(arrlist);
cin>>choice;

switch (choice)
{
case 'A':
    while(1)
    {
    cout << "a. Insert name :" << endl;
    cout << "b. Delete name :"<< endl;
    cout << "c. Search name :"<< endl;
    cout << "d. Forward Traverse  :"<< endl;
    cout << "e. Backward Traverse :"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 'a':
        cout<<"please insert a name to add to the list"<<endl;
        cin>>name;
        insert_arr(arrlist, name);
        break;
        case 'b':
        cout<<"please input name to delete"<<endl;
        cin>>name;
        delete_arr(arrlist, name);
        break;
        case 'c':
        cout<<"Please insert a name to search"<<endl;
        cin>>name;
        cout<<search_arr(arrlist,name)<<endl;
        break;
        case 'd':
        forward_array(arrlist);
        break;
        case 'e':
        backward_array(arrlist);
        break;
        default: 
        cout<<"No such command"<<endl;
    }
    }
    case 'P':
    while(1)
    {
    cout << "a. Insert name :" << endl;
    cout << "b. Delete name :"<< endl;
    cout << "c. Search name :"<< endl;
    cout << "d. Forward Traverse  :"<< endl;
    cout << "e. Backward Traverse :"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 'a':
        cout<<"please insert a name to add to the list"<<endl;
        cin>>name;
        insert_linkedlist(myList, name);
        break;
        case 'b':
        cout<<"please input name to delete"<<endl;
        cin>>name;
        delete_linkedlist(myList, name);
        break;
        case 'c':
        cout<<"Please insert a name to search"<<endl;
        cin>>name;
        cout<<search_linkedlist(myList,name)<<endl;
        break;
        case 'd':
        forward_traverse_linkedlist(myList);
        break;
        case 'e':
        back_traverse_linkedlist(myList);
        break;
        default: 
        cout<<"No such command"<<endl;
    }
}
}
return 0;
}
