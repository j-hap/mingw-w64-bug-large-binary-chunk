# mingw-w64-bug-large-binary-chunk
Small example to reproduce a bug in MinGW-W64's standard lib

## Instructions

1.  Clone the repo and enter directory  
    ```
    git clone https://github.com/j-hap/mingw-w64-bug-large-binary-chunk.git
    cd mingw-w64-bug-large-binary-chunk
    ```
2.  create a file that is at least `INT32_MAX + 1 = 2147483648` Bytes in size  
    Windows:
    ```
    fsutil file createnew test.dat 2147483649
    ```
    Linux:
    ```
    fallocate -l 2147483649 test.dat
    ```
3.  Setup up environment (depends on your compiler, OS, shell, etc.)
4.  Build
    ```
    cmake -S . -B ./out
    cmake --build ./out
    ```
5.  Run (executable may be in a subdirectory, depending on the build tool)
    ```
    ./out/mingw-w64-bug-large-binary-chunk*
    ```