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
leaks --atExit -- ./build/flappy_bird
```

## CMake Commands

### Clean up build files

```bash
sh clean.sh
```

### Build

```bash
sh make.sh
```

### Run

```bash
sh run.sh
```
