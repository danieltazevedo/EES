#!/bin/bash

# Get the arguments from the command line and assign them to variables INPUTSIZE and NTIMES
INPUTSIZE=$1
NTIMES=$2

# Check if INPUTSIZE is 1, 2 or 3 and if NTIMES is greater or equal than 1
if [[ $INPUTSIZE -eq 1 || $INPUTSIZE -eq 2 || $INPUTSIZE -eq 3 ]] && [[ $NTIMES -ge 1 ]]; then
    # Instalação das dependências
    # Detect the Linux distribution
    if [ -f /etc/lsb-release ]; then
        # Ubuntu or Debian-based system
        sudo apt-get update -y
        sudo apt-get install lm-sensors -y
        sudo apt-get install make -y
        sudo apt-get install python -y
        sudo apt-get install build-essential python3-pip -y
        sudo apt-get install openjdk-11-jdk-headless -y
        sudo apt-get install nodejs -y
        sudo apt-get install npm -y
        sudo apt-get install php -y
        sudo apt-get update -y
    elif [ -f /etc/fedora-release ]; then
        # Fedora-based system
        sudo dnf check-update -y
        sudo dnf install lm_sensors -y
        sudo dnf install make -y
        sudo dnf install python -y
        sudo dnf install @development-tools python3-pip -y
        sudo dnf install java-11-openjdk-headless -y
        sudo dnf install nodejs -y
        sudo dnf install npm -y
        sudo dnf install php -y
        sudo dnf check-update -y
    elif [ -f /etc/redhat-release ]; then
        # Red Hat-based system
        sudo yum check-update -y
        sudo yum install lm_sensors -y
        sudo yum install make -y
        sudo yum install python -y
        sudo yum groupinstall 'Development Tools' -y
        sudo yum install python3-pip -y
        sudo yum install java-11-openjdk-headless -y
        sudo yum install nodejs -y
        sudo yum install npm -y
        sudo yum install php -y
        sudo yum check-update -y
    elif [ -f /etc/SuSE-release ]; then
        # SUSE-based system
        sudo zypper refresh
        sudo zypper install lm_sensors
        sudo zypper install make
        sudo zypper install python
        sudo zypper install -t pattern devel_basis
        sudo zypper install python3-pip
        sudo zypper install java-11-openjdk-headless
        sudo zypper install nodejs
        sudo zypper install npm
        sudo zypper install php
        sudo zypper refresh
    elif [ -f /etc/slackware-version ]; then
        # Slackware-based system
        sudo slackpkg update
        sudo slackpkg install lm_sensors
        sudo slackpkg install make
        sudo slackpkg install python
        sudo slackpkg install-new build-essential python3-pip
        sudo slackpkg install openjdk-11-jdk-headless
        sudo slackpkg install nodejs
        sudo slackpkg install npm
        sudo slackpkg install php
        sudo slackpkg update
    elif [ -f /etc/arch-release ]; then
        # Arch Linux-based system
        sudo pacman -Sy
        sudo pacman -Syu lm_sensors
        sudo pacman -Syu make
        sudo pacman -Syu python
        sudo pacman -Syu base-devel python-pip
        sudo pacman -Syu jdk11-openjdk
        sudo pacman -Syu nodejs
        sudo pacman -Syu npm
        sudo pacman -Syu php
        sudo pacman -Sy
    elif [ -f /etc/gentoo-release ]; then
        # Gentoo Linux-based system
        sudo emerge --sync
        sudo emerge -av lm_sensors
        sudo emerge -av make
        sudo emerge -av python
        sudo emerge -av build-essential python3-pip
        sudo emerge -av openjdk11
        sudo emerge -av nodejs
        sudo emerge -av npm
        sudo emerge -av php
        sudo emerge --sync
    else
        echo "Unsupported Linux distribution"
        exit 1
    fi
    # Instalação do pandas
    pip install pandas
    # Clone do repositório
    cd RAPL
    # Compilação do RAPL
    make
    # Compilação do código-fonte
    cd ../src
    make
    # Execução do benchmark
    make INPUTSIZE=$INPUTSIZE NTIMES=$NTIMES measure
    # Volta para o diretório raiz
    cd ..
    # Execução do arquivo finalfile.py
    python3 finalfile.py
else
    echo "INPUTSIZE is not 1, 2, or 3 and/or NTIMES is not greater or equal than 1"
    echo "sudo ./script.sh INPUTSIZE NTIMES"
    echo -e "INPUTSIZE:\n\t1 = array of 100 elements\n\t2 = array of 50 elements\n\t3 = array of 10 elements"
    echo "NTIMES: number of times to run the benchmark"
    echo -e "Example:\n\tsudo ./script.sh 1 5"
    exit 1
fi