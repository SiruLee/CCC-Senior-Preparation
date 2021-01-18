#include <iostream>
#include <string>
#include <map>

using namespace std;
map <size_t, bool> mp;
int arr[2][256];

bool check() {
	for (int a = 'a'; a <= 'z'; a++) {
		if (arr[0][a] != arr[1][a])
			return false;
	}
	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string needle, haystack;
	cin >> needle >> haystack;
	int nl = needle.length(); int hl = haystack.length();
	if (nl > hl) {
		cout << 0;
		return 0;
	}
	int count = 0;
	for (auto x : needle) {
		arr[0][x]++;
	}
	for (int i = 0; i < nl; i++) {
		arr[1][haystack[i]]++;
	}
	int i = 0;
	string ss = haystack.substr(i, nl);
	hash<string>hasher;
	if (check()) {
		size_t hash = hasher(ss);
		if (!mp[hash]) {
			count++;
			mp[hash] = true;
		}
	}
	for (int i = 1; i <= hl - nl; i++) {
		arr[1][haystack[i - 1]]--;
		arr[1][haystack[i + nl - 1]]++;
		ss = haystack.substr(i, nl);
		size_t hash = hasher(ss);
		if (check()) {
			if (!mp[hash]) {
				count++;
				mp[hash] = true;
			}
		}
	}
	cout << count;

	return 0;
}