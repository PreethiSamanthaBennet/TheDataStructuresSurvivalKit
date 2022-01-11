#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0
class Node{
  public:
    int data;
    Node*next;

};
/**********************************************/
int Push(Node**(headref), int new_data){
  Node*new_node = new Node();
  new_node->data = new_data;
  new_node-> next = *(headref);
  *(headref) = new_node;
}
/**********************************************/
int Pop(Node**headref){
  Node* temp = *headref;
  if(temp == NULL){
    cout<<"Stack is Empty"<<endl;
    return 0;
  }
  *headref = temp->next;
  delete temp;
  return 0;
}
/**********************************************/
int Display(Node*n){
  if(n == NULL){
    cout<<"Stack is empty"<<endl;
    return 0;
  }
  while(n != NULL){
    cout<<n->data<<" ";
    n = n->next;
  }
  cout<<endl;
}
/**********************************************/

int main(){
  Node*head = NULL;
    int ch;
    int data;
    
    
    cout<<"1—>Push"<<endl<<"2->pop"<<endl<<"3—>display"<<endl<<"4->exit"<<endl;
    do{
    cout<<"Enter choice: "<<endl;  
    cin>>ch;
    switch(ch){
      case 1:
        cout<<"Enter the data: "<<endl;
        cin>>data;
         Push(&head, data);
         cout<<endl;
         break;
       case 2:
         Pop(&head);
         break;
       case 3:
         Display(head);
        /* cout<<endl;*/
         break;
       case 4:
         break;
       default:
         cout<<"Invalid input"<<endl;
       }
    }while(ch != 4);
    return 0;
}
