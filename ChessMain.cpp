#include "Const.h"
#include "ChessBoard.h"
#include "Pieces.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>

using namespace std;

int main() {

	ChessBoard cb;

	cout << "========================\n";
	cout << "Testing the Chess Engine\n";
	cout << "========================\n\n";

	cb.resetBoard();
	cb.printBoard();

	cb.submitMove("D7", "D6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("D4", "H6");
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("F8", "B4");
	cout << '\n';

	cout << "=========================\n";
	cout << "Alekhine vs. Vasic (1931)\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cb.printBoard();
	cout << '\n';

	cb.submitMove("E2", "E4");
	cb.printBoard();
	cb.submitMove("E7", "E6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("D2", "D4");
	cb.printBoard();
	cb.submitMove("D7", "D5");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("B1", "C3");
	cb.printBoard();
	cb.submitMove("F8", "B4");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("F1", "D3");
	cb.printBoard();
	cb.submitMove("B4", "C3");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("B2", "C3");
	cb.printBoard();
	cb.submitMove("H7", "H6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("C1", "A3");
	cb.printBoard();
	cb.submitMove("B8", "D7");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("D1", "E2");
	cb.printBoard();
	cb.submitMove("D5", "E4");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("D3", "E4");
	cb.printBoard();
	cb.submitMove("G8", "F6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("E4", "D3");
	cb.printBoard();
	cb.submitMove("B7", "B6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("E2", "E6");
	cb.printBoard();
	cb.submitMove("F7", "E6");
	cb.printBoard();
	cout << '\n';

	cb.submitMove("D3", "G6");
	cb.printBoard();
	cout << '\n';

	cout << "=========================\n";
	cout << "Other games\n";
	cout << "=========================\n\n";

	cb.resetBoard();
	cb.submitMove("E2","E4");
	cb.printBoard();
	cb.submitMove("E7","E5");
	cb.printBoard();
	cb.submitMove("D1","F3");
	cb.printBoard();
	cb.submitMove("B8","C6");
	cb.printBoard();
	cb.submitMove("F1","C4");
	cb.printBoard();
	cb.submitMove("H7","H5");
	cb.printBoard();
	cb.submitMove("F3","F8");
	cb.submitMove("F3","F6");
	cb.printBoard();
	cb.submitMove("A7","A4");
	cb.printBoard();
	cb.submitMove("H5","H3");
	cb.submitMove("H5","H4");
	cb.printBoard();
	cb.submitMove("F6","F7");
	cb.printBoard();

	return 0;
}
