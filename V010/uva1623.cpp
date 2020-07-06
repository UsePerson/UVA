#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int in[N];
int lake[N];
int ans[N];
int noRain[N];
void init (int day){

    memset(ans, 0, sizeof(ans));
    memset(lake, 0, sizeof(lake));
    memset(noRain, 0, sizeof(noRain));
    for(int i  = 1 ; i <= day ; i ++) {
        scanf("%d",&in[i]);
    }
    noRain[day+1] = day+1;
    for(int i = day ; i > 0 ; i -- ){

        if(in[i] == 0){
            noRain[i] = i ;
        }
        else{
            noRain[i] = noRain[i+1];
        }
    }
    noRain[0] = noRain[1];
}
int find(int x){

    if( noRain[x] == x) return x;
    return noRain[x] = find(noRain[x]);
}
int main(){
    
    int test;
    scanf("%d",&test);
    while(test -- ) {

        int lakeSize, day;
        scanf("%d%d", &lakeSize, &day );
        init(day);
        bool t= true;
        for(int i = 1 ; i <= day ; i ++){

            if(in[i] == 0)continue;
            int x = find(lake[in[i]]);
            if(x <=i){

                ans[x] = in[i];
                noRain[x] = find(x+1);
            }
            else{
                t= false;
                break;
            }
            lake[in[i]] = i;
        }
        if(t){
            puts("YES");
            for(int i = 1  ;i <= day ; i++){
                if(in[i] == 0)
                    printf("%d ",ans[i]);
            }
            puts("");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}