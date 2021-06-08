#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

    int n = 0;

    void dfs(string node, unordered_map<string, set<string>> &from, vector<string> &path){
        if(from[node].empty()){
            n = path.size();
            return;
        }
        for(const string &parent : from[node]){
            path.push_back(parent);
            dfs(parent, from, path);
            path.pop_back();
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
          unordered_set<string> dict = {wordList.begin(), wordList.end()};
          if(dict.find(endWord) == dict.end()){
              return 0;
          }
          dict.erase(beginWord);
          unordered_map<string, int> steps = {{beginWord, 0}};
          unordered_map<string, set<string>> from = {{beginWord, {}}};
          int step = 0;
          bool found = false;
          queue<string> q;
          q.push(beginWord);
          int wordllen = beginWord.size();
          while(!q.empty()){
              step++;
              int size = q.size();
              for(int i=0;i<size;i++){
                  string cur = q.front();
                  string next = cur;
                  q.pop();
                  for(int j = 0; j<wordllen; j++){
                      char origin = next[j];
                      for(char c = 'a';c<='z';c++){
                          next[j]=c;
                          if(steps[next] == step){
                             from[next].insert(cur);
                          }
                          if(dict.find(next)==dict.end()){
                              continue;
                          }
                          dict.erase(next);
                          q.push(next);
                          from[next].insert(cur);
                          steps[next]=step;
                          if(next == endWord){
                              found = true;
                          }
                      }
                      next[j]=origin;
                  }
              }
              if(found){
                  break;
              }
          }
          if(found){
              vector<string> Path = {endWord};
              dfs(endWord, from, Path);
          }
          return n;
    }



int main(){
     string beginword = "hit";
     string endword = "cog";
     vector<string> wordlist = {"hot","dot","dog","lot","log","cog"};
     int n  = ladderLength(beginword, endword, wordlist);
     return 0;
}