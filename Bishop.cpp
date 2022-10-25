#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "Bishop.h"

using namespace std;

//-----------------------------------BISHOP-----------------------------------//

Bishop::Bishop(int colour):Piece(colour){} //constructor

void Bishop::print(){ //print override
  if(colour == 1){
    cout << "B";
  } else {
    cout << "b";
  }
}

void Bishop::printName(int error){ //print name override
  if(error==1){
    if(colour ==1){
      cout << "White's Bishop";
    }else{
      cout << "Black's Bishop";
    }
  }
}

bool Bishop::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const{
  int rowdiff = drow-srow;
  int coldiff = dcol-scol;

  if(abs(rowdiff)!=abs(coldiff)){ //difference in rows & cols must be same
    if(error==1){
      cerr << "Bishops must move along a diagonal.\n";
    }
    return false;
  }
  if(!clearPath(srow,scol,drow,dcol,squares,error)){ //if bishop path not clear
    return false;
  }
  return true;
}
