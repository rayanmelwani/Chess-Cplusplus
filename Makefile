chess: chessmain.o chessboard.o pieces.o rook.o bishop.o queen.o pawn.o king.o knight.o
	g++ chessmain.o chessboard.o pieces.o rook.o bishop.o queen.o pawn.o king.o knight.o -o chess

chessmain.o: ChessMain.cpp ChessBoard.h Const.h Pieces.h Rook.h Bishop.h Queen.h Pawn.h King.h Knight.h
	g++ -Wall -g -c ChessMain.cpp -o chessmain.o

chessboard.o: ChessBoard.cpp ChessBoard.h Const.h Pieces.h Rook.h Bishop.h Queen.h Pawn.h King.h Knight.h
	g++ -Wall -g -c ChessBoard.cpp -o chessboard.o

rook.o: Rook.cpp Rook.h Pieces.h Const.h
	g++ -Wall -g -c Rook.cpp -o rook.o

bishop.o: Bishop.cpp Bishop.h Pieces.h Const.h
	g++ -Wall -g -c Bishop.cpp -o bishop.o

queen.o: Queen.cpp Queen.h Pieces.h Const.h
	g++ -Wall -g -c Queen.cpp -o queen.o

pawn.o: Pawn.cpp Pawn.h Pieces.h Const.h
	g++ -Wall -g -c Pawn.cpp -o pawn.o

knight.o: Knight.cpp Knight.h Pieces.h Const.h
	g++ -Wall -g -c Knight.cpp -o knight.o

king.o: King.cpp King.h Pieces.h Const.h
	g++ -Wall -g -c King.cpp -o king.o

pieces.o: Pieces.cpp Pieces.h Const.h
	g++ -Wall -g -c Pieces.cpp -o pieces.o

.PHONY: clean
clean:
	rm -f *.o chess
