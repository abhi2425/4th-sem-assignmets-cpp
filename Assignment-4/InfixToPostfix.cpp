#include <iostream>
#include <stack>
using namespace std;

bool IsOperator(char);
bool IsOperand(char);
bool eqlOrHigherPrecedence(char, char);
string convert(string);

bool IsOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

bool IsOperand(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    if (character >= 'a' && character <= 'z')
        return true;
    if (character >= '0' && character <= '9')
        return true;
    return false;
}
int operatorPrecedence(char operators)
{
    if (operators == '+' || operators == '-')
        return 1;
    if (operators == '*' || operators == '/')
        return 2;
    if (operators == '^')
        return 3;
    return 0;
}
bool eqlOrHigherPrecedence(char operator_1, char operator_2)
{
    int precedence_1 = operatorPrecedence(operator_1);
    int precedence_2 = operatorPrecedence(operator_2);
    if (precedence_1 == precedence_2)
    {
        if (operator_1 == '^')
            return false;
        return true;
    }
    return (precedence_1 > precedence_2 ? true : false);
}

string convert(string infix)
{
    stack<char> Stack;
    string postfix = "";
    char ch;

    Stack.push('(');
    infix += ')';

    for (int i = 0; i < infix.length(); i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;
        else if (ch == '(')
            Stack.push(ch);
        else if (IsOperand(ch))
            postfix += ch;
        else if (IsOperator(ch))
        {
            while (!Stack.empty() && eqlOrHigherPrecedence(Stack.top(), ch))
            {
                postfix += Stack.top();
                Stack.pop();
            }
            Stack.push(ch);
        }
        else if (ch == ')')
        {
            while (!Stack.empty() && Stack.top() != '(')
            {
                postfix += Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
    }
    return postfix;
}
int main()
{
    string infixExpression, postfixExpression;
    char choice;
    cout << "******INFIX TO POSTFIX CONVERSION******" << endl;
    do
    {
        cout << " Enter an infix expression: ";
        cin >> infixExpression;
        postfixExpression = convert(infixExpression);
        cout << "Postfix expression is: " << postfixExpression << endl;
        cout << "\n Do you want to enter infix expression (y/n)?" << endl;
        cin >> choice;
    } while (choice == 'y');
    return 0;
}