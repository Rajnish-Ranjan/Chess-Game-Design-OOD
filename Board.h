#pragma once
#include<bits/stdc++.h>
#include"Position.h"
using namespace std;


class Board {
public:
	vector<vector<string> > BoardMatrix;
public:
	Board() :BoardMatrix
	{
		{"BR1", "BN2", "BB3","BQ4", "BK5", "BB6", "BN7", "BR8"},
		{"BP1","BP2","BP3","BP4","BP5","BP6","BP7","BP8"},
		{"","","","","","","",""},
		{"","","","","","","",""},
		{"","","","","","","",""},
		{"","","","","","","",""},
		{"WP1","WP2","WP3","WP4","WP5","WP6","WP7","WP8"},
		{"WR1", "WN2", "WB3","WQ4", "WK5", "WB6", "WN7", "WR8"}
	}
	{
		PrintBoard();
	}
	string getPiece(Position* Pos) {
		return BoardMatrix[Pos->Y][Pos->X];
	}
	void PrintBoard() {
		cout << "\n";
		for (auto row : BoardMatrix) {
			for (string item : row) {
				if (item == "") {
					cout << "-- ";
				}
				else {
					cout << item.substr(0, 2) << " ";
				}
			}
			cout << "\n";
		}
	}

};

