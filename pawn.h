#ifndef PAWN_H
#define PAWN_H

#include <vector>
#include "piece.h"
#include "pos.h"

class Pawn: public Piece {
	void setPassant(bool val) override;
	bool IsLegal(Pos newPos, vector <vector<Piece*>>* pieces) override;
	vector<Pos> getPossibleMoves(vector <vector<Piece*>>* pieces) override;
	Pawn(Color c, Pos Pos, bool hasMoved, bool enPassant);
};

#endif
