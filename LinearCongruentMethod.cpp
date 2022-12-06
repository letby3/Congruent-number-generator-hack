#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

int X1[] = { 157, 5054, 25789, 13214 };

int* T = new int[3];

int* M = new int[10001];

int main(){
	int size_m = 0;
	int u;
	for (int i = 0; i < 3; i++) {
		cout << X1[i + 1] - X1[i] << endl;
		T[i] = X1[i + 1] - X1[i];
	}
	u = abs(T[2] * T[0] - T[1]*T[1]);
	//cout << u << endl;
	for (int i = max(X1[0], max(X1[1], max(X1[2], X1[3]))) + 1; i < 65535; i++)
		if (u % i == 0) {
			M[size_m] = i; 
			size_m++;
		}
	
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < size_m; j++) {
			if ((20735 + i * M[j]) % 4897 == 0)
				cout << i << ' ' << j << ' ' << (20735 + i * M[j]) / 4897 << endl;
		}
	}
	cout << endl;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < size_m; j++) {
			if ((-12575 + i * M[j]) % 20735 == 0)
				cout << i << ' ' << j << ' ' << (-12575 + i * M[j]) / 20735 << endl;
		}
	}
	cout << endl;
	cout << M[3] << ' ' << M[4];
	cout << endl;

	for (int i = 0; i < 1001; i++) {
		if()
	}
	

	return 0;
}
