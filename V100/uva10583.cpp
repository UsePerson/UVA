#include<bits/stdc++.h>
using namespace std;
int arr[ 50000 + 5 ];
int findparent(int a){

    return (arr[a] < 0 )? a: findparent(arr[a]);
}
void find(int a, int b){

    int x = findparent(a);
    int y = findparent(b);
    if(x == y){

    }
    else if(arr[x] < arr[y] ){
        arr[x] += arr[y];
        arr[y] = x;
    }
    else {
        arr[y] += arr[x];
        arr[x] = y;
    }
    
}
int ans(int member){

    int sum = 0;
    for(int i = 1 ; i <= member ; i ++ ){
        if(arr[i] < 0)sum ++ ;
    }
    
    return sum;
}
int main(){

    int member,cas;
    int test = 1;
    while(scanf("%d %d",&member,&cas) && member && cas){

        memset(arr, -1 , sizeof(arr));
        for(int i = 0 ; i < cas ; i ++ ){
            int a,b;
            scanf("%d %d",&a,&b);
            find(a,b);
        }
        printf("Case %d: %d\n",test++,ans(member));
    }
    return 0;
}