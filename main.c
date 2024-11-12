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
    gen_test(orig_str, str_len, -3);

    int shift;
    tis_make_unknown(&shift, sizeof(shift));
    gen_test(orig_str, str_len, shift);

    return 0;
}
