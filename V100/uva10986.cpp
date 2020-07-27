#include<bits/stdc++.h>
using namespace std;
struct Node{

    int to;
    int w;
    bool operator<(const Node& other)const{
        return w > other.w;
    }
};
vector<Node> vec[20005];
void init(int node,int m){

    for( int i = 0 ; i < node ; i ++ )
        vec[i].clear();
    for(int i = 0 ; i < m ; i ++ ){
        int x,y,w;
        scanf("%d %d %d",&x, &y, &w);
        vec[x].push_back({ y, w });
        vec[y].push_back({ x, w });
    }
}
int dijkstra(int from, int to, int node){

    int distance[node];
    fill(distance ,distance + node, 1e9); 

    distance[ from ] = 0;
    priority_queue<Node> pq;
    pq.push({ from , 0 });
    while( !pq.empty() ){

        Node walk = pq.top();
        pq.pop();
        if( walk.to == to )
            return walk.w;
        if( walk.w > distance[ walk.to ] )
            continue;
        
        for( Node nextWalk : vec[ walk.to ] ){

            if( ( nextWalk.w + walk.w ) < distance[ nextWalk.to ] ){

                distance[ nextWalk.to ] =  nextWalk.w + walk.w;
                pq.push( { nextWalk.to ,distance[ nextWalk.to ] } );
            }
        }
    }
    return 1e9;
}
int main(){

    int test;
    scanf("%d",&test);
    
    int cas = 1;
    while( test -- ){

        int node, m, from, to;
        scanf("%d %d %d %d", &node, &m, &from, &to);
        init( node , m );
        int ans = dijkstra( from , to , node );

        if( ans != 1e9 ){
            
            printf("Case #%d: %d\n", cas++ , ans );
        }
        else{
        
            printf("Case #%d: unreachable\n", cas++ );
        }

    }
    return 0;
}