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
leaks --atExit -- ./flappy_bird
```

## Non-OS Sepecific Commands

### Clean up build files

```bash
make clean
```

### Build

```bash
make all
```

### Run

```bash
make run
```
