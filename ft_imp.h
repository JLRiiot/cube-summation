/*
* Fenwick tree implementation for 3D matrix
*
* This file is subject to the terms and conditions defined in
* file 'LICENSE.txt', which is part of this source code package.
*/

long long fenwick_get(long x, long y, long z);
long long fenwick_sum(long x, long y, long z);
void fenwick_update(long x, long y, long z, long long val);