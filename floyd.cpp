#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <list>
#include <stdlib.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if(i==j) a[i][i] = 0;
            else{
                a[i][j] = 99999999;
            }
        }
    }
    for(int i=0;i<m;i++){
        int x,y,d;
        cin>>x>>y>>d;
        a[x][y] = d;
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
    }
    cout<<a[3][1];
    return 0;
}
