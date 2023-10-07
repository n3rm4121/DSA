#include <iostream>
#include <stack>
using namespace std;

bool areBalanced(string x){
    stack<char> temp;
    for (int i = 0; i < x.length(); i++)
    {
        if(temp.empty()){
        temp.push(x[i]);
         }
         else if(temp.top() == '(' && x[i] == ')'
                 || temp.top() == '{' && x[i] == '}'
                 || temp.top() == '[' && x[i] == ']'
                 ){
                    temp.pop();
                 }else  
                    temp.push(x[i]);

    }
    if(temp.empty()){
        return true;
    }
    return false;
    
    
    }

int main(){
     string x;
    cout << "Enter parenthesis characters: ";
    cin >> x;
   
    if(areBalanced(x)){
        cout << "Balanced" << endl;
    }else{
        cout << "not balanced" << endl;
    }

}