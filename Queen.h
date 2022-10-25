#ifndef QUEEN_H
#define QUEEN_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------QUEEN-----------------------------------//

class Queen : public Piece {
public:
  Queen(int colour); //constructor
  ~Queen()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const override; //legal move override
};

#endif
