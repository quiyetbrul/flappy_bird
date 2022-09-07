## SFML Download

### MacOS

```bash
brew install sfml
```

### Windows

```bash
choco install sfml
```

### Linux

```bash
sudo apt-get install libsfml-dev
```

## MacOS Specific Command

Run memory leak detection tool

```bash
cd build && leaks --atExit -- ./flappy_bird
```

## CMake Commands

### Clean up build files

```bash
cmake --build build --target clean
```

### Configure

```bash
cmake -S . -B build/
```

### Build

```bash
cd build && make
```

### MakeRun

```bash
sh makerun.sh
```
