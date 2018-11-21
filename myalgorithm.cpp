//
//  main.cpp
//  teamnote
//
//  Created by 주진형 on 2018. 11. 20..
//  Copyright © 2018년 주진형. All rights reserved.
//
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#define MAX_NODE 100000
#define MAX_LENGTH 1000000
#define INF 1000000000

namespace shortest_path {
    typedef struct node{
        int e, w;
    } node_t;
    
    class min_node{
    public:
        bool operator() (const node_t& a, const node_t& b){
            return a.w > b.w;
        }
    };
    
    void floyd_wharshall(int n, vector<int> dist[]){
        for (int k=1; k<=n; k++) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    vector<int> dijkstra(int s, vector<node_t> graph[]){
        vector<int> dist(MAX_NODE, INF);
        priority_queue<node_t, vector<node_t>, min_node> q;
        dist[s] = 0;
        q.push({s, 0});
        while (!q.empty()) {
            node_t cur = q.top();
            q.pop();
            for(node_t next : graph[cur.e]){
                if(dist[next.e] > dist[cur.e] + next.w){
                    dist[next.e] = dist[cur.e] + next.w;
                    next.w = dist[next.e];
                    q.push(next);
                }
            }
        }
        return dist;
    }
    
    vector<int> bellman_ford(int s, int n, vector<node_t> graph[]){
        vector<int> dist(MAX_NODE, INF);
        bool minusCycle = false;
        dist[s] = 0;
        for(int i=1; i<=n; i++){
            for (int j=1; j<=n; j++) {
                for(node_t& next : graph[j]){
                    if(dist[j] != INF && dist[next.e] > dist[j] + next.w){
                        dist[next.e] = dist[j] + next.w;
                        if(i == n){minusCycle = true;}
                    }
                }
            }
        }
        if(minusCycle){
            dist[s] = -INF;
        }
        return dist;
    }
    
    vector<int> spfa(int s, vector<node_t> graph[]){
        vector<int> dist(MAX_NODE, INF);
        vector<bool> inq(MAX_NODE, false);
        queue<node_t> q;
        q.push({s, 0});
        dist[s] = 0;
        inq[s] = true;
        while (!q.empty()) {
            node_t cur = q.front();
            q.pop();
            inq[cur.e] = false;
            for(node_t& next : graph[cur.e]){
                if(dist[next.e] > dist[cur.e] + next.w){
                    dist[next.e] = dist[cur.e] + next.w;
                    if(!inq[next.e]){
                        q.push(next);
                        inq[next.e] = true;
                    }
                }
            }
        }
        
        return dist;
    }
}

namespace string_compare {
    
    vector<int> failure_function(string& ptr){
        vector<int> fail(MAX_LENGTH, 0);
        int n = (int)ptr.size();
        int j=0;
        for (int i=1; i<n; i++) {
            while (j>0 && ptr[i] != ptr[j]) {
                j = fail[j-1];
            }
            if(ptr[i] == ptr[j]){
                fail[i] = ++j;
            }
        }
        return fail;
    }
    
    vector<int> kmp(string& str, string& ptr){
        int n = (int)str.size();
        int m = (int)ptr.size();
        vector<int> fail = failure_function(ptr);
        vector<int> ret;
        int j=0;
        for(int i=1; i<n; i++){
            while(j>0 && str[i] != ptr[j]){
                j = fail[j-1];
            }
            if(str[i] == ptr[j]){
                if(j == m-1){
                    ret.push_back(i-m+2);
                    j = fail[j];
                }
                else{
                    j++;
                }
            }
        }
        return ret;
    }
    
    vector<int> rabin_karp(string& str, string& ptr){
        vector<int> ret;
        int m = (int)ptr.size();
        int ptrHash=0;
        
        
        return ret;
    }
}

namespace util {
    long long power(long long base, int exp){
        if(base==1) return 1;
        long long ans = 1;
        while(exp){
            if(exp & 1) ans *= base;
            base *= base;
            exp >>= 1;
        }
        return ans;
    }
}

int main(){
    
    return 0;
}











