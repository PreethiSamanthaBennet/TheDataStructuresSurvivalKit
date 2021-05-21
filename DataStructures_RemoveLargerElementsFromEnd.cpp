#include <iostream>
using namespace std;
#define size 100

int arr[size];
int n;
int f = 0, r = n - 1; 
int sum = 0;

int dequeue_front(){
  int a;
  if((f == -1) && (r == -1)){
    cout<<"Queue is empty";
  }
  else if(f == r){
    a = arr[f];
    cout<<"the deleted element is: "<< a;
    f = -1;
    r = -1;
  }
  else if(f == n - 1){
    a = arr[f];
    cout<<"the deleted element is: "<< a;
    f = 0;
  }
  else{
    a = arr[f];
    cout<<"the deleted element is: "<< a;
    f = f+1;
  }
  cout<<endl;
  return a;
}

int dequeue_rear(){
  int a;
  if((f == -1) && (r == -1)){
    cout<<"Queue is empty";
  }
  else if(f == r){
    a = arr[r];
    cout<<"the deleted element is: "<<a;
    f = -1;
    r = -1;
  }
  else if(r == 0){
    a = arr[r];
    cout<<"the deleted element is: "<<a;
    r = n - 1;
  }
  else{
    a = arr[r];
    cout<<"the deleted element is: "<<a;
    r = r - 1;
  }
  cout<<endl;
  return a;
}

int main(){
  int n, i, j;
  
  cout<<"Enter the number of elements: "<<endl;
  cin>>n;
  r = n - 1;
  cout<<"Enter the elements: "<<endl;
  for(i = 0; i < n; i++){
    cin>>arr[i];
  }
  cout<<"Enter the no of elements to be deleted: "<<endl;
  cin>>j;
  
  for(int k = 0; k < j; k++){
    if(arr[f]>arr[r]){
      sum += dequeue_front();
    }
    else{
      sum += dequeue_rear();
    }
  }
  cout<<"\nSum = "<<sum;
  return 0;
}
