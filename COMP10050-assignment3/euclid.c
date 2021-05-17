//
// Created by agbod on 5/15/2021.
//

#include "euclid.h"

int gcd1(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcd2(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int gcd3(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd3(b, a % b);
    }
}
