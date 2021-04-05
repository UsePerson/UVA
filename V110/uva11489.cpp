#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int cas = 1;
    cin >> t;
    while(t --){

        string s;
        cin >> s;
        vector<int> remainder[3];
        int sum = 0;
        for(int i = 0 ; i < s.size(); i ++ ){

            int num = s[i] - '0';
            sum += num;
            if(num % 3 == 1){

                remainder[1].push_back(num);
            }
            else if(num % 3 == 2){

                remainder[2].push_back(num);
            }
            else{

                remainder[0].push_back(num);
            }
        }
        bool winS = true;
        if( (sum % 3 == 1) && ( !remainder[1].size() ) || (sum % 3 == 2) && ( !remainder[2].size() ) ){

            winS = false;
        }
        else{

            int cnt = 0;
            if( !(sum % 3) ){
                cnt++;
            }

            cnt += remainder[0].size();

            if( cnt & 1 )
                winS = false;
        }

        if(winS){

            printf("Case %d: S\n", cas++);
        }
        else{

            printf("Case %d: T\n", cas++);
        }

    }
}