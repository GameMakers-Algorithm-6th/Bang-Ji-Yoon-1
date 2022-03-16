#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int input, answer=0;
    const int threeKg = 3;
    const int fiveKg = 5;

    cin>>input;

    while(input>=threeKg){
        if(input%5==0){
            input -= 5;
            answer++;
        }
        else if(input%3==0){
            input -= 3;
            answer++;
        }
        else{
            if(input>=fiveKg){
                input -= 5;
                answer++;
            }
            else{
                input -= 3;
                answer++;
            }
        }
    }

    cout<<((input==0)?answer:-1);;
    return 0;
}