/*
* Fenwick tree implementation for 3D matrix
*
* This file is subject to the terms and conditions defined in
* file 'LICENSE.txt', which is part of this source code package.
*/

long long matrix[101][101][101];
long long fenwick_sum(long x, long y, long z, long n);
long long fenwick_get(long x, long y, long z, long x1, long y1, long z1, long n);
void fenwick_update(long x, long y, long z, long long val, long n);