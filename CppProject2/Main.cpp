#include "Deck.h"
#include "Input.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	static int num = 0;
	Deck deck;
	deck.ReadDeckFile();
	deck.ViewCardInfo(num);
	//std::cout << "\n";
	//std::cout << "\n";
	//deck.ViewCardInfo(num + 1);

	Input input;
	//std::cout << "\n" << num;
	while (true) //그냥 while문 사용하면 될듯?
	{
		
		//std::cout << "\n" << num;
		input.SavePreviouseKeyStates();

		input.ProcessInput();

		if(Input::Get().GetKeyDown(VK_ESCAPE))
		{
			system("cls");
			std::cout << "Escape Key Pressed. Exiting...\n";
			return 0;
		}

		if (Input::Get().GetKeyDown(VK_LEFT) && num > 0)
		{
			--num;
			system("cls");
			deck.ViewCardInfo(num); 
		} // 만약 왼쪽눌렀는데 현재 인덱스가 0이면?
		else if(Input::Get().GetKeyDown(VK_LEFT) && num == 0)
		{
			num = deck.GetInfo().Size() - 1; //num 끝 인덱스로 이동.
			system("cls"); 
			deck.ViewCardInfo(num);
		}

		if(Input::Get().GetKeyDown(VK_RIGHT) && num < deck.GetInfo().Size() - 1)
		{
			++num;
			system("cls"); 
			deck.ViewCardInfo(num);
		} //만약 오른쪽 눌렀는데 현재 인덱스가 끝인덱스이면?
		else if (Input::Get().GetKeyDown(VK_RIGHT) && num == deck.GetInfo().Size() - 1)
		{
			num = 0; //num 첫번째 인덱스로 이동.
			system("cls");

			deck.ViewCardInfo(num); 
		}

	}
}

enum asd
{

};