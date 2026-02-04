//제미나이 제공 코드

//이전 dfs처럼 경로를 생성하는게 아니라
//이전 bfa처럼 마냥 퍼져나가는 것도 아니고
//둘을 혼합해 ㅠ, ㅑ처럼 기존 방식으론 안 되는 모양을 시도할 수 있음
//다음 진행 칸을 현재 위치에서 상하좌우만 고르는 게 아니라
//전체의 인접한 칸에서 고름
//이를 위해서 방문 후보지를 벡터에 저장하되
//재귀를 거쳤다가 돌아왔을 때 후보지가 사라지지 않게 복사복으로 전달
//ㄴ어차피 5*5라 복사 비용이 크지 않음

//또, 순서가 무의미한 상황이므로 중복은 쳐내야 함
//그래서 7칸을 저장했다가 중복인지를 확인해서 쳐낼 방법이 필요
//이를 비트 마스킹으로 해결함
//5*5이므로 어차피 24비트까지만 사용
//근데 이 중복을 결과만 쳐내는게 아니라 과정에서도 쳐냄
//이 비트마스킹이 결과의 중복 뿐만 아니라 일반 visit의 역할도 해냄

//그러나 메모리를 너무 잡아먹어서 문제
//경우에 따라선 그냥 배열에 저장하고 있는지 없는지 루프 돌려서 비교
//ㄴ이건 시간복잡도가 커져서 문제

//그냥 맨 밑에 조건문을 통해 인자로 전달한 부분만 보고 넘기기

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char map[5][5];
bool visited[1 << 25]; // 2^25 비트마스크 방문 체크 (약 32MB)
int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// dfs: 현재 상태에서 후보군 중 하나를 골라 영역을 넓힘
// mask: 현재 선택된 칸들의 비트마스크
// scnt: 현재 선택된 'S'의 개수
// cnt: 현재 선택된 칸의 총 개수
// cands: 다음에 방문 가능한 후보 칸들의 목록 (인접한 칸들)
void dfs(int mask, int scnt, int cnt, vector<int> cands) {
    // 1. 가지치기: 남은 칸을 모두 채워도 S가 4개가 안 되면 중단
    if (scnt + (7 - cnt) < 4) return;

    // 2. 종료 조건: 7칸을 모두 채웠을 때
    if (cnt == 7) {
        if (scnt >= 4) ans++;
        return;
    }

    // 3. 후보군 중에서 하나를 선택하여 확장
    // cands에 있는 모든 후보를 하나씩 시도해봄
    for (int i = 0; i < cands.size(); i++) {
        int curr = cands[i]; // 이번에 선택할 칸 번호 (0~24)
        
        // 이미 이전에 동일한 조합(mask)으로 방문한 적이 있다면 스킵 (중복 제거 핵심)
        int next_mask = mask | (1 << curr);
        if (visited[next_mask]) continue;
        visited[next_mask] = true;

        int r = curr / 5;
        int c = curr % 5;
        
        // 다음 단계로 넘겨줄 후보 목록 생성
        // 기존 후보 목록을 복사한 뒤, 현재 선택한 칸은 제거하고
        // 현재 선택한 칸의 이웃들을 추가함
        vector<int> next_cands = cands;
        next_cands.erase(next_cands.begin() + i); // 방금 선택한 건 후보에서 삭제

        // 상하좌우 탐색하여 새로운 후보 추가
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            int next_idx = nr * 5 + nc;

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue; // 맵 밖
            if (mask & (1 << next_idx)) continue; // 이미 선택된 칸이면 패스
            
            // 아직 선택 안 된 칸이면 후보군에 추가
            // (주의: 이미 next_cands에 들어있을 수 있으나, visited[mask]가 중복을 걸러주므로 그냥 추가해도 됨)
            // 더 최적화하려면 중복 체크 후 push하지만, 여기선 단순화함
            next_cands.push_back(next_idx);
        }

        // 재귀 호출
        dfs(next_mask, scnt + (map[r][c] == 'S'), cnt + 1, next_cands);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> map[i][j];

    // 모든 칸(0~24)을 시작점으로 시도
    for (int i = 0; i < 25; i++) {
        vector<int> start_cands;
        
        // 시작점의 상하좌우를 초기 후보군으로 설정
        int r = i / 5;
        int c = i % 5;
        for(int d=0; d<4; d++){
            int nr = r + dx[d];
            int nc = c + dy[d];
            if(nr>=0 && nr<5 && nc>=0 && nc<5)
                start_cands.push_back(nr*5 + nc);
        }

        // 시작점 방문 처리
        visited[1 << i] = true;
        
        // 탐색 시작
        dfs(1 << i, (map[r][c] == 'S'), 1, start_cands);
    }

    cout << ans;
    return 0;
}