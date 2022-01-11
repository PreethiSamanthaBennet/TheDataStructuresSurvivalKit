#include <iostream>
using namespace std;
#define SIZE 100

int stack[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int pushed_element){
  if(top1 < top2 - 1){
    top1++;
    stack[top1] = pushed_element;
    cout<<pushed_element<<" - pushed successfully to stack 1"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }
}

void push2(int pushed_element){
  if(top1 < top2 - 1){
    top2--;
    stack[top2] = pushed_element;
    cout<<pushed_element<<" - pushed successfully to stack 2"<<endl;
  }
  else{
    cout<<"Stack is full"<<endl;
  }
}

void pop1(){
  if(top1 >= 0){
    int popped_element = stack[top1];
    top1--;
    cout<<popped_element<<" - popped successfully from stack 1"<<endl;
  }
  else{
    cout<<"Stack is empty"<<endl;
  }
}

void pop2(){
  if(top2 < SIZE){
    int popped_element = stack[top2];
    top2++;
    cout<<popped_element<<" - popped successfully from stack 2"<<endl;
  }
  else{
    cout<<"Stack is empty"<<endl;
  }
}

void display_stack1(){
  int i;
  for(i = top1; i >= 0; i--){
    cout<< stack[i]<<endl;
  }
  cout<<endl;
}

void display_stack2(){
  int i;
  for(i = top2; i < SIZE; i++){
    cout<< stack[i]<<endl;
  }
  cout<<endl;
}

int main(){
  int code;
  
  char ch;
   cout << "Enter \n1 ————> push (Stack 1)\n2 ————> push (Stack 2)\n3 ————> pop (Stack 1)\n4 ————> pop (Stack 2)\n5 ————> display (Stack 1)\n6 ————> display (Stack 2)\n\n";
  do{
    int num;
    cout<<"enter a number corresponding to your choice"<<endl;
    cin>>num;
    
    switch(num){
      
      case 1:
        cout<<"enter the number"<<endl;
        cin>>code;
        push1(code);
        break;
        
      case 2:
          cout<<"enter the number"<<endl;
        cin>>code;
        push2(code);
        break;
      
      case 3:
        pop1();
        break;
        
      case 4:
        pop2();
        break;
      
      case 5:
        cout<<endl;
        display_stack1();
        break;
        
      case 6:
        cout<<endl;
        display_stack2();
        break;
        
      default:
        cout<<"invalid function"<<endl;
      
    }
    
    cout<<"do you want to continue (Y/N)?"<<endl;
    cin>>ch;
    cout<<endl;
  }while(ch == 'Y' || ch == 'y');
  return 0;
}
