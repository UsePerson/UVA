#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    string s[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(n --){

        int m,d;
        cin >> m >> d;
       
        int new_year_eve = 5; // Saturday, 2010/12/31
        for(int i = 0 ; i < (m - 1) ; i ++ ){

            new_year_eve += days[i];
        }

        cout << s[ (new_year_eve + d) % 7 ] << "\n";
    }

}
    
