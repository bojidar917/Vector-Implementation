#include <iostream>
#include "Vector.h"
#include <cstring>

bool compare( const char* cmd, const char* value)
{
    for (int i = 0; i < 2; i++)
    {
        if(cmd[i] != value[i])
            return false;
    }

    return true;
}

int main()
{
    // Vector vec(5);
    // vec.pushBack(19);
    // vec.pushBack(1);
    // vec.pushBack(2);
    // vec.pushBack(3);
    // vec.pushBack(4);
    // vec.pushBack(5);
    // vec.pushBack(6);
    // vec.pushBack(7);
    // vec.pushBack(8);
    // vec.pushBack(9);
    // std::cout << "Capacity =>" << vec.capacity() << std::endl;
    // std::cout << "Size =>" << vec.size() << std::endl;
    // vec.see();

    // vec.erase(3);
    // std::cout << "Capacity =>" << vec.capacity() << std::endl;
    // std::cout << "Size =>" << vec.size() << std::endl;
    // vec.see();

    // vec.reserve(100);
    // vec.pushBack(12);
    // vec.pushBack(13);
    // vec.pushBack(14);
    // vec.pushBack(15);
    // vec.pushBack(16);
    // vec.pushBack(17);
    // vec.pushBack(18);
    // vec.pushBack(19);
    // std::cout << "Capacity =>" << vec.capacity() << std::endl;
    // std::cout << "Size =>" << vec.size() << std::endl;
    // vec.see();

    // vec.capacity();

   Vector vec(5);
    char cmd[4]; // Increase the size to accommodate commands like "fnd"
    int param;

    std::cin >> cmd;

    while (!compare(cmd, "end")) 
    {
        if(compare(cmd, "add")) 
        {
            std::cin >> param;
            vec.pushBack(param);
        } 
        else if(compare(cmd, "see")) 
        {
            vec.see();
        } 
        else if(compare(cmd, "del")) 
        {
            std::cin >> param;
            vec.erase(param);
        } 
        else if(compare(cmd, "get")) 
        {
            std::cin >> param;
            std::cout << "Element at index " << param << ": " << vec.at(param) << std::endl;
        } 
        else if(compare(cmd, "fnd")) 
        {
            std::cin >> param;
            int index = vec.find(param);
            if( index != -1)
                std::cout << "Element is at index: " << index << std::endl;
            else
                std::cout << "Element doesn't exist!" << std::endl;
        } 
        else if(compare(cmd, "get"))
        {
            std::cin >> param;
            int element = vec.get(param);
            if( element != -1)
                std::cout << "Element is at index: " << element << std::endl;
            else if(element == -2)
                std::cout << "Provided index is out of range!" << std::endl;
            else
                std::cout << "The element does not exist!" << std::endl;
        }
        else 
        {
            std::cout << cmd << " is invalid " << std::endl;
        }

        std::cin >> cmd;
    }
}