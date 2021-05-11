#include <bits/stdc++.h>

using namespace std;

bool isAnOperator(char operators)
{
    if (operators == '+' || operators == '-' || operators == '*' || operators == '/' || operators == '^')
        return true;
    return -1;
}
bool isAnOperand(char operand)
{
    if (operand >= '0' && operand <= '9')
        return true;
    return -1;
}
float operationToPerform(int currentChar, int nextChar, char operation)
{
    if (operation == '+')
        return nextChar + currentChar;
    else if (operation == '-')
        return nextChar - currentChar;
    else if (operation == '*')
        return nextChar * currentChar;
    else if (operation == '/')
        return nextChar / currentChar;
    else if (operation == '^')
        return pow(nextChar, currentChar);
    else
        return INT8_MIN;
}
float scanNum(char ch)
{
    int value;
    value = ch;
    cout << float(value - '0');
    return float(value - '0'); //return float from character
}

float postfixNotationEvaluation(string postfixExpression)
{
    string::iterator character;
    int currentChar, nextChar;
    stack<float> Stack;

    for (character = postfixExpression.begin(); character != postfixExpression.end(); character++)
    {
        if (isAnOperator(*character) != -1) // passing the reference, coz iterator stores address
        {
            currentChar = Stack.top();
            Stack.pop();
            nextChar = Stack.top();
            Stack.pop();
            Stack.push(operationToPerform(currentChar, nextChar, *character));
        }
        else if (isAnOperand(*character) > 0)
        {
            Stack.push(scanNum(*character));
        }
    }

    return Stack.top();
}
int main()
{
    string postfixExpression;
    cout << "****Postfix Evaluation using Stack****" << endl;
    cout << "Enter the postfix expression-:" << endl;
    cin >> postfixExpression;
    float result = postfixNotationEvaluation(postfixExpression);
    cout << result;
    return 0;
}