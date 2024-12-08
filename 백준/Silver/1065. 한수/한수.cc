#include <iostream>
 
using namespace std;
 
int f(int num) {
	int cnt = 0;
 
	if (num < 100) {
		return num;
	} else {
		cnt = 99;
 
		for (int i = 100; i <= num; i++) {
			int hun = i / 100;	
			int ten = (i / 10) % 10;
			int one = i % 10;
 
			if ((hun - ten) == (ten - one)) { 
				cnt++;
			}
		}
	}
	return cnt;
}
 
int main(int argc, char const *argv[]) {
 
	int N;
	cin >> N;
 
	int result = f(N);
	cout << result;
	return 0;
}