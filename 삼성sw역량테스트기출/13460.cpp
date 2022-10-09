#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n, m;
bool map[10][10];

typedef pair<int, int> pos;
pos startR, startB, goal;

int moveCounts = 11;
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

typedef struct {
    pos curR;
    pos curB;
    int cnt;
} state;

bool visited[10][10][10][10];
queue<state> q;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>m;

    for(int i = 0; i < n; i++){
        string str;
        cin>>str;

        // 이동가능한 지역은 true
        // #이면 false
        for(int j = 0; j < m; j++){
            char ch = str[j];

            switch(ch){
                case '#':
                    map[i][j] = false;
                    break;
                case '.':
                    map[i][j] = true;
                    break;
                case 'O':
                    goal = make_pair(i, j);
                    map[i][j] = true;
                    break;
                case 'R':
                    startR = make_pair(i, j);
                    map[i][j] = true;
                    break;
                case 'B':
                    startB = make_pair(i, j);
                    map[i][j] = true;
                    break;
                default:
                    std::cout<<"input error!\n";
                    break;
            }
        }
    }

    state initState = {startR, startB, 0};

    q.push(initState);

    while(!q.empty()){
        // 현재 red와 blue 위치
        pos curR = q.front().curR;
        pos curB = q.front().curB;
        // 현재까지 이동 횟수
        int curCount = q.front().cnt;
        q.pop();

        // 횟수 초과시 다음
        if(curCount > 10) continue;

        // red가 도착하면 다음
        if(curR.first == goal.first && curR.second == goal.second){
            if(moveCounts > curCount) moveCounts = curCount;
            continue;
        }

        // 방문 표시
        visited[curR.first][curR.second][curB.first][curB.second] = true;

        for(int i = 0; i < 4; i++){
            pos nextR = curR;
            pos nextB = curB;

            // red 이동
            while(1){
                if(map[nextR.first + moves[i][0]][nextR.second + moves[i][1]]){
                    nextR.first += moves[i][0];
                    nextR.second += moves[i][1];
                    if(nextR.first == goal.first && nextR.second == goal.second)
                        break;
                }
                else break;
            }

            // blue 이동
            while(1){
                if(map[nextB.first + moves[i][0]][nextB.second + moves[i][1]]){
                    nextB.first += moves[i][0];
                    nextB.second += moves[i][1];
                    if(nextB.first == goal.first && nextB.second == goal.second)
                        break;
                }
                else break;
            }

            // blue가 도착하면 다음
            if(nextB.first == goal.first && nextB.second == goal.second) continue;

            // 두 공이 같은 곳에 위치하면 초기 위치와 방향을 기반으로 위치 조정
            if(nextR.first == nextB.first && nextR.second == nextB.second){
                if(i == 0){
                    if(curR.second > curB.second)   nextB.second--;
                    else nextR.second--;
                }
                else if(i == 1){
                    if(curR.second < curB.second)   nextB.second++;
                    else nextR.second++;
                }
                else if(i == 2){
                    if(curR.first > curB.first) nextB.first--;
                    else nextR.first--;
                }
                else if(i == 3){
                    if(curR.first < curB.first) nextB.first++;
                    else nextR.first++;
                }
            }

            // 다음으로 이동한 곳 push
            if(!visited[nextR.first][nextR.second][nextB.first][nextB.second]){
                state nextState = {nextR, nextB, curCount + 1};
                q.push(nextState);
            }
        }
    }
    
    if(moveCounts == 11) cout<<-1;
    else cout<<moveCounts;

    return 0;
}