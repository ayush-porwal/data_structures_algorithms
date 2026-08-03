FROM ubuntu:26.04

ENV container=container \
    LANG=C.UTF-8 \
    LC_ALL=C.UTF-8
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    dbus \
    systemd \
    systemd-sysv \
    openssh-server \
    sudo \
    build-essential \
    gdb \
    cmake \
    ninja-build \
    python3 \
    python3-pip \
    git \
    curl \
    wget \
    ca-certificates \
    tar \
    iproute2 && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/dbus && \
    : > /etc/machine-id && \
    : > /var/lib/dbus/machine-id

RUN systemctl set-default multi-user.target && \
    systemctl enable ssh.service && \
    systemctl mask \
        dev-hugepages.mount \
        sys-fs-fuse-connections.mount \
        systemd-update-utmp.service \
        systemd-tmpfiles-setup.service \
        console-getty.service

RUN install -d -m 0755 \
        /etc/ssh/authorized_keys \
        /etc/ssh/sshd_config.d && \
    printf '%s\n' \
        'AuthorizedKeysFile /etc/ssh/authorized_keys/%u' \
        'PasswordAuthentication no' \
        'PermitRootLogin no' \
        > /etc/ssh/sshd_config.d/99-container-machine.conf

RUN sed -i \
    's/^AcceptEnv LANG LC_\*$/#AcceptEnv LANG LC_*/' \
    /etc/ssh/sshd_config