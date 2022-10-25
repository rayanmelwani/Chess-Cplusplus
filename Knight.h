#ifndef KNIGHT_H
#define KNIGHT_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------KNIGHT-----------------------------------//

class Knight : public Piece {
public:
  Knight(int colour); //constructor
  ~Knight()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const override; //legal move override
};

#endif
