#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int N, M, V;
std::vector<std::vector<int>> adjList;
bool visited[1001] = { false };

void DFS(int n) {
	if (visited[n] == true) return;
	std::cout << n << ' ';
	visited[n] = true;
	for (int node : adjList[n]) {
		DFS(node);
	}
}

void BFS(int n) {
	std::queue<int> qu;
	qu.push(n);
	visited[n] = true;
	while (!qu.empty()) {
		int cur = qu.front();
		std::cout << cur << ' ';
		qu.pop();
		for (int node : adjList[cur]) {
			if (!visited[node]) {
				visited[node] = true;
				qu.push(node);
			}
		}
	}
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> V;
	adjList.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	for (int i = 0; i <= N; i++) {
		sort(adjList[i].begin(), adjList[i].end());
	}
	DFS(V);
	fill(visited, visited + N + 1, false);
	cout << '\n';
	BFS(V);
}