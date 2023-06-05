# Sin/Cos approximation
A quick approximation of sin and cos

## Build
The real code is only in poor_sin.h, but if you want to try and compile it you can use cmake for that.
Try
```
mkdir build
cd build
cmake ..
make
```
If you want to compile a gui test and have raylib installed then add `-DRAYLIB=ON` to cmake<br>
and it should build it, you can then run the sinapprox binary
