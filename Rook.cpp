#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "Rook.h"

using namespace std;

//-----------------------------------ROOK-----------------------------------//

Rook::Rook(int colour):Piece(colour){} //constructor

void Rook::print(){ //print override
  if(colour == 1){
    cout << "R";
  } else {
    cout << "r";
  }
}

void Rook::printName(int error){ //print name override
  if(error==1){
    if(colour ==1){
      cout << "White's Rook";
    }else{
      cout << "Black's Rook";
    }
  }
}

bool Rook::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const{
  int rowdiff = drow-srow;
  int coldiff = dcol-scol;

  if(rowdiff!=0 && coldiff!=0){ //need to move only horizontally or vertically
    if(error==1){
      cerr << "Rooks move horizontally and vertically.\n";
    }
    return false;
  }
  if(!clearPath(srow,scol,drow,dcol,squares,error)){ //if rook path is not clear
    return false;
  }
  return true;
}
