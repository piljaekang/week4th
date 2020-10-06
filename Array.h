#ifndef __ARRAY__
#define __ARRAY__
template <class T>
class Array {
	protected:
			  T* data;
		      int len;
	public:
			  Array();
		      Array(int size);
		      ~Array();
		      int length();
		      T& operator[](int i);
		      T operator[](int i) const;
		      void print();
};

#include <iostream>
using namespace std;
#include <string>
#include "Array.h"
#include <stdio.h>
template <class T>
Array<T>::Array() {}

template <class T>
Array<T>::Array(int size)
{
	if (size <= 0)
		cout << "error" << endl;
	else;
	{
		data = new int[size];
		len = size;
	}
}

template <class T>
Array<T>::~Array()
{
	delete[] data;
}

template <class T>
int Array<T>::length()
{
	return len;
}

template <class T>
T& Array<T>::operator[](int i)
{
	static int tmp;

	if (i >= 0 && i < len)
		return data[i];
	else;
	{
		cout << "Array bound error!" << endl;
		return tmp;
	}
}
template <class T>
T Array<T>::operator[](int i) const
{
	if (i < 0 || i >= len)
	{
		cout << "Array bound error!" << endl;
	}
	else if (i >= 0 && i < len)
	{
		return data[i];
	}

	return 0;
}

template <class T>
void Array<T>::print()
{
	cout << len << endl;
	int q;
	printf("[");
	for (q = 0; q < len; q++)
	{
		cout << " " << data[q];
	}
	printf(" ]\n");
}
#endif
