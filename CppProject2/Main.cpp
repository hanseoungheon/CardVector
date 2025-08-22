#include "Deck.h"
#include <Windows.h>
int main()
{
	Deck deck;
	deck.ReadDeckFile();
	deck.ViewCardInfo(2);

}