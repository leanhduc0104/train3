#include <bits/stdc++.h>
using namespace std;
int n, k, m;
int x[100], c[100][100];
int count_output = 0;
int count_edge = 0, old_count;

int visit( int point, int h ){
    for ( int i = 1; i < h; i++)
        if (point == x[i]) return 1;
    return 0;
}

void TRY(int h) {
    for (int i = 1; i <= n; i++) {
        if (!c[x[h - 1]][i]) continue;
        if (visit(i, h)) continue;

        x[h] = i;
        count_edge++;

        if (count_edge == k) {
            count_output++;
        }
        else TRY (h + 1);

        count_edge--;
        x[h] = 0;
    }
}
int main () {
    vector<pair<int, int>> edge;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n ; j++) {
            c[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        int m1, m2;
        cin>> m1 >> m2;
        edge.push_back(make_pair(m1, m2));
    }
    for (int t = 0; t < m; t++) {
        c[edge[t].first][edge[t].second] = 1;
        c[edge[t].second][edge[t].first] = 1;
    }
    for (int t = 1; t <= n; t++) {
        x[1] = t;
        count_edge = 0;
        TRY(2);
    }
    cout<<count_output / 2;
    return 0;
}

