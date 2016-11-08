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


#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<assert.h>

// Implementation of a template of a class, which shows a dynamic array
template<class DataType>
class DynamicArray
{
public:
//Constructors, destructor and copy assignment operator

	// Default constructor
	DynamicArray();

	// Destructor
	~DynamicArray();

	//Copy constructor
	DynamicArray(const DynamicArray &);

	// Copy assignment operator
	DynamicArray& operator=(const DynamicArray&);
	
// Operators for access

	// Operator functions for indexing
	const DataType& operator[](int) const;
	DataType& operator[](int);

	// Adds an element at the end of the array
	void Add(DataType);

	// Prints the elements of the array
	void Print() const;


// Information methods

	// Returns the number of elements currunetly stored in the array
	int GetSize() const;

	// Returns the allocated memory for the array
	int GetCapaity() const;

	// Checks whether the stack is empty
	bool IsEmpty() const;

private:
	DataType* data;
	int usedSize;
	int capacity;


// Help functions

	// Initializes the data members of the object
	void Init();

	// Removes all elements in the array and frees the allocated memory
	void Delete();

	// Makes a copy of the array
	void Copy(const DynamicArray&);

	// Resizes the array
	void Resize(int);
};

// Constructs an empty array
template<class DataType>
DynamicArray<DataType>::DynamicArray()
{
	Init();
}

// Destructor
template<class DataType>
DynamicArray<DataType>::~DynamicArray()
{
	Delete();
}


// Copy constructor
template<class DataType>
DynamicArray<DataType>::DynamicArray(const DynamicArray& other)
{
	Init();
	Copy(other);
}

// Assignment operator
// The operator frees the currently allocated mamory and then performs the copying
template<class DataType>
DynamicArray<DataType>& DynamicArray<DataType>::operator=(const DynamicArray& other)
{
	if (this != &other)
	{
		Delete();
		Copy(other);
	}

	return *this;
}

// Constant operation function for indexing
template<class DataType>
const DataType& DynamicArray<DataType>::operator[](int index) const
{
	//assert(index < usedSize);

	return data[index];
}

// Non-constant operation function for indexing
template<class DataType>
DataType& DynamicArray<DataType>::operator[](int index)
{
	//assert(index < usedSize);

	return data[index];
}

// Adds an element at the end of the array
template<class DataType>
void DynamicArray<DataType>::Add(DataType element)
{
	if (usedSize >= capacity)
	{
		int newSize = (capacity == 0 ? 2 : capacity * 2);
		Resize(newSize);
	}
	data[usedSize++] = element;
}

// Returns the number of elements currunetly stored in the array
template<class DataType>
int DynamicArray<DataType>::GetSize() const
{
	//assert(usedSize != 0);

	return usedSize;
}

// Returns the allocated memory for the array
template<class DataType>
int DynamicArray<DataType>::GetCapaity() const
{
	assert(capacity != 0);

	return capacity;
}

// Checks whether the array is empty
template<class DataType>
bool DynamicArray<DataType>::IsEmpty() const
{
	return usedSize == 0;
}

// Prints the elements of the array
template<class DataType>
void DynamicArray<DataType>::Print() const
{
	for (int i = 0; i < usedSize; i++)
	{
		cout << data[i];
	}
	cout << endl;
}

// Initializes the data members of the object
template<class DataType>
void DynamicArray<DataType>::Init()
{
	data = NULL;
	usedSize = 0;
	capacity = 0;
}

// Removes all elements in the array and frees the allocated memory
template<class DataType>
void DynamicArray<DataType>::Delete()
{
	delete[] data;
	data = NULL;
	usedSize = 0;
	capacity = 0;
}

// Makes a copy of the array
template<class DataType>
void DynamicArray<DataType>::Copy(const DynamicArray& other)
{
	capacity = capacity ? capacity : 1;
	data = new DataType[capacity];
	for (int i = 0; i < usedSize; i++)
	{
		data[i] = other[i];
	}
}

// Resizes the array
template<class DataType>
void DynamicArray<DataType>::Resize(int newCapacity)
{
	DataType* newData = new DataType[newCapacity];

	for (int i = 0; i < usedSize && i < newCapacity; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
}
#endif