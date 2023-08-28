//후보군 3개의 벽 구할 때, 반드시 세개의 벽을 설치해야 하기 때문에 서로 달라야 한다.
//시간 복잡도 n^3 * dfs시간 복잡도 (n^2) n^5 정도 되는 거 같다. 좀더 개선할 수 있는 방법이 있을 거 같긴 하다.
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int size1;
int graph[8][8];
int visited[8][8];
int template1[8][8];
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, 1, -1, -1, 1};
vector<pair<int, int>> candidates;
vector<vector<pair<int, int>>> combinations;

bool isCandidate(int y, int x) {
    if (template1[y][x] != 0) {
        return false;
    }
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m) continue ; 
        if (ny < 0 || ny >= n) continue ;
        if (template1[ny][nx] == 1) {
            count++;
        }
    }
    if (count >= 2) {
        return  true;
    }
    return false;
}


void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (visited[ny][nx]) continue;
        if (graph[ny][nx] == 1) continue; 
        visited[ny][nx] = 1;
        graph[ny][nx] = 2;
        dfs(ny, nx);
    }
}

void initialize(vector<pair<int, int>> tempQ) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            graph[y][x] = template1[y][x];
            visited[y][x] = 0;
        }
    }
    for (auto candidate : tempQ) {
        graph[candidate.first][candidate.second] = 1;
    }
}

int findCount() {
    int count = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (graph[y][x] == 2 && !visited[y][x]) {
                visited[y][x] =1;
                dfs(y, x);
            }
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (graph[y][x] == 0) count ++;
        }
    }
    return count;

}
void print(int array[8][8]) {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cout << array[y][x] << " ";
        }
        cout << "\n";
    }
}

int executeComb() {
    int maxCount = 0;
    for (int i = 0 ; i < size1 ; i++) {
        for (int j = i + 1; j < size1; j++) {
            for (int k = j + 1 ; k < size1; k++) {
                vector<pair<int, int>> tempQ;
                tempQ.push_back(candidates[i]);
                tempQ.push_back(candidates[j]);
                tempQ.push_back(candidates[k]);
                initialize(tempQ);
                int count = findCount();
                maxCount = max(count, maxCount);
            }
        }
    }
    return maxCount;
}
 
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> template1[y][x];
        }
    }
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (template1[y][x] == 0) {
            // if (isCandidate(y, x)) {
                candidates.push_back(make_pair(y, x));
                size1++;
            }
        }
    }
    int count = executeComb();
    cout << count << "\n";
}