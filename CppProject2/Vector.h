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
	void ReAllocate(int newCapacity) //capacity 동적으로 증가시키는 함수.
	{
		//1. 새로운 공간할당.
		T* newBlock = new T[newCapacity];
		memset(newBlock, 0, sizeof(int) * newCapacity);

		//data의 값을 비어있는 배열인 newBlock에 복사시키기.
		memcpy(newBlock, data, sizeof(int) * capacity);

		//아래 for문과 같음.
		//for (int i = 0; i < capacity; ++i)
		//{
		//	newBlock[i] = data[i]; //위 memcpy와 동일한 과정. 근데 memcpy가 더 빠름.
		//}

		//이제 데이터 옮기기.
		delete[] data;
		data = nullptr;

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