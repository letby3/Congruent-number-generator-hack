﻿#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <ctime>
#include "LinearCongruentMethod.h"

using namespace std;

int main(){
	for (int i = 0; i < 10000; i++) {
		int answ = start_hack(1, 0); 
		/*Show_ans (first Parameter) = 1/0 показывать ответы или нет
		AutoR = 1/0, авторежим генерации(автоматически выбирает 3)*/
		cout << answ << endl;
		if (answ == 0)
			system("PAUSE");
	}

	return 0;
}
