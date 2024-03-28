#include "colors.h"
#include <iostream>
using namespace std;

void changeColor(int text, int back) {
	cout << "\033[" << text << ";" << back + 10 << "m";
}

void resetColor() {
	changeColor(white, black);
}