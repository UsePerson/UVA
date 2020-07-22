#include<bits/stdc++.h>
using namespace std;
struct Edge{

    int from;
    int to;
    double distance;

    bool operator < (const Edge &other) const{
        return distance < other.distance;
    }
};
struct Node{

    int x;
    int y;
    int population;
};
vector<Edge> edge, graph[1000 +5 ];
Node node[10005];

double dis(int i , int j){
    double x = node[i].x - node[j].x;
    double y = node[i].y - node[j].y;
    return sqrt( x * x + y * y );
}
int arr[1005];
int findparent(int x){
    
    return ( arr[x] <= -1 )? x : ( arr[x] = findparent( arr[x] ) ); 
}
bool find(int a, int b){

    int x = findparent(a);
    int y = findparent(b);
    if( x == y ){
        return false;
    }
    else if( arr[x] > arr[y] ){
        arr[y] += arr[x];
        arr[x] = y;
    } 
    else{
        arr[x] += arr[y];
        arr[y] = x;
    }
    return true;
}
double kruskal(int cas){

    for(int i = 0  ;i < cas ; i ++ ){

        arr[i] = -1;
        graph[i].clear();
    }
    double ansB = 0.0;
    int cnt = 0;
    for(Edge e: edge){

        if( find(e.from,e.to) ){
            graph[e.from].push_back(e);
            graph[e.to].push_back({e.to,e.from,e.distance});
            ansB += e.distance;
            if( ++cnt == cas -1 )break;
        }
    }
    return ansB;
}
double XuFu[1005][1005];
bool check[1005];
void dfs(int first , int now){

    check[now] = 0;
    for( Edge g : graph[now] ){

        if( check[g.to] ){
            XuFu[first][g.to] = max( XuFu[first][g.from] , g.distance );
            dfs( first , g.to );
        }
    }
}
int main(){

    int test;
    scanf("%d",&test );
    while(test -- ){

        int cas;
        scanf("%d",&cas );
        for(int i = 0  ;i < cas ; i ++ ){

            int x,y,p;
            scanf("%d %d %d", &node[i].x, &node[i].y, &node[i].population );
        }
        edge.clear();
        for(int i = 0  ;i < cas ; i ++ ){

            for(int j = i+1 ; j < cas ; j ++ ){

                edge.push_back( { i, j, dis( i , j ) } );
            }
        }
        sort( edge.begin(), edge.end() );

        double ansB = kruskal(cas);

        memset( XuFu,0,sizeof( XuFu ) );
        for(int i = 0  ;i < cas ; i ++ ){

            memset(check,1,sizeof(check));
            dfs(i,i);
        }

        double ans = 0.0;
        for(int i = 0  ;i < cas ; i ++ ){

            for(int j = i+1 ; j <cas ; j ++ ){

                ans = max( ans , (double)(  node[i].population + node[j].population ) / ( ansB -XuFu[i][j] ) );
            }
        }

        printf("%.2lf\n",ans);
    }

}