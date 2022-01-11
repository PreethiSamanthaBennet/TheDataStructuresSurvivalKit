#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char);
bool isOperand(char);
int precedence(char);
bool equal_or_higher(char,char);
string reverse(string);
string convert(string);

int main(){
  string infixExpression, prefixExpression;
  int ch;
  cout<<"press the enter key to start"<<endl;
  
  do{
    cin.ignore(256, '\n');
    cout<<"enter the infix expression: "<<endl;
    getline(cin,infixExpression);
    prefixExpression = convert(reverse(infixExpression));
    cout<<"the infix expression is:"<<infixExpression<<endl;
    cout<<"the prefix expression is:"<<reverse(prefixExpression);
    cout<<"\ndo you want to continue(1/0)? ";
    cin>>ch;
    cout<<endl;
  }while(ch == 1);
  
  return 0;
}

string reverse(string str){
  int n = str.length();
  
  for(int i = 0; i< n / 2; i++){
    swap(str[i], str[n - i - 1]);
  }
  return str;
}

bool isOperator(char c){
  if(c == '+' || c == '-'|| c == '*'|| c == '/'|| c == '^')
    return true;
  return false;
}

bool isOperand(char c){
  if(c >= 'A' && c <= 'Z')
    return true;
    
  if(c >= 'a' && c <= 'z')
    return true;
    
  if(c >= '0' && c <= '9')
    return true;
return false;
}

int precedence(char op){
  if(op == '+'|| op == '-')
      return 1;
    
  if(op == '*'|| op == '/')
      return 2;
    
  if(op == '^')
      return 3;
return 0;    
}

bool equal_or_higher(char op1, char op2){
  int p1 = precedence(op1);
  int p2 = precedence(op2);
  
  if(p1 == p2){
    if(op1 == '^')
      return false;
  }
  return(p1>p2 ? true : false);
}

string convert(string infix){
  stack <char> S;
  string prefix = "";
  char ch;
  for(int i = 0; i < infix.length(); i++){
    if(infix[i] == '('){
      infix[i] = ')';
      i++;
    }
    else if(infix[i] == ')'){
      infix[i] = '(';
      i++;
    }
  }
  
  S.push('(');
  infix += ')';
    
    for (int i = 0; i < infix.length(); i++)
    {  
        ch = infix[i];  
  
        if(ch == ' ' && !isOperator(infix[i+1]))
        {
            prefix += ' ';
            continue;
        }
             
        if(ch == '(')  
            S.push(ch);
             
             
        else if(isOperand(ch))
        {
            prefix += ch;
        }
             
        else if(isOperator(ch))
        {  
            while(!S.empty() && equal_or_higher(S.top(), ch))
            {
                prefix += S.top();
                S.pop();
            }
            S.push(ch);
            
        }
          
        else if(ch == ')')
        {  
            while(!S.empty() && S.top() != '(')
            {  
                prefix += S.top();  
                S.pop();
            }  
            S.pop();
        }  
    }  
    return prefix;  
}  
