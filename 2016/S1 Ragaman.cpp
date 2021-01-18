#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string original;
	string anagram;
	char arr[256] = { 0, };

	cin >> original >> anagram;

	for (auto c : original) {
		arr[c]++;
	}
	for (auto c : anagram) {
		arr[c]--;
	}
	for (int a = 'a'; a <= 'z'; a++) {
		if (arr[a] < 0) {
			cout << 'N';
			return 0;
		}
	}
	cout << 'A';

	return 0;
}