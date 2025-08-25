#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:
	Vector()
		:size(0), capacity(2) // ĳ�Ľ�Ƽ�� �⺻ 2.
	{
		data = new T[capacity];
	}

	~Vector()
	{
		if(data != nullptr)
			delete[] data;
	}

	//������ �߰� �Լ�.
	void Push_Back(const T& newData)
	{
		if (size == capacity)
		{
			ReAllocate( 2 * capacity);
		}

		data[size] = newData;

		++size;
	}

	void Push_Back(const T*& newData)
	{
		if (size == capacity)
		{
			ReAllocate( 2 * capacity);
		}

		data[size] = *newData;

		++size;
	}

	void Push_Back(T&& newData_RValue) //�����ε�.
	{
		if (size == capacity)
		{
			ReAllocate(2 * capacity);
		}

		data[size] = std::move(newData_RValue);

		++size;
	}

	T& operator[](int index) //[] ������ �������̵�
	{
		if (index < 0 || index >= size)
		{
			__debugbreak(); //����� �ɸ��� ����.
		}

		return data[index];
	}

	const T& operator[](int index) const //const �ȸ���� ���߿� �����ϴ�.
	{
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}

	//���� �Լ�. �� �����Լ�.
	T& At(int index)
	{
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}

	void Set(int index, T& newData)
	{
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		
		data[index] = newData;
	}

	T* begin()
	{
		return data;
	}

	T* end()
	{
		return data + size;
	}

public:
	//��Ÿ �ζ��� �Լ���.
	inline T* Data() const 
	{ 
		return data; 
	}

	inline int Size() const 
	{ 
		return size; 
	}

	inline int Capacity() const 
	{
		return capacity; 
	}

private:
	void ReAllocate(int newCapacity)
	{
		// 1. ���ο� ���� �Ҵ� (ũ�� Ȯ���ؼ�)

		// ���� ũ�⿡ 2�� Ȯ��.
		newCapacity = capacity * 2;
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. ���� �� ����/�̵�.
		memcpy(newBlock, data, sizeof(T) * capacity);
		//for (int ix = 0; ix < capacity; ++ix)
		//{
		//	newBlock[ix] = std::move(data[ix]);
		//}

		// 3. �پ� �޸� ���� ���� �� ������Ʈ.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}
private:
	T* data = nullptr;

	//���� �迭�� ���� ����� ����
	int size = 0;

	//���� �迭�� ���� ������ ũ�� �̸� �Ҵ��� ���¿뵵.
	int capacity = 0;
};