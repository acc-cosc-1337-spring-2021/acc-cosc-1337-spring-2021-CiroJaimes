//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>
using std::cout;

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(int i = 0; i <= manager.games.size(); i++)
    {
        cout<<manager.games[i];
        cout<<"\n";
    }

    return out;
}
void TicTacToeManager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_wins++;
    }
    else if(winner == "O")
    {
        o_wins++;
    }
    else
    {
        ties++;
    }
    
}

void TicTacToeManager::save_game(TicTacToe game)
{
    games.push_back(game);
    update_winner_count(game.get_winner());
}

void TicTacToeManager::get_winner_totals(int& o, int& x, int& t)
{
    o = o_wins;
    x = x_wins;
    t = ties;
}