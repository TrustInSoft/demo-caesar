#include <stdlib.h>
#include <stdio.h>
#include <caesar.h>

void gen_test(char *str, int str_len, int shift)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = caesar_encrypt(str, str_len, shift);
    if (!res1) return;
    printf("Result:       %s\n", res1);

    printf("Decrypt text '%s'\n", res1);
    res2 = caesar_decrypt(res1, str_len, shift);
    if (!res2) return;
    printf("Result:       %s\n", res2);

    free(res1);
    free(res2);
}

int main(void)
{
    check_magic_number();

    char orig_str[] = "People of Earth, your attention please";
    int str_len = sizeof orig_str;

    printf("Test 1: Shift with a negative input\n");
    gen_test(orig_str, str_len, -3);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(orig_str, str_len, 7);

    return 0;
}
