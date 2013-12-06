#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int a[20][20];
bool visited[66000];
struct Point{
    int state;
    int step;
};
int flip[16] = {19, 39, 78, 140,
               305, 626, 1252, 2248,
               4880, 10016, 20032, 35968,
              12544, 29184, 58368, 51200};
void BFS(Point s) {
    queue<Point>Q;
    Q.push(s);
    Point hd, t;
    while(!Q.empty()) {
        hd = Q.front();
        Q.pop();
        if(hd.state == 0|| hd.state == 0xffff) {
            printf("%d\n", hd.step);
            return;
        }
        for(int i = 0; i < 16; ++ i) {
            t.state = hd.state ^ flip[i];
            if(visited[t.state]) {
                continue;
            }
            t.step = hd.step + 1;
            visited[t.state] = true;
            Q.push(t);
        }
    }
    cout<<"Impossible"<<endl;
}
int main() {
    cin>>n>>d;
    int s = 0;
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < n; ++ j) {
            cin>>a[i][j]
            s <<= 1;
            s += a[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    Point start;
    start.state = s;start.step = 0;
    visited[s] = true;
    BFS(start);
    return 0;
}
