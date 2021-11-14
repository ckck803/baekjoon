#include <iostream>
#include <queue>
using namespace std;

// (1,0,0), (0,1,0), (0,0,1),
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

struct point
{
    int x;
    int y;
    int z;
    point(int a, int b, int c) : x(a), y(b), z(c) {}
};

int m, n, h;
int box[110][110][110];

queue<point> q;

int main(void)
{
    cin >> m >> n >> h;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < h; k++)
                cin >> box[m][n][h];
}
