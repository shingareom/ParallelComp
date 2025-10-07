Perfect ⚡ Om — that’s exactly the right structure. Now here are 3 clean, ready-to-use README files for your setup:


⚡ Part 1 Folder – part1/README.md
(MPI Cluster Setup and Matrix Multiplication)
# Part 1 – MPI Cluster Environment Setup and Matrix Multiplication

This part demonstrates the setup of a **Multi-node MPI Cluster** using 4 systems connected through **LAN or Wi-Fi**, and the execution of a **parallel matrix multiplication program**.

---

## 🧩 Steps to Setup

### 1️⃣ Install OpenMPI
Run this command on all systems:
```bash
sudo apt update
sudo apt install openmpi-bin openmpi-common libopenmpi-dev
2️⃣ Enable SSH Access
Generate SSH key and share with worker nodes:
ssh-keygen -t rsa
ssh-copy-id user@worker_ip
3️⃣ Create hosts File
On master node:
192.168.1.10 slots=1
192.168.1.11 slots=1
192.168.1.12 slots=1
192.168.1.13 slots=1
4️⃣ Test Cluster
mpirun -np 4 --hostfile hosts hostname
5️⃣ Run the Matrix Multiplication Code
Compile:
mpicc matrix_mpi.c -o matrix_mpi
Run:
mpirun -np 4 --hostfile hosts ./matrix_mpi

🧮 Code Description
	•	The master node initializes the matrices and distributes rows to all nodes.
	•	Each worker node multiplies its assigned rows.
	•	The master node gathers the partial results and displays the final matrix.

📷 Screenshots (Add Yours)
	•	SSH Setup
	•	Hostfile
	•	Cluster Output
	•	Final Matrix Output

🧠 Learnings
	•	Setting up an MPI Cluster environment
	•	Understanding distributed computation
	•	Hands-on with OpenMPI commands and SSH networking
---


Would you like me to also generate a **sample `vectorized_program.c`** (simple AVX vector addition or dot product) to include in your `part2` folder?  
That’ll make your repo complete and demo-ready.
.
