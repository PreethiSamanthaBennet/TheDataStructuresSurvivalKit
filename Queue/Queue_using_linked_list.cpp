#include <iostream>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
};
/********************************************/
void Display(Node* n){
  if(n == NULL){
    cout<<"queue is empty"<<endl;
    return;
  }
  while(n != NULL){
    cout<< n->data <<" ";
    n = n->next;
  }
  cout<<endl;
}
/********************************************/
int Enqueue(Node**headref, int new_data){
  Node* new_node = new Node();
  Node* last = *headref;
  new_node->data = new_data;
  new_node->next = NULL;
  
  if(*headref == NULL){
    *headref = new_node;
    return 0;
  }
  while(last->next != NULL){
    last = last->next;
  }
    last->next = new_node;
    return 0;
  
}
/********************************************/
int Dequeue(Node**headref){
  Node* temp = *headref;
  if(temp == NULL){
    cout<<"Queue is empty"<<endl;
    return 0;
  }
  *headref = temp->next;
  delete temp;
  return 0;
}
/********************************************/
int main(){
  Node*head = NULL;
  int choice, val;
  cout<<"1->Enqueue"<<endl;
  cout<<"2->Dequeue"<<endl;
  cout<<"3->Display"<<endl;
  cout<<"4->Exit"<<endl;
  
  do{
    cout<<"Enter choice"<<endl;
    cin>>choice;
    
    switch(choice){
      case 1:
        cout<<"Enter the value: "<<endl;
        cin>>val;
        Enqueue(&head, val);
        break;
      case 2:
        Dequeue(&head);
        break;
      case 3:
        Display(head);
        break;
      case 4:
        break;
      default:
        cout<<"Enter the values between 1 and 4"<<endl;
    }
  
  
  }while(choice != 4);
  return 0;
}

