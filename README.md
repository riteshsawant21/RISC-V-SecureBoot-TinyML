
---

## 🚀 Key Components

### 🔧 Firmware Modules
- **bootloader.c**: Handles secure boot verification, signature validation, and integrity checks.
- **secure_model_load.c**: Responsible for decrypting and loading the TinyML model.
- **inference_engine.c**: Runs basic TinyML inference on embedded data.
- **crypto_utils.c / crypto_utils.h**: Contains AES/GCM encryption and hashing routines.
- **Makefile**: Compilation setup for simulation on a POSIX environment.

---

## 🔒 Secure Boot Process

This flow mimics how a secure embedded system might perform verification and initialization:

1. **Bootloader Verification**: Authenticates firmware using a secure signature mechanism.
2. **Decryption of TinyML Model**: Decrypts stored TinyML model using AES-256 encryption.
3. **Loading and Initialization**: Loads decrypted weights into the inference engine.
4. **Inference**: Performs a simple classification task using simulated TinyML logic.
5. **Secure Runtime Monitoring**: Monitors memory integrity and runtime signatures.

---

## 🧪 Simulation Output

### 1️⃣ Stage: Bootloader Verification  
![Stage 1](https://raw.githubusercontent.com/riteshsawant21/RISC-V-SecureBoot-TinyML/main/stage1.PNG)

### 2️⃣ Stage: Encrypted Model Loading  
![Stage 2](https://raw.githubusercontent.com/riteshsawant21/RISC-V-SecureBoot-TinyML/main/stage2.PNG)

### 3️⃣ Stage: Model Decryption  
![Stage 3](https://raw.githubusercontent.com/riteshsawant21/RISC-V-SecureBoot-TinyML/main/stage3.PNG)

### 4️⃣ Stage: Inference Execution  
![Stage 4](https://raw.githubusercontent.com/riteshsawant21/RISC-V-SecureBoot-TinyML/main/stage4.PNG)

### 5️⃣ Stage: Secure Monitoring  
![Stage 5](https://raw.githubusercontent.com/riteshsawant21/RISC-V-SecureBoot-TinyML/main/stage5.PNG)

---

## 📚 Technical Highlights

- 🛡️ **RSA-2048** based signature validation for bootloader.
- 🔐 **AES-256 GCM** for model encryption.
- 📦 **FlatBuffers** or simulated `.tflite` format loader.
- ⚙️ POSIX-compliant simulation for code portability.
- 🔬 Basic TinyML model logic mimicked via matrix ops.
- 🧪 Logging interface added to mimic secure debug channel.

---

## 💻 Requirements

- GCC / Clang compiler
- Make
- OpenSSL (for crypto simulation)
- Ubuntu WSL2 / Linux environment

---

## 📦 Build Instructions

```bash
cd firmware
make
./secure_boot_sim
