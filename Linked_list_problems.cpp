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

   
    




void DeleteList(Node*& head){
Node* temp = head;

while(temp != nullptr)
{
    Node* current = temp;
    temp = temp->next;
    delete current;
}
head = nullptr;
}



Node* CopyList(Node* head){
  if (head == nullptr) return nullptr;
  Node* temp = head;
  Node* copy_head = nullptr;
  Node* copy_tail = nullptr;
 while(temp != nullptr) {
    Node* new_node = create_node(temp->data);
    if (copy_head == nullptr) {
        copy_head = new_node;
        copy_tail = new_node;
    } else {
        copy_tail->next = new_node;
        copy_tail = new_node;
    }
    cout << new_node->data << " ";
    temp = temp->next;
}
  return copy_head;
}



Node* combineLists(Node*& head , Node*& second)
{
    Node* temp = head;
    if(head == nullptr)
    {
    head = second;
    return second;
    }
    
    while(temp->next != nullptr){
        temp = temp->next;
      
    }
    temp->next = second;
    second = nullptr;
    return head;
}


void FrontBackSplit(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast!= nullptr && fast->next != nullptr)
    {
        cout<<slow->data<<endl;
        slow = slow->next;
        cout<<fast->data<<endl;
        fast = fast->next->next;
        
    }
   Node* temp =  slow->next;
   slow->next = nullptr;
   
   
}

void RemoveDublicates(Node* head)
{
    Node* temp = head;
    while(temp->next != nullptr)
    {
        if(temp->data == temp->next->data)
        {
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
        }
        else
        {
            temp = temp->next;
        }
    }
}


void MoveNode(Node*& head , Node*& start)
{
    if(start == nullptr)return;
    Node* f_node = start;
    start->next = head;
    head = start;
}






int main()
{
Node* head = create_node(5);
appendLast(head , 20);
appendLast(head , 25);
appendLast(head , 25);
appendLast(head , 25);
appendLast(head , 25);
InsertNth(head , 3 , 1);
appendLast(head , 24);
GetNth(head , 3);
RemoveDublicates(head);
print(head);
FrontBackSplit(head);
Node* new_list = CopyList(head);
MoveNode(head , new_list);
combineLists(new_list , head);
DeleteList(head);


}