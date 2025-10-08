#include <iostream>
using namespace std;

long long fibo(int n){
    // vector<long long> f(n+1);
    long long first=0;
    long long second=1;
    for(int i=2;i<n;i++){
        long long temp=first+second;
        first=second;
        second=temp;
    }
    return second;
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
}
// 0 1 1 2 3 5 8 13 21 34 55 89