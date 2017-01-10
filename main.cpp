#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include "ft_imp.h"
using namespace std;

/*
long long update(long long x, long long y, long long z, long long val){
    matrix[x][y][z] = val;
    return val;
}

long long query(long long x1, long long y1, long long z1, long long x2, long long y2, long long z2){
    long long sum = 0;
    long long x, y, z;

    z = z1;
    while(z<=z2){
        y = y1;
        while(y<=y2){
            x = x1;
            while(x<=x2){
                sum += matrix[x][y][z];
                x+=1;
            }
            y+=1;
        }
        z+=1;
    }

    return sum;
}
*/
void processCase(int T)
{
    // Store test case variables:
    // N => matrix size
    // M => Commands number
    long long n, m;
    char cmd[8];
    scanf("%lld %lld", &n, &m);

    long long x1, y1, z1, x2, y2, z2, val;

    memset(matrix, 0, sizeof(matrix));

    while (m){
        scanf("%s", cmd);
        if(!strcmp(cmd, "UPDATE")){
            // Execute upate command.
            scanf(" %lld %lld %lld %lld", &x1, &y1, &z1, &val);
            //update(x1, y1, z1, val);
            //printf("UPDATE\n");
            fenwick_update(x1, y1, z1, val - fenwick_get(x1, y1, z1, x1, y1, z1, n), n);
            //printf("%s %d %d %d %d\n", cmd, x1, y1, z1, val);
        }
        if(!strcmp(cmd, "QUERY")){
            // Execute query calculation.
            long long result;
            scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &z1, &x2, &y2, &z2);
            //result = query(x1, y1, z1, x2, y2, z2);
            //printf("QUERY\n");
            result = fenwick_get(x1, y1, z1, x2, y2, z2, n);
            printf("%lld\n", result);
            //printf("%s %d %d %d %d %d %d\n", cmd, x1, y1, z1, x2, y2, z2);
        }
        m = m-1;
    }
}

int main()
{
    // Setting stdout to file
    freopen("output.txt", "a+", stdout);

    // Test cases number
    int T;
    scanf("%d", &T);

    while (T--)
    {
        // Process each case separately.
        processCase(T);
    }
    return 0;
}