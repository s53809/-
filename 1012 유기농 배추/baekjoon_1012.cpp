#include <iostream>
#include <vector>
#include <algorithm>

int M, N, K;
int d_x[] = { -1,1,0,0 };
int d_y[] = { 0,0,-1,1 };
int x[51][51] = { 0 };
bool visited[51][51] = { false };

void DFS(int yPos, int xPos) {
	visited[yPos][xPos] = true;
	for (int i = 0; i < 4; i++) {
		int nextX = d_x[i] + xPos;
		int nextY = d_y[i] + yPos;
		if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N) {
			if (visited[nextY][nextX] == false && x[nextY][nextX] == 1) {
				DFS(nextY, nextX);
			}
		}
	}
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T;
	cin >> T;
	while (T != 0) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				x[i][j] = 0;
				visited[i][j] = false;
			}
		}
		T--;
		cin >> M >> N >> K;
		int count = 0;
		for (int i = 0; i < K; i++) {
			int xPos, yPos;
			cin >> xPos >> yPos;
			x[yPos][xPos] = 1;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (x[i][j] == 1 && visited[i][j] == false) {
					DFS(i, j);
					count++;
				}
			}
		}
		cout << count << '\n';
	}
}