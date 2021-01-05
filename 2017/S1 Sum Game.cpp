#include <iostream>

using namespace std;
int swift[100100];
int semaphores[100100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	int k=0;
	int s1=0, s2=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> swift[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> semaphores[i];
	}
	for (int i = 0; i < N; i++) {
		s1 += swift[i];
		s2 += semaphores[i];
		if (s1 == s2) k = i + 1;
	}
	cout << k;
	return 0;
}