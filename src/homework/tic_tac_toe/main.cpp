#include<memory>
using std::unique_ptr; using std::make_unique;

#include <string>
using std::string;

#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
using std::cout; using std::cin;
string go_again;

int main() 
{
  
  
  TicTacToeManager manager;  
  
  int x;  
  int o;
  int t;

  do  
  {
  
    unique_ptr<TicTacToe> game;

    string game_type;
    
    

    do
    {
      cout<<"Enter '3' for 3x3 board or '4' for 4x4 board: \n";
      cin>>game_type;

      if(game_type == "3")
      {
        game = make_unique<TicTacToe3>();
      }
      else if(game_type == "4")
      {
        game = make_unique<TicTacToe4>();
      }
    }
    while(!(game_type == "3" || game_type == "4")); 



    string first_player;

    do
    {
      cout<<"Please enter first player. (Enter X or O): \n";
      cin>> first_player;

      if (first_player == "x")
      {
        first_player = "X";
      }
      else if (first_player == "o")
      {
        first_player = "O";
      }
    }
    while(!(first_player == "X" || first_player == "O")); 
    game->start_game(first_player);

    cout<<*game; 

    do
    {
      cin>>*game;

      cout<<*game; 
    }
    while(!(game->game_over()));
        
  
    cout<<"GAME OVER. The winner was: " << game->get_winner() << "\n";

    manager.save_game(game); 
    
    manager.get_winner_total(o, x, t); 
    cout<<"Games Winning Tally: \n";
    cout<<"O wins: " << o << "\n";
    cout<<"X wins: " << x << "\n";
    cout<<"Ties: " << t << "\n";
    
    cout<<"Would you like to play again? Type 'Y' or 'y' to play again. \n";
    cin>>go_again;

    
  }
  while(go_again == "Y" || go_again == "y");
	
  cout<<"-------------------------------------------------------------------- \n";
  cout<<"Displaying game boards history: \n";
  cout<<manager; 

  manager.get_winner_total(o, x, t);
  cout<<"Final Games Winning Tally: \n";
  cout<<"O wins: " << o << "\n";
  cout<<"X wins: " << x << "\n";
  cout<<"Ties: " << t << "\n\n";

  cout<<"Thanks for playing.";
    
  return 0;
}