#include <stdlib.h>

#define ASSERT(x) if (!(x)) 1/0

#ifdef DEBUG
# define LOG(x) printf("%c\n", x)
#else
# define LOG(x) while(0) // noop
#endif

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

// Return 'A', 'a', or 0
char get_a(char c)
{
    char a;

    if ('A' <= c && c <= 'Z')
        a = 'A';
    else if ('a' <= c && c <= 'z')
        a = 'a';
    else
        return 0;

    LOG(*str);
    // check that c - a ∈ [0..NB_LTR-1]
    ASSERT(0 <= c - a);
    ASSERT(c - a < NB_LTR);
    return a;
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
        char a = get_a(*str);
        if (a) {
            // check that *str - a ∈ [0..NB_LTR-1]
            ASSERT(0 <= *str - a);
            ASSERT(*str - a < NB_LTR);

            buf[i] = (*str + abs_shift - a) % NB_LTR + a;
        }
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
        char a = get_a(*str);
        if (a) {
            // check that *str - a ∈ [0..NB_LTR-1]
            ASSERT(0 <= *str - a);
            ASSERT(*str - a < NB_LTR);

            buf[i] = (*str + (NB_LTR - abs_shift) - a) % NB_LTR + a;
        }
        else
            /* Spaces and other characters are not encrypted. */
            buf[i] = *str;
        i++;
        str++;
    }
    buf[i] = '\0';
    return buf;
}
