extern int xlat[];
extern int XLAT_SIZE;

void encrypt_ios7(char* const password, char* hash);
void decrypt_ios7(char* const hash, char* password);
