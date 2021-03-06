/*
 * 最简分数需要用到最大公约数，因此需要先定义一个最大公约数函数。
 * 最大公约数一般用辗转相除法得到，辗转相除法即：
 * 辗转相除法即：a, b --> b, a % b, 例如：15, 10 --> 10, 5 --> 5, 0 | 5 就是
 */

#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() {

    int n1, m1, n2, m2, k;
    scanf("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);

    if(n1 * m2 > n2 * m1) {
        swap(n1, n2);
        swap(m1, m2);
    }

    int num = 1;
    bool flag = false;
    while(n1 * k >= m1 * num) num++;
    while(n1 * k < m1 * num && m2 * num < n2 * k) {
        if(gcd(num, k) == 1) {
            printf("%s%d/%d", flag == true ? " " : "", num, k);
            flag = true;
        }
        num++;
    }
    return 0;
}
