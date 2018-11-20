//
//  main.cpp
//  teamnote
//
//  Created by 주진형 on 2018. 11. 20..
//  Copyright © 2018년 주진형. All rights reserved.
//
#include <vector>
#include <algorithm>
using namespace std;

void floyd_warshall(int n, vector<int> dist[]){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for (int j=1; j<=n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
