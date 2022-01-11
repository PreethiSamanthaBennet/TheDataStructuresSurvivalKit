#include <iostream>
#include <string.h>
using namespace std;
float count = 0.0;
float rain = 0.0;
struct queue{
  char month[12];
  int rainfall;
  int temp;
};
queue cqueue[5];

int front = -1, rear = -1, n = 5;

void insertCQ(char month[],int rainfall,int temp){
  if(front ==(rear + 1)%n){
    cout<<"Queue overflow"<<endl;
  }
  if(front == -1){
    front = 0;
    rear = 0;
  }
  else{
    rear = (rear + 1)%n;
  }
  strcpy(cqueue[rear].month,month);
  cqueue[rear].rainfall = rainfall;
  cqueue[rear].temp = temp;
  count++;
  rain += rainfall;
}

void deleteCQ(){
  if(front == -1){
    cout<<"Queue underflow"<<endl;
  }
  cout<<"the element deleted is "<<cqueue[front].month<<" "<<cqueue[front].rainfall<<" "<<cqueue[front].temp<<"\n";
  if(front == rear){
    front = -1;
    rear = -1;
    count--;
    rain -= cqueue[front].rainfall;
  }
  else{
    front = (front + 1)%n;
    count--;
    rain -= cqueue[front].rainfall;
  }
}

void displayCQ(){
  int f = front, r = rear;
  
  if(f<=r){
    while(f<=r){
      cout<<cqueue[f].month<<" "<<cqueue[f].rainfall<<" "<<cqueue[f].temp<<"\n";
      f++;
    }
  }
  else{
    while(f<=(n - 1)){
    cout<<cqueue[f].month<<" "<<cqueue[f].rainfall<<" "<<cqueue[f].temp<<"\n";
    f++;
    }
  
  f = 0;
  while(f <= r){
    cout<<cqueue[f].month<< " " <<cqueue[f].rainfall<< " " <<cqueue[f].temp<<"\n";
    f++;
    }
  }
}

void avg_rainfall(){
  float avg = rain/count;
  cout<<"the average rainfall in cm is "<<avg<<endl;
}
int main(){
  int ch, rainfall, temp;
  char month[12];
  cout<<"1———-> Insert"<<endl;
  cout<<"2———-> Delete"<<endl;
  cout<<"3———-> Display"<<endl;
  cout<<"4———-> Average rainfall"<<endl;
  do{
    cout<<"Enter your choice: "<<endl;
    cin>>ch;
    
    switch(ch){
      case 1:
        cout<<"enter the month: "<<endl;
        cin>>month;
        cout<<"enter the rainfall in cm: "<<endl;
        cin>>rainfall;
        cout<<"enter the temp in C: "<<endl;
        cin>>temp;
        insertCQ(month, rainfall, temp);
        break;
        
      case 2:
        deleteCQ();
        break;
      
      case 3:
        displayCQ();
        break;
        
      case 4:
        avg_rainfall();
        break;
    }
  }while(ch != 5);
  return 0;
}
