#include <iostream>
#include <algorithm>

using namespace std;

int record[110];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> record[i];
	}
	sort(record, record + N);
	int k = 0;
	if (N % 2 == 0) {
		for (int i = 0; i < N / 2; i++) {
			cout << record[N / 2 - k - 1] << ' ' << record[N / 2 + k] << ' ';
			k++;
		}
	}
	else {
		for (int i = 0; i < N / 2; i++) {
			cout << record[N / 2 - k] << ' ' << record[N / 2 + k + 1] << ' ';
			k++;
		}
		cout << record[0];
	}


	return 0;
}