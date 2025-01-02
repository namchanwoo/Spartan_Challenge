#include <iostream>
#include <algorithm>

template <typename T>
class SimpleVector
{
public:
	// 기본 생성자: 초기 용량은 10
	SimpleVector() : currentSize(0), currentCapacity(10)
	{
		data = new T[currentCapacity];
	}

	SimpleVector(int capacity = 10) : currentSize(0), currentCapacity(capacity)
	{
		data = new T[currentCapacity];
	}

	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity)
	{
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; ++i)
		{
			data[i] = other.data[i];
		}
	}

	~SimpleVector()
	{
		delete[] data;
	}


	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			// 용량이 가득 찼으면 5만큼 늘린다
			resize(currentCapacity + 5);
		}
		data[currentSize] = value;
		currentSize++;
	}

	void pop_back()
	{
		if (currentSize > 0)
		{
			currentSize--;
		}
	}

	void resize(int newCapacity)
	{
		if (newCapacity <= currentSize)
		{
			return;
		}

		T* newData = new T[newCapacity];

		for (int i = 0; i < currentSize; ++i)
		{
			newData[i] = data[i];
		}

		delete[] data;

		data = newData;
		currentCapacity = newCapacity;
	}

	void sortData()
	{
		std::sort(data, data + currentSize);
	}

	int size() const
	{
		return currentSize;
	}

	int capacity() const
	{
		return currentCapacity;
	}

private:
	T* data;            
	int currentSize;    
	int currentCapacity;
};
