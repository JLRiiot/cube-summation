#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h> 

using namespace std;
/*
* Fenwick tree implementation for 3D matrix
*/

long long matrix[101][101][101];
// Implementing less significant bit function
#define LSB(i) ((i) & (-i))

long long fenwick_sum(long x, long y, long z, long n){
    long long sum = 0;
    long y1, x1;
    while(z>0){
        x1 = x;
        while(x1>0){
            y1 = y;
            while(y1>0){
                sum += matrix[x1][y1][z];
                //printf("sum >> %ld, %ld, %ld   |   %lld\n", x1, y1, z, sum);
                y1 -= LSB(y1);
            }
            x1 -= LSB(x1);
        }
        z -= LSB(z);
    }
    //printf("sum >> %ld, %ld, %ld   |   %lld\n", x, y, z, sum);
    return sum;
}

long long fenwick_get(long x, long y, long z, long x1, long y1, long z1, long n){
    long long v1 = 0, v2 = 0;

    v1 = fenwick_sum(x1, y1, z1, n) -  fenwick_sum(x-1, y1, z1, n) 
        - fenwick_sum(x1, y-1, z1, n) + fenwick_sum(x-1, y-1, z1, n);
    v2 = fenwick_sum(x1, y1, z-1, n) - fenwick_sum(x-1, y1, z-1, n) 
        - fenwick_sum(x1, y-1, z-1, n) + fenwick_sum(x-1, y-1, z-1, n);

    return v1 - v2;
}

void fenwick_update(long x, long y, long z, long long val, long n){
    long x1, y1;
    while(z<=n){
        x1 = x;
        while(x1<=n){
            y1 = y;
            while(y1<=n){
                //printf("%ld, %ld, %ld  |  %lld\n", x1, y1, z, matrix[x1][y1][z]);
                matrix[x1][y1][z] += val;
                //printf("%ld, %ld, %ld  |  %lld\n", x1, y1, z, matrix[x1][y1][z]);

                y1 += LSB(y1);
            }
            x1 += LSB(x1);
        }
        z += LSB(z);
    }
}

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