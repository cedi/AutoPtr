//
//  main.cpp
//  AutoPtr
//
//  Created by cedric on 09.10.13.
//  Copyright (c) 2013 cedric. All rights reserved.
//

#include <iostream>
#include "AutoPtr.h"

class HelloWorld
{
public:
    void Out() { std::cout<< "Hello World\n"; }
    void Out2() { std::cout<< "Hallo Hase\n"; }
};

int main(int argc, const char * argv[])
{
    AutoPtr<HelloWorld> pMyPtr;

    pMyPtr.Attach(new HelloWorld());
    
    pMyPtr->Out();
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

