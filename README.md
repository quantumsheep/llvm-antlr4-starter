# LLVM + ANTLR4 Starter Project
Starter project for ANTLR4 and LLVM C++ project.

## Prerequisite
- LLVM **12**
- Java (for ANTLR4)
- git

### Install prerequisite libraries
#### Debian / Ubuntu
```bash
sudo apt-get update && \
sudo apt-get install -y --no-install-recommends \
    ca-certificates \
    lsb-release \
    wget \
    software-properties-common \
    gpg-agent \
    libedit-dev \
    uuid-dev \
    zlib1g-dev \
    openjdk-8-jre-headless \
    build-essential \
    pkg-config \
    cmake \
    git && \
wget https://apt.llvm.org/llvm.sh && \
chmod +x llvm.sh && \
sudo ./llvm.sh 12
```

## Functionalities
- Object Emitter
- JIT
- CLI

## CLI
The code of this repository comes with a pre-configured CLI for fast iteration.

```
Usage: compiler <file> [OPTIONS]

Options:
    -h, --help              Get usage and available options
    -c, --compile           Outputs to an object file. By default the program is using the JIT
    -o                      Filename used along with --compile option. Default is output.o
        --print-llvm        Print generated LLVM bytecode
```

## Development
To start using the project, first clone it:
```bash
git clone git@github.com:quantumsheep/llvm-antlr4-starter.git
```
For non-SSH users:
```bash
git clone https://github.com/quantumsheep/llvm-antlr4-starter.git
```

Grammar and visitors and located in `src/grammar`.

Some scripts are available to ease development:
- `compile.sh`: Compile the sources using CMake
- `compile-grammar.sh`: Generate structures from ANTL4 grammar files
- `docker.sh`: Launch a coding environment inside Docker with everything pre-installed
-  `run.sh`: Run the program (located at `build/compiler` once compiled)
