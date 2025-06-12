// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void Push(Node*& head, int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->next=head;
    head = temp;
}

int GetNth(Node* head , int index)
{
    if (head == nullptr)return -1;
    Node* temp = head;
    
    int count = 0;
    while(temp != nullptr){
        if(count == index-1)
        {
            return temp->data;
        }
        temp = temp->next;
        count++;
    }
    return  -1;
    
}
void InsertNth(Node*& head , int index , int x)
{
    Node* temp = head;
    Node* current = new Node;
    int data = GetNth(head , index);
    while(temp != nullptr)
    {
        if(data == temp->data)
        {
            current->next = temp->next;
            current->data = x;
            temp->next = current;
            temp = temp->next;
            
        }
        temp = temp->next;
    }
}

Node* Create_node(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
}




void Append(Node*& head , int data)
{
    Node* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
    }
    temp->next = Create_node(data);
    
    
}

Node* BubbleSort(Node*& head)
{
    Node* temp = head;
    bool isswapped = true;
 
        Node* current = temp;
        while(isswapped)
        {
            Node* current = temp;
            isswapped = false;
            while(current!= nullptr && current->next!= nullptr){
                if(current->data >current->next->data){
                   int data = current->data;
                    current->data = current->next->data;
                    current->next->data = data;
                    isswapped = true;
                    
                }else
                {
                    current = current->next;
                    
                }}
                if(current->next == nullptr)isswapped = false;
            }
    
    return head;
}








void print(Node* head)
{
    Node* temp = head;
    cout<<"List is:";
    while(temp!= nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    
}
void DeleteList(Node*& head)
{
    Node* current = head;
    while (current != nullptr)
    {
        Node* todelete = current;
        current = current->next;
        delete todelete;
    }
    head = nullptr;
}


Node* CopyList(Node* head)
{
   // Node* temp = head;
    Node* new_node = new Node{head->data , nullptr};
    Node* current_new = new_node;
    Node* current_old = head->next;
    
    while(current_old != nullptr)
    {
        current_new->next = Create_node(current_old->data);
        current_new = current_new->next;
        current_old = current_old->next;
        
    }
    return new_node;
    
}
Node*  AppendL(Node*& a , Node*& b)
{
    Node* temp_a =a ;
    Node* temp_b = b;
    
    while(temp_a->next != nullptr)
    {
        temp_a = temp_a->next;
    }
    temp_a->next = temp_b;
    b = nullptr;
    return a;
}

void FrontBackSplit(Node* head)
{
    Node* slow = head;
    Node* fast =head;
    
    while(fast!= nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
   // Node* middle = slow;
    slow->next = nullptr;
    
}

void RemoveDuplicates(Node*& head)
{
    //the list is sorted
    Node* temp = head;
    while(temp!=nullptr && temp->next != nullptr)
    {
        if(temp->data == temp->next->data)
        {
           Node* todelete =  temp->next;
           temp->next = temp->next->next;
           delete todelete;
           
        }else{
        temp = temp->next;
        }
        
    }
}

void Move(Node*& a , Node*& b)
{
    if(b == nullptr)return;
    Node* temp = a;
    if(a == nullptr)
    {
        b->next = nullptr;
        a = b;
        b = nullptr;
        return;
    }
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    b->next = nullptr;
    temp->next = b;
    b = nullptr;
}

Node* ReverseList(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr)
    {
        next = current->next;  
        current->next = prev;    
        prev = current;         
        current = next;         
    }
    
    return prev;  
}

void AlternatingSplit(Node* head)
{
    Node* temp = head;
    Node* even = new Node{0 , nullptr};
    Node* odd = new Node{0 , nullptr};
    while(temp != nullptr)
    {
        if(temp->data %2 == 0)
        {
            Append(even , temp->data);
        }else
        {
            Append(odd , temp->data);
        }
        temp = temp->next;
    }
    ReverseList(even->next);
    ReverseList(odd->next);

}

void AlternatingSplit2(Node* head)
{
    Node* temp = head;
    Node* even = new Node{0 , nullptr};
    Node* odd = new Node{0 , nullptr};
    while(temp != nullptr)
    {
        if(temp->data %2 == 0)
        {
            Append(even , temp->data);
        }else
        {
            Append(odd , temp->data);
        }
        temp = temp->next;
    }
    
}
Node* ShuffleMerge(Node* a, Node* b)
{
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    Node* new_list = nullptr;
    Node* tail = nullptr;

    int count = 1;
    while (a != nullptr || b != nullptr)
    {
        if (count % 2 == 1 && a != nullptr)
        {
            Node* newNode = new Node{a->data, nullptr};
            a = a->next;

            if (!new_list)
                new_list = tail = newNode;
            else
                tail = tail->next = newNode;
        }
        else if (count % 2 == 0 && b != nullptr)
        {
            Node* newNode = new Node{b->data, nullptr};
            b = b->next;

            if (!new_list)
                new_list = tail = newNode;
            else
                tail = tail->next = newNode;
        }
        count++;
    }
    return new_list;
}

Node* SortedMerge(Node* a , Node* b)
{
   Node* c =  AppendL(a , b);
    BubbleSort(c);
}

Node* SortedIntersect(Node* a , Node* b){
    Node* new_list = new Node{0 , nullptr};
    Node* temp1 = a;
    
    while(temp1 != nullptr)
    {
        Node* temp2 = b;
        while(temp2!= nullptr)
        {
            if(temp1->data == temp2->data)
            {
               Append(new_list  ,temp1->data);
                
            }
            
            temp2 = temp2->next;
        }
        
        
        temp1 = temp1->next;
        
    }
    
    
    RemoveDublicates(new_list);
    return new_list;
    
}

Node* SortedUnion(Node* a , Node* b){
    Node* new_list =  AppendL(a , b);
    RemoveDublicates(new_list);
    return new_list;
    
}

Node* SortedDiffrence(Node* a , Node* b){
    Node* new_list = new Node{0 , nullptr};
    Node* temp1 = a;
    
    while(temp1 != nullptr)
    {
        Node* temp2 = b;
        while(temp2!= nullptr)
        {
            if(temp1->data != temp2->data)
            { 
               Append(new_list  ,temp1->data);
                
            }
            
            temp2 = temp2->next;
        }
        
        
        temp1 = temp1->next;
        
    }
    
    
    RemoveDublicates(new_list);
    return new_list;
    
}










int main() {
    Node* a=nullptr;
   Node* b=nullptr;
   for (int i=8; i>=1; i--)
   {
       Push(a,i);
   }
   for (int i=1; i<=6; i++)
   {
       Push(b,i);
   }
 cout<<GetNth(b , 3)<<endl;
 InsertNth(b , 5 , 4);
 
  print(b);
 // DeleteList(b);
  Node* c =CopyList(b);
  Node* d = AppendL(a, b);
  print(b);
  print(d);
  print(c);
  
   

    return 0;
}