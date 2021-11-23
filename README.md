# Exception
Basic implementation of Exception class. You can create your own exception classes by inheriting from BaseException. We already derived two classes named SocketException and SecureSocketException that please do not hesitate to include other exception classes such as Win32Exception(may be?). 

# Very basic example of usage Exception class:

```c++

void somefuncThrowsException(){
  throw BaseException("I am just throwing something that who will catch?");
}

int main(){
  try{
    somefuncThrowsException();
  }catch (const BaseException& ex){
    std::cout << "Caught it! : " << ex.getErrorMsg() << "\n";
  }
  return 0;
}

```
