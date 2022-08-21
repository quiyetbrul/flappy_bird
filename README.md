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

## CMake Commands

### Clean up build files

`if homebrew was used make sure to include the -L LDFLAGS in Makefile (e.g. -L"/opt/homebrew/lib")`

```bash
rm -rf build
```

### Build

```bash
sh make.sh
```

### Run

```bash
sh run.sh
```
