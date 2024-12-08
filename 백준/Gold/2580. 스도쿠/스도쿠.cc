#include <stdio.h>

int arr[9][9];
int box_visited[3][3][10]; // 3x3 박스 안에서 숫자 방문 여부
int linex_visited[9][10]; // 각 행에서 숫자 방문 여부
int liney_visited[9][10]; // 각 열에서 숫자 방문 여부

bool bruteforce(int y, int x);

int main(void) {
  // 입력받기
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &arr[i][j]);
      if (arr[i][j] != 0) { // 초기 방문 처리
        int num = arr[i][j];
        box_visited[i / 3][j / 3][num] = 1;
        linex_visited[i][num] = 1;
        liney_visited[j][num] = 1;
      }
    }
  }

  // 백트래킹으로 스도쿠 해결
  bruteforce(0, 0);

  // 결과 출력
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}

bool bruteforce(int y, int x) {
  // 끝까지 탐색했으면 true 반환
  if (y == 9) return true;
  // 다음 행으로 이동
  if (x == 9) return bruteforce(y + 1, 0);
  // 숫자가 이미 채워진 칸은 넘어감
  if (arr[y][x] != 0) return bruteforce(y, x + 1);

  // 숫자 1부터 9까지 시도
  for (int num = 1; num <= 9; num++) {
    if (!box_visited[y / 3][x / 3][num] &&
        !linex_visited[y][num] &&
        !liney_visited[x][num]) {
      // 숫자 배치
      arr[y][x] = num;
      box_visited[y / 3][x / 3][num] = 1;
      linex_visited[y][num] = 1;
      liney_visited[x][num] = 1;

      // 다음 칸으로 이동
      if (bruteforce(y, x + 1)) return true;

      // 배치 취소 (백트래킹)
      arr[y][x] = 0;
      box_visited[y / 3][x / 3][num] = 0;
      linex_visited[y][num] = 0;
      liney_visited[x][num] = 0;
    }
  }

  return false; // 숫자를 배치할 수 없으면 false 반환
}
