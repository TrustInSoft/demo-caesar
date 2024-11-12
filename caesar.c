#include <stdlib.h>

#define ASSERT(x) (1/(x))

#define NB_LTR ('z' - 'a' + 1)

void check_magic_number(void)
{
    short tmp = (short)(0x1234 << 8);
    char c = ((char *)&tmp)[0];
    int i = 0 << (int)c;
}

int absolute_int(int x)
{
    int abs_x;
    if (x < 0)
        abs_x = -x;
    else
        abs_x = x;
    return abs_x;
}

// Fills out parameter 'a' and 'z' if c is a lower case letter,
// 'A' and 'Z' if c is an upper case letter,
// 'A' and 'Z' if c is an upper case letter,
// return 0 if c is not a letter.
int alphabet_limits(char c, char* a, char* z) {
  int ret;
  if (c >= 'a' && c <= 'z') {
    *a = 'a';
    *z = 'z';
    ret = 1;
  } else if (c >= 'A' && c <= 'Z') {
    *a = 'A';
    *z = 'Z';
    ret = 1;
  } else {
    *a = *z = 0;
    ret = 0;
  }

  ASSERT(*a <= *z);
  return ret;
}

char *caesar_encrypt(char *str, unsigned long str_len, int shift)
{
    int abs_shift = absolute_int(shift);
    int i = 0;
    char *buf = (char *)malloc(str_len);
    if(!buf)
      exit(1);

    while (*str) {
        char a, z;
        int is_alphabetical = alphabet_limits(*str, &a, &z);
        ASSERT(a <= z);
        if (is_alphabetical)
            buf[i] = (*str + abs_shift % NB_LTR - a) + a;
        else if (*str >= 'A' && *str <= 'Z')
            buf[i] = (*str + abs_shift % NB_LTR - 'A') + 'A';
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
