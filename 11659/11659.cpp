#include <iostream>
using namespace std;

int n, m;
vector<long long> v;
vector<long long> tree;

long long init(int node, int start, int finish){
    if(start == finish){
        return tree[node] = arr[start];
    }

    int mid = (start + finish) / 2;
    tree[node] = init(node * 2, start, mid) + 
}

int main(void){
    cin>>n>>m;
    v = vector<long long>(n);
    tree = vector<long long>(4*n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    for(int j=0; j<m; j++){
        int a, b;
        cin>>a>>b;
    }
}