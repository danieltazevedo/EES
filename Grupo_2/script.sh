#!/bin/bash

# Instalação das dependências
sudo apt-get update
sudo apt-get install build-essential python3-pip -y

# Clone do repositório
cd rapl

# Compilação do RAPL
make

# Compilação do código-fonte
cd ../src
make

# Execução do benchmark
make measure

# Volta para o diretório raiz
cd ..

# Instalação do pandas
pip install pandas

# Execução do arquivo finalfile.py
python3 finalfile.py

