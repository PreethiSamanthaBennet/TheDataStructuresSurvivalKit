#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100
int TOP = -1;

struct stk{
  int data;
  char des[50];
};
stk STACK[MAX];

//check if stack is empty
int isEmpty(){
  if(TOP == -1){
    return 1;
  }
  else{
    return 0;
  }
}

//check if the stack is full
int isFull(){
  if(TOP == MAX - 1){
    return 1;
  }
  else{
    return 0;
  }
}

//push function
void push(int data, char des[]){
  if(isFull()){
    cout<<"stack is full"<<endl;
    return;
  }
  TOP++;
  STACK[TOP].data = data;
  strcpy(STACK[TOP].des, des);
  cout<<data<<" "<<des<<" -pushed sucessfully"<<endl;
}

//to display current elements in an array
void display(){
  int i;
  if(isEmpty()){
    cout<<"stack is empty"<<endl;
    return;
  }
  for(i = TOP; i>=0; i--){
    cout<<STACK[i].data<<" "<<STACK[i].des<<endl;
  }
}

//pop function
void pop(int data, char des[]){
  if(isEmpty()){
    cout<<"stack is empty"<<endl;
    return;
  }
  STACK[TOP].data = data;
  strcpy(STACK[TOP].des, des);
  TOP--;
  cout<<data<<" "<<des<< " - popped sucessfully"<<endl;
}

int main(){
  int data;
  char des[50];
  
  char cont;
  
  do{
    int num;
    cout<<"Enter \n1 —> push \n2 —> pop \n3 —> display"<<endl;
    cout<<"Enter your choice: "<<endl;
    cin>>num;
    
    switch(num){
      case 1:
        cout<<"Enter a number: "<<endl;
        cin>>data;
        cout<<"Enter a description: "<<endl;
        cin>>des;
        push(data,des);
        break;
     
      case 2:
        pop(data, des);
        break;
      
      case 3:
        cout<<endl;
        display();
        break;
      default:
        cout<<"Invalid input"<<endl;
       
    }
    cout<<"do you want to continue (Y/N)?"<<endl;
    cin>>cont;
    cout<<endl;
  }while(cont == 'Y' || cont == 'y');
  return 0;
}
