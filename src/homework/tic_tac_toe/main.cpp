/*Play more than one game
Allow user to quit the game
Display winner of game*/

#include "tic_tac_toe.h"
#include <iostream>
using namespace std;

int main() 
{
	Game game;
	string player;
	int position;
	string again = "Y";

	while(again == "Y" || again == "y")
	{
			cout<<"------------ TIC TAC TOE ------------\n";
			cout<<"Ready to play? Player 1 enter X or O to begin: ";
			cin>>player;

		while (player != "X" || player != "O")
		{
			cout<<"Player one, select X or O: ";
			cin>>player;
			if (player == "X" || player == "O")
			{
				break;
			}
		}
		game.start_game(player);
		game.display_board();

		while(game.game_over() == false)
		{
			cout<<"Player "<<game.get_player()<<", Pick a position (1-9): ";
			cin>>position;
			
			while(position < 1 || position > 9)
			{
				cout<<"That position doesn't exist! Please try again: ";
				cin>>position;
			}
			game.mark_board(position);
			game.display_board();
		}
	if(game.get_winner() == "C")
	{
		cout<<"Cat's Scratch!";
	}
	
	else
	cout<<"Player "<<game.get_winner()<<" has WON!\n";
	cout<<"Enter Y to play again: ";
	cin>>again;
	}
	
	return 0;
}