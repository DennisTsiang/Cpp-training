# Build using [Scons][1]

[1]: http://scons.org/ "Scons"


## To build target image
At the project root do:
```
$ scons
```

This will generate a file ```build/debug/C++11-501.elf```


## To run the image on Qemu

```
$ ./qemu-run build/debug/C++11-501.elf
```

## To clean the build
```
$ scons -c
```

## To build with the RTOS enabled
At the project root do:
```
$ scons --rtos
```

