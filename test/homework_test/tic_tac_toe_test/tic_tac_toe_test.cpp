#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected."){
	Game game1;

	game1.start_game("X");
	game1.mark_board(1);
	REQUIRE(game1.game_over() == false);

	game1.start_game("O");
	game1.mark_board(2);
	REQUIRE(game1.game_over() == false);

	game1.start_game("X");
	game1.mark_board(3);
	REQUIRE(game1.game_over() == false);

	game1.start_game("O");
	game1.mark_board(4);
	REQUIRE(game1.game_over() == false);

	game1.start_game("X");
	game1.mark_board(5);
	REQUIRE(game1.game_over() == false);

	game1.start_game("O");
	game1.mark_board(7);
	REQUIRE(game1.game_over() == false);

	game1.start_game("X");
	game1.mark_board(8);
	REQUIRE(game1.game_over() == false);

	game1.start_game("O");
	game1.mark_board(6);
	REQUIRE(game1.game_over() == false);

	game1.start_game("X");
	game1.mark_board(9);
	REQUIRE(game1.game_over() == true);
}

TEST_CASE("Test the 'start_game' function: Player 'X")
{
	Game game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test the 'start_game' function: Player 'O'")
{
	Game game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test the 'check_diagonal_win' function: Starting from position 1 down to position 9, through position 5")
{
	Game game;

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
	Game game;

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
	Game game;
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
	Game game;
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
	Game game;
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
	Game game;
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
	Game game;
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
	Game game;
	game.start_game("X");
	game.mark_board(7); //X
	game.mark_board(4); //O
	game.mark_board(8); //X
	game.mark_board(1); //O
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
}