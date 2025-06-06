#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* create_node(int data){
    Node* head = new(nothrow) Node {data};
    head->data = data;
    head->next = nullptr;
    return head;
}

void create_a_list(int a, int b)
{
    for(int i = a; i<b ; i++)
    {
        Node* temp = create_node(i);
        cout<<temp->data<<" ";
    }
    
}
void appendLast(Node* head , int data)
{   
    if(head == nullptr)return;
    
    Node* temp = head;
    Node* new_node = create_node(data);
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = nullptr;
}


void GetNth(Node* head , int index)
{
    Node* temp = head;
    int count = 1;
    while (count!=index)
    {
        temp = temp->next;
        count++;
    } 
    cout<<temp->data;
}





int main()
{
//create_a_list(10 , 20);
Node* head = create_node(5);
appendLast(head , 20);
appendLast(head , 25);
appendLast(head , 24);
GetNth(head , 3);

}