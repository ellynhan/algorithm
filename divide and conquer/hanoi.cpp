#include <cstdio>
#include <queue>
using namespace std;

void hanoi(int n, int from, int by, int to,queue<pair<int, int> >& q) {
	if (n == 1)
		q.push(make_pair(from,to));
	else {
		hanoi(n - 1, from, to, by,q);
		q.push(make_pair(from, to));
		hanoi(n - 1, by, from, to,q);
	}
}
int main() {
	queue<pair<int,int> > o;
	int N;
	scanf("%d", &N);
	hanoi(N, 1, 2, 3,o);
	printf("%d\n", o.size());
	while (!o.empty()) {
		printf("%d %d\n", o.front().first, o.front().second);
		o.pop();
	}
}