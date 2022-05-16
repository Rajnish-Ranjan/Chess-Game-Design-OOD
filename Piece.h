#pragma once
#include<bits/stdc++.h>
#include"Board.h"
#include"Position.h"

using namespace std;

class Piece {
protected:
	char Team;
	Board* bd;
	string Id;
	void updateBoard(int x1, int y1, int x2, int y2) {
		bd->BoardMatrix[x1][y1] = "";
		bd->BoardMatrix[x2][y2] = Id;
	}

	bool BishopMove(Position* pos1, Position* pos2) {
		int r1, c1, r2, c2;
		r1 = pos1->Y;
		r2 = pos2->Y;
		c1 = pos1->X;
		c2 = pos2->X;
		int r = r1, c = c1;
		if (abs(r2 - r1) != abs(c2 - c1)) {
			return false;
		}

		string opp = bd->BoardMatrix[r2][c2];
		if (opp != "" && opp[0] == Team) {
			return false;
		}
		int dr = (r1 > r2) ? -1 : 1;
		int dc = (c1 > c2) ? -1 : 1;
		do {
			r1 = r1 + dr;
			c1 = c1 + dc;
			if (bd->BoardMatrix[r1][c1] != "") {
				break;
			}
		} while (r1 != r2);

		if (r1 != r2) {
			return false;
		}
		updateBoard(r, c, r2, c2);
		return true;
	}


	bool RookMove(Position* pos1, Position* pos2) {
		int r1, c1, r2, c2;
		r1 = pos1->Y;
		r2 = pos2->Y;
		c1 = pos1->X;
		c2 = pos2->X;
		int r = r1, c = c1;
		if (r1 != r2 && c1 != c2) {
			return false;
		}
		int dr = (r1 > r2) ? -1 : 1;
		int dc = (c1 > c2) ? -1 : 1;
		dr = (r1 == r2) ? 0 : dr;
		dc = (c1 == c2) ? 0 : dc;
		do {
			r1 = r1 + dr;
			c1 = c1 + dc;
			if (bd->BoardMatrix[r1][c1] != "") {
				break;
			}
		} while (r1 != r2 && c1 != c2);

		if (r1 == r2 && c1 == c2) {
			updateBoard(r, c, r2, c2);
			return true;
		}
		return false;
	}

public:
	Piece(Board* board, string pname) {
		bd = board;
		Id = pname;
		Team = pname[0];
	}
	virtual bool CanMove(Position*, Position*) = 0;
};

class Pawn :public Piece {
	bool isFirstMove;
public:
	Pawn(Board* board, string pName) :Piece(board, pName) {
		isFirstMove = true;

	}
	bool CanMove(Position* pos1, Position* pos2) {
		int r1, c1, r2, c2;
		bool isF = isFirstMove;
		isFirstMove = false;
		r1 = pos1->Y;
		r2 = pos2->Y;
		c1 = pos1->X;
		c2 = pos2->X;
		if (c1 == c2) {
			if (Team == 'B') {
				if (r1 + 1 > 7) {
					return false;
				}
				if (bd->BoardMatrix[r1 + 1][c2] != "") {
					return false;
				}
				if (r2 == r1 + 1) {

					updateBoard(r1, c1, r2, c2);
					return true;
				}
				else if (isF && r2 == r1 + 2) {
					if (bd->BoardMatrix[r2][c2] != "") {
						return false;
					}
					updateBoard(r1, c1, r2, c2);
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if (r1 - 1 < 0) {
					return false;
				}
				if (bd->BoardMatrix[r1 - 1][c2] != "") {
					return false;
				}
				if (r2 == r1 - 1) {

					updateBoard(r1, c1, r2, c2);
					return true;
				}
				else if (isF && r2 == r1 - 2) {
					if (bd->BoardMatrix[r2][c2] != "") {
						return false;
					}
					updateBoard(r1, c1, r2, c2);
					return true;
				}
				else {
					return false;
				}
			}
		}
		if (abs(c1 - c2) == 1 && abs(r1 - r2) == 1) {
			string opponent = bd->BoardMatrix[r2][c2];
			if (opponent == "") {
				return false;
			}
			if (Team == 'B' && r2 > r1) {

				if (opponent[0] == 'W') {
					updateBoard(r1, c1, r2, c2);
					return true;
				}
			}
			if (Team == 'W' && r2 < r1) {
				if (opponent[0] == 'B') {
					updateBoard(r1, c1, r2, c2);
					return true;
				}
			}
		}
		return false;
	}
};

class Knight :public Piece {
public:
	Knight(Board* board, string pName) :Piece(board, pName) {
	}
	bool CanMove(Position* pos1, Position* pos2) {
		int r1, c1, r2, c2;
		r1 = pos1->Y;
		r2 = pos2->Y;
		c1 = pos1->X;
		c2 = pos2->X;
		string opp = bd->BoardMatrix[r2][c2];
		if (abs(r1 - r2) == 1 && abs(c1 - c2) == 2) {
			if (opp == "" || opp[0] != Team) {
				updateBoard(r1, c1, r2, c2);
				return true;
			}
		}
		else if (abs(r1 - r2) == 2 && abs(c1 - c2) == 1) {
			if (opp == "" || opp[0] != Team) {
				updateBoard(r1, c1, r2, c2);
				return true;
			}
		}
		return false;
	}
};

class Bishop :public Piece {
public:
	Bishop(Board* board, string pName) :Piece(board, pName) {
	}
	bool CanMove(Position* pos1, Position* pos2) {
		return BishopMove(pos1, pos2);
	}
};

class King :public Piece {
public:
	King(Board* board, string pName) :Piece(board, pName) {
	}
	bool CanMove(Position* pos1, Position* pos2) {
		int r1, c1, r2, c2;
		r1 = pos1->Y;
		r2 = pos2->Y;
		c1 = pos1->X;
		c2 = pos2->X;
		if (abs(r1 - r2) > 1 || abs(c1 - c2) > 1) {
			return false;
		}
		string opp = bd->BoardMatrix[r2][c2];
		if (opp == "" || opp[0] != Team) {
			updateBoard(r1, c1, r2, c2);
			return true;
		}
		return false;
	}
};

class Queen :public Piece {
public:
	Queen(Board* board, string pName) :Piece(board, pName) {
	}
	bool CanMove(Position* pos1, Position* pos2) {
		return BishopMove(pos1, pos2) || RookMove(pos1, pos2);
	}
};

class Rook :public Piece {
public:
	Rook(Board* board, string pName) :Piece(board, pName) {
	}
	bool CanMove(Position* pos1, Position* pos2) {
		return RookMove(pos1, pos2);
	}
};
