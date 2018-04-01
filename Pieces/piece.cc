#include "piece.h"
using namespace std;

void Piece::setMoved(bool val) {
	hasMoved = val;
}

Color getColor(){
	return color;
}

void Piece::updatePos(Pos newPos) {
	Pos.row = newPos.row;
	Pos.col = newPos.col;
}

Pos Piece::getPos() {
	return Pos;
}

void Piece::setPassant(bool val) {}
	
Piece::Piece(Color c, Pos Pos, bool hasMoved = false, bool enPassant = false): color{c}, Pos{Pos}, 
	hasMoved{hasMoved}, enPassant{enPassant} {}