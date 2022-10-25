#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "Pawn.h"

using namespace std;

//-----------------------------------PAWN-----------------------------------//

Pawn::Pawn(int colour):Piece(colour){} //constructor

void Pawn::print(){ //print override
  if(colour == 1){
    cout << "P";
  } else {
    cout << "p";
  }
}
void Pawn::printName(int error){ //print name override
  if(error==1){
    if(colour ==1){
      cout << "White's Pawn";
    }else{
      cout << "Black's Pawn";
    }
  }
}

bool Pawn::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const{
  int rowdiff = drow-srow;
  int coldiff = dcol-scol;

  if(coldiff==0){ //pushing pawn manoeuvre
    if(getHasMoved()==0){ //if not moved yet
      if(abs(rowdiff)==2){ //and is trying to move 2 squares
        if(clearPath(srow,scol,drow,dcol,squares,error) && squares[drow][dcol]
        ==nullptr){ //check if anything blocking
          return true;
        }
      } else if(abs(rowdiff)==1 && squares[drow][dcol]==nullptr){ //can move 1 up
        return true;
      }
    }
    if(getHasMoved()!=0){ //if has already moved
      if(abs(rowdiff)==1 && squares[drow][dcol]==nullptr){ //cannot move 1+ up
        return true;
      }
    }
  }

  if(abs(coldiff)==1){ //if taking a piece with pawn
    if(abs(rowdiff)!=1){ // must advance forwards by 1
      if(error==1){
        cerr << "Pawns only move forwards and capture 1 square diagonally.\n";
      }
      return false;
    }
    if(colour==1){ //if white pawn
      if(rowdiff>0){ // must take forwards
        if(error==1){
          cerr << "Pawns only move forwards and capture 1 square diagonally.\n";
        }
        return false;
      }
    } else if(colour==0){ //if black pawn
      if(rowdiff<0){ //must take downwards
        if(error==1){
          cerr << "Pawns only move forwards and capture 1 square diagonally.\n";
        }
        return false;
      }
    }
    return true;
  }

  if(error==1){
    cerr << "Pawns only move forwards and capture 1 square diagonally.\n";
  }
  return false;
}
