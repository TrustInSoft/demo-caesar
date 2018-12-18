void check_magic_number(void);

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
