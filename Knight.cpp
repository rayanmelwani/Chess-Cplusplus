#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "Knight.h"

using namespace std;

//-----------------------------------KNIGHT-----------------------------------//

Knight::Knight(int colour):Piece(colour){} //constructor

void Knight::print(){ //print override
  if(colour == 1){
    cout << "N";
  } else {
    cout << "n";
  }
}

void Knight::printName(int error){ //print name override
  if(error==1){
    if(colour ==1){
      cout << "White's Knight";
    }else{
      cout << "Black's Knight";
    }
  }
}

bool Knight::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE],int error)const{

  int rowdiff = drow-srow;
  int coldiff = dcol-scol;

  if(abs(rowdiff)==2&&abs(coldiff)==1){ //checking if correct knight manoeuvre
    return true;
  } else if(abs(coldiff)==2&&abs(rowdiff)==1){
    return true;
  }
  if(error==1){
    cerr << "Knights move in an L shape.\n";
  }
  return false;
}
