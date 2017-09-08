
#include <iostream>
#include "kc_md5.h"

int main(int argc, char *argv[])
{
    kc::md5 mymd5("grape");
    std::cout << "md5 of 'grape': " << mymd5.hexdigest() << std::endl;

    mymd5.update("apple");
    std::cout << "\nmd5 of 'apple': " << mymd5.hexdigest() << std::endl;

    kc::md5 mymd5_2("apple");
    std::cout << "\nmd5_2 of 'apple': " << mymd5_2.hexdigest() << std::endl;
    return 0;
}