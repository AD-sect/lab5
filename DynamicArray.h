#pragma once
#include <iostream>
#include"Exception.h"
#include <cmath>
#include <stdlib.h>


template <typename T>
class DynamicArray
{
private:
	T* m_mas = nullptr;
	int m_size = 0;
public:

	DynamicArray() = default;

	DynamicArray(int size)
	{
		m_size = size;

		if (m_size < 0)
			throw IndexIsNegative();

		this->m_mas = new T[size];
	}

	DynamicArray(T* m_mas, int count) : DynamicArray(count)
	{
		std::memcpy(this->m_mas, m_mas, count * sizeof(T));
	}

	DynamicArray(DynamicArray<T> const& dynamicArray) : DynamicArray(dynamicArray->m_mas, dynamicArray->m_size) {}

	T Get(int index)
	{
		if (index < 0 || index >= m_size)
			throw IndexOutOfRange();
		return m_mas[index];
	}

	int GetSize()
	{
		return m_size;
	}

	void Set(int index, T value)
	{

		if (index < 0 || index >= m_size)
			throw IndexOutOfRange();
		m_mas[index] = value;
	}

	void Resize(int newSize)
	{
		if (newSize < 0)
			throw IndexOutOfRange();

		if (this->m_size == 0)
		{
			T* newMas = new T[newSize];
			delete[] this->m_mas;
			this->m_mas = newMas;
			this->m_size = newSize;
		}

		else
		{
			T* newMas = new T[newSize];
			memcpy(newMas, m_mas, newSize * sizeof(T));
			delete[] this->m_mas;
			this->m_mas = newMas;
			this->m_size = newSize;
		}
	}

	void Print()
	{
		for (int i = 0; i < m_size; ++i)
		{
			if (i % 10 == 0 && i != 0)
				std::cout << m_mas[i] << std::endl;
			else
				std::cout << m_mas[i] << " ";
		}
	}

	~DynamicArray()
	{
		delete[] m_mas;
		m_size = 0;
	}
};

