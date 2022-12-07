#pragma once
#include <iostream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <ctime>

using namespace std;

struct anscom {
	int count = 0;
	int a = 0;
	int c = 0;
	int m = 0;
	int* x = new int[5];
};

long long* X1 = new long long[4];

long long* T = new long long[5];

vector<long long> M;

vector<pair<long long, long long>> M2;

map<long long, bool> check;

int start_hack(int show_answ, int autoR) {
	int a, c, m, x0;
	srand(time(NULL));
	int choose;
	if (!autoR)
		cin >> choose;
	else
		choose = 3;
	long long max_m = 65535;
	long long u;
	if (choose == 1) {
		// xi = {125 43001 19535 15089 12023} a = 343, c = 126, m = 54354, x0 = 125;
		// xi = {1242 1405 19932 13063 30} a = 41253, c = 54235, m = 21424, x0 = 1242;
		cout << "Xi = ";
		cin >> X1[0] >> X1[1] >> X1[2] >> X1[3];
	}
	else if (choose == 2) {
		X1[0] = 157; X1[1] = 5054;
		X1[2] = 25789; X1[3] = 13214;
	}
	else if (choose == 3) {

		a = rand();
		c = rand();
		m = rand() % max_m;
		x0 = rand();
		X1[0] = x0;
		X1[1] = (x0 * a + c) % m;
		X1[2] = (((x0 * a + c) % m) * a + c) % m;
		X1[3] = (((((x0 * a + c) % m) * a + c) % m) * a + c) % m;

		cout << "CREATED" << endl;
		cout << "x[0] = " << X1[0] << endl; //x1
		cout << "x[1] = " << X1[1] << endl; //x2 
		cout << "x[2] = " << X1[2] << endl; //x3
		cout << "x[3] = " << X1[3] << endl; //x3
		cout << "x[4] = " << (X1[3] * a + c) % m << endl; //x4
		cout << "a = " << ' ' << a << " c = " << c << " m = " << m << endl << endl;

	}

	for (auto i = 0; i < 3; i++) {
		T[i + 1] = X1[i + 1] - X1[i];
		//cout << T[i + 1] << ' ' << endl;
	}

	u = abs(T[3] * T[1] - T[2] * T[2]);
	if (u == 0) {
		cout << "HAVE MORE " << max_m - max(X1[1], max(X1[2], X1[3])) << " ANSWER-s one of them:" << endl;
		u = max(X1[1], max(X1[2], X1[3])) + 1;
	}
	//cout << "u = " << u << endl;
	for (long long i = max(X1[1], max(X1[2], X1[3])) + 1; i <= max_m; i++)
		if (u % i == 0) {
			M.push_back(i);
		}

	for (long long i = 0; i < 100001; i++)
		for (auto j : M) {
			if ((i * i * abs(T[1])) % j == abs(T[3])) {
				M2.push_back(make_pair(j, i));
			}
			if ((i * abs(T[1])) % j == abs(T[2])) {
				M2.push_back(make_pair(j, i));
			}
			if ((i * abs(T[2])) % j == abs(T[3])) {
				M2.push_back(make_pair(j, i));
			}
		}

	vector<anscom> ans_com;

	for (auto i : M2) {
		for (int j = 0; j < 100001; j++) {
			int c1 = X1[1] - ((X1[0] * i.second) % i.first);
			c1 = c1 + j * i.first;
			if (c1 > 0)
				if ((X1[0] * i.second + c1) % i.first == X1[1] &&
					(X1[1] * i.second + c1) % i.first == X1[2] &&
					(X1[2] * i.second + c1) % i.first == X1[3] && !check[(X1[3] * i.second + c1) % i.first]) {
					check[(X1[3] * i.second + c1) % i.first] = 1;
					anscom buf;
					buf.x[0] = X1[0];
					buf.x[1] = X1[1];
					buf.x[2] = X1[2];
					buf.x[3] = X1[3];
					buf.x[4] = (X1[3] * i.second + c1) % i.first;
					buf.a = i.second;
					buf.m = i.first;
					buf.c = c1;
					ans_com.push_back(buf);
				}
		}
	}
	if(show_answ)
	for(int i = 0;i < ans_com.size(); i++) {
		cout << "x[0] = " << ans_com[i].x[0] << endl;
		cout << "x[1] = " << ans_com[i].x[1] << endl;
		cout << "x[2] = " << ans_com[i].x[2] << endl;
		cout << "x[3] = " << ans_com[i].x[3] << endl;
		cout << "x[4] = " << ans_com[i].x[4] << endl;
		cout << "a = " << ' ' << ans_com[i].a << " c = " << ans_com[i].c << " m = " << ans_com[i].m << "\n\n";
	}

	M.clear();
	M2.clear();
	check.clear();
	return ans_com.size();
}

