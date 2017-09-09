
#include "kc_md5.h"
#include <fstream>


using std::cout; using std::endl;

int main() {
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::MD5 Test Suite";
    std::cout << std::endl << "================================================================================";

    int fail_ct = 0;
    int pass_ct = 0;
    {
        std::cout << std::endl << "Hashing";
        {
            std::cout << std::endl << "    std::string ....................................................... ";
            kc::md5 md5;
            if (md5.hash("apples") == "daeccf0ad3c1fc8c8015205c332f5b42") {
                std::cout << "Pass";
                ++pass_ct;
            } else {
                std::cout << "FAIL";
                ++fail_ct;
            }
        }
    }

    {
        std::cout << std::endl << "    std::ifstream ..................................................... ";
        std::ofstream outfile;
        outfile.open("kc_md5_temp.dat");
        outfile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
                "\n"
                "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
                "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
                "culpa qui officia deserunt mollit anim id est laborum.";
        outfile.close();
        std::ifstream infile;
        infile.open("kc_md5_temp.dat");
        kc::md5 md5;
        if (md5.hash(infile) == "a5e90c16beb53bb93468496eaf2e0ac4") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
        infile.close();
    }


    std::remove("kc_md5_temp.dat");

    std::cout << std::endl << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::MD5 Summary";
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "Status: " << ((fail_ct)?"FAIL":"Pass");
    std::cout << std::endl << "    Success Count: " << pass_ct;
    std::cout << std::endl << "    Failure Count: " << fail_ct;

    return 0;
}