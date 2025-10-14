#!/bin/bash

# =====================================
# MPI Worker Setup Script
# Run this on the WORKER machine
# =====================================

MPIUSER="mpiuser"
CLOUD_DIR="/home/$MPIUSER/cloud"
MANAGER_HOST="manager"   # Replace with your manager's Tailscale hostname or IP
MANAGER_SSH_KEY="/home/$MPIUSER/.ssh/id_rsa.pub"

# -----------------------------
# 1️⃣ Install OpenMPI and SSH
# -----------------------------
sudo apt update
sudo apt install -y openmpi-bin openmpi-common libopenmpi-dev ssh rsync

# -----------------------------
# 2️⃣ Create mpiuser if missing
# -----------------------------
if ! id -u $MPIUSER >/dev/null 2>&1; then
    sudo adduser --gecos "" $MPIUSER
fi

# -----------------------------
# 3️⃣ Create cloud directory
# -----------------------------
sudo -u $MPIUSER mkdir -p $CLOUD_DIR

# -----------------------------
# 4️⃣ Setup SSH keys for passwordless login from manager
# -----------------------------
sudo -u $MPIUSER mkdir -p /home/$MPIUSER/.ssh
sudo -u $MPIUSER chmod 700 /home/$MPIUSER/.ssh

# Make sure the manager's public key is appended
echo "Paste your manager's public SSH key here (or use ssh-copy-id from manager):"
read -r MANAGER_KEY
echo "$MANAGER_KEY" >> /home/$MPIUSER/.ssh/authorized_keys
sudo -u $MPIUSER chmod 600 /home/$MPIUSER/.ssh/authorized_keys

# -----------------------------
# 5️⃣ Test passwordless SSH to manager
# -----------------------------
echo "Testing passwordless SSH to manager..."
sudo -u $MPIUSER ssh -o StrictHostKeyChecking=no $MPIUSER@$MANAGER_HOST "hostname"

echo "Worker setup completed! Cloud directory: $CLOUD_DIR"
