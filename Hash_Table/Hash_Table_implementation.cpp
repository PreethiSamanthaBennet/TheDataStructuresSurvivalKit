#include <iostream>
#include <list>
using namespace std;

class Hashing {
  int hash_bucket;
  list<int> *hashtable;
  
  public:
    int HashFunction(int a){
      return a % hash_bucket;
    }
/*************************************************/    
    Hashing(int b){
      this->hash_bucket = b;
      hashtable = new list<int>[hash_bucket]; 
    }
/*************************************************/
    void insertKey(int key){
      int index = HashFunction(key);
      hashtable[index].push_back(key);
    }
/*************************************************/
    void deleteKey(int key){
      int index = HashFunction(key);
      list<int>::iterator i;
      
      for(i = hashtable[index]. begin(); i != hashtable[index].end();i++){
        if(*i == key){
          break;
        }
      }
      if(i != hashtable[index].end()){
        hashtable[index].erase(i);
      }
    
    }
/*************************************************/
    void PrintHash(){
      for(int i = 0; i< hash_bucket; i++){
        cout<<i; 
        for(int c:hashtable[i]){
          cout<<" -> "<<c;
        }
        cout<<endl;
      }
    }
/*************************************************/
    int SearchKey(int key){
      int j;
      for(j = 0; j < hash_bucket; j++){
        for(int y: hashtable[j]){
          if(y == key)
            return j+1;
        }
          
      }
      return 0;
    } 
};
/*************************************************/
int main()
{
    int num;
    cout<<"enter the number of buckets"<<endl;
    cin>>num;
    Hashing h(num);
    int choice, x, y;
    
    cout<<"1 -> Insert"<<endl;
    cout<<"2 -> Delete"<<endl;
    cout<<"3 -> Display"<<endl;
    cout<<"4 -> Search Key"<<endl;
    cout<<"5 -> exit"<<endl;
    
    do{
      cout<<"Enter choice"<<endl;
      cin>>choice;
      
      switch(choice){
        case 1:
          cout<<"Enter a value to insert: "<<endl;
          cin>>x;
          h.insertKey(x);
          break;
        case 2:
          cout<<"Enter a value to delete: "<<endl;
          cin>>y;
          h.deleteKey(y);
          break;
        case 3:
          h.PrintHash();
          break;
        case 4:
          int key;
          cout<<"Enter a Search key to be checked: "<<endl;
          cin>>key;
          if(h.SearchKey(key)){
            cout<<key<<" is present in Hash table in bucket "<<h.SearchKey(key)-1<<endl;
          }
          else{
            cout<<key<<" is Not present in Hash table "<<endl;
          }
          break;
        case 5:
          break;
        default:
          cout<<"Enter a value between 1 and 4"<<endl;
      }
   }while(choice != 5);
   
   return 0;
}
