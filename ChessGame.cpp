#include<bits/stdc++.h>
#include"BoardServices.h"
using namespace std;

int main() {
	string command;
	BoardServices* bServcie = new BoardServices();
	string pos1, pos2;
	while (true) {
		cin >> pos1;
		if (pos1 == "exit") {
			break;
		}
		cin >> pos2;
		try {
			if (bServcie->CanMove(pos1, pos2) == false) {
				cout << "Invalid Move\n";
			}
			else {
				bServcie->print();
				cout << "\n";
			}
		}
		catch (const char* ex) {
			cout << ex << endl;
		}
	}
	return 0;
}
