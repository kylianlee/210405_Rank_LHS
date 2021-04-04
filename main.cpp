//
// Created by Kylian Lee on 2021/04/06.
//

#include <iostream>
#include <vector>

using namespace std;

//int INF = 101;
int cache[101][101];

int solution(int n, vector<vector<int>> results);

int main() {

    cout << solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}}) << endl;

    return 0;
}

int solution(int n, vector<vector<int>> results){

    for(int i = 0; i < results.size(); i++)
        cache[results[i][0]][results[i][1]] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(cache[j][i] + cache[i][k] == 2)
                    cache[j][k] = 1;
            }
        }
    }

//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <=n; j++){
//            cout << cache[i][j] << " ";
//        }
//        cout << endl;
//    }

    int count, result = 0;

    for(int i = 1; i <= n; i++){
        count = 0;
        for(int j = 1; j <= n; j++){
            if((cache[i][j] == 1) || (cache[j][i] == 1))
                count++;
        }
        if(count == n -1)
            result++;
    }

    return result;

}
