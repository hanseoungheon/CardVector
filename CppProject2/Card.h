#pragma once
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Core.h"
class Card
{
public:
	Card()
		: id(1), name(nullptr), type(nullptr), cost(0), rarity(1)
	{
		//std::cout << "Caution: DummyCard Created\n";
	}

	Card(int id,const char* name, const char* type, int cost, int rarity)
		: id(id), cost(cost), rarity(rarity)
	{
		if (name != nullptr)
		{
			size_t length = strlen(name) + 1;
			this->name = new char[length];
			strcpy_s(this->name,length,name);
		}

		if (type != nullptr)
		{
			size_t length = strlen(type) + 1;
			this->type = new char[length];
			strcpy_s(this->type, length, type);
		}
	}

	~Card()
	{
		//_CrtSetBreakAlloc(162);
		SafeDelete(name);
		SafeDelete(type);
	}

public:
	//Getter 만 Setter는 필요없을듯?
	int GetId() const
	{
		return id;
	}

	char* GetName() const
	{
		return name;
	}

	char* GetType() const
	{
		return type;
	}

	int GetCost() const
	{
		return cost;
	}

	int GetRarity() const
	{
		return rarity;
	}

private:
	int id;
	char* name = nullptr;
	char* type = nullptr;
	int cost;
	int rarity;

};