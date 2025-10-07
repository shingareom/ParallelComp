# Part 1 – MPI Cluster Environment Setup and Matrix Multiplication

This part demonstrates the setup of a **Multi-node MPI Cluster** using 4 systems connected through **LAN or Wi-Fi**, and the execution of a **parallel matrix multiplication program**.

---

## 🧩 Steps to Setup

1 Install OpenMPI
Run this command on all systems:

```bash
sudo apt update
sudo apt install openmpi-bin openmpi-common libopenmpi-dev
```
2 Enable SSH Access
Generate SSH key and share with worker nodes:

```bash
ssh-keygen -t rsa
ssh-copy-id user@worker_ip
```
3 Create hosts File
On master node:
```
192.168.1.10 slots=1
192.168.1.11 slots=1
192.168.1.12 slots=1
192.168.1.13 slots=1
```
4 Test Cluster

```bash
mpirun -np 4 --hostfile hosts hostname
```

5 Run the Matrix Multiplication Code

Compile:

```bash
mpicc matrix_mpi.c -o matrix_mpi
```

Run:
```bash
mpirun -np 4 --hostfile hosts ./matrix_mpi
```

## Code Description
- The master node initializes the matrices and distributes rows to all nodes.
- Each worker node multiplies its assigned rows.
- The master node gathers the partial results and displays the final matrix.
