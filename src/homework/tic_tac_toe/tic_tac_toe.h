//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
#include <vector>
#include <string>
#include <iostream>

using std::string;
using std::vector;

class TicTacToe{
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe&);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);
    
    public:

        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player()const{return player;}
        string get_winner(){return winner;}


    private:

        vector<string> pegs{9, " "};
        string player, winner;
        void clear_board();
        bool check_board_full();
        void set_next_player();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();

};

#endif