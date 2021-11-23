#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector<std::vector<int>> adjNode;
std::vector<bool> visited;
int cnt = 0;

void BFS() {
	std::queue<int> qu;
	qu.push(1);
	visited[1] = true;
	while (!qu.empty()) {
		int dist = qu.front();
		qu.pop();
		for (int i = 0; i < adjNode[dist].size(); i++) {
			if (!visited[adjNode[dist][i]]) {
				qu.push(adjNode[dist][i]);
				visited[adjNode[dist][i]] = true;
				cnt++;
			}
		}
	}
}

int main() {
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	adjNode.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adjNode[u].push_back(v);
		adjNode[v].push_back(u);
	}
	BFS();
	cout << cnt;
}