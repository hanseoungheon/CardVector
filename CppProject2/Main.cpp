#include "Deck.h"
#include "Input.h"
int main()
{
	static int num = 0;
	Deck deck;
	deck.ReadDeckFile();
	deck.ViewCardInfo(num);
	Input* input = new Input();

	while (true) //�׳� while�� ������.
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
		} // ���� ���ʴ����µ� ���� �ε����� 0�̸�?
		else if(input->Get().GetKeyDown(VK_LEFT) && num == 0)
		{
			system("cls"); 
			num = deck.GetInfo().Size() - 1; //num �� �ε����� �̵�.
			deck.ViewCardInfo(num);
		}

		if(Input::Get().GetKeyDown(VK_RIGHT) && num < deck.GetInfo().Size() - 1)
		{
			system("cls"); 
			++num;
			deck.ViewCardInfo(num);
		} //���� ������ �����µ� ���� �ε����� ���ε����̸�?
		else if (Input::Get().GetKeyDown(VK_RIGHT) && num == deck.GetInfo().Size() - 1)
		{
			system("cls");
			num = 0; //num ù��° �ε����� �̵�.
			deck.ViewCardInfo(num); 
		}

	}

	delete input;
}