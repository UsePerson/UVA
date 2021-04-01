#include<bits/stdc++.h>
using namespace std;

int num[10+5];
bool check(int a){

    if((a / 10000) == 0 )
        num[0]++;
    
    while(a){

        num[a%10]++;
        if(num[a%10] > 1)
            return 0;
        a /= 10;
    }
    if(num[0] > 1)
        return 0;
    return 1;
}

int main(){

    int n;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    while( cin>>n && n ){

        if(cnt++){

            cout << '\n';    
        }
        bool noPairs = true;
        for(int i = 1234 ; i <= (98765/n) ; i ++ ){

           
            fill(num, num+10, 0);

            if( !check(i) || !check(i*n) )
                continue;
            
            noPairs = false;
            if( (i / 10000) == 0){

                cout << (i*n) << " / 0" << i << " = " << n << '\n';
            }
            else{

                cout << (i*n) << " / " << i << " = " << n << '\n';
            }

        }
        
        if(noPairs){

            cout << "There are no solutions for " << n << ".\n";
        }
        
    }
}