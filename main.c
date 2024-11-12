#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "caesar.h"

#include <tis_builtin.h>

void gen_test(char *str, size_t str_len, int shift)
{
    char *res1, *res2;

    res1 = caesar_encrypt(str, str_len, shift);
    res2 = caesar_decrypt(res1, str_len, shift);

    free(res1);
    free(res2);
}

int main(void)
{
    char orig_str[] = "Hello, world!";
    unsigned long str_len = sizeof orig_str;

    printf("Test 1: Shift with a negative input\n");
    int shift = tis_interval(INT_MIN+1, INT_MAX);
    gen_test(orig_str, str_len, shift);

    for(int i = 0; i < str_len - 1; i++)  // Keep the string null terminated.
      orig_str[i] = tis_interval(1, CHAR_MAX); // Don't introduce null character in the middle.

    gen_test(orig_str, str_len, shift);

    return 0;
}
