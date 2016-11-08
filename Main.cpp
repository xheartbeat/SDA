/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Nevena Mihaylova Gadzheva
* @idnumber 61938
* @task 1
* @compiler VC
*
*/


#include "stdafx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>

using namespace std;

#include "Stack.h"
#include "DynamicArray.h"


// Checks whether the symbol is operator
bool isOperator(const char);

// Checks whether the symbol is digit
bool isDigit(const char);

// Returns operation
int Operator(char, int, int);

// Converts a prefix expression to postfix expression
DynamicArray<char> Convert(const DynamicArray<char>&);

// Calculates a postfix expression
void Calculate(DynamicArray<char>);

int main()
{

	string exprLine;
	

	DynamicArray<char>prefixExpr;



	ifstream prefixExpression("PostfixExpression.txt");
	if (prefixExpression.is_open())
	{
		while (prefixExpression.good())
		{
			getline(prefixExpression, exprLine);
			
			cout << exprLine << endl;
		}
	}
	else
		cout << "Unable to open" << endl;

	cout << endl;

	for (int i = 0; i < exprLine.size(); ++i)
	{
		prefixExpr.Add(exprLine[i]);
	}
	
	
	DynamicArray<char> postfixExpr;
	
	
	postfixExpr = Convert(prefixExpr);
	postfixExpr.Print();
	cout << postfixExpr.GetSize() << endl;  // Изкарва ми, че няма елементи
	
	Calculate(Convert(prefixExpr)); // Въобще не ми влиза във функцията

	cout << endl;

	prefixExpression.close();
	

	system("pause");

    return 0;
}

bool isOperator(const char symbol)
{
	if ((symbol == 'a') || (symbol == 'b') || (symbol == 'c') || (symbol == 'd') || (symbol == 'e') || (symbol == 'f'))
		return true;
	else
		return false;
}

bool isDigit(const char symbol)
{
	if (symbol >= '0' && symbol <= '9')
		return true;
	else
		return false;
}


int Operator(char oper, int number1, int number2)
{
	switch (oper)
	{
	case 'a': return number1 + number2;
		break;
	case 'b': return number1 + number2;
		break;
	case 'c': return number1 - number2;
		break;
	case 'd': return number1 * number2;
		break;
	case 'e': return number2 / number1;
		break;
	case 'f': return number1 / number2;
		break;
	default: return NULL;
	}
}

DynamicArray<char> Convert(const DynamicArray<char>& expression)
{
	DynamicArray<char> polish;
	Stack<char> operators;
	Stack<char> space;

	for (int i = 0; i < expression.GetSize(); i++)
	{
		if (isOperator(expression[i]))
			operators.Push(expression[i]);
		else if (expression[i] == ' ')
			space.Push(expression[i]);
		else if (expression[i] == '-')
			polish.Add(expression[i]);
		else if (isDigit(expression[i]))
		{
			polish.Add(expression[i]);
			if (expression[i + 1] == ' ')
			{
				polish.Add(space.Pop());
				if (isDigit(expression[i - 2]))
				{
					polish.Add(operators.Pop());
					polish.Add(space.Pop());
				}
				else
					continue;
			}
			else
				continue;
		}
		else
			throw exception("ERROR");
	}

	while (space.Pop())
	{
		polish.Add(' ');
		polish.Add(operators.Pop());
	}

	polish.Print();
	cout << polish.GetSize() << endl;

	return polish;
}

void Calculate(DynamicArray<char> postfixExpression)
{
	cout << postfixExpression.GetSize() << endl;
}
