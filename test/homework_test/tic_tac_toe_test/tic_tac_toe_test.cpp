#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>
using std::cout;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected."){
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.game_over() == false);
	game.mark_board(5);
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(1);
	REQUIRE(game.game_over() == false);
	game.mark_board(9);
	REQUIRE(game.game_over() == false);
	game.mark_board(8);
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);
	REQUIRE(game.game_over() == false);
	game.mark_board(7);
	REQUIRE(game.game_over() == false);
	game.mark_board(6);
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test the 'start_game' function: Player 'X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test the 'start_game' function: Player 'O'")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test the 'check_diagonal_win' function: Starting from position 1 down to position 9, through position 5")
{
	TicTacToe game;

	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(2); //O
	game.mark_board(5); //X
	game.mark_board(4); //O
	game.mark_board(9); //X
	
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test the 'check_diagonal_win' function: Starting from position 7 up to position 3, through position 5")
{
	TicTacToe game;

	game.start_game("X");
	game.mark_board(7); //X
	game.mark_board(2); //O
	game.mark_board(5); //X
	game.mark_board(4); //O
	game.mark_board(3); //X
	
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test 'check_column_win' function: Starting from position 1 down to 7, through 4")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(2);	//O
	game.mark_board(4); //X
	game.mark_board(3); //O
	game.mark_board(7); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_column_win' function: Starting from position 2 down to 8, through 5")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2); //X
	game.mark_board(1); //O
	game.mark_board(5); //X
	game.mark_board(3); //O
	game.mark_board(8); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_column_win' function: Starting from position 3 down to 9, through 6")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3); //X
	game.mark_board(1);	//O
	game.mark_board(6); //X
	game.mark_board(4); //O
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_row_win' function: Starting from position 1 to 3, through 2")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(4); //O
	game.mark_board(3); //X
	game.mark_board(7); //O
	game.mark_board(2); //X

	REQUIRE(game.game_over() == true);
}


TEST_CASE("Test 'check_row_win' function: Starting from position 4 to 6, through 5")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4); //X
	game.mark_board(3); //O
	game.mark_board(5); //X
	game.mark_board(8); //O
	game.mark_board(6); //X

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test 'check_row_win' function: Starting from position 7 to 9, through 8")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7); //X
	game.mark_board(4); //O
	game.mark_board(8); //X
	game.mark_board(1); //O
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("tests get_winner function")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);//x
	REQUIRE(game.game_over() == false);
	game.mark_board(4);
	REQUIRE(game.game_over() == false);
	game.mark_board(5);//x
	REQUIRE(game.game_over() == false);
	game.mark_board(2);
	REQUIRE(game.game_over() == false);
	game.mark_board(3);//x
	REQUIRE(game.game_over() == true);
	REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Tests manager incrementing function with 3 games")
{
	int o{0}, x{0}, t{0};
	TicTacToe a, b, c;
	TicTacToeManager manager;
	a.start_game("X");
	a.mark_board(7);//X
	REQUIRE(a.game_over() == false);
	a.mark_board(4);
	REQUIRE(a.game_over() == false);
	a.mark_board(5);//X
	REQUIRE(a.game_over() == false);
	a.mark_board(2);
	REQUIRE(a.game_over() == false);
	a.mark_board(3);//X
	REQUIRE(a.game_over() == true);
	manager.save_game(a);
	manager.get_winner_totals(o,x,t);
	REQUIRE(x == 1);
	REQUIRE(o == 0);
	REQUIRE(t == 0);

	b.start_game("O");
	b.mark_board(4);//O
	REQUIRE(b.game_over() == false);
	b.mark_board(3);
	REQUIRE(b.game_over() == false);
	b.mark_board(5);//O
	REQUIRE(b.game_over() == false);
	b.mark_board(8);
	REQUIRE(b.game_over() == false);
	b.mark_board(6);//O
	REQUIRE(b.game_over() == true);
	manager.save_game(b);
	manager.get_winner_totals(o,x,t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 0);

	c.start_game("X");
	REQUIRE(c.game_over() == false);
	c.mark_board(5);
	REQUIRE(c.game_over() == false);
	c.mark_board(4);
	REQUIRE(c.game_over() == false);
	c.mark_board(1);
	REQUIRE(c.game_over() == false);
	c.mark_board(9);
	REQUIRE(c.game_over() == false);
	c.mark_board(8);
	REQUIRE(c.game_over() == false);
	c.mark_board(2);
	REQUIRE(c.game_over() == false);
	c.mark_board(3);
	REQUIRE(c.game_over() == false);
	c.mark_board(7);
	REQUIRE(c.game_over() == false);
	c.mark_board(6);
	REQUIRE(c.game_over() == true);
	manager.save_game(c);
	manager.get_winner_totals(o,x,t);
	REQUIRE(x == 1);
	REQUIRE(o == 1);
	REQUIRE(t == 1);
}