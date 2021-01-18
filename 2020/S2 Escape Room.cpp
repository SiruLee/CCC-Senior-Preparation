#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Cord {
public:
	int x;
	int y;
};

vector<vector<Cord>> vals(1000100);
bool visited[1010][1010];

string BFS(Cord last_cord) {
	queue<Cord> q;
	q.push(last_cord);
	while (!q.empty()) {
		Cord cord = q.front(); q.pop();
		vector<Cord> next = vals[cord.x * cord.y];
		for (Cord cell : next) {
			if (cell.x == 1 && cell.y == 1) {
				return "yes";
			}
			else if (visited[cell.x][cell.y]!=true) {
				visited[cell.x][cell.y] = true;
				q.push(cell);
			}
		}
	}
	return "no";
}

int main() {
	int m, n;
	cin >> m >> n;
	Cord last_cord;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <=n; j++) {
			int val;
			cin >> val;
			Cord cord;
			cord.x = i; cord.y = j;
			vals[val].push_back(cord);
		}
	}
	last_cord.x = m; last_cord.y = n;
	cout << BFS(last_cord)<<"\n";
	return 0;
}