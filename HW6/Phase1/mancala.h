/**************************************************************************
	Header file for class Mancala, which is the child of class
        game, written by Walter Savitch.  It implements the virtual 
        functions provided in the parent class so that they work for
        a game of mancala.
	    Kayleigh Shaw			Spring 2018
****************************************************************************/

#include <string>
#include <cstdlib>
#include <queue>
#include <iostream>
#include "colors.h"
#include "game.h"
using namespace main_savitch_14;

class Mancala : public game {
 public:
  Mancala();
  void make_move(const std::string& move);
  void restart();
  game* clone() const;
  void compute_moves(std::queue<std::string>& moves) const;
  void display_status() const;
  int evaluate() const;
  bool is_game_over() const;
  bool is_legal(const std::string& move) const;
 private:
  int move_to_array(const int& move);
  int board [14];
  static const int P1MANCALA = 0;
  static const int P2MANCALA = 7;
};
