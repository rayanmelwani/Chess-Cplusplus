#ifndef PIECES_H
#define PIECES_H

#include "Const.h"

//-----------------------------------PIECES-----------------------------------//

class Piece{ //abstract class
protected:
  int colour;
  int hasMoved=0;
  int king=0;
public:
  Piece(int colour); //constructor
  virtual ~Piece(){}; //virtual destructor
  virtual void print()=0; //pure virtual print function
  virtual void printName(int error)=0; //pure virtual print name function
  int getColour()const; //getter function for colour
  int getHasMoved()const; //accessing the has moved flag
  void setHasMoved(); //setting has moved flag to 1
  int getKing()const; //accessing the king flag
  bool clearPath(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const; //function to check if clearpath
  virtual bool canMove(const int srow, const int scol, const int drow, const int dcol,
    Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const=0; //function to check poss move
};

#endif
