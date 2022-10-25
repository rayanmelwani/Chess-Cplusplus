#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <cmath>

#include "Const.h"
#include "ChessBoard.h"
#include "Pieces.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

using namespace std;

ChessBoard::ChessBoard(){//constructor
  move=0; //initialise move to 0 (white to move)
  check=0; //initialise check to 0 (no kings under attack)
  end=0; //initialise end to 0
  for(int i=0; i<BOARDSIZE; i++){ //iterate through board and fill with nullptr
    for(int j=0; j<BOARDSIZE; j++){
      squares[i][j]=nullptr;
    }
  }
  for(int i=0; i<BOARDSIZE; i++){ //placing black and white pawns on board
    Piece* wpawn = new Pawn(1);
    Piece* bpawn = new Pawn(0);
    squares[6][i]=wpawn;
    squares[1][i]=bpawn;
  }

  Piece* wrook1 = new Rook(1); // placing rooks in correct squares
  Piece* wrook2 = new Rook(1);
  Piece* brook1 = new Rook(0);
  Piece* brook2 = new Rook(0);
  squares[7][0]=wrook1;
  squares[7][7]=wrook2;
  squares[0][0]=brook1;
  squares[0][7]=brook2;

  Piece* wknight1 = new Knight(1);
  Piece* wknight2 = new Knight(1);
  Piece* bknight1 = new Knight(0);
  Piece* bknight2 = new Knight(0);
  squares[7][1]=wknight1; //placing knights in correct squares
  squares[7][6]=wknight2;
  squares[0][1]=bknight1;
  squares[0][6]=bknight2;

  Piece* wbishop1 = new Bishop(1);
  Piece* wbishop2 = new Bishop(1);
  Piece* bbishop1 = new Bishop(0);
  Piece* bbishop2 = new Bishop(0);
  squares[7][2]=wbishop1; //placing bishops in correct squares
  squares[7][5]=wbishop2;
  squares[0][2]=bbishop1;
  squares[0][5]=bbishop2;

  Piece* wqueen = new Queen(1);
  Piece* bqueen = new Queen(0);
  squares[7][3]=wqueen; //placing queens in correct squares
  squares[0][3]=bqueen;

  Piece* wking = new King(1);
  Piece* bking = new King(0);
  squares[7][4]=wking; //placing kings in correct squares
  squares[0][4]=bking;

  cout << "A new chess game is started!" << endl;
}

ChessBoard::~ChessBoard(){ //destructor (need to free existing board pieces)
  for(int i=0; i<BOARDSIZE; i++){ //iterate through board
    for(int j=0; j<BOARDSIZE; j++){
      if(squares[i][j]!=nullptr){
        delete squares[i][j]; //free pieces and fix dangling pointer
        squares[i][j]=nullptr;
      }
    }
  }
}

int ChessBoard::getMove()const{ //function to get move
  return move;
}
int ChessBoard::getCheck()const{//function to get check
  return check;
}
int ChessBoard::getEnd()const{ //function to get end
  return end;
}

ChessBoard& ChessBoard::operator=(ChessBoard const& other){ //assignment operator
  this->move=other.getMove(); //copying over states
  this->end=other.getEnd();
  this->check=other.getCheck();

  for(int i=0;i<BOARDSIZE;i++){ //clearing current board
    for(int j=0;j<BOARDSIZE;j++){
      if(this->squares[i][j]!=nullptr){
        delete this->squares[i][j];
        squares[i][j]=nullptr;
      }
    }
  }

  for(int i=0; i<BOARDSIZE;i++){ //copy over stuff from other
    for(int j=0;j<BOARDSIZE;j++){
      this->squares[i][j]=other.getPiece(i,j);
    }
  }
  return *this;
}

ChessBoard::ChessBoard(ChessBoard const& other){ //copy constructor
  *this = other;
}

void ChessBoard::resetBoard(){

  move=0; //reinitialise move to 0 (white to move)
  check=0; //reinitialise check to 0 (no kings under attack)
  end=0; //initialise end to 0
  for(int i=0; i<BOARDSIZE; i++){ //iterate through board & clean all
    for(int j=0; j<BOARDSIZE; j++){
      if(squares[i][j]!=nullptr){
        delete squares[i][j]; //free pieces and fix dangling pointer
        squares[i][j]=nullptr;
      }
    }
  }

  for(int i=0; i<BOARDSIZE; i++){ //placing black and white pawns on board
    Piece* wpawn = new Pawn(1);
    Piece* bpawn = new Pawn(0);
    squares[6][i]=wpawn;
    squares[1][i]=bpawn;
  }

  Piece* wrook1 = new Rook(1); // placing rooks in correct squares
  Piece* wrook2 = new Rook(1);
  Piece* brook1 = new Rook(0);
  Piece* brook2 = new Rook(0);
  squares[7][0]=wrook1;
  squares[7][7]=wrook2;
  squares[0][0]=brook1;
  squares[0][7]=brook2;

  Piece* wknight1 = new Knight(1);
  Piece* wknight2 = new Knight(1);
  Piece* bknight1 = new Knight(0);
  Piece* bknight2 = new Knight(0);
  squares[7][1]=wknight1; //placing knights in correct squares
  squares[7][6]=wknight2;
  squares[0][1]=bknight1;
  squares[0][6]=bknight2;

  Piece* wbishop1 = new Bishop(1);
  Piece* wbishop2 = new Bishop(1);
  Piece* bbishop1 = new Bishop(0);
  Piece* bbishop2 = new Bishop(0);
  squares[7][2]=wbishop1; //placing bishops in correct squares
  squares[7][5]=wbishop2;
  squares[0][2]=bbishop1;
  squares[0][5]=bbishop2;

  Piece* wqueen = new Queen(1);
  Piece* bqueen = new Queen(0);
  squares[7][3]=wqueen; //placing queens in correct squares
  squares[0][3]=bqueen;

  Piece* wking = new King(1);
  Piece* bking = new King(0);
  squares[7][4]=wking; //placing kings in correct squares
  squares[0][4]=bking;

  cout << "A new chess game is started!\n" << endl;

}

void ChessBoard::printBoard()const{ //function to print current board state
  int widthsize=5;

  cout << "Current board state:\n\n";

  cout.width(widthsize);
  cout << " " ;

  for(char c='A'; c<'I'; c++){ //prints out col letters
    cout.width(widthsize);
    cout << c;
  }
  cout << endl << endl;

  for(int i=0; i<BOARDSIZE; i++){
    cout.width(widthsize);
    cout << BOARDSIZE-i; //prints out row numbers
    for(int j=0; j<BOARDSIZE; j++){
      cout.width(widthsize);
      if(squares[i][j]==nullptr){
        cout << '.'; //if empty square print .
      } else {
        squares[i][j]->print(); //print out values if not empty
      }
    }
    cout << endl << endl;
  }
  cout << endl;
}

bool ChessBoard::whiteToMove()const{ //function that returns T if white to move
  if(move%2==0){
    return true;
  }
  return false;
}

Piece* ChessBoard::getPiece(const int row, const int col)const{ //function to check & return contents of square
  if(squares[row][col]==nullptr){
    return nullptr;
  }
  return squares[row][col];
}

bool ChessBoard::validSquares(const int srow, const int scol, const int drow,
  const int dcol, int error)const{ //function to check if valid src&dest squares

  int rowdiff = drow-srow;
  int coldiff = dcol-scol;
  Piece* p=nullptr;
  Piece* d=nullptr;
  char position[2];
  position[0] = scol + 'A';
  position[1]= '1' + BOARDSIZE-1 - srow;

  if(srow<0||scol<0||drow<0||dcol<0){ //rows/cols cannot be less than 0
    if(error==1){
      cerr << "Row & col values must be from A-H and 1-8!\n";
    }
    return false;
  }
  if(srow>7||scol>7||drow>7||dcol>7){ //rows/cols cannot be more than 7
    if(error==1){
      cerr << "Row & col values must be from A-H and 1-8!\n";
    }
    return false;
  }
  if(rowdiff==0&&coldiff==0){ //cannot not move piece at all
    if(error==1){
      cerr << "An actual move has not been specified (not moving at all)!\n";
    }
    return false;
  }

  int piececolour=0; //getting piece colour
  if(whiteToMove()){
    piececolour=1;
  }

  p=getPiece(srow, scol);
  if(p==nullptr){ //source square not actually pointing to a piece
    if(error==1){
      cerr << "There is no piece at position " << position << "!\n";
    }
    return false;
  }

  if(p->getColour()!=piececolour){ //if white to move, src piece must be white
    if(error==1){
      cerr << "It is not";
      if(piececolour==1){
        cerr << " Black's ";
      } else {
        cerr << " White's ";
      }
      cerr << "turn to move!\n";
    }
    return false;
  }

  d=getPiece(drow, dcol); //if destination square has piece
  if(d!=nullptr){
    if(d->getColour()==p->getColour()){ //piece cannot be same colour
      if(error==1){
        cerr << "The destination square cannot have the same coloured piece!\n";
      }
      return false;
    }
  }
  return true; //otherwise, look at piece movement
}

int ChessBoard::findKing(int colour)const{ //function to find king square
  int square=0;
  for(int i=0;i<BOARDSIZE;i++){ //iterates through the board
    for(int j=0;j<BOARDSIZE;j++){
      if(squares[i][j]!=nullptr){
        if(squares[i][j]->getKing()==1){ //if finds king piece
          if(squares[i][j]->getColour()==colour){ //if correct colour
            square+=i*ROWVAL;
            square+=j;
            return square;
          }
        }
      }
    }
  }
  return square;
}

bool ChessBoard::evalPinsChecks(const int srow, const int scol, const int drow,
  const int dcol, int error){ //function to eval if moving a pinned piece / resolves a check

  int piececolour = 1;
  int kingcolour = 0;
  if(whiteToMove()){ //if white to move, look for white king and black pieces
    piececolour = 0;
    kingcolour=1;
  }

  int kingloc = findKing(kingcolour); //finding white/black king
  int kingrow=kingloc/ROWVAL;
  int kingcol=kingloc%ROWVAL;

  Piece* p = getPiece(srow, scol); //getting source piece
  Piece* d = getPiece(drow, dcol); //getting destination piece / nullptr

  squares[drow][dcol]=p; //making move
  squares[srow][scol]=nullptr;

  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
      if(squares[i][j]!=nullptr){
        if(squares[i][j]->getColour()==piececolour){ //find black piece
          if(squares[i][j]->canMove(i,j,kingrow,kingcol,squares,0)){
            if(error==1){ //if error flag set
              if(check==1){
                cerr << "A King is still in check. Illegal move!\n";
              }
              else{
                cerr << "You cannot move a pinned piece. Illegal move!\n";
              }
            }
            squares[srow][scol]=p; //moving pieces back
            squares[drow][dcol]=d;
            p=nullptr; //fixing dangling pointers
            d=nullptr;
            return false;
          }
        }
      }
    }
  }
  squares[srow][scol]=p; //moving pieces back regardless
  squares[drow][dcol]=d;
  p=nullptr; //fixing dangling pointers
  d=nullptr;
  return true;
}

bool ChessBoard::validMove(const int srow, const int scol, const int drow,
  const int dcol, int error){ //function that checks if a move is valid

  char position[2];
  position[0] = dcol + 'A';
  position[1]= '1' + BOARDSIZE-1 - drow;
  Piece* p=nullptr;
  if(!validSquares(srow,scol,drow,dcol,error)){ //if not valid squares or piece does not exist
    return false;
  }
  p = getPiece(srow,scol); //get piece on source square

  if(!p->canMove(srow,scol,drow,dcol,squares,error)){ //if piece cannot move
    if(error==1){
      p->printName(error);
      cout << " cannot move to " << position << endl;
    }
    p=nullptr; //fix dangling pointer
    return false;
  }

  if(!evalPinsChecks(srow, scol, drow, dcol,error)){ //if moving a pinned piece
    p=nullptr;
    return false;
  }
  return true;
}

bool ChessBoard::isCheck()const{ //function to check if king attacked after move
  int piececolour = 1;
  int kingcolour = 0;
  if(whiteToMove()){ //if white to move, look for white king and black pieces
    piececolour = 0; //else opposite
    kingcolour=1;
  }
  int kingloc = findKing(kingcolour); //finding white/black king
  int kingrow=kingloc/ROWVAL;
  int kingcol=kingloc%ROWVAL;

  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
      if(squares[i][j]!=nullptr){
        if(squares[i][j]->getColour()==piececolour){ //finds black/white piece
          if(squares[i][j]->canMove(i,j,kingrow,kingcol,squares,0)){ //if king in check
            return true; //print out king is being attacked & return true
          }
        }
      }
    }
  }
  return false; //else return false
}

bool ChessBoard::isCheckmate(){
  int piececolour = 0;
  if(whiteToMove()){ //look for same coloured pieces
    piececolour = 1;
  }
  Piece *s=nullptr;
  Piece *d=nullptr;

  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0;j<BOARDSIZE;j++){
      if(squares[i][j]!=nullptr){
        if(squares[i][j]->getColour()==piececolour){ //for same coloured pieces
          for(int k=0;k<BOARDSIZE;k++){
            for(int l=0;l<BOARDSIZE;l++){
              if(validSquares(i,j,k,l,0)){ //if piece can move any square
                if(squares[i][j]->canMove(i,j,k,l,squares,0)){
                  s=squares[i][j]; //copy source and dest square pieces/nullptr
                  d=squares[k][l];
                  squares[i][j]=nullptr; //make the move
                  squares[k][l]=s;
                  if(!isCheck()){ //if no longer check
                    squares[i][j]=s; //fix board
                    squares[k][l]=d;
                    return false; //then not checkmate
                  }
                  squares[i][j]=s; //fix board regardless
                  squares[k][l]=d;
                }
              }
            }
          }
        }
      }
    }
  }
  return true; //if cannot find a legal move that resolves check, checkmate
}

bool ChessBoard::isStalemate(){
  int piececolour = 0;
  if(whiteToMove()){ //look for same coloured pieces
    piececolour = 1;
  }

  if(check==1){ //cannot be stalemate after a check
    return false;
  }
  else if(check!=1){ //if not check
    for(int i=0;i<BOARDSIZE;i++){
      for(int j=0;j<BOARDSIZE;j++){
        if(squares[i][j]!=nullptr){
          if(squares[i][j]->getColour()==piececolour){ //for same coloured pieces
            for(int k=0;k<BOARDSIZE;k++){
              for(int l=0;l<BOARDSIZE;l++){
                if(validMove(i,j,k,l,0)){ //if piece can move to any square
                  return false; //not stalemate!
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "A Stalemate has been reached\n";
  return true; //if could not find valid move, stalemate has been reached
}

bool ChessBoard::piecesLeft()const{ //returns T if pieces still left (not king)
  for(int i=0;i<BOARDSIZE;i++){
    for(int j=0; j<BOARDSIZE; j++){
      if(squares[i][j]->getKing()==0){
        return true;
      }
    }
  }
  cout << "There are no other pieces left other than the Kings. This is a draw";
  return false;
}

void ChessBoard::submitMove(const char source[2], const char dest[2]){

  Piece* p=nullptr;
  Piece* d=nullptr;
  int srow = BOARDSIZE-1-source[1]+'1';
  int scol = source[0]-'A';
  int drow = BOARDSIZE-1-dest[1]+'1';
  int dcol = dest[0]-'A';
  int checkcout=0;

  if(end==1){
    cerr << "Can no longer edit board as game has been concluded!\n";
  }

  if(!validMove(srow,scol,drow,dcol,1)){ //if not a valid move, return false
    return;
  }

  p=getPiece(srow,scol); //get piece in source square
  d=getPiece(drow,dcol); //get dest piece if exists in destination square
  squares[drow][dcol]=p; //make move (place source piece on destination square)
  squares[srow][scol]=nullptr; //set source square to nullptr
  p->printName(1);
  cout << " moves from " << source << " to " << dest; //printing out output
  if(p->getHasMoved()==0){ //set hasmoved flag if still 0
    p->setHasMoved();
  }
  if(check==1){ //resolve check if check flag set
    check=0;
  }
  if(d!=nullptr){ //free captured piece
    cout << " taking ";
    d->printName(1);
    delete d;
  }
  cout << endl;
  d=nullptr; //fix dangling pointers
  p=nullptr;
  move++; //increment move counter

  if(isCheck()){ //if king being attacked, set check flag to 1
    checkcout=1;
    check=1;
    if(isCheckmate()){ //if checkmate, end the game & declare winner
      checkcout=2;
      end=1;
    }
  }
  if(checkcout>0){ //if check or checkmate print correct output
    if(whiteToMove()){
      cout << "White";
    } else {
      cout << "Black";
    }
    cout << " is in check";
    if(checkcout==2){
      cout << "mate!";
    }
    cout << endl;
  }

  if(isStalemate()){ //if stalemate, end game and declare draw
    end=1;
  }
  if(!piecesLeft()){ //if only kings left, end game and declare draw
    end=1;
  }
}
