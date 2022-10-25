#ifndef ROOK_H
#define ROOK_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------ROOK-----------------------------------//

class Rook : public Piece {
public:
  Rook(int colour); //constructor
  ~Rook()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error )const override; //legal move override
};

#endif
