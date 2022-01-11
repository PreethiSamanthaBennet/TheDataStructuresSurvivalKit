#include <iostream>
using namespace std;
#define N 5

int stack1[5], stack2[5]; 
int top1 = -1, top2 = -1, count = 0;
char des1[50], des2[50];

void push1(int code){

  if(top1 == N - 1){
    cout<<"stack overflow\n"<<endl;
  }
  else{
    top1++;
    stack1[top1] = code;
    
  }
}

int pop1(){
  if(top1 == -1){
    cout<<"stack is empty\n"<<endl;
  }
  else{
    int x = stack1[top1];
    top1--;
  
    return x;
  }
}

void push2(int code){
  if(top2 == N - 1){
    cout<<"stack overflow\n"<<endl;
  }
  else{
    top2++;
    stack2[top2] = code;
   
  }
}

int pop2(){
    int y = stack2[top2];
    top2--;
    
    return y;
}

void enqueue(int x)  
{  
    push1(x);  
    count++;  
}  
void dequeue()  
{  
   if((top1==-1) && (top2==-1))  
{  
   cout<<endl<<"Queue is empty\n"<<endl;  
}  
else  
{  
  for(int i=0;i<count;i++)  
  {  
     int y = pop1();  
     push2(y);  
  }  
int b= pop2();  
cout<<"The dequeued element is "<<b;  
cout<<endl;  
count--;  
for(int i=0;i<count;i++)  
{  
   int x = pop2();  
   push1(x);   
}  
}}   

void display(){
  for(int i = 0; i<=top1; i++){
  

    cout<<stack1[i]<<endl;
  }
  cout<<endl;
}

int main(){
  int val, code;
  char cont;
   int ch;
  do{
   
    cout<< "enqueue --> 1\ndequeue --> 2\ndisplay --> 3\nexit -----> 4\n "<<endl;
    cout<<"enter your choice : "<<endl;
    cin>>ch;
    
    switch(ch){
      case 1:
        cout<<"enter a number : "<<endl;
        cin>>code;
        enqueue(code);
        break;
        
      case 2:
        dequeue();
        break;  
         
      case 3:
        cout<<endl;
      
        display();
        break;
        
      case 4:
        break;
      
        
      default:
        cout<<"Enter a number between 1 and 4"<<endl;
     }
  }while(ch != 4); 
  return 0;
}

