#include <iostream>
using namespace std;

class QUEUE{
  private:
    int  cqueue[5];
    int front, rear,n;
  
  public:
    QUEUE();
    int insertCQ(int);
    int deleteCQ();
    void displayCQ();
};
/*********************************/
QUEUE::QUEUE(){
  front = -1, rear = -1, n = 5;
}
/**************************************/
int QUEUE::insertCQ(int val){

  if(front == (rear + 1)%n){
    cout<<"Queue overflow"<<endl;
    return 0;
  }
  
 if(front == -1){
    front = 0;
    rear = 0;
  }
  else{
    rear=(rear + 1)%n;
  }
  cqueue[rear] = val;
  cout<<val<<" Enqueued successfully"<<endl;
}
/**************************************/
int QUEUE::deleteCQ(){
 // int val;
  // val = cqueue[front];
  if(front == -1){
    cout<<"Queue underflow"<<endl;
    return 0;
  }
  cout<<"Element deleted from queue is: "<<cqueue[front]<<endl;
  if(front == rear){
    front = -1;
    rear = -1;
    
  }
  else{
    front = (front + 1)%n;
    
  }
}
/**************************************/
void QUEUE::displayCQ(){
  int f = front, r = rear;
 
  cout<<"Queue elements are: "<<endl;
  if(f<=r){
    while(f<=r){
      cout<<cqueue[f]<< " ";
      f++;
    }
  }
  else{
    while(f<=(n - 1)){
      cout<<cqueue[f]<< " ";
      f++;
    }
  
    f = 0;
    while(f <= r){
    cout<<cqueue[f]<< " ";
    f++;
    }
  }
  cout<<endl;
}
/**************************************/
  QUEUE q1, q2;
int main(){

    int ch, val;
  cout<<"1———-> Insert in Queue 1"<<endl;
  cout<<"2———-> Insert in Queue 2"<<endl;
  cout<<"3———-> Delete in Queue 1"<<endl;
  cout<<"4———-> Delete in Queue 2"<<endl;
  cout<<"5———-> Display Queue 1"<<endl;
  cout<<"6———-> Display Queue 2"<<endl;
  cout<<"7———-> Exit"<<endl;
  do{
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    
    switch(ch){
      case 1:
        cout<<"Enter the value: "<<endl;
        cin>>val;
        q1.insertCQ(val);
        break; 
        
      case 2:
        cout<<"Enter the value: "<<endl;
        cin>>val;
        q2.insertCQ(val);
        break; 
        
      case 3:
        q1.deleteCQ();
        break;
        
      case 4:
        q2.deleteCQ();
        break;
      
      case 5:
        q1.displayCQ();
        break;
        
      case 6:
        q2.displayCQ();
        
      case 7:
        break;
        
      default:
        cout<<"Invalid input";
    }
  }while(ch != 7);
  return 0;
  }

