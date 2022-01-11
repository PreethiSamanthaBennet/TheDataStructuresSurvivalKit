#include <iostream>
using namespace std;

typedef struct Queue{
  int cqueue[5];
  int front, rear, num;
};

void insertCirQueue(Queue *q, int val){
  if (q->front == (q->rear + 1) % q->num){
    cout << "Queue Overflow\n";
    return;
  }
  if (q->front == -1){
    q->front = 0;
    q->rear = 0;
  }
  else{
    q->rear = (q->rear + 1) % q->num;
  }
  q->cqueue[q->rear] = val;
}

void deleteCirQueue(Queue *q){
  if(q->front == -1){
    cout << "Queue Underflow\n";
    return;
  }
  cout << "Element deleted from queue is " << q->cqueue[q->front] << endl;
  if (q->front == q->rear){
    q->front = -1;
    q->rear = -1;
  }
  else{
    q->front = (q->front + 1) % q->num;
  }
}

void displayCirQueue(Queue *q){
  int f = q->front, r = q->rear;
  if(f <= r){
    while(f <= r){
      cout << q->cqueue[f] << " ";
      f++;
    }
  }
  else{
    while(f <= (q->num - 1)){
      cout << q->cqueue[f] << " ";
      f++;
    }
    f = 0;
    while(f <= r){
      cout << q->cqueue[f] << " ";
      f++;
    }
  }
  cout << endl;
}

void cmp(Queue queue1, Queue queue2){
  int count = 0;
  for(int i = 0; i < 5; i++){
    if (queue1.cqueue[i] == queue2.cqueue[i]){
      count++;
    }
  }
  if (count == 5){
    cout << "The Queues are Identical\n";
  }
  else{
    cout << "The Queues are Not Identical\n";
  }
  return;
}

int main(){
  Queue queue1, queue2;
  
  queue1.front = -1;
  queue1.rear = -1;
  queue1.num = 5;
  
  queue2.front = -1;
  queue2.rear = -1;
  queue2.num = 5;
  
  int x, num;
  cout << "1 : Insert an element to Queue 1\n";
  cout << "2 : Insert an element to Queue 2\n";
  cout << "3 : Delete an element from Queue 1\n";
  cout << "4 : Delete an element from Queue 2\n";
  cout << "5 : Display elements in Queue 1\n";
  cout << "6 : Display elements in Queue 2\n";
  cout << "7 : Compare the Queues\n";
  cout << "8 : Exit\n";
  
  do{
    cout << "\nEnter your choice : ";
    cin >> x;
  
    switch(x){
    
      case 1:
        cout << "Enter the value to be inserted in Queue 1 : ";
        cin >> num;
        insertCirQueue(&queue1, num);
        break;
        
      case 2:
        cout << "Enter the value to be inserted in Queue 2 : ";
        cin >> num;
        insertCirQueue(&queue2, num);
        break;
      
      case 3:
        deleteCirQueue(&queue1);
        break;
        
      case 4:
        deleteCirQueue(&queue2);
        break;
    
      case 5:
        displayCirQueue(&queue1);
        break;
        
      case 6:
        displayCirQueue(&queue2);
        break;
      
      case 7:
        cmp(queue1, queue2);
        break;
      
      case 8:
        break;
        
      default:
        cout << "Enter a value between 1 and 8";
    }
  }while(x != 8);
}
