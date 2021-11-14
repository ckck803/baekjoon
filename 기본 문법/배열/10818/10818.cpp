#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main(void){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<*min_element(arr, arr+n)<<" "<<*max_element(arr, arr+n)<<'\n';
}