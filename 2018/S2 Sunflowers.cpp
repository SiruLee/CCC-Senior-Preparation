#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int arr[110][110];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	if (arr[0][0] < arr[0][1]) {
		if (arr[0][0] < arr[1][0]) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << arr[i][j]<<' ';
				}
				cout << '\n';
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					cout << arr[j][i]<<' ';
				}
				cout << '\n';
			}
		}
	}
	else{
		if (arr[0][0] < arr[1][0]) {
			for (int i = n-1; i >= 0; i--) {
				for (int j = 0; j <n; j++) {
					cout << arr[j][i]<<' ';
				}
				cout << '\n';
			}
		}
		else {
			for (int i = n - 1; i >= 0; i--) {
				for (int j = n - 1; j >= 0; j--) {
					cout << arr[i][j]<<' ';
				}
				cout << '\n';
			}
		}
	}
	
	return 0;
}