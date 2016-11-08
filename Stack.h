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


#ifndef STACK_H
#define STACK_H

#include <assert.h>

// Implementation of a template of a class, which shows a linked stack
template<class DataType>
class Stack
{
	struct Box
	{
		DataType data;  // data
		Box* next;      // pointer to the next element
	};

public:
//Constructors, destructor and copy assignment operator

	// Default constructor
	Stack();

	// Destructor
	~Stack();

	// Copy constructor
	Stack(Stack const&);

	// Copy assignment operator
	Stack& operator=(Stack const&);


// Adding and removing elements and returning the element on the top of the stack

	// Adds an element on the top of the stack
	void Push(const DataType&);

	// Removes an element from the top of the stack
	DataType Pop();

	// Returns the element on the top of the stack
	DataType& Top();


// Information methods

	// Returns the number of elements currunetly stored in the stack
	int GetSize() const;

	// Checks whether the stack is empty
	bool IsEmpty() const;

private:
	Box* top;      // pointer to the top of the stack
	int usedSize;  // number of elements currunetly stored in the stack

// Help functions

	// Initializes the data members of the object
	void Init();

	// Removes all elements in the stack and frees the allocated memory
	void Delete();

	// Makes a copy of the stack
	void Copy(Stack const&);
};

// Constructs an empty stack
template<class DataType>
Stack<DataType>::Stack()
{
	Init();
}

// Destructor
template<class DataType>
Stack<DataType>::~Stack()
{
	Delete();
}

// Copy constructor
template<class DataType>
Stack<DataType>::Stack(Stack const& other)
{
	Init();
	Copy(other); 
}

// Assignment operator
// The operator frees the currently allocated mamory and then performs the copying
template<class DataType>
Stack<DataType>& Stack<DataType>::operator=(Stack<DataType> const & other)
{
	if (this != &other)
	{
		Delete();
		Copy(other);
	}

	return *this;
}

// Adds an element on top of the stack
template<class DataType>
void Stack<DataType>::Push(const DataType& element)
{
	Box* newBox = top;
	top = new Box;
	top->data = element;
	top->next = newBox;
}

// Removes and returns the element on top of the stack
template<class DataType>
DataType Stack<DataType>::Pop()
{
	Box* newBox;   // makes a new box
	if (top)
	{
		DataType element = top->data;
		newBox = top;
		top = top->next;

		delete newBox;

		return element;
	}
	else
		return NULL;
}

// Returns the element on the top of the stack
template<class DataType>
DataType& Stack<DataType>::Top()
{
	// Checks whether the stack is empty
	assert(IsEmpty()); 
	
	return top->data;
}

// Returns the number of elements currunetly stored in the stack
template<class DataType>
int Stack<DataType>::GetSize() const
{
	return usedSize;
}

// Checks whether the stack is empty
template<class DataType>
bool Stack<DataType>::IsEmpty() const
{
	return usedSize == 0;
}

// Initializes the data members of the object
template<class DataType>
void Stack<DataType>::Init()
{
	top = 0;
	usedSize = 0;
}

// Removes all elements in the stack and frees the allocated memory
template<class DataType>
void Stack<DataType>::Delete()
{
	// Makes new box
	Box* newBox;   

	// While there are elements in the stack
	// the new box points to the top of the stack then
	// moves the pointer of the top of the stack to the next element and
	// removes the element
	while (top)            
	{
		newBox = top;      
		top = top->next;   
		delete newBox;     
	}

	Init();
}

// Makes a copy of the stack
template<class DataType>
void Stack<DataType>::Copy(Stack const& other) 
{
	// Checking whether the stack is empty
	assert(IsEmpty()); 

	// If the stack is empty, there is nothing for copying
	if (!other.top) 
		return;  

	Box* newBox = other.top;       // makes new element, which points to the top of the stack
	top = new Box;  // makes help pointer, which points to the bottom of the stack
	Box* bottom = top                            // and allocates memory for the first element
	top->data = newBox->data;   // copies data for the first element
	newBox = newBox->next;     // moves to the second element


	// While there are elements in the stack
	// allocates memory for the new element then
	// moves the pointer of the bottom of the stack to the new element,
	// copies data and moves to the next element
	while (newBox) // while there are elements in the stack
	{
		bottom->next = new Box;       
		bottom = bottom->next;         
		bottom->data = newBox->data;  
		newBox = newBox->next;      
	}

	// moves the pointer of the "next" bottom to NULL
	bottom->next = NULL; 
}

#endif