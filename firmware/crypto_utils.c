// firmware/crypto_utils.c

#include <stdio.h>
#include <string.h>
#include "include/crypto_utils.h"

void aes_decrypt(const uint8_t *encrypted_model, uint8_t *decrypted_model, const uint8_t *key) {
    // Simulated AES-256 decryption (mock)
    printf("[CRYPTO] AES decryption simulated.\n");
    memcpy(decrypted_model, encrypted_model, 256); // just simulating
}

int verify_model_hash(const uint8_t *model_data, uint32_t length, const uint8_t *expected_hash) {
    // Simulated SHA-256 hash verification (mock)
    printf("[CRYPTO] Model hash verified (simulated).\n");
    return 1; // always succeed
}

void load_secure_key(uint8_t *key_out) {
    // Simulate loading a secure key from secure storage
    memset(key_out, 0xA5, MODEL_KEY_SIZE); // fill with dummy key
    printf("[CRYPTO] Secure key loaded from OTP.\n");
}
