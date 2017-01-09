#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void processCase(int T)
{
    // Store test case variables:
    // N => matrix size
    // M => Commands number
    long long n, m;
    char cmd[8];
    scanf("%lld %lld", &n, &m);

    int x1, y1, z1, x2, y2, z2, val;

    printf("Test case: %d\n", T);
    printf("N: %lld, M: %lld\n", n, m);

    while (m){
        scanf("%s", cmd);
        if(!strcmp(cmd, "UPDATE")){
            // Execute upate command.
            scanf(" %d %d %d %d", &x1, &y1, &z1, &val);
            printf("%s %d %d %d %d\n", cmd, x1, y1, z1, val);
        }
        if(!strcmp(cmd, "QUERY")){
            // Execute query calculation.
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            printf("%s %d %d %d %d %d %d\n", cmd, x1, y1, z1, x2, y2, z2);
        }
        m = m-1;
    }

    long matrix[n][n][n];
    memset(matrix, 0, sizeof(matrix));
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