#include <stack>

using namespace std;

int main(){
    stack<int> sta;
    sta.push(1);
    sta.push(2);
    sta.push(3);
    int z = move(sta.top());
    z = 5;
    int b = sta.top();
    return 0;
}