/*
   Andrew Pennebaker
   Copyright 2005-2011 Andrew Pennebaker
*/

#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "ios7crypt.h"

int xlat[] = {
  0x64, 0x73, 0x66, 0x64, 0x3b, 0x6b, 0x66, 0x6f,
  0x41, 0x2c, 0x2e, 0x69, 0x79, 0x65, 0x77, 0x72,
  0x6b, 0x6c, 0x64, 0x4a, 0x4b, 0x44, 0x48, 0x53,
  0x55, 0x42, 0x73, 0x67, 0x76, 0x63, 0x61, 0x36,
  0x39, 0x38, 0x33, 0x34, 0x6e, 0x63, 0x78, 0x76,
  0x39, 0x38, 0x37, 0x33, 0x32, 0x35, 0x34, 0x6b,
  0x3b, 0x66, 0x67, 0x38, 0x37
};

int XLAT_SIZE = 53;

void encrypt_ios7(char* const password, char* hash) {
  size_t password_length;

  int seed;

  size_t i;

  if (
    password != NULL &&
    strlen(password) > 0 &&
    hash != NULL
  ) {
    password_length = strlen(password);

    seed = rand() % 16;

    (void) snprintf(hash, 3, "%02d", seed);

    for (i = 0; i < password_length; i++) {
      (void) snprintf(hash + 2 + i * 2, 3, "%02x", (unsigned int) (password[i] ^ xlat[(seed++) % XLAT_SIZE]));
    }
  }
}

void decrypt_ios7(char* const hash, char* password) {
  long seed;
  size_t i;
  int index, c;

  char *pair = (char*) calloc(3, sizeof(char));

  if (
    hash != NULL &&
    strlen(hash) > 3 &&
    password != NULL &&
    pair != NULL) {

    strncat(pair, hash, 2);

    seed = strtol(pair, NULL, 10);

    index = 0;

    for (i = 2; i < strlen(hash); i += 2) {
      pair[0] = pair[1] = '\0';
      strncat(pair, hash + i, 2);
      c = (int) strtol(pair, NULL, 16);

      password[index++] = (char) (c ^ xlat[(seed++) % XLAT_SIZE]);
    }

    free(pair);
  }
}
