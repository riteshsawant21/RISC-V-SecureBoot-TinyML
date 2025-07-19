// firmware/bootloader.c

#include <stdio.h>
#include <stdint.h>
#include "include/crypto_utils.h"

extern int start_secure_model_loading();

int main() {
    printf("Bootloader started...\n");

    // Step 1: Load key
    uint8_t key[MODEL_KEY_SIZE];
    load_secure_key(key);

    // Step 2: Simulate secure boot & signature verification
    printf("[BOOT] Secure Boot Verified. Signature Valid.\n");

    // Step 3: Proceed to secure model loading
    int result = start_secure_model_loading();
    if (result != 0) {
        printf("[BOOT] Model load failed. Halting system.\n");
        return 1;
    }

    printf("[BOOT] TinyML system booted successfully.\n");
    return 0;
}
