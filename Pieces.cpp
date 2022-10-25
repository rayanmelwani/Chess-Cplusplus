#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "Pieces.h"

using namespace std;

//-----------------------------------PIECES-----------------------------------//

Piece::Piece(int colour):colour(colour){ //constructor
  hasMoved=0;
  king=0;
}

int Piece::getColour()const{ //getter function for piece colour
  return colour;
}

int Piece::getHasMoved()const{ //accessing the has moved flag
  return hasMoved;
}

void Piece::setHasMoved(){ //setting the has moved flag to 1
  hasMoved = 1;
}

int Piece::getKing()const{ //accessing the king flag
  return king;
}

bool Piece::clearPath(const int srow, const int scol, const int drow, const int dcol,
  Piece* const squares[BOARDSIZE][BOARDSIZE], int error)const{
  int rowdiff = drow-srow; //calculates row & col differences
  int coldiff = dcol-scol;

  int rowsign=0;
  int colsign=0;
  if(rowdiff!=0){ //calculates sign (-1 or +1)
    rowsign = rowdiff/abs(rowdiff);
  }
  if(coldiff!=0){
    colsign = coldiff/abs(coldiff);
  }

  if(rowdiff==0){ //checking rook path horizontally
    for(int i=1;i<abs(coldiff);i++){
      if(squares[srow][scol+i*colsign]!=nullptr){
        if(error==1){
          cerr << "There is a piece in the way. Could not make horizontal move!\n";
        }
        return false;
      }
    }
  } else if(coldiff==0){ //checking rook/pawn path vertically
    for(int i=1;i<abs(rowdiff);i++){
      if(squares[srow+i*rowsign][scol]!=nullptr){
        if(error==1){
          cerr << "There is a piece in the way. Could not make vertical move!\n";
        }
        return false;
      }
    }
  } else if(abs(rowdiff)==abs(coldiff)){ //checking bishop diagonals
    for(int i=1;i<abs(rowdiff);i++){
      if(squares[srow+i*rowsign][scol+i*colsign]!=nullptr){
        if(error==1){
          cerr << "There is a piece in the way. Could not make diagonal move!\n";
        }
        return false;
      }
    }
  }
  return true; //otherwise path is clear
}
