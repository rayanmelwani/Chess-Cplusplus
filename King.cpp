#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"
#include "King.h"

using namespace std;


//-----------------------------------KING-----------------------------------//

King::King(int colour):Piece(colour){ //constructor
  king=1;
}

void King::print(){ //print override
  if(colour == 1){
    cout << "K";
  } else {
    cout << "k";
  }
}

void King::printName(int error){ //print name override
  if(error==1){
    if(colour ==1){
      cout << "White's King";
    }else{
      cout << "Black's King";
    }
  }
}

bool King::canMove(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE],int error)const{

  int rowdiff = drow-srow;
  int coldiff = dcol-scol;
  int kingcolour = getColour();

  if(abs(rowdiff)>1 || abs(coldiff)>1){ //cannot move more than 1 sq any direction
    if(error==1){
      cerr << "The King cannot move more than 1 square in any direction.\n";
    }
    return false;
  }
  for(int i=0;i<BOARDSIZE;i++){ //iterating through board
    for(int j=0;j<BOARDSIZE;j++){
      if(squares[i][j]!=nullptr){ //if square not empty
        if(squares[i][j]->getColour()!=kingcolour){ //if piece is opposite colour
          if(squares[i][j]->canMove(i,j,drow,dcol,squares,0)){
            if(error==1){ //king cannot move to dest square attacked by piece
              cerr << "The King cannot move to this square as it will be attacked.\n";
            }
            return false;
          }
        }
      }
    }
  }

  return true;
}
