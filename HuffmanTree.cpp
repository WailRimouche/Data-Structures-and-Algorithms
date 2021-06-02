#include <iostream>
#include <string>
using namespace std;

typedef struct node
{
    char letter;
    int frequency;
    node* Lchild;
    node* Rchild;
}node;

typedef node* pNode;
pNode HuffmanTree;
void huffman(int freq[], char letters[],pNode &huff, int number)
{   huff = new node;
    pNode tmp1,tmp2;
    huff->frequency = freq[0];
    huff->letter =letters[0];
    for(int i=1; i< number ;i++)
    {
        tmp1 = new node;
        tmp1->frequency = freq[i];
        tmp1->letter = letters[i];
        tmp2 = new node;
        tmp2->frequency = freq[i] + huff->frequency;
        tmp2->Lchild= tmp1;
        tmp2->Rchild = huff;
        huff = tmp2;
    }  
}
void bitcodes(pNode &huff)
{
    string bitcode = "";
    pNode tmp = huff ;
    while(tmp->Rchild != nullptr )
    {
        cout<<"The letter    "<<tmp->Lchild->letter<<endl;
        cout<<bitcode<<"0"<<endl;
        bitcode = bitcode +"1";
        tmp = tmp->Rchild;
    }
    cout<<"The letter     "<<tmp->letter<<endl;
    cout<<bitcode<<endl;

}


int main()
{
    int number;
    cout<<"Insert the number of letters    "<<endl;
    cin>>number;
    char letters[number];
    int frequency[number];
    int frequency_sorted[number];
    for(int i = 0; i< number; i++)
    {
        cout<<"Insert   "<<(i+1)<<"    letter   "<<endl;
        cin>>letters[i];
        cout<<"Insert   "<<(i+1)<<"    letter frequency    "<<endl;
        cin>>frequency[i];
        frequency_sorted[i]=10000000;
    }
    char letter_sorted[number];
    int minfreq = -10;
    for (int i = 0; i<number;i++)
    {
        for(int j= 0; j<number; j++)
        {
            if(frequency_sorted[i] > frequency[j] && frequency[j] > minfreq)
            {
                frequency_sorted[i]= frequency[j];
                letter_sorted[i] = letters[j];
            }
        }
        minfreq  = frequency_sorted[i];
    }
    huffman(frequency_sorted,letter_sorted,HuffmanTree ,number);
    bitcodes(HuffmanTree);
    return 0;
}