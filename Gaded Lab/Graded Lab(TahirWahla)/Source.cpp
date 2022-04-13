#include <iostream>

using namespace std;
#include"stack.h"
int priority(char alpha) {
    if (alpha == '+' || alpha == '-')
        return 1;

    if (alpha == '*' || alpha == '/')
        return 2;

    if (alpha == '^')
        return 3;


    return 0;
}
string convert(string infix)
{
    int i = 0;
    string postfix = "";
    stack <char>obj(size(infix));

    while (infix[i] != '\0')
    {
      
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z'||infix[i]>='0'&&infix[i]<='9')
        {
            postfix += infix[i];
            i++;
        }
       
        else if (infix[i] == '(')
        {
            obj.push(infix[i]);
            i++;
        }
     
        else if (infix[i] == ')')
        {
            while (obj.topel() != '(') {
                postfix += obj.topel();
                obj.pop();
            }
            obj.pop();
            i++;
        }
        else
        {
            while (!obj.empty() && priority(infix[i]) <= priority(obj.topel())) {
                postfix += obj.topel();
                obj.pop();
            }
            obj.push(infix[i]);
            i++;
        }
    }
    while (obj.empty()) {
        postfix += obj.topel();
        obj.pop();
    }


    cout << "Postfix is : " << postfix; //it will print postfix conversion  
    return postfix;
}

int main()
{
    string infix = "((8+(3*4))-2)";
    string postfix;
    postfix = convert(infix);

    return 0;
}