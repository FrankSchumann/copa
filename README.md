# copa
Controller Platform main application

## Conan

### Installation
Installation of Conan 2.0

```bash
$ pip install conan --pre
```

Deinstallation
```bash
$ pip deinstall conan
```

### Create
Build and upload package to Conan cache.

```bash
copa $ conan create .
```
### Install
Install conan packages and create files for building.
Must be done before Build

Creates build files (Makefile) in folder build.

#### Release
```bash
copa $ conan install . --output-folder=build
```
#### Debug
```bash
copa $ conan install . --output-folder=build -s build_type=Debug
```
## Build
Build application copa

### Release
```bash
copa $ cd build
copa/build $ cmake .. --preset release 
copa/build $ make -j4 
```
### Release
```bash
copa $ cd build
copa/build $ cmake .. --preset debug
copa/build $ make -j4 
```

## Run
run application copa

```bash
copa/build $ cd ..
copa $ ./build/copa
```

## Test
Build and execute GoogleTest.

```bash
copa/build/test $ conan install . --output-folder=build
```
```bash
copa/build/test $ cd build
copa/build/test $ cmake .. --preset=release
```
```bash
copa/build/test $ cmake --build .
```
```bash
copa/build/test $ ./copaTest
```


## Clean
Clean directory from all files which are builded and created.

```bash
copa $ git clean -fxd 
```