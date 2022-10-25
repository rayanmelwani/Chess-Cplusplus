#ifndef BISHOP_H
#define BISHOP_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------BISHOP-----------------------------------//

class Bishop : public Piece {
public:
  Bishop(int colour); //constructor
  ~Bishop()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const override; //legal move override
};

#endif
