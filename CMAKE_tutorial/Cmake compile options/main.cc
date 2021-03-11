#include<iostream>


#ifdef USE_STD //如果编译了USE_STD
#include"submodule/subfun.h"
#else // 如果没有编译
using namespace std;
#endif

int main(int argc, char const *argv[])
{
#if USE_STD //如果编译了USE_STD
sayHelloSubFunc("Hello from submodule");
std::cout<<"Hello from submodule"<<std::endl;
#else // 如果没有编译
cout<<"hello from std"<<endl;
#endif
    return 0;
}
