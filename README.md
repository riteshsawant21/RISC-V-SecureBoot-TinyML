# RISC-V-SecureBoot-TinyML
This project simulates secure boot and encrypted storage on RISC-V to safely run TinyML models in low-power embedded systems. It showcases secure AI deployment (e.g., anomaly detection) using open-source cores, fully in simulation—ideal for research, prototyping, and industry testing.
# SecureTinyML-RISCV 🔐🤖
**Simulated Secure Boot + Encrypted TinyML Model Execution on RISC-V**

![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/build-simulation-blue)
![Platform](https://img.shields.io/badge/platform-RISC--V-lightgrey)

## 🧠 Overview

**SecureTinyML-RISCV** is a simulation-based project demonstrating secure boot and encrypted storage mechanisms on a RISC-V architecture. It enables loading and executing TinyML (lightweight AI) models in a trusted, low-power environment — perfect for edge-AI and embedded applications.

Security-critical applications (e.g., anomaly detection, predictive maintenance) can be securely deployed even in resource-constrained systems using a simulated secure bootloader, encrypted model storage, and OTA update logic.

⚡️ Fully simulation-based → no physical hardware required!
## 🎯 Key Features

✅ **Secure Boot Simulation**  
Signature-based firmware validation at boot using simulated bootloader logic.

✅ **AES-Encrypted Model Storage**  
TinyML models and configuration files are AES-encrypted and decrypted only at runtime in trusted memory.

✅ **RISC-V Execution Simulation**  
Fully simulated on RISC-V using QEMU or Spike with support for linker scripts and memory layout control.

✅ **Verified Model Inference**  
Only verified and decrypted models are allowed for execution; inference runs on dummy TinyML logic.

✅ **OTA Update Flow (Simulated)**  
Supports Over-the-Air (OTA) update simulation with secure signature checks and rollback protection.

✅ **TUI Output (Terminal UI)**  
Simulation results are printed in a clear, structured terminal format ideal for screenshots and academic documentation.

✅ **Hardware-Independent**  
Works in any Linux-based dev environment — no embedded board needed.

## 🏭 Industry Use Cases

This simulation aligns with real-world needs across industries where secure TinyML deployment is essential:

### 🔒 Secure Firmware and Edge AI  
Focus: Loading only signed firmware and AI models at the edge.  
Use Case: Enables trusted execution of anomaly detection, keyword spotting, or signal processing on microcontrollers or embedded DSPs.

### ⚙️ Secure AI Execution in Edge Accelerators  
Focus: AI model protection using encrypted boot chains.  
Use Case: Demonstrates how encrypted TinyML models can be deployed securely on hardware-accelerated platforms with isolated compute domains.

### 🌐 IoT & Remote Sensor Networks  
Focus: Low-power, autonomous edge systems with secure updates.  
Use Case: Firmware and ML models are verified and decrypted before execution, allowing secure OTA updates in field-deployed devices.

### 🚗 Automotive, Industrial, and Aerospace Systems  
Focus: Safety-critical embedded systems.  
Use Case: AI-based predictive maintenance or decision logic must pass cryptographic checks before activating, preventing unauthorized firmware use.

### 🧪 Research and Prototyping Environments  
Focus: Fast simulation without hardware dependency.  
Use Case: Helps researchers explore secure TinyML pipelines, validate bootloaders, or study cryptographic workflows at an architecture level.

---

This project provides a simulation framework for designing secure, AI-enabled embedded systems suited for both research and real-world applications.

## 🧰 Tech Stack

This project brings together multiple technologies from embedded systems, AI, and security domains. The stack is selected to ensure a balance of simulation accessibility, real-world relevance, and modular extensibility.

### 🖥️ Processor Simulation & ISA
- **RISC-V 32-bit Core (RV32IM)** – Open-source instruction set with simulation support for embedded devices.
- **QEMU (or Renode)** – Emulates RISC-V hardware platforms for secure boot simulation and firmware testing.
- **OpenOCD (Optional)** – For debugging bootloader behavior in virtual environments.

### 🔐 Security Layer
- **SHA-256** – Used for firmware hashing and signature verification.
- **RSA / ECC (Simulated)** – Validates digital signatures during the secure boot phase.
- **AES-128/256** – Encrypts TinyML models and logs before storage or OTA transfer.

### 🤖 TinyML & AI Model Handling
- **TensorFlow Lite for Microcontrollers (TFLM)** – For model inference in embedded environments.
- **uTensor / CMSIS-NN** – Lightweight ML libraries for bare-metal platforms.
- **Dummy Inference Pipeline** – Simulates secure ML model loading, decryption, and execution flow.

### 📁 File & Storage System
- **Virtual Flash / SD Card File System** – Simulated encrypted storage using mounted files.
- **Bootloader Image Layout** – Structured binary with secure headers and model containers.

### 🧪 Development Environment
- **GCC for RISC-V / Clang** – Toolchain for compiling bootloaders and firmware.
- **Make / CMake** – Build system to orchestrate secure boot, decryption, and inference modules.
- **Python / Bash Scripts** – Automate signing, encryption, and deployment of secure firmware images.

---

Each component in the tech stack is modular and replaceable, making this simulation highly adaptable for both hardware prototyping and system security education.

## 🔁 Workflow / System Design

This project emulates a secure boot and encrypted storage pipeline tailored for embedded TinyML deployments. It follows a step-by-step secure boot and execution model, from power-on to AI inference.

### 🔄 Step-by-Step Workflow

1. **🔌 Power-On Reset (POR)**
   - Simulated device resets and starts executing from a fixed memory address (bootloader entry).

2. **🧱 Bootloader Stage (Secure Boot Begins)**
   - Reads metadata from firmware header (e.g., version, checksum, digital signature).
   - Performs SHA-256 hash on firmware binary and verifies signature using RSA/ECC.
   - Checks integrity of encrypted TinyML model package.

3. **🔓 Decryption of Secure Storage**
   - Encrypted model file stored in virtual flash is decrypted using AES-128/256.
   - Model is stored temporarily in RAM for inference.

4. **🧠 TinyML Model Inference (Simulated)**
   - Loads precompiled TensorFlow Lite Micro model.
   - Executes inference on dummy sensor data to simulate a real-world application (e.g., anomaly detection).

5. **🧾 Logging & Results**
   - Logs results to an encrypted file in the virtual storage.
   - Optionally reboots or awaits further OTA updates.

6. **📤 (Optional) OTA Update Simulation**
   - Signed and encrypted firmware updates are pushed into the virtual environment.
   - Bootloader validates and replaces previous firmware only if the update passes verification.

---

### 📌 Design Principles

- **Zero Trust at Boot**: Nothing executes unless verified and decrypted.
- **Hardware-Agnostic Design**: Fully simulated—no physical hardware required.
- **Modular Simulation Blocks**: Security, storage, and AI logic separated for clarity and reusability.
- **Reproducibility**: Every build is deterministic and traceable.

---

This design mimics real-world secure embedded platforms and provides a trusted simulation environment for experimenting with secure ML workflows.

## 💾 File Structure & Folder Layout

This repository is organized to simulate a secure embedded pipeline that separates concerns between secure boot, encrypted storage, and TinyML inference — while maintaining a modular and extensible structure.

```bash
SecureTinyML-RISCV/
├── bootloader/
│   ├── main.c                  # Simulated secure boot logic (verification, hash, signature)
│   ├── crypto.c                # AES/RSA implementations (simulated)
│   └── boot_config.h           # Metadata structure for firmware headers
│
├── firmware/
│   ├── firmware.bin            # Signed & encrypted firmware binary (dummy file)
│   ├── model.tflite.enc        # Encrypted TinyML model (AES encrypted)
│   └── manifest.json           # Metadata: version, hash, signature, model info
│
├── inference_engine/
│   ├── model_runner.c          # Loads and runs decrypted TinyML model
│   ├── dummy_sensor_data.csv   # Sample data to simulate inference input
│   └── inference_results.log   # Securely logged output of model
│
├── ota_simulation/
│   ├── update_firmware.bin     # Simulated OTA firmware update
│   └── ota_updater.py          # Pushes update, validates version/signature
│
├── simulation_env/
│   ├── virtual_flash.py        # Simulates flash memory for storage
│   ├── key_store/              # Contains public keys, certs, AES keys
│   └── boot_sequence.py        # Emulates entire power-on to inference cycle
│
├── docs/
│   ├── architecture.md         # High-level system architecture
│   └── threat_model.md         # Description of threat mitigation strategies
│
├── LICENSE
├── README.md
└── .gitignore

🧪 Setup & Run Instructions
Follow these steps to set up and simulate secure boot and encrypted TinyML inference using this repository.

1️⃣ Prerequisites
Ensure the following tools and packages are available on your system:

Python 3.8+

pycryptodome for encryption simulation

numpy, pandas (for TinyML inference simulation)

Basic C compiler (e.g., gcc) for bootloader logic (optional for full simulation)

Git CLI or GitHub Desktop

To install dependencies:

bash
Copy
Edit
pip install pycryptodome numpy pandas
2️⃣ Clone the Repository
bash
Copy
Edit
git clone https://github.com/your-username/SecureTinyML-RISCV.git
cd SecureTinyML-RISCV
3️⃣ Simulate the Boot Sequence
This step mimics the secure boot validation of firmware and model:

bash
Copy
Edit
python simulation_env/boot_sequence.py
📌 Output:

Verifies digital signatures

Decrypts model and firmware

Logs validation results

4️⃣ Run the Encrypted TinyML Inference
Once booted securely, simulate running an encrypted model:

bash
Copy
Edit
python inference_engine/model_runner.py
📌 Output:

Decrypted model runs inference on dummy sensor data

Outputs are logged in inference_results.log

5️⃣ Simulate OTA Firmware/Model Update
Push an OTA update and verify secure acceptance:

bash
Copy
Edit
python ota_simulation/ota_updater.py
📌 Output:

Validates manifest signature and version

Accepts or rejects firmware based on security checks

📂 Example Logs
logs/boot_status.log: Bootloader validation events

logs/inference_results.log: Prediction outcomes

logs/ota_update.log: Update process trace

RESULTS:- 
### 1️⃣ Stage: Bootloader Verification

![Bootloader Verification](output_screnshots/bootloader_stage_verifying.PNG)


📄 License
This project is licensed under the MIT License — a permissive open-source license that allows reuse, modification, distribution, and private use, with proper attribution.
MIT License

Copyright (c) 2025 Ritesh Sawant

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

