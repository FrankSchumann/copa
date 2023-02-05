# copa
Controller Platform main application

## Conan

### Install
Install conan packages and create files for building.
Must be done first.

Creates build files (Makefile) in folder build.

#### Release
```bash
copa $ conan install . --output-folder=build
```
#### Debug
```bash
copa $ conan install . --output-folder=build -s build_type=Debug
```
### Build
Build application copa

#### Release
```bash
copa $ cd build
copa/build $ cmake .. --preset release 
copa/build $ make -j4 
```
#### Release
```bash
copa $ cd build
copa/build $ cmake .. --preset debug
copa/build $ make -j4 
```

### Run
run application copa

```bash
copa/build $ cd ..
copa $ ./build/copa 
```

## Clean
Clean directory from all files which are builded and created.

```bash
copa $ git clean -fxd 
```