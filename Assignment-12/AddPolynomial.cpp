#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    int coefficient;
    int power;
    struct Node *next;
};

void readPolynomial(struct Node **polynomial)
{
    int coefficient, exp;
    char choice;
    struct Node *newNode = new Node;
    *polynomial = newNode;
    do
    {
        cout << "Value of Coefficient-:" << endl;
        cin >> coefficient;
        cout << "Value of Exponent-:" << endl;
        cin >> exp;
        newNode->coefficient = coefficient;
        newNode->power = exp;
        newNode->next = NULL;
        cout << "Have more terms ? Press any key for Yes and 0 for No:" << endl;
        cin >> choice;
        if (choice != '0')
        {
            newNode->next = new Node;
            newNode = newNode->next;
            newNode->next = NULL;
        }
    } while (choice != '0');
}

void displayPolynomial(struct Node *polynomial)
{
    cout << "Polynomial Expression is-:";
    while (polynomial != NULL)
    {
        cout << polynomial->coefficient << "x^" << polynomial->power;
        polynomial = polynomial->next;
        if (polynomial != NULL)
            cout << " + ";
    }
    cout << endl;
}

void addPolynomials(struct Node **result, struct Node *first, struct Node *second)
{
    struct Node *newNode = new Node;
    newNode->next = NULL;
    *result = newNode;
    while (first && second)
    {
        if (first->power > second->power)
        {
            newNode->coefficient = first->coefficient;
            newNode->power = first->power;
            first = first->next;
        }
        else if (first->power < second->power)
        {
            newNode->coefficient = second->coefficient;
            newNode->power = second->power;
            second = second->next;
        }
        else
        {
            newNode->coefficient = first->coefficient + second->coefficient;
            newNode->power = first->power;
            first = first->next;
            second = second->next;
        }

        if (first && second)
        {
            newNode->next = new Node;
            newNode = newNode->next;
            newNode->next = NULL;
        }
    }
    while (first || second)
    {
        newNode->next = new Node;
        newNode = newNode->next;
        newNode->next = NULL;

        if (first)
        {
            newNode->coefficient = first->coefficient;
            newNode->power = first->power;
            first = first->next;
        }
        else if (second)
        {
            newNode->coefficient = second->coefficient;
            newNode->power = second->power;
            second = second->next;
        }
    }
}

int main()
{

    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *result = NULL;
    cout << endl;
    cout << "****Adding Of Polynomial using Linked List****" << endl;

    cout << "Enter First polynomial" << endl;
    readPolynomial(&first);
    displayPolynomial(first);

    cout << "Enter Second polynomial" << endl;
    readPolynomial(&second);
    displayPolynomial(second);

    addPolynomials(&result, first, second);
    cout << "Added ";
    displayPolynomial(result);
    return 0;
}