/**************************************************************************
	Implimentation file for class Mancala, which is the child of class
        game, written by Walter Savitch.  It implements the virtual 
        functions provided in the parent class so that they work for
        a game of mancala.
	    Kayleigh Shaw			Spring 2018
****************************************************************************/

#include <string>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <iomanip>
#include "colors.h"
#include "game.h"
#include "mancala.h"
using namespace main_savitch_14;

Mancala::Mancala(){
    board[0] = 0;
    for(int i = 1; i < 14; i++){
      board[i] = 4;
    }
    board[7] = 0;
  }
void Mancala::make_move(const std::string& move){
    if(next_mover() == HUMAN){
      int i_move = move_to_array(atoi(move.c_str()));
      int stones = board[i_move];
      board[i_move] = 0;
      int i = ++i_move;
      for(i; stones != 0; i++){
	if(i == 14){
	  i = 0;
	}
	if(i == P2MANCALA){
	  i = 8;
	}
	++board[i];
	--stones;
      }
      if(--i == P1MANCALA){
	display_status();
	string move;
	move == get_user_move();
	while(!is_legal(move)){
	  display_message("Illegal move.\n");
	  move = get_user_move();
	}
	make_move(move);
      }
    } else {
      int i_move = move_to_array(atoi(move.c_str()));
      int stones = board[i_move];
      board[i_move] = 0;
      int i = ++i_move;
      for(i; stones != 0; i++){
	if(i == 14){
	  i = 0;
	}
	if(i == P1MANCALA){
	  i = 1;
	}
	++board[i];
	--stones;
      }
      if(--i == P2MANCALA){
	display_status();
	string move;
	move == get_user_move();
	while(!is_legal(move)){
	  display_message("Illegal move.\n");
	  move = get_user_move();
	}
	make_move(move);
      }				
    }
    game::make_move(move);	
  }
  void Mancala::restart(){
    board[P1MANCALA] = 0;
    for(int i = 1; i < 14; i++){
      board[i] = 4;
    }
    board[P2MANCALA] = 0;
  }
  game* Mancala::clone()const{/*return new Mancala(*this);*/}
  void Mancala::compute_moves(std::queue<std::string>& moves) const{}
  void Mancala::display_status() const{
    for(int i = 0; i < 152; i++){
      if (i == 76){std::cout << std::endl;}
      std::cout << B_YELLOW << " ";
    }
    std::cout << std::endl << "               ";
    for(int half = 0; half < 2; half++){
      int desig = 1;
      if(half == 0){
	for(int i = 0; i < 50; i++){
	  if(i % 9 == 0){
	    std::cout << BLUE << desig;
	    desig++;
	  } else {
	    std::cout << " ";
	  }
	}
      }
      if(half == 0){
	std::cout << WHITE << B_YELLOW << "           " << std::endl;
      }
      for(int i = 0; i < 8; i++){
	std::cout << B_YELLOW << "    " << B_BLUE << "     ";
      }
      std::cout << B_YELLOW << "    " << std::endl;
      if(half == 0){
	for(int num = 7; num >= 0; num--){
	  std::cout << B_YELLOW << "    " 
		    << B_BLUE << std::setw(2) << "  " << board[num] << "  ";
	}
      } else {
	std::cout << B_YELLOW << "    " << B_BLUE << "     ";
	for(int num = 8; num < 14; num++){
	  std::cout << B_YELLOW << "    " 
		    << B_BLUE << std::setw(2) << "  " << board[num] << "  ";
	}
	std::cout << B_YELLOW << "    " << B_BLUE << "     ";
      }
      std::cout << B_YELLOW << "    " << std::endl;
      for(int i = 0; i < 8; i++){
	std::cout << B_YELLOW << "    " << B_BLUE << "     ";
      }
      std::cout << B_YELLOW << "    " << std::endl;
      if(half == 0){
	std::cout << B_YELLOW << "    " << B_BLUE << "     ";
	for(int i = 0; i < 58; i++){
	  std::cout << B_YELLOW << " ";
	}
	std::cout << B_BLUE << "     " << B_YELLOW << "    " << std::endl 
		  << B_YELLOW << "    " << B_BLUE << "     ";
	for(int i = 0; i < 58; i++){
	  std::cout << B_YELLOW << " ";
	}
	std::cout << B_BLUE << "     " << B_YELLOW << "    " << std::endl;
      }
      if(half == 1){
	std::cout << "               ";
	for(int i = 0; i < 50; i++){
	  if(i % 9 == 0){
	    std::cout << BLUE << desig;
	    desig++;
	  } else {
	    std::cout << " ";
	  }
	}
      }
    }
    std::cout << B_YELLOW << "           " << std::endl;
  }
  int Mancala::evaluate() const{}
  bool Mancala::is_game_over() const{}
  bool Mancala::is_legal(const std::string& move) const{
    int i_move = atoi(move.c_str());
    if(i_move < 7 && i_move > 0){
      return true;
    } else {
      return false;
    }
  }
  
  int Mancala::move_to_array(const int& move){
    if(next_mover() == HUMAN){
      switch(move){
      case 1:
	return 8;
      case 2:
	return 9;
      case 3:
	return 10;
      case 4:
	return 11;
      case 5:
	return 12;
      case 6:
	return 13;
      }
    } else {
      switch(move){
      case 1:
	return 6;
      case 2:
	return 5;
      case 3:
	return 4;
      case 4:
	return 3;
      case 5:
	return 2;
      case 6:
	return 1;
      }
    }
  }
