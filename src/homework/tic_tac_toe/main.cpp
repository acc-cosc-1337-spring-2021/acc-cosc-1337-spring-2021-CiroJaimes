#include "tic_tac_toe.h"
#include <iostream>
using namespace std;

int main() 
{
	Game game;
	string player;
	int position;

	cout<<"------------ TIC TAC TOE ------------\n";
	cout<<"Ready to play? Player 1 enter X or O to begin: ";
	cin>>player;

	game.start_game(player);
	game.display_board();

	do
	{
		cout<<"Player "<<game.get_player()<<" Select a spot 1-9 to place your marker. \nEnter '10' to close the board: ";
		cin>>position;
		game.mark_board(position);
		game.display_board();

	}while(position != 10);
	return 0;
}