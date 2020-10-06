#include "Array.h"
template <class U>
class GrowableArray : public Array<U> {
protected:
	U * arr;
public:
	GrowableArray(int num);
	~GrowableArray();
	U& operator[](int num);
};

#include <iostream>
#include <string>
using namespace std;
#include "Array.h"

template <class U>
GrowableArray<U>::GrowableArray(int num)
{
	this->data = new U[num];
	this->len = num;
}
template <class U>
GrowableArray<U>::~GrowableArray()
{
	delete[] arr;
}

template <class U>
U& GrowableArray<U>::operator[](int num)
{
	int i;

	if (num >= this->len)
	{
		arr = new U[this->len];

		for (i = 0; i < this->len; i++)
			arr[i] = this->data[i];

		this->data = new U[num * 2];

		for (i = 0; i < this->len; i++)
			this->data[i] = arr[i];

		for (i = this->len; i < num * 2; i++)
			this->data[i] = 0;

		this->len = 2 * num;

		return this->data[num];
	}
	else if (num >= 0 && num < this->len)
	{
		return this->data[num];
	}

}

