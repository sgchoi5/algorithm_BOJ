// Modified codes of page 171 (Online book: http://www.digitalculture.or.kr/koi/StudyBook.do),
// to handle additional condition of https://www.acmicpc.net/problem/13265


#include <stdio.h>
#include <vector>

int n, m, visited[1000];
std::vector<int> G[1000];

void solve(int v, int c) {
	visited[v] = c;
	bool can = true;
	for (int i = 0; i < G[v].size(); i++) {
		if (visited[G[v][i]] == c) {
			can = false;
		}
	}
	if (!can) {
		visited[v] = -1;
		return;
	}
	for (int i = 0; i < G[v].size(); i++) {
		if (!visited[G[v][i]]) {
			if (c == 2)
				solve(G[v][i], 1);
			else
				solve(G[v][i], 2);
		}
	}
}

int main(void) {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int s, e;
			scanf("%d %d", &s, &e);
			G[s - 1].push_back(e - 1);
			G[e - 1].push_back(s - 1);
		}
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0)
				solve(i, 1);
		}
		
		bool possible = true;
		for (int i = 0; i < n; i++) {
			if (visited[i] == -1) {
				possible = false;
				break;
			}
		}
		printf("%s\n", possible ? "possible" : "impossible");

		for (int i = 0; i < n; i++) {
			visited[i] = 0;
			G[i].clear();
		}
	}
	return 0;
}
