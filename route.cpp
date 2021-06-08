#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    int bi=0,bj=0;
    vector<vector<int>> use(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char s;
            cin>>s;
            if(s=='$'){
                bi = i;
                bj = j;
            }
            else if(s=='#'){
                use[i][j]=1;
            }

        }
    }
    vector<string> direction(k,"");
    for(int i=0;i<k;i++){
        cin>>direction[i];
    }
    for(int i=0;i<k;i++){
        if(direction[i]=="EAST"){
            if(bj<m-1 && use[bi][bj+1]!=1){
                  ++bj;
            }
        }
        if(direction[i]=="WEST"){
            if(bj>0 && use[bi][bj-1]!=1){
                  --bj;
            }
        }
        if(direction[i]=="NORTH"){
            if(bi>0 && use[bi-1][bj]!=1){
                  --bi;
            }
        }
        if(direction[i]=="SOUTH"){
            if(bj>n-1 && use[bi+1][bj]!=1){
                  ++bi;
            }
        }
        cout<<"("<<bi<<","<<bj<<")"<<endl;
    }

    return 0;
}
