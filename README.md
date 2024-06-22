# Exception
Basic implementation of Exception class. You can create your own exception classes by inheriting from BaseException. We already derived two classes named SocketException and SecureSocketException that please do not hesitate to include other exception classes such as Win32Exception. 

# Features
- Cross platform
- C++11 and later are supported.

# Prerequisites
- C++11 or later supported compiler
    - msvc
    - gcc
    - clang
- CMake (Optional)

# Cloning the library
You can clone the library using git. Just run the command as shown below:

```
  > git clone https://github.com/kadirlua/Exception.git
```

# Building the library
You can build the library using vcpkg or your own environment. You can use Visual Studio, VSCode or CLion IDEs for building.

## Compile the library using cmake
```
  > mkdir build
  > cmake -B build -S .
  > cmake --build build
```

Or with make option
```
  > mkdir build
  > cd build
  > cmake ..
  > make
```

If you want to build as static library (default is shared), you can pass the argument as shown below to cmake for configuration:
```
  > cmake -B build -S . -DBUILD_SHARED_LIBS=OFF
```


# Use the library
You can use the library into your project. It's easy to integrate into your project using cmake configuration. Insert the necessary codes into your project as shown below:

CMakeLists.txt:
``` cmake

cmake_minimum_required(VERSION 3.22.1)

project(TestProject VERSION 1.0 LANGUAGES CXX)

find_package(Exception REQUIRED)    # It's required to find the library

add_executable(TestProject main.cpp)

target_link_libraries(TestProject PRIVATE Exception::BaseException)    # link the library if It's found
```

main.cpp:

``` cpp
#include <iostream>
#include <BaseException.h>

int main()
{
    try {
        throw sdk::general::BaseException("Some exception here\n");
    } catch(const sdk::general::BaseException& ex) {
        std::cout << ex.getErrorMsg() << "\n";
    }
    return 0;
}
```


# Basic example of usage (BaseException class):

```cpp

void somefuncThrowsException() {
  throw BaseException("Test error message");
}

int main(){
  try {
    somefuncThrowsException();
  } catch (const BaseException& ex) {
    std::cout << "An error occurred: " << ex.getErrorMsg() << "\n";
  }
  return 0;
}

```

# Conclusion
If you have any opinions or questions, please do not hesitate to ask me :)
