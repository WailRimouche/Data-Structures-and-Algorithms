#include <iostream>
#include <string.h>

using namespace std;
typedef struct person
{
    int age;
    string firstname;
    string lastname; 
}person;

typedef struct node
{
    person pers;
    node* next;
}node;
person newperson(string firstname, string lastname, int age)
{
    person* thisperson = new person;
    thisperson->firstname = firstname;
    thisperson->age = age;
    thisperson->lastname= lastname;
    return *(thisperson);
}
void showperson(person &p)
{
    cout<<p.firstname<<" "<<p.lastname<<" "<<p.age<<endl;
}
typedef node* pNode;

/* QUEUE IMPLEMENTATION */ 
typedef struct queue
{
    pNode head;
    pNode tail;
}queue;
void init_queue(queue &q)
{
    q.head = nullptr;
    q.tail = nullptr;
}

void enqueue(queue &q,person &p)
{
    pNode newnode = new node;
    newnode->pers = p;
    newnode->next = nullptr;

    if (q.head == nullptr)
    {
        q.head = newnode;
        q.tail = newnode;
    }else
    {
        newnode->next = q.head;
        q.head = newnode;
    }
}
person dequeue(queue &q)
{
    pNode tmp = q.head;
    if(q.head==nullptr)
    { 
        person noperson = newperson("NONE","NONE",0);
        return noperson;
    }
    while(tmp->next != q.tail)
   {
       if(q.head != q.tail)
       {tmp = tmp->next;}
       else 
       {
           cout<<"Queue is now empty"<<endl;
           init_queue(q);
           return tmp->pers;
       }
   }
   q.tail = tmp;
   person tmpperson = tmp->next->pers;
   tmp->next = nullptr;
   free(tmp->next);
   return tmpperson;
}

void delete_queue(queue &q,person &p)
{

}
void queue_traverse_forward(queue &q)
{
    pNode tmp = q.head;
    while(tmp != nullptr)
    {
        showperson(tmp->pers);
        tmp = tmp->next;
        
    }
}
void list_back(pNode &p)
{
    pNode tmp = p;
    if(tmp->next != nullptr)
    {
        list_back(tmp->next);
       
    }
     showperson(tmp->pers);
}
void queue_traverse_backward(queue &q)
{
    if(q.head != nullptr)
    {
    pNode tmp = q.head;
    list_back(tmp);
    }
}


/* STACK IMPLEMENTATION */
typedef node* stack;
void init_stack(stack &s)
{
    s = nullptr;
}
void stack_push(stack &s, person &p)
{
    pNode newnode = new node;
    newnode->pers = p;
    newnode->next = s;
    s = newnode;
}
person stack_pop(stack &s)
{
    pNode tmp = s;
    s = tmp->next;
    person Pertmp = tmp->pers;
    free(tmp);
    return Pertmp;
}

void forward_traverse_stack(stack &s)
{
    pNode tmp = s;
    while(tmp != nullptr )
    {
        showperson(tmp->pers);
        tmp = tmp->next;
    }
}
void backward_traverse_stack(stack &s)
{
    if(s != nullptr)
    {
        pNode tmp = s;
        list_back(tmp);
    }
}



int main()
{
    queue q;
    stack s;
    init_queue(q);
    init_stack(s);
    person tmpperson; 
    string firstname,lastname;
    int age;
    char op,op2 ='M';
    cout<<"Type S for stack or Q for Queue"<<endl;
    cin>>op;
    switch(op)
    {
        
        case 'S':
        while(op2 != 's')
        {
        cout<<"Choose among the following operations: through the corresponding letter:"<<endl;
        cout<<"a- Push a person's info into the stack"<<endl;
        cout<<"b- pop a person's info from the stack"<<endl;
        cout<<"c- Forward Traverse the Stack"<<endl;
        cout<<"d- Backward Traverse the Stack"<<endl;
        cout<<"s- stop the program"<<endl;
        cin>>op2;

        switch(op2)
        {
            case 'a':
            cout<<"Please insert person's first name"<<endl;
            cin>>firstname;
            cout<<"please insert person's last name"<<endl;
            cin>>lastname;
            cout<<"please insert person's age"<<endl;
            cin>>age;
            tmpperson = newperson(firstname,lastname,age);
            stack_push(s,tmpperson);
            break;
            case 'b':
            tmpperson = stack_pop(s);
            showperson(tmpperson);
            break;
            case 'c':
            forward_traverse_stack(s);
            break;
            case 'd':
            backward_traverse_stack(s);
            break;
            default:
            cout<<"no such command"<<endl;
            break;
        }
        }
        
        case 'Q':
        while(op2 != 's')
        {
        cout<<"Choose among the following operations: through the corresponding letter:"<<endl;
        cout<<"a- insert a person's info into the Queue"<<endl;
        cout<<"b- exist a person's info from the Queue"<<endl;
        cout<<"c- Forward Traverse the Queue"<<endl;
        cout<<"d- Backward Traverse the Queue"<<endl;
        cout<<"s- stop the program"<<endl;
        cin>>op2;
        switch(op2)
        {
            case 'a':
            cout<<"Please insert person's first name"<<endl;
            cin>>firstname;
            cout<<"please insert person's last name"<<endl;
            cin>>lastname;
            cout<<"please insert person's age"<<endl;
            cin>>age;
            tmpperson = newperson(firstname,lastname,age);
            enqueue(q,tmpperson);
            break;
            case 'b':
            tmpperson = dequeue(q);
            showperson(tmpperson);
            break;
            case 'c':
            queue_traverse_forward(q);
            break;
            case 'd':
            queue_traverse_backward(q);
            break;
            default:
            cout<<"no such command"<<endl;
            break;

        }
        }
       
    }
    return 0;
}