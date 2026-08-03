# Data Structures and Algorithms

This repository contains implementations of various data structures and algorithms.

## Why AI?

As of March 2025, advanced Language Learning Models (LLMs) have achieved a Codeforces rating of approximately 2000, demonstrating their significant capabilities in problem-solving. LLMs serve as valuable learning companions by:

- Exploring alternative solution approaches
- Offering patient responses to fundamental questions
- Providing detailed explanations for complex problems
- Enhancing the overall learning experience through interactive problem-solving

Their ability to analyze and explain different approaches makes them excellent tools for mastering Data Structures and Algorithms.

## Linux development environment with Apple `container`

This repository includes a `Dockerfile` for a persistent Ubuntu container machine with GCC, GDB, CMake, Ninja, Git, Python, and an SSH server. VS Code runs on macOS, while Remote SSH runs the terminal, C++ IntelliSense, compiler, and debugger inside Linux.

The instructions below assume Apple's `container` CLI and VS Code are already installed on an Apple silicon Mac.

### Names used by this guide

- Image: `local/ubuntu-cp:26.04`
- Container machine: `dsa`
- macOS SSH alias: `apple-container-dsa`
- Resources: 4 virtual CPUs and 4 GB RAM
- Home sharing: read/write, so Linux sees the macOS repository, `.gitconfig`, and `.ssh` files

The image name, machine name, and SSH alias are independent. Change all later references if you choose different names.

### 1. Build the image

From the repository root:

```bash
cd /Users/ayush.porwal/Documents/workspace/data_structures_algorithms

container system start

container build \
  --cpus 4 \
  --memory 2G \
  --tag local/ubuntu-cp:26.04 \
  .

container builder stop
```

The build CPU and memory settings apply only to the temporary image builder. Stopping the builder releases its resources without deleting the image.

Confirm that the image exists:

```bash
container image list
```

### 2. Create the persistent machine

```bash
container machine create \
  --name dsa \
  --cpus 4 \
  --memory 4G \
  --home-mount rw \
  local/ubuntu-cp:26.04
```

This intentionally omits `--set-default`. If this is the only machine, Apple `container` may still mark it as the current default automatically. Use `-n dsa` with machine commands so the target is always explicit and does not depend on default selection.

`--home-mount rw` shares the macOS home directory with Linux using read/write access. Consequently, Linux can read and modify the repository and other files under `/Users/ayush.porwal`, including `.ssh`.

Verify the machine and toolchain:

```bash
container machine list
container machine run -n dsa -- whoami
container machine run -n dsa -- g++ --version
container machine run -n dsa -- gdb --version
```

Apple provisions a Linux user matching the current macOS username during the machine's first boot.

### 3. Authorize SSH access

The macOS private key remains at `~/.ssh/id_ed25519`. Its public half is installed as a key authorized to enter the Linux machine.

Confirm that the public key exists:

```bash
ls -l ~/.ssh/id_ed25519 ~/.ssh/id_ed25519.pub
```

If this key pair does not exist, create it before continuing:

```bash
ssh-keygen -t ed25519 -f ~/.ssh/id_ed25519
```

Install the public key inside the machine:

```bash
DEV_USER="$(id -un)"

container machine run -n dsa --root -- \
  install -d -m 0755 /etc/ssh/authorized_keys

container machine run -n dsa --root -- \
  install -o "$DEV_USER" -m 0600 \
  "$HOME/.ssh/id_ed25519.pub" \
  "/etc/ssh/authorized_keys/$DEV_USER"
```

The owner is important. A root-owned file with mode `0600` cannot be read by the authenticating user and produces `Permission denied (publickey)`.

Validate the server configuration and start SSH:

```bash
container machine run -n dsa --root -- /usr/sbin/sshd -t
container machine run -n dsa --root -- systemctl restart ssh
container machine run -n dsa --root -- systemctl is-active ssh
```

The final command should print `active`.

Confirm that SSH is reading the expected authorization path:

```bash
DEV_USER="$(id -un)"

container machine run -n dsa --root -- \
  /usr/sbin/sshd -T \
  -C "user=$DEV_USER,host=localhost,addr=127.0.0.1" | \
  grep '^authorizedkeysfile'
```

Expected output:

```text
authorizedkeysfile /etc/ssh/authorized_keys/%u
```

Changing `authorized_keys` does not require restarting SSH; it is read during every login. Restarting above ensures that any server configuration changes are loaded.

### 4. Enable `sudo` for the development user

Apple's automatically provisioned user does not have a usable password by default. For this local development machine, enable passwordless `sudo`:

```bash
DEV_USER="$(id -un)"

container machine run -n dsa --root -- sh -c \
  "printf '%s\n' '$DEV_USER ALL=(ALL) NOPASSWD:ALL' > '/etc/sudoers.d/$DEV_USER' && chmod 0440 '/etc/sudoers.d/$DEV_USER'"

container machine run -n dsa -- sudo -n true
```

No output from the final command means it succeeded. Administrative commands can alternatively be executed from macOS with `container machine run -n dsa --root -- <command>`.

### 5. Configure the macOS SSH client

Find the machine's current address:

```bash
container machine list
```

Copy the IP from the `dsa` row, then edit the macOS SSH configuration:

```bash
mkdir -p ~/.ssh
chmod 700 ~/.ssh
touch ~/.ssh/config
chmod 600 ~/.ssh/config
nano ~/.ssh/config
```

Add this block, replacing `MACHINE_IP` with the displayed address:

```sshconfig
Host apple-container-dsa
    HostName MACHINE_IP
    User ayush.porwal
    IdentityFile ~/.ssh/id_ed25519
    IdentitiesOnly yes
```

`Host` is only a friendly macOS SSH nickname. `HostName` is the actual Linux machine address, and `User` is the Linux username created by Apple `container`.

Test the connection:

```bash
ssh apple-container-dsa
```

Accept the machine fingerprint when prompted. After confirming that the shell is Linux, return to macOS with `exit`.

The machine IP may change after stopping and starting it. If SSH reports `No route to host`, run `container machine list` again and update `HostName` in `~/.ssh/config`.

### 6. Verify Git access from Linux

Because the macOS home directory is shared read/write, Linux can use the existing macOS Git configuration and SSH key:

```bash
container machine run -n dsa -- git config --global --get user.name
container machine run -n dsa -- git config --global --get user.email
container machine run -it -n dsa -- ssh -T git@github.com
```

Git `user.name` and `user.email` control commit authorship. The SSH key authenticates operations such as `git pull` and `git push` when the Git remote uses SSH.

### 7. Connect with VS Code Remote SSH

Install the macOS Remote SSH extension:

```bash
code --install-extension ms-vscode-remote.remote-ssh
```

Install the C++ extension into the Linux SSH environment:

```bash
code --remote ssh-remote+apple-container-dsa \
  --install-extension ms-vscode.cpptools
```

Open this repository through the Linux environment:

```bash
code --remote ssh-remote+apple-container-dsa \
  /Users/ayush.porwal/Documents/workspace/data_structures_algorithms
```

If the `code` command is unavailable, open the VS Code Command Palette and run `Shell Command: Install 'code' command in PATH`.

In the VS Code terminal, verify that commands execute in Linux:

```bash
uname -s
which g++
which gdb
```

Expected paths include `/usr/bin/g++` and `/usr/bin/gdb`. Open a C++ file containing `main()`, set a breakpoint, and press `F5` to build and debug the active file. CMake is available but is not required for the repository's independent competitive-programming source files.

### 8. Daily machine commands

```bash
# List machines and their current IP addresses.
container machine list

# Start dsa without opening an interactive shell.
container machine run -n dsa -- true

# Open an interactive Linux shell.
container machine run -n dsa

# Execute one Linux command.
container machine run -n dsa -- uname -a

# Open a root shell.
container machine run -n dsa --root

# Stop the machine cleanly.
container machine stop dsa
```

To change resources, stop and restart after updating them:

```bash
container machine set -n dsa cpus=4 memory=4G
container machine stop dsa
container machine run -n dsa -- true
```

### Troubleshooting

Show recent SSH service logs:

```bash
container machine run -n dsa --root -- \
  journalctl -u ssh -n 50 --no-pager
```

Compare the local and installed public-key fingerprints:

```bash
DEV_USER="$(id -un)"

ssh-keygen -lf ~/.ssh/id_ed25519.pub

container machine run -n dsa --root -- \
  ssh-keygen -lf "/etc/ssh/authorized_keys/$DEV_USER"
```

The `SHA256` fingerprints must match.

Inspect the macOS settings applied to the SSH alias:

```bash
ssh -G apple-container-dsa | \
  grep -E '^(hostname|user|identityfile) '
```

If a recreated machine has a different SSH host key, remove the obsolete saved entry and connect again:

```bash
ssh-keygen -R MACHINE_IP
ssh apple-container-dsa
```
