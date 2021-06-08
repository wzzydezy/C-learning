#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

void dfs(vector<vector<string>> &res, const string &node, unordered_map<string, set<string>> &from,
      vector<string> &path){
          if(from[node].empty()){
              res.push_back({path.rbegin(), path.rend()});
              return;
          }
          for (const string &parent:from[node]){
              path.push_back(parent);
              dfs(res, parent, from, path);
              path.pop_back();
          }
      }

vector<vector<string>> findladders(string beginword, string endword, vector<string> &wordlist){
    vector<vector<string>> res;
    unordered_set<string> dict = {wordlist.begin(), wordlist.end()};
    if(dict.find(endword)==dict.end()){
        return res;
    }
    dict.erase(beginword);
    //
    unordered_map<string, int> steps = {{beginword, 0}};
    unordered_map<string, set<string>> from = {{beginword,{}}};
    int step = 0;
    bool found = false;
    queue<string> q = queue<string>{{beginword}};
    int wordlen = beginword.size();
    while(!q.empty()){
        step++;
        int size = q.size();
        for(int i=0;i<size;i++){
            const string curword = q.front();
            string nextword = curword;
            q.pop();
            for(int j=0;j<wordlen;++j){
                const char origin = nextword[j];
                for(char c='a';c<='z';++c){
                    nextword[j] = c;
                    if(steps[nextword]==step){
                        from[nextword].insert(curword);
                    }
                    if(dict.find(nextword)==dict.end()){
                        continue;
                    }
                    dict.erase(nextword);
                    q.push(nextword);
                    from[nextword].insert(curword);
                    steps[nextword] = step;
                    if (nextword == endword){
                        found = true;
                    }
                }
                nextword[j] = origin;
            }
        }
        if (found){
            break;
        }
    }
    if (found) {
        vector<string> path = {endword};
        dfs(res, endword, from, path);
    }
}

int main(){
     string beginword = "hit";
     string endword = "cog";
     vector<string> wordlist = {"hot","dot","dog","lot","log","cog"};
     vector<vector<string>> res = findladders(beginword, endword, wordlist);
     return 0;
}