/*
* Fenwick tree implementation for 3D matrix
*
* This file is subject to the terms and conditions defined in
* file 'LICENSE.txt', which is part of this source code package.
*/

#include "ft_imp.h"


/*
* Fenwick tree implementation for 3D matrix
*/

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