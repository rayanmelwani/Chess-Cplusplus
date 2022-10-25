#ifndef PAWN_H
#define PAWN_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------PAWN-----------------------------------//

class Pawn : public Piece {
public:
  Pawn(int colour); //constructor
  ~Pawn()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const override; //legal move override
};

#endif
