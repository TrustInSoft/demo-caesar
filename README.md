# Demo-caesar

## Overview

This library serves as the support material for TrustInSoft Analyzer
tutorial. The purpose of this tutorial is to successively perform:

- The verification of the test suite
- The verification of the generalized test suite with the exhaustive
  API verification

### Tags

For the purpose of the tutorial, each verification step is marked with
a git tag. This allows to easily follow the verification methodology.

- Tag `STEP_0`: Verification of the test suite
- Tag `STEP_1`: Fixes of the test suite
- Tag `STEP_2`: Verification of the generalized test suite
- Tag `STEP_3`: Fixes of the generalized test suite
- Tag `STEP_4`: Exhaustive verification

## Caesar Cipher

This library is based on the Caesar cipher.

> The Caesar cipher is one of the simplest and most widely known
> encryption techniques. It is a type of substitution cipher in which
> each letter in the plain text is replaced by a letter some fixed
> number of positions down the alphabet.
>
> [Caesar cipher](http://en.wikipedia.org/caesar_cypher)

For example, with a fix number `3`, the letter `A` is replaced by `D`.

```
Plain text:   c a e s a r
Cipher text:  f d h v d u
```

### API Reference

The user provides the string to encrypt as well as the corresponding
shifting value, and the same applies for the decrypt version.

The specificity of the `caesar_encrypt` function is that it always
performs a shift to the right while the `caesar_decrypt` function
always performs a shift to the left.

```c
/* \brief Encrypt a string with a right shift specified by the user
   \param [in] str The string to encrypt
   \param [in] shift The right shift to perform
   \return The pointer to the encrypted string
*/
char *caesar_encrypt(char *str, int shift);

/* \brief Decrypt a string with a left shift specified by the user
   \param [in] str The string to decrypt
   \param [in] shift The left shift to perform
   \return The pointer to the decrypted string
*/
char *caesar_decrypt(char *str, int shift);
```

## Test suite

A test driver has been written to check the functional correctness of
the source code:

```
∀ string str, int d, caesar_decrypt(caesar_encrypt(str, d), d) = str
```

The test driver performs two tests:

1. encrypt and decrypt a string with a negative shift value
2. encrypt and decrypt a string with a positive shift value

The two tests aim at covering all the source code and checking the
source code specification (i.e. passing a negative value to
`caesar_encrypt` should still perform a shift to the right).

### Results

```
$ gcc -I. -fprofile-arcs -ftest-coverage caesar.c main.c && ./a.out

Test 1: Shift with a negative input
Encrypt text 'People of Earth, your attention please'
Result:       Shrsoh ri Hduwk, brxu dwwhqwlrq sohdvh
Decrypt text 'Shrsoh ri Hduwk, brxu dwwhqwlrq sohdvh'
Result:       People of Earth, your attention please

Test 2: Shift with a positive input
Encrypt text 'People of Earth, your attention please'
Result:       Wlvwsl vm Lhyao, fvby haaluapvu wslhzl
Decrypt text 'Wlvwsl vm Lhyao, fvby haaluapvu wslhzl'
Result:       People of Earth, your attention please
```

```
$ gcov caesar.c

File 'caesar.c'
Lines executed:100.00% of 38
Creating 'caesar.c.gcov'
```
