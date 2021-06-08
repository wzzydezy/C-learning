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

int trailingZeroes(int n) {
    int m = n;
    int count5 = 0;
    for(int i=5;i<=n;i=i+5){
        int j = i;
        while(j>=5){
            j=j/5;
            count5++;
        }
    }
    return count5;
}

int main(){
    int res = trailingZeroes(30);
    return 0;
}