FROM ubuntu:18.04
LABEL Description="Build environment for C lang"

ENV HOME /root

SHELL ["/bin/bash", "-c"]

# Installs C and required dependencies to build a project.
RUN apt-get update && apt-get -y --no-install-recommends install \
    build-essential \
    clang \
    cmake \
    gdb \
    wget