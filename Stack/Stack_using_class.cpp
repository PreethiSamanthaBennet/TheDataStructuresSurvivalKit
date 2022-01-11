#include<iostream>

#define SIZE 15
 
using namespace std;
 
class STACK{
    private:
        int num[SIZE];
        int top;
    public:
        STACK();    //default constructor
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
        void displayItems();
};
/**************************************/
STACK::STACK(){
    top=-1;
}
/**************************************/
int STACK::isEmpty(){
    if(top==-1){
      return 1;
    }
    else
      return 0;   
}
/**************************************/
int STACK::isFull(){
    if(top==(SIZE-1))
        return 1;
    else
        return 0;
}
/**************************************/
int STACK::push(int n){
    //check stack is full or not
    if(isFull()){
        return 0;
    }
    ++top;
    num[top]=n;
    return n;
}
/**************************************/
int STACK::pop(){
    //to store and print which number
    //is deleted
    int temp;
    //check for empty
    if(isEmpty())
        return 0;
    temp=num[top];
    --top;
    return temp;
     
}
/**************************************/
void STACK::displayItems(){
    int i; //for loop
    if (top==-1){
      cout<<"STACK is EMPTY";
    }
    
    else{
      cout<<"STACK is: ";
      for(i=(top); i>=0; i--)
        cout<<num[i]<<" ";
      cout<<endl;
    }
}
/**************************************/
STACK stk1;
STACK stk2;
   //declare object     
int main(){   
      int choice, n,temp;
      cout<<"0 - Exit."<<endl;
        cout<<"1 - Push Item in stack1."<<endl;
        cout<<"2 - Push Item in stack2."<<endl;
        cout<<"3 - Pop Item in stack1"<<endl;
        cout<<"4 - Pop item in stack2"<<endl;
        cout<<"5 - Display Items in stack1 (Print STACK)."<<endl;
        cout<<"6 - Display Items in stack2 (Print STACK)."<<endl; 
        
    do
    {
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
         
        switch(choice){
            case 0:
               break;
             
            case 1:
                cout<<"Enter item to insert: ";
                cin>>n;
                temp=stk1.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted in stk1."<<endl;
                break;
            
            case 2:
              cout<<"Enter item to insert: "; 
              cin>>n;
               temp=stk2.push(n);
                if(temp==0)
                    cout<<"STACK is FULL."<<endl;
                else
                    cout<<temp<<" inserted in stk2."<<endl; 
                    break;  
            case 3:
                temp=stk1.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                    
                else
                    cout<<temp<<" is removed (popped) from stk1."<<endl;
                    break;
                
            case 4:
              temp=stk2.pop();
                if(temp==0)
                    cout<<"STACK IS EMPTY."<<endl;
                else
                    cout<<temp<<" is removed (popped) from stk2."<<endl;
                break;
                    
            case 5:
              cout<<"Stack 1: "<<endl;
                stk1.displayItems();
                break;
                
            case 6:
               cout<<"Stack 1: "<<endl;
               stk2.displayItems();
                break;
             
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
       
    return 0;
     
}
