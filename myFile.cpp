
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

/*
-----------------------------------------------------------------------------------------------------------
Question 1*/
void Card::write(){ //display color and value
 switch (col)
 {
    case 0:
    cout << "club " << val <<endl;
        break;
    case 1:
    cout << "diamond " << val <<endl;
        break;
	case 2:
	cout << "heart " << val<<endl;
		break;
    case 3:
	cout << "spade " << val<<endl;
        break;
    default:
    cout << "This card shouldn't exist" ;//this should never happen
        break;
 }
}



/*
--------------------------------------------------------------------------
Question 2
*/



void CardsSet::novSet(){
    for (size_t i = 0; i < 3; i++)
    {
        for (int k = 0; k < 13; k++)
        {
            set[i+k] = Card{(color) i,k};
        }
        
    }
	number = 52;
    
}

void CardsSet::shuffle(){
	srand(time(0));
    for (size_t i = 0; i < 52; i++)
	{
		int r = rand() % 52 ;
		Card temp = set[i];
		set[i] = set[r];
		set[r] = temp;
	}
	
}
Card CardsSet::take(){
    if (number == 0)
	{
		cout << "no cards";
		return Card();
	}
	return set[--number];
	
}

void CardsSet::put(Card k){
	set[number++] = k;
}


Card CardsSet::lookIn(int n){
    return set[n-1];
}

/*
------------------------------------------------------------------------------
Question 3*/

int Player::play(){
	bool keepDrawing;
do
{
	
	Card card = packet.take();
  cout<< "You get Card:" ; card.write();
  inHand.put(card);
  cout<< "Your score is " <<countPoints() << " points"<<endl;
  if (countPoints() > 21)
  {
	return countPoints();
  }
  
cout<< "Any additional Card ?[y/n]";
	do
	{
	  string input;
	  cin >> input;
		if (input == "y" || input == "n" ) // if the input is valid change keepDrawing and break out of the inner loop.
		{
			keepDrawing = (input == "y")? true:false;
			break;        
		}
		cout<< "invalid input";
	} while (1);
 
} while (keepDrawing);



	return countPoints();

}

int Player::countPoints(){
	int sum = 0;
	int numAces = 0;
	for (size_t i = 1; i <= inHand.numCards(); i++)
	{   
		int value = inHand.lookIn(i).value();
		if (value == 1)
		{
			numAces++;
		}
		else{
		sum += value;

		}
	}
	while (numAces-- > 0)
	{
		if (sum + 14 >21) // if ace = 14 goes over 21.
		{
			sum += 1;
		}
		else{ // if it doesn't it becomes 14.
			sum += 14;
		}
		
	}
	
	return sum;
	
}

