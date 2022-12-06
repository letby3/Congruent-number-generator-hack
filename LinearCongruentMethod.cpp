#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long*X1 = new long long[4];

long long* T = new long long[3];

vector<long long> M;

vector<pair<long long, long long>> M2;

set<pair<long long, long long>> M3;
 
map<pair<long long, long long>, pair<bool, bool>> check_in;

int main(){
	int choose;
	cin >> choose;
	long long max_m = 65535;
	long long u;
	if (choose == 1) {
		cout << "Xi = ";
		cin >> X1[0] >> X1[1] >> X1[2] >> X1[3];
	}
	else {
		X1[0] = 157; X1[1] = 5054;
		X1[2] = 25789; X1[3] = 13214;
	}

	for (auto i = 0; i < 3; i++) {
		T[i] = X1[i + 1] - X1[i];
		cout << T[i] << endl;
	}
	u = abs(T[2] * T[0] - T[1] * T[1]);
	cout << u << endl;

	for (long long i = max(X1[0], max(X1[1], max(X1[2], X1[3]))) + 1; i <= max_m; i++) 
		if (u % i == 0)
			M.push_back(i);

	for(long long i = 0;i < 100001;i++)
		for (long long j = 0; j < M.size(); j++) {
			if ((T[1] + i * M[j]) % T[0] == 0) {
				M2.push_back(make_pair(M[j], (T[1] + i * M[j]) / T[0]));
				check_in[M2.back()].first = 1;
				//cout << "1 : " << M[j] << ' ' << (T[1] + i * M[j]) / T[0] << endl;
			}
			if ((abs(T[1]) + i * M[j]) % abs(T[0]) == 0) {
				M2.push_back(make_pair(M[j], (abs(T[1]) + i * M[j]) / abs(T[0])));
				check_in[M2.back()].first = 1;
				//cout << "1 : " << M[j] << ' ' << (T[1] + i * M[j]) / T[0] << endl;
			}
			if ((abs(T[2]) + i * M[j]) % abs(T[1]) == 0) {
				M2.push_back(make_pair(M[j], (abs(T[2]) + i * M[j]) / abs(T[1])));
				check_in[M2.back()].second = 1;
				//cout << "2 : " << M[j] << ' ' << (abs(T[2]) + i * M[j]) / abs(T[1]) << endl;
			}
			if (((T[2]) + i * M[j]) % (T[1]) == 0) {
				M2.push_back(make_pair(M[j], ((T[2]) + i * M[j]) / (T[1])));
				check_in[M2.back()].second = 1;
				//cout << "2 : " << M[j] << ' ' << ((T[2]) + i * M[j]) / (T[1]) << endl;
			}
		}


	for (auto i : M2) {
		if (check_in[i].first && check_in[i].second) {
			M3.insert(i);
		}
	}

	M.clear();
	//M2.clear();
	check_in.clear();
	/*
	for (auto i : M2) {
		long long c1, c2;
		
		c1 = (X1[1]) - X1[0] * i.second;
		if (i.first == 21424 && i.second == 41253)
			cout << c1 << endl;
		if ((X1[0] * i.second + c1) % i.first == X1[1] &&
			(X1[1] * i.second + c1) % i.first == X1[2] &&
			(X1[2] * i.second + c1) % i.first == X1[3] && c1 >= 0) {
			cout << "x[0] = " << X1[0] << endl;
			cout << "x[1] = " << (X1[0] * i.second + c1) % i.first << endl;
			cout << "x[2] = " << (X1[1] * i.second + c1) % i.first << endl;
			cout << "x[3] = " << (X1[2] * i.second + c1) % i.first << endl;
			cout << "x[4] = " << (X1[3] * i.second + c1) % i.first << endl;
			cout << "a = " << ' ' << i.second << " c = " << c1 << " m = " << i.first << endl;
		}
	}
	
	for (int i = 0; i < 100001; i++) {		
		for (auto j : M3) {

			long long c1 = X1[1] - j.first * X1[0] + j.second * i;
			if (c1 > 0) {
				if ((X1[0] * j.second + c1) % j.first == X1[1] && 
					(X1[1] * j.second + c1) % j.first == X1[2] &&
					(X1[2] * j.second + c1) % j.first == X1[3]) {
					cout << "x[0] = " << X1[0] << endl;
					cout << "x[1] = " << (X1[0] * j.second + c1) % j.first << endl;
					cout << "x[2] = " << (X1[1] * j.second + c1) % j.first << endl;
					cout << "x[3] = " << (X1[2] * j.second + c1) % j.first << endl;
					cout << "x[4] = " << (X1[3] * j.second + c1) % j.first << endl;
					cout << "a = " << ' ' << j.second << " c = " << c1 << " m = " << j.first << endl;
				}
			}
		}
	}
	*/
	for (auto i : M3) {
		int c1 = X1[1] - (X1[0] * i.second) % i.first;
		if(c1 > 0)
			if ((X1[0] * i.second + c1) % i.first == X1[1] &&
				(X1[1] * i.second + c1) % i.first == X1[2] &&
				(X1[2] * i.second + c1) % i.first == X1[3] && c1 >= 0) {
				cout << "x[0] = " << X1[0] << endl;
				cout << "x[1] = " << (X1[0] * i.second + c1) % i.first << endl;
				cout << "x[2] = " << (X1[1] * i.second + c1) % i.first << endl;
				cout << "x[3] = " << (X1[2] * i.second + c1) % i.first << endl;
				cout << "x[4] = " << (X1[3] * i.second + c1) % i.first << endl;
				cout << "a = " << ' ' << i.second << " c = " << c1 << " m = " << i.first << endl;

			}
				
	}
	// 125 43001 19535 15089 12023 47465 a = 343, c = 126, m = 54354, x0 = 125;
	// 1242 1405 19932 13063 30 a = 41253, c = 54235, m = 21424, x0 = 1242;
	int a = 41253, c = 54235, m = 21424, x0 = 1242;
	cout << endl;
	cout << (x0 * a + c) % m << endl; //0 = 125
	cout << (((x0 * a + c) % m) * a + c) % m << endl; //1 = 43001
	cout << (((((x0 * a + c) % m) * a + c) % m) * a + c) % m << endl; //2 = 19535
	cout << (((((((x0 * a + c) % m) * a + c) % m) * a + c) % m) * a + c) % m << endl; //3 = 15089
	cout << (((((((((x0 * a + c) % m) * a + c) % m) * a + c) % m) * a + c) % m) * a + c) % m << endl; //4 = 12023
	return 0;
}
