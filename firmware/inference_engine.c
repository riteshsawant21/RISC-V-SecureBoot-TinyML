// firmware/inference_engine.c

#include <stdio.h>
#include <stdint.h>

void run_inference(uint8_t *model) {
    printf("[INFERENCE] TinyML Inference Engine Initialized...\n");

    // Simulated input sensor data
    float input_data[3] = {22.5, 30.1, 15.9};
    printf("[INFERENCE] Input: {%.2f, %.2f, %.2f}\n", input_data[0], input_data[1], input_data[2]);

    // Fake model output
    float output = (input_data[0] + input_data[1] + input_data[2]) / 3;
    printf("[INFERENCE] Prediction (Anomaly Score): %.2f\n", output);

    if (output > 25.0) {
        printf("[INFERENCE] ALERT: Abnormal condition detected!\n");
    } else {
        printf("[INFERENCE] System functioning within normal parameters.\n");
    }
}
