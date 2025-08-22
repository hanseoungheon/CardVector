#pragma once
#include "Vector.h"
#include "Card.h"

//일단 지금 해야하는게 선택해야됨 카드에서 파싱을 할지 덱에서 파싱을 할지?
//카드에서 파싱을 한다면 줄을 선택해서 그 부분만 파싱하면 될거같은데?
//그냥 덱에서 하는게 좋을거같은데 
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
			std::cout << "파일을 읽는데 실패하였습니다.\n";
			return;
		}


		//스택에 할당된 file이 가리기키는 주소를 파일의 맨 끝으로 이동.
		fseek(file, 0, SEEK_END);

		size_t fileSize = ftell(file); //ftell을 사용하여 현재 위치를 구한 후 fileSzie변수에 저장

		rewind(file); //다시 파일의 시작주소로 이동.

		char* buffer = new char[fileSize + 1];
		memset(buffer, 0, fileSize + 1); // 0으로 초기화.

		//파일 읽기.
		size_t readSzie = fread(buffer, sizeof(char), fileSize, file);

		//파싱.
		char* context = nullptr; //잘리는 위치를 저장할 포인터.
		char* token = nullptr; //문자열 저장할 포인터.

		token = strtok_s(buffer, "\n", &context);
		//token에서 \n으로 받아서 줄마다 분리. 일단 한줄 분리.

		while (token != nullptr)
		{
			//","로 분리할거임 이제
			//,로 분리해야됨 하지만 어떻게???
			//먼저 id를 따로 뺀 다음에 ,%s 로 구분하는건?
			//그 다음에 벡터에 추가해버리자.
			//헤더는 그냥 계속 재사용하는게 나을듯? 아마?
			//주소를 공유해버리니 이상해짐.
			char header[10] = { };
			char nameHeader[10] = { };
			char typeHeader[10] = { };
			
			//카드 id 저장용 템프.
			int cardId = 0;
			const char* cardName = nullptr;
			const char* cardType = nullptr;
			int cardCost = 0;
			int cardRarity = 0;
			//여기서 줄 내부를 처리해야하는데..

			char* innerToken = nullptr;
			char* innerContext = nullptr;

			//반복문 쓰면 안될듯? 직접 반복해야됨.
			//token을 다시 자르기.
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
			//어차피 뒤에는 ,가 없음

			//이제 덱에 카드 추가하기.
			Info.Push_Back(Card(cardId, cardName, cardType, cardCost, cardRarity));

			token = strtok_s(nullptr, "\n", &context);
			//그 다음 줄 분리
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