#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    while(n --){

        int e,c,f,ans=0;
        cin >> e >> f >> c;
        e += f;
        while( (e/c) != 0){

            ans += e/c;
            e = e/c + e%c; 
        }
        printf("%d\n",ans);
    }

}
    
