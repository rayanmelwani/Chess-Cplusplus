#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Const.h"
#include "Pieces.h"

class ChessBoard{
  Piece* squares[BOARDSIZE][BOARDSIZE];
  int move=0; //if even white to move, if odd black to move
  int check=0; //0 if no check, 1 if check
  int end=0; //if game state has reached a conclusion
public:
  ChessBoard(); //constructor
  ~ChessBoard(); //destructor
  ChessBoard& operator=(ChessBoard const& other); //assignment operator
  ChessBoard(ChessBoard const& other);//copy constructor
  int getMove()const; //function to get move
  int getCheck()const; //function to get check
  int getEnd()const; //function to get end
  void resetBoard(); //function to reset chess board to initial state
  void printBoard()const; //function to print current board
  bool whiteToMove()const; //function that returns T if white to move
  Piece* getPiece(const int row, const int col)const; //function to check contents of square
  bool validSquares(const int srow, const int scol, const int drow, const int dcol,
    int error)const; //function to check if valid source & destination squares
  int findKing(int colour)const; //function to get square of specific king
  bool evalPinsChecks(const int srow, const int scol, const int drow, const int dcol,
    int error);  //function to eval if moving a pinned piece / resolves a check
  bool validMove(const int srow, const int scol, const int drow, const int dcol,
    int error); //function that checks if a move is valid 
  bool isCheck()const; //function to check if king is in check
  bool isCheckmate(); //function to check if king is in checkmate
  bool isStalemate(); //function to check if game is in stalemate
  bool piecesLeft()const; //function that returns T if pieces other than kings still left
  void submitMove(const char source[2], const char dest[2]); //function that submits mv to board
};

#endif
