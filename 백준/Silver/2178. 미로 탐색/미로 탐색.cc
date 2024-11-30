#include <stdio.h>
#include <queue>

using namespace std;

int N, M;
int matrix[101][101];
int visited[101][101];
char string[101][102];

int ans = 1;

queue<pair<int, int>> q;

//파라미터 matrix[x][y] 로 이동할수 있는지 없는지 true false 로 리턴하는 함수.
bool canMove(int x, int y)
{
	if (x >= 1 && x <= N && y >= 1 && y <= M && matrix[x][y] == 1 && !visited[x][y]) return true;
	return false;
}

//queue에 x,y 넣고, 방문처리.
void Move(int x, int y)
{
	visited[x][y] = 1;
	q.push(make_pair(x, y));
	return;
}

int main()
{

	//입력을 문자열로 받고, 그걸 미로 matrix 배열에 저장.
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", string[i]);
		for (int j = 0; j < M; j++) matrix[i + 1][j + 1] = (int)(string[i][j] - '0');
	}

	//bfs

	q.push(make_pair(1, 1));
	while (!q.empty())
	{
		int s = q.size();

		//탐색
		for (int i = 0; i < s; i++) {
			int x = q.front().first;
			int y = q.front().second;

			//종료 조건
			if (x == N && y == M) {
				printf("%d\n", ans);
				return 0;
			}

			if (canMove(x + 1, y)) {
				Move(x + 1, y);
			}
			if (canMove(x - 1, y)) {
				Move(x - 1, y);
			}
			if (canMove(x, y + 1)) {
				Move(x, y + 1);
			}
			if (canMove(x, y - 1)) {
				Move(x, y - 1);
			}
			q.pop();
		}
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
