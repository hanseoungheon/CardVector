#include "Deck.h"
#include "Input.h"
int main()
{
	static int num = 0;
	Deck deck;
	deck.ReadDeckFile();
	deck.ViewCardInfo(num);
	Input* input = new Input();

	while (true) //그냥 while문 쓸거임.
	{
		if(Input::Get().GetKeyDown(VK_ESCAPE))
		{
			system("cls");
			std::cout << "Escape Key Pressed. Exiting...\n";
			return 0;
		}

		if (Input::Get().GetKeyDown(VK_LEFT) && num > 0)
		{
			system("cls");
			--num; 
			deck.ViewCardInfo(num); 
		} // 만약 왼쪽눌렀는데 현재 인덱스가 0이면?
		else if(input->Get().GetKeyDown(VK_LEFT) && num == 0)
		{
			system("cls"); 
			num = deck.GetInfo().Size() - 1; //num 끝 인덱스로 이동.
			deck.ViewCardInfo(num);
		}

		if(Input::Get().GetKeyDown(VK_RIGHT) && num < deck.GetInfo().Size() - 1)
		{
			system("cls"); 
			++num;
			deck.ViewCardInfo(num);
		} //만약 오른쪽 눌렀는데 현재 인덱스가 끝인덱스이면?
		else if (Input::Get().GetKeyDown(VK_RIGHT) && num == deck.GetInfo().Size() - 1)
		{
			system("cls");
			num = 0; //num 첫번째 인덱스로 이동.
			deck.ViewCardInfo(num); 
		}

	}

	delete input;
}