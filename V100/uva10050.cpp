#include<bits/stdc++.h>
using namespace std;
int main(){

    int T;
    cin >> T;
    while(T--){

        int n,p;
        cin >> n >> p;
        bool day[n];
        memset(day,0,sizeof(day));
        int ans =0;
        int size = sizeof(day);
        for(int i = 0 ; i < p ; i ++ ){
            int party;
            cin >> party;
            int real_day = party-1;
            while( real_day < size ){
                if(!day[real_day] && ((real_day%7!=5) && ((real_day)%7!=6))){
                    day[real_day] = 1;
                    ans++;
                }
                real_day += party;
            }
        }
        printf("%d\n",ans);
    }
}