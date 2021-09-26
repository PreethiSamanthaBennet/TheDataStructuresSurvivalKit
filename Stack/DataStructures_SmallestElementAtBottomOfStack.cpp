#include <iostream>
#include <stack>
using namespace std;

struct Queue{
  stack<int>s1, s2;
  
  void enqueue(int x){
    while(!s1.empty() && x < s1.top()){
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    
    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
    cout<<x<<" - Enqueued sucessfully"<<endl;
  }
  int dequeue(){
    if(s1.empty()){
      cout<<"Q is empty";
      exit(0);
    }
    
    int x = s1.top();
    s1.pop();
    cout<<x<<" - Dequeued sucessfully"<<endl;
    return x;
  }
  
  int display(){
    if(s1.empty()){
      cout<<"Q is empty";
      exit(0);
    }
    while(!s1.empty()){
      cout<<s1.top()<<endl;
      s2.push(s1.top());
      s1.pop();
    }
    
   while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
    cout<<endl;
  }
};

int main(){
  Queue q;
  int ele;
  int n;
  
  do{
    cout<<"Enter \n1 -------> push \n2------->pop \n3------->display \n4------->exit";
    cout<<"\nenter choice: ";
    cin>>n;
    
    switch(n){
      case 1:
        cout <<"enter the number\n";
        cin>>ele;
        q.enqueue(ele);
        break;
        
      case 2:
        q.dequeue();
        break;
        
      case 3:
        cout<<endl;
        q.display();
        break;
        
      case 4:
        break;
        
      default:
        cout<<"Invalid input";       
    }
    cout<<endl;
  }while(n != 4);
  
  return 0;
}
