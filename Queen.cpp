#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "Queen.h"

using namespace std;

//-----------------------------------QUEEN-----------------------------------//

Queen::Queen(int colour):Piece(colour){} //constructor

void Queen::print(){ //print override
  if(colour == 1){
    cout << "Q";
  } else {
    cout << "q";
  }
}

void Queen::printName(int error){ //print name override
  if(error==1){
    if(colour==1){
      cout << "White's Queen";
    }else{
      cout << "Black's Queen";
    }
  }
}

bool Queen::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const{
  int rowdiff = drow-srow;
  int coldiff = dcol-scol;

  if(!clearPath(srow,scol,drow,dcol,squares,error)){ //if queen path is not clear
    return false;
  }
  if((abs(rowdiff)==abs(coldiff) || rowdiff==0 || coldiff==0)){ //neither rook/bishop move
    return true;
  }
  if(error==1){
    cerr << "The Queen moves like a rook or bishop.\n";
  }
  return false;

}
