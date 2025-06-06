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

void print(Node* head)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<"End"<<endl;
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
void InsertNth(Node*& head, int index, int data) {
    // Handle index 0: insert at the head
    if (index == 0) {
        Node* new_node = create_node(data);
        new_node->next = head;
        head = new_node;
        return;
    }

    Node* temp = head;
    int count = 0;

   
    while (temp != nullptr && count < index - 1) {
        temp = temp->next;
        count++;
    }

    
    if (temp == nullptr) {
        std::cerr << "Index out of bounds\n";
        return;
    }

    
    Node* new_node = create_node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

   // new_node->next = temp->next->next;
    





int main()
{
//create_a_list(10 , 20);
Node* head = create_node(5);
appendLast(head , 20);
appendLast(head , 25);
InsertNth(head , 3 , 1);
appendLast(head , 24);
GetNth(head , 3);
print(head);

}