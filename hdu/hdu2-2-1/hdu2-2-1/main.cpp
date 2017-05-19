//
//  main.cpp
//  hdu2-2-1
//
//  Created by 孙斗南 on 2017/2/21.
//  Copyright © 2017年 test. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int fib[31];
void node()
{
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i <= 30 ; i++ )
    {
        fib[i] = fib[i-1] + fib [i-2];
    }
    string str1 = to_string (fib[30]);
    string str2 = to_string(fib[29]);
    cout<< str1 + str2 <<endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    node();
    return 0;
}
