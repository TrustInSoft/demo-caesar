#include <stdlib.h>

#define NB_LTR ('z' - 'a' + 1)

int absolute_int(int x)
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}

int upper[NB_LTR] = {0};
int lower[NB_LTR] = {0};
void count(char c)
{
    size_t offset;
    int *upper_or_lower = NULL;

    if ('A' <= c && c <= 'Z') {
        offset = c - 'A';
        upper_or_lower = &upper[0];
    } else if ('a' <= c && c <= 'z') {
        offset = c - 'a';
        upper_or_lower = &lower[0];
    }

    if (upper_or_lower != NULL)
        upper_or_lower[offset]++;
}

char *caesar_encrypt(char *str, unsigned long str_len, int shift)
{
    int abs_shift = absolute_int(shift);
    abs_shift %= NB_LTR;
    int i = 0;
    char *buf = (char *)malloc(str_len);
    if(!buf)
      exit(1);

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            buf[i] = (*str + abs_shift - 'a') % NB_LTR + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            buf[i] = (*str + abs_shift - 'A') % NB_LTR + 'A';
        else
            /* Spaces and other characters are not encrypted. */
            buf[i] = *str;
        i++;
        str++;
    }
    buf[i] = '\0';
    return buf;
}

char *caesar_decrypt(char *str, unsigned long str_len, int shift)
{
    int abs_shift = absolute_int(shift);
    abs_shift %= NB_LTR;
    int i = 0;
    char *buf = (char *)malloc(str_len);
    if(!buf)
      exit(1);

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            buf[i] = (*str + (NB_LTR - abs_shift) - 'a') % NB_LTR + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            buf[i] = (*str + (NB_LTR - abs_shift) - 'A') % NB_LTR + 'A';
        else
            /* Spaces and other characters are not encrypted. */
            buf[i] = *str;
        i++;
        str++;
    }
    buf[i] = '\0';
    return buf;
}
