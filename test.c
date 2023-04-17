#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "ryu.h"

#define test(fmt, input, expected) { \
    char buf[256]; \
    ryu_print((input), (fmt), buf, sizeof(buf)); \
    if (strcmp(buf, (expected)) != 0) { \
        fprintf(stderr, "line %d: expected %s, got %s\n", \
            __LINE__, (expected), buf); \
        exit(1); \
    } \
}

int main(void) {
    test('f', 212123123.123188832, "212123123.12318882");
    test('e', 212123123.123188832, "2.1212312312318882e8");
    test('E', 212123123.123188832, "2.1212312312318882E8");
    test('f', 9223372036854775808.0, "9223372036854776000");
    test('f', 0.000123123001, "0.000123123001");
    test('f', 1.3441331, "1.3441331");
    test('f', 1.0, "1");
    test('f', -1.0, "-1");
    test('f', -0.0, "-0");
    test('f', 0.5, "0.5");
    test('f', -0.5, "-0.5");
    test('f', 0.0, "0");
    test('f', -0.0, "-0");
    test('f', 0.5, "0.5");
    test('f', -0.5, "-0.5");
    test('f', 0.0, "0");
    test('f', -0.01, "-0.01");
    test('f', -0.015, "-0.015");
    test('f', 5000.0, "5000");
    test('f', 0000.0, "0");
    test('f', 5000000000000000000.0, "5000000000000000000");
    test('f', 5123.0, "5123");

    char buf[32];
    size_t n1 = ryu_print(-112.89123883, 'f', buf, sizeof(buf));
    assert(strcmp(buf, "-112.89123883") == 0);
    size_t n2 = ryu_print(-112.89123883, 'f', NULL, 0);
    assert(n1 == n2);
    size_t n3 = ryu_print(-112.89123883, 'f', buf, 5);
    assert(n3 == n2);
    assert(strcmp(buf, "-112") == 0);

    ryu_print(-112.89123883, 'f', buf, 1);
    assert(strcmp(buf, "") == 0);
    ryu_print(-112.89123883, 'f', buf, 2);
    assert(strcmp(buf, "-") == 0);
    ryu_print(-112.89123883, 'f', buf, 6);
    assert(strcmp(buf, "-112.") == 0);

    return 0;
}
