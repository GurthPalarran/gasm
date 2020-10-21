# Gasm
An Assembly Interpreter.

## What is Gasm

Gasm is an assembly interpreter. It can allocate a section of memory as virtual memory to make sure your operation safety. CPU port support will come soon. 

## Download

To get the sources from git, click [here](https://github.com/GurthPalarran/gasm). To get a binary snapshot, see [here](https://github.com/GurthPalarran/gasm/releases/tag/1.0).

## Build

First of all please make sure you have installed the following package:

```
sudo apt update && sudo apt install libreadline-dev libyaml-cpp-dev
```

If you get source from git, please check out brunch "inasm".

```
git checkout inasm
```

If you want to use outside assembler, such as nasm, please make sure it is installed. And check out "outasm" brunch.

Then

```
mkdir build
cmake ..
make
```

To run gasm:

```
./gasm
```

## Contact me:

gurthpalarran@outlook.com
