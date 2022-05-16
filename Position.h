#pragma once
#include<bits/stdc++.h>
using std::string;
class Position {
public:
	int X, Y;
	Position() {
		X = 0;
		Y = 0;
	}
	Position(string pos) {
		if (pos.length() > 2) {
			throw "Position [" + pos + "] is not correct";
		}
		if (pos[0] >= 'a' && pos[0] < 'i') {
			X = pos[0] - 'a';
		}
		else {
			throw "Position [" + pos + "] is not correct";
		}
		if (pos[1] > '0' && pos[1] < '9') {
			Y = pos[1] - '1';
		}
		else {
			throw "Position [" + pos + "] is not correct";
		}
	}
};
