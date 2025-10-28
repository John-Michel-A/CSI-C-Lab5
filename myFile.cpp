
#include <iostream>
using namespace std;

#include "myFile.h"
#include "Card.h"
#include "CardsSet.h"
#include "Player.h"

int main() {
	CardsSet packet;
	Player you(packet, false);
	Player me(packet, true);
	char answer[3];
	bool continuous = true;
	cout << "Hello! " << endl;
	while (continuous)
	{
		cout << "A new game? " << endl;
		cin >> answer;
		continuous = answer[0] == 'y';
		if (continuous)
		{
			packet.novSet();
			packet.shuffle();
			packet.take();
			int p1 = you.play();
			if (p1 > 21) {
				cout << "You lost! " << endl;
			}
			else if (p1 == 21) {
				cout << "You won! " << endl;
			}
			else // the computer must play
			{
				int p2 = me.play();
				if (p2 <= 21 && p2 >= p1) {
					cout << "You lost! " << endl;
				}
				else {
					cout << "You won! " << endl;
				}
			}
		}
	}
	return 0;
}





/*Question 2*/


void CardsSet::novSet(){
    for (size_t i = 0; i < 3; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            set[i+k] = Card{(color) i,k};
        }
        
    }
    
}

void CardsSet::shuffle(){
    
}
Card CardsSet::take(){
    
}

void CardsSet::put(Card k){
    
}

Card CardsSet::lookIn(int n){
    
}

