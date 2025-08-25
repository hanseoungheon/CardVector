#pragma once
#include <iostream>

template<typename T>
class Vector
{
public:
	Vector()
		:size(0), capacity(2) // 캐파시티는 기본 2.
	{
		data = new T[capacity];
	}

	~Vector()
	{
		if(data != nullptr)
			delete[] data;
	}

	//데이터 추가 함수.
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

	void Push_Back(T&& newData_RValue) //오버로딩.
	{
		if (size == capacity)
		{
			ReAllocate(2 * capacity);
		}

		data[size] = std::move(newData_RValue);

		++size;
	}

	T& operator[](int index) //[] 연산자 오버라이딩
	{
		if (index < 0 || index >= size)
		{
			__debugbreak(); //디버그 걸리게 만듬.
		}

		return data[index];
	}

	const T& operator[](int index) const //const 안만들면 나중에 못씁니당.
	{
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}

		return data[index];
	}

	//접근 함수. 및 설정함수.
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
	//기타 인라인 함수들.
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
		// 1. 새로운 공간 할당 (크기 확장해서)

		// 기존 크기에 2배 확장.
		newCapacity = capacity * 2;
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(T) * newCapacity);

		// 2. 기존 값 복사/이동.
		memcpy(newBlock, data, sizeof(T) * capacity);
		//for (int ix = 0; ix < capacity; ++ix)
		//{
		//	newBlock[ix] = std::move(data[ix]);
		//}

		// 3. 다쓴 메모리 공간 해제 및 업데이트.
		delete[] data;
		data = newBlock;
		capacity = newCapacity;
	}
private:
	T* data = nullptr;

	//벡터 배열의 현재 요소의 갯수
	int size = 0;

	//벡터 배열의 저장 공간의 크기 미리 할당해 놓는용도.
	int capacity = 0;
};