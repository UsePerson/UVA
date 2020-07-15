#include<bits/stdc++.h>
using namespace std;
int x[ 50000 + 5 ];
int y[ 50000 + 5 ];
int main(){

    int test ;
    scanf("%d",&test);
    while(test -- ){

        int x_size,y_size,cas;
        scanf("%d %d %d",&x_size,&y_size,&cas);
        for(int i = 0 ; i < cas ; i ++ ){
            scanf("%d %d",&x[i],&y[i]);
        }
        sort(x,x + cas);
        sort(y,y + cas);
        printf("(Street: %d, Avenue: %d)\n",x[ ( cas - 1 ) / 2 ],y[ ( cas - 1 ) / 2 ]);
    }
}