#include <iostream>
using namespace std;

#define N 4

int maze[N][N] = {
    {1, 1, 1, 1},
    {0, 0, 0, 1},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

int sol[N][N] = {0};

bool isSafe(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0 );
}

bool solveMaze(int x, int y, int tx, int ty){
    if(x == tx && y == ty){
        sol[x][y] = 1;
        return true;
    }

    sol[x][y] = 1;

    if(isSafe(x+1, y) && solveMaze(x+1, y, tx, ty)) return true;

    if(isSafe(x, y+1) && solveMaze(x, y+1, tx, ty)) return true;

    if(isSafe(x-1, y) && solveMaze(x-1, y, tx, ty)) return true;

    if(isSafe(x, y-1) && solveMaze(x, y-1, tx, ty)) return true;

    sol[x][y] = 0;
    return false;
}

int main(){
    int startX = 0, startY = 0;
    int targetX = 2, targetY = 0;

    if (solveMaze(startX, startY, targetX, targetY)) {
        cout << "Path found:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path found!\n";
    }
}