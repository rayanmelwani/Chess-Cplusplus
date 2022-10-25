#ifndef KING_H
#define KING_H

#include "Const.h"
#include "Pieces.h"

//-----------------------------------KING-----------------------------------//

class King : public Piece {
public:
  King(int colour); //constructor
  ~King()=default; //destructor
  void printName(int error) override; //printName override
  void print() override; //print override
  bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const override; //legal move override
};


#endif
