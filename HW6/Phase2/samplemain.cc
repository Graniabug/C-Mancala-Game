/*****************************************************
This is a sample of what the main should like for the second phase of 
the Mancala game.The only change is that the game now announces a 
winner.
	John Dolan	Ohio University		Spring 2018
*************************************************************/
#include<iostream>
#include "mancala.h"
using namespace std;
using namespace main_savitch_14;


int main(){
  Mancala stonegame;
  game::who winner;
  winner=stonegame.play();
  if (winner == game::HUMAN)
    std::cout<<"Player 1 Wins\n";
  else
    std::cout<<"Player 2 Wins\n";
  return 0;
}

