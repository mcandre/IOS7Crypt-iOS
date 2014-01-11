extern int xlat[];
extern int XLAT_SIZE;

void encrypt_ios7(const char *password, char *hash);
void decrypt_ios7(const char *hash, char *password);
