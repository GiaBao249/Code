#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int MAX_N = 20;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Point
{
    int x, y;
};

int W, H;
char room[MAX_N][MAX_N];

int bfs(Point start, Point target)
{
    queue<Point> q;
    vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
    q.push(start);
    dist[start.x][start.y] = 0;

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        if (cur.x == target.x && cur.y == target.y)
            return dist[target.x][target.y];

        for (int dir = 0; dir < 4; ++dir)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx >= 0 && nx < H && ny >= 0 && ny < W &&
                room[nx][ny] != 'x' && dist[nx][ny] == INT_MAX)
            {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> W >> H;
    Point robot;
    bool robotFound = false;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> room[i][j];
            if (room[i][j] == 'o')
            {
                robot = {i, j};
                robotFound = true;
            }
        }
    }

    if (!robotFound)
    {
        cout << "-1" << endl;
        return 0;
    }

    int totalSteps = 0;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (room[i][j] == '*')
            {
                int steps = bfs(robot, {i, j});
                if (steps == -1)
                {
                    cout << "-1" << endl;
                    return 0;
                }
                totalSteps += steps;
            }
        }
    }

    cout << totalSteps << endl;

    return 0;
}
