#include<bits/stdc++.h>
#define MAX 300+5
using namespace std;

struct Edge{

    int to;
    int open_time;
    int close_time;
    int pass_time; 
};
struct Node{

    int to;
    int dist;
    bool operator<(const Node &other)const{

        return dist > other.dist; 
    }
};
vector<Edge> e[MAX];
bool visit[MAX]; 
int shortest_time[MAX];
void init(int n){

    fill(visit, visit+n+5, false);
    fill(shortest_time, shortest_time+n+5, 1e9);
    for(int i = 1 ; i <= n ; i ++ ){

        e[i].clear();
    }
}
int dijkstra(int from, int to){

    shortest_time[from] = 0;
    priority_queue<Node> pq;
    pq.push(Node{from, 0});
    while(!pq.empty()){

        Node now = pq.top();
        pq.pop();
        if(visit[now.to]){
            continue;
        }
        visit[now.to] = true;
        int time;
        for(Edge next : e[now.to] ){

            if( ( shortest_time[now.to] % (next.open_time + next.close_time)) <= (next.open_time - next.pass_time)  ){

                time = shortest_time[now.to] + next.pass_time;
            }
            else{

                time = shortest_time[now.to] + (next.open_time + next.close_time - (shortest_time[now.to] % (next.open_time + next.close_time))) + next.pass_time;
            }
            if(time < shortest_time[next.to]){

                shortest_time[next.to] = time;
                pq.push(Node{next.to, time});
            }

        }
    }
    return shortest_time[to];
}
int main(){
    
    int n,m,s,t;
    int cas = 1;

    while(cin >> n >> m >> s >> t){

        init(n);
        for(int i = 0 ; i < m ; i ++ ){

            int u, v, a, b, t;
            cin >> u >> v >> a >> b >> t;
            if( a >= t )
                e[u].push_back(Edge{v, a, b, t});
        }

        printf("Case %d: %d\n", cas++, dijkstra(s, t));
    }
}
