#include <iostream>
using namespace std;
#include "say_func.h"
#include "submodule/subfun.h"
int main(int argc, char const *argv[])
{
    std::cout<<"hello word"<<endl;
    sayHelloFunc("hello from function");
    sayHelloSubFunc("hello from sub function");
    return 0;
}
