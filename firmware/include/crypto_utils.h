// firmware/include/crypto_utils.h

#ifndef CRYPTO_UTILS_H
#define CRYPTO_UTILS_H

#include <stdint.h>

#define MODEL_KEY_SIZE 32

// Simulated AES decryption
void aes_decrypt(const uint8_t *encrypted_model, uint8_t *decrypted_model, const uint8_t *key);

// Simulated hash verification (SHA-256)
int verify_model_hash(const uint8_t *model_data, uint32_t length, const uint8_t *expected_hash);

// Secure key loading
void load_secure_key(uint8_t *key_out);

#endif
