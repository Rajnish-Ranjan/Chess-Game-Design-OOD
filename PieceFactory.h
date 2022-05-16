#pragma once
#include<bits/stdc++.h>
#include"Piece.h"
using namespace std;

class PieceFactory {
	Board* bd;
public:
	PieceFactory(Board* board) {
		bd = board;
	}
	Piece* CreatePiece(string pieceName) {
		Piece* piece = NULL;
		if (pieceName[1] == 'P') {
			piece = new Pawn(bd, pieceName);
		}
		else if (pieceName[1] == 'R') {
			piece = new Rook(bd, pieceName);
		}
		else if (pieceName[1] == 'N') {
			piece = new Knight(bd, pieceName);
		}
		else if (pieceName[1] == 'B') {
			piece = new Bishop(bd, pieceName);
		}
		else if (pieceName[1] == 'K') {
			piece = new King(bd, pieceName);
		}
		else if (pieceName[1] == 'Q') {
			piece = new Queen(bd, pieceName);
		}
		return piece;
	}
};
