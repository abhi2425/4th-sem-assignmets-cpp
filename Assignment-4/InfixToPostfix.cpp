#include <iostream>
#include <stack>
using namespace std;

bool IsAnOperand(char);
bool IsAnOperator(char);
bool eqlOrHigherPrecedence(char, char);
string convertInToPostfix(string);

bool IsAnOperand(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    if (character >= 'a' && character <= 'z')
        return true;
    if (character >= '0' && character <= '9')
        return true;
    return false;
}
bool IsAnOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
int operatorPrecedence(char operators)
{
    if (operators == '^')
        return 3;
    if (operators == '*' || operators == '/')
        return 2;
    if (operators == '+' || operators == '-')
        return 1;

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

string convertInToPostfix(string infixExpression)
{
    stack<char> Stack;
    string postfix = "";
    char ch;

    Stack.push('(');
    infixExpression += ')';

    for (int i = 0; i < infixExpression.length(); i++)
    {
        ch = infixExpression[i];

        if (ch == ' ')
            continue;
        else if (ch == '(')
            Stack.push(ch);
        else if (IsAnOperand(ch))
            postfix += ch;
        else if (IsAnOperator(ch))
        {
            while (eqlOrHigherPrecedence(Stack.top(), ch) && !Stack.empty())
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
    cout << "******INFIX TO POSTFIX CONVERSION******" << endl;

    cout << " Enter an infix expression: ";
    cin >> infixExpression;
    postfixExpression = convertInToPostfix(infixExpression);
    cout << "Postfix expression is: " << postfixExpression << endl;
    return 0;
}