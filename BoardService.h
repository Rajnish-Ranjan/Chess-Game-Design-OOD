#pragma once
#include<bits/stdc++.h>
#include"Piece.h"
#include"Board.h"
#include"Position.h"
#include"PieceFactory.h"
using namespace std;


class BoardServices {
	map<string, Piece*> PieceMapping;
	Board* bd;
	char Turn;
	void ChangeTurn() {
		if (Turn == 'B') {
			Turn = 'W';
		}
		else {
			Turn = 'B';
		}
	}
public:
	BoardServices() {
		Turn = 'B';
		bd = new Board();
		PieceFactory* pf = new PieceFactory(bd);

		string pieceName;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Position* pos = new Position();
				pos->X = j;
				pos->Y = i;
				pieceName = bd->getPiece(pos);
				if (pieceName != "") {
					PieceMapping[pieceName] = pf->CreatePiece(pieceName);
				}
			}
		}
	}
	bool CanMove(string pos1, string pos2) {
		if (pos1 == pos2) {
			return false;
		}
		Position* p1, * p2;
		p1 = new Position(pos1);
		p2 = new Position(pos2);
		Piece* piece;
		string piecename;
		piecename = bd->getPiece(p1);
		if (PieceMapping.find(piecename) == PieceMapping.end()) {
			return false;
		}
		if (piecename[0] != Turn) {
			return false;
		}
		ChangeTurn();
		piece = PieceMapping[piecename];
		//bd->PrintBoard();
		return piece->CanMove(p1, p2);
	}
	void print() {
		bd->PrintBoard();
	}
};

