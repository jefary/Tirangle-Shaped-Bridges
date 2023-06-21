#include "/public/read.h"
#include <vector>
#include <algorithm>
#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
using namespace std;
using namespace bridges;

const int SIZE = 30;
int arr[SIZE][(SIZE*2)+1];

int pascal(int row, int col) {
	if (row % 2 != 0 and col % 2 == 0) return 0;
	if (row <= 0 or col > (SIZE*2)-1 or row > SIZE-1 or col < 0) return 0;

	int NW = 0, NE = 0;

	if (arr[row-1][col-1] !=  0) {
		NW = arr[row-1][col-1];
	}
	else {
		NW = pascal(row-1,col-1); 
	}

	if (arr[row-1][col+1] != 0) {
		NW = arr[row-1][col+1];
	}
	else {
		NE = pascal(row-1,col+1);
	}

	int sum = NW + NE;

	arr[row][col] = sum;

	return sum;
}

int main() {

	Bridges bridges(1020,  "jefary", "1082731491246");
	bridges.setTitle("Pascal bofa: (size=40)");

	ColorGrid bofa(SIZE, (SIZE*2)+1, Color("grey"));
	cout << 1;
	//Init phase
/*
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < (SIZE*2)+1; j++) {
			arr[i][j] = 0; //All the values start off "not calculated" which is -1
		}
	}
*/
	arr[0][SIZE] = 1;

	//Run the algorithm
	for (int i = 0; i < (SIZE*2)+1; i++) {
		pascal(SIZE-1,i);
	}

	cout << 2;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < (SIZE*2)+1; j++) {
			if(arr[i][j] != 0) {
				if(arr[i][j] % 3 == 0) { bofa.set(i, j, Color("black")); }
				if(arr[i][j] % 3 == 1) { bofa.set(i, j, Color("red")); }
				if(arr[i][j] % 3 == 2) { bofa.set(i, j, Color("blue")); }

			}
		}
	}
	cout << 3;

	bridges.setDataStructure(bofa);
	bridges.visualize();
}


