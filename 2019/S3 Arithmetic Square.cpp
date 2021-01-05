//  9/15

#include <iostream>
#include <algorithm>

using namespace std;

int INF = numeric_limits<int>::min();
int sq[4][4];
int rc[3][3] = { -1, };
char d[3][3];
int best = 0;
bool check = false;

int count(int i, int j) {
	int num1 = 0, num2 = 0;
	for (int a = 0; a < 3; a++) {
		if (sq[i][a] != INF) num1++; //row
	}
	for (int a = 0; a < 3; a++) {
		if (sq[a][j] != INF) num2++; //column
	}
	if (num1 >= num2) d[i][j] = 'r';
	else d[i][j] = 'c';
	return max(num1, num2);
}

void tra() {
	best = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (sq[i][j] == INF) {
				rc[i][j] = count(i, j);
				best = max(best, rc[i][j]);
				check = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int in;
			cin >> in;
			if (cin.fail()) {
				sq[i][j] = INF;
				cin.clear();
				if (j == 2)
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				else
					cin.ignore(numeric_limits<streamsize>::max(), ' ');
			}
			else sq[i][j] = in;
		}
	}

	tra();
	while (check) {
		check = false;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (rc[i][j] == best) {
					if (best == 2) {
						if (d[i][j] == 'r') {
							if (j == 0) sq[i][0] = sq[i][1] - sq[i][2] + sq[i][1];
							else if (j == 1) sq[i][1] = sq[i][0] + (sq[i][2] - sq[i][0]) / 2;
							else sq[i][2] = sq[i][1] + sq[i][1] - sq[i][0];
						}
						else {
							if (i == 0) sq[0][j] = sq[1][j] - sq[2][j] + sq[1][j];
							else if (i == 1) sq[1][j] = sq[0][j] + (sq[2][j] - sq[0][j]) / 2;
							else sq[2][j] = sq[1][j] + sq[1][j] - sq[0][j];
						}
					}
					else if (best == 1) {
						int num = 0;
						if (d[i][j] == 'c') {
							for (int k = 0; k < 3; k++) {
								if (sq[k][j] != INF) num = sq[k][j];
							}
							for (int k = 0; k < 3; k++) {
								if (sq[k][j] == INF) sq[k][j] = num;
							}
						}
						else {
							for (int k = 0; k < 3; k++) {
								if (sq[i][k] != INF) num = sq[i][k];
							}
							for (int k = 0; k < 3; k++) {
								if (sq[i][k] == INF) sq[i][k] = num;
							}
						}
					}
					tra();
					rc[i][j] = -1;
					i = 0; j = 0;
				}
				else continue;
			}
		}

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << sq[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}