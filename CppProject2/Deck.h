#pragma once
#include "Vector.h"
#include "Card.h"

//�ϴ� ���� �ؾ��ϴ°� �����ؾߵ� ī�忡�� �Ľ��� ���� ������ �Ľ��� ����?
//ī�忡�� �Ľ��� �Ѵٸ� ���� �����ؼ� �� �κи� �Ľ��ϸ� �ɰŰ�����?
//�׳� ������ �ϴ°� �����Ű����� 
class Deck
{

public:
	Deck()
	{

	}

	void ReadDeckFile()
	{
		FILE* file = nullptr;
		const char* Path = "../CardDB.txt";
		fopen_s(&file, Path, "rt");

		if (file == nullptr)
		{
			std::cout << "������ �дµ� �����Ͽ����ϴ�.\n";
			return;
		}


		//���ÿ� �Ҵ�� file�� ������Ű�� �ּҸ� ������ �� ������ �̵�.
		fseek(file, 0, SEEK_END);

		size_t fileSize = ftell(file); //ftell�� ����Ͽ� ���� ��ġ�� ���� �� fileSzie������ ����

		rewind(file); //�ٽ� ������ �����ּҷ� �̵�.

		char* buffer = new char[fileSize + 1];
		memset(buffer, 0, fileSize + 1); // 0���� �ʱ�ȭ.

		//���� �б�.
		size_t readSzie = fread(buffer, sizeof(char), fileSize, file);

		//�Ľ�.
		char* context = nullptr; //�߸��� ��ġ�� ������ ������.
		char* token = nullptr; //���ڿ� ������ ������.

		token = strtok_s(buffer, "\n", &context);
		//token���� \n���� �޾Ƽ� �ٸ��� �и�. �ϴ� ���� �и�.

		while (token != nullptr)
		{
			//","�� �и��Ұ��� ����
			//,�� �и��ؾߵ� ������ ���???
			//���� id�� ���� �� ������ ,%s �� �����ϴ°�?
			//�� ������ ���Ϳ� �߰��ع�����.
			//����� �׳� ��� �����ϴ°� ������? �Ƹ�?
			//�ּҸ� �����ع����� �̻�����.
			char header[10] = { };
			char nameHeader[10] = { };
			char typeHeader[10] = { };
			
			//ī�� id ����� ����.
			int cardId = 0;
			const char* cardName = nullptr;
			const char* cardType = nullptr;
			int cardCost = 0;
			int cardRarity = 0;
			//���⼭ �� ���θ� ó���ؾ��ϴµ�..

			char* innerToken = nullptr;
			char* innerContext = nullptr;

			//�ݺ��� ���� �ȵɵ�? ���� �ݺ��ؾߵ�.
			//token�� �ٽ� �ڸ���.
			innerToken = strtok_s(token, ",", &innerContext);

			sscanf_s(innerToken, "%d", &cardId);
			innerToken = strtok_s(nullptr, ",", &innerContext);

			sscanf_s(innerToken, "%s", nameHeader, 10);
			cardName = nameHeader;
			innerToken = strtok_s(nullptr, ",", &innerContext);

			sscanf_s(innerToken, "%s", typeHeader, 10);
			cardType = typeHeader;
			innerToken = strtok_s(nullptr, ",", &innerContext);

			sscanf_s(innerToken, "%d", &cardCost);
			innerToken = strtok_s(nullptr, ",", &innerContext);

			sscanf_s(innerToken, "%d", &cardRarity);
			//������ �ڿ��� ,�� ����

			//���� ���� ī�� �߰��ϱ�.
			Info.Push_Back(Card(cardId, cardName, cardType, cardCost, cardRarity));

			token = strtok_s(nullptr, "\n", &context);
			//�� ���� �� �и�
		}
	}

	void ViewCardInfo(int num)
	{
		std::cout
			<< "Id: " << Info[num].GetId() << "\n"
			<< "Name : " << Info[num].GetName() << "\n"
			<< "Type : " << Info[num].GetType() << "\n"
			<< "Cost : " << Info[num].GetCost() << "\n"
			<< "Rairity : " << Info[num].GetRarity();
	}

private:

	Vector<Card> Info;
};