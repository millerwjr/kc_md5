
#include "kc_md5.h"
#include <fstream>

int main(int argc, char *argv[]) {
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::MD5 Test Suite";
    std::cout << std::endl << "================================================================================";

    int fail_ct = 0;
    int pass_ct = 0;
    std::cout << std::endl << "String Constructor";
    {
        std::cout << std::endl << "    MD5 Check .................................. ";
        kc::md5 mymd5_1_1("apples");
        if (mymd5_1_1.hexdigest() == "daeccf0ad3c1fc8c8015205c332f5b42") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        std::cout << std::endl << "    Update w/ String; MD5 Check ................ ";
        kc::md5 mymd5_1_2("apples");
        mymd5_1_2.update("oranges");
        if (mymd5_1_2.hexdigest() == "91b07b3169d8a7cb6de940142187c8df") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        std::cout << std::endl << "    Update w/ File; MD5 Check .................. ";
        kc::md5 mymd5_1_3("apples");
        std::ofstream outfile;
        outfile.open("kc_md5_temp_1.dat");
        outfile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
                "\n"
                "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
                "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
                "culpa qui officia deserunt mollit anim id est laborum.";
        outfile.close();
        std::ifstream infile;
        infile.open("kc_md5_temp_1.dat");
        mymd5_1_3.update(infile);
        if (mymd5_1_3.hexdigest() == "a5e90c16beb53bb93468496eaf2e0ac4") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }


    std::cout << std::endl << std::endl << "File Constructor";
    {
        std::cout << std::endl << "    MD5 Check .................................. ";
        std::ifstream infile;
        infile.open("kc_md5_temp_1.dat");
        kc::md5 mymd5_2_1(infile);
        if (mymd5_2_1.hexdigest() == "a5e90c16beb53bb93468496eaf2e0ac4") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        std::cout << std::endl << "    Update w/ String; MD5 Check ................ ";
        std::ifstream infile;
        infile.open("kc_md5_temp_1.dat");
        kc::md5 mymd5_2_2(infile);
        mymd5_2_2.update("apples");
        if (mymd5_2_2.hexdigest() == "daeccf0ad3c1fc8c8015205c332f5b42") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        std::cout << std::endl << "    Update w/ File; MD5 Check .................. ";
        std::ifstream infile;
        infile.open("kc_md5_temp_1.dat");
        kc::md5 mymd5_2_3(infile);
        infile.close();
        std::ofstream outfile;
        outfile.open("kc_md5_temp_2.dat");
        outfile << "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
                "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
                "culpa qui officia deserunt mollit anim id est laborum.\n"
                "\n"
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
        outfile.close();
        infile.open("kc_md5_temp_2.dat");
        mymd5_2_3.update(infile);
        if (mymd5_2_3.hexdigest() == "738b52562b33e27f762f485b0e4d9e72") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    
    std::remove("kc_md5_temp_1.dat");
    std::remove("kc_md5_temp_2.dat");

    std::cout << std::endl << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::MD5 Summary";
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "Status: " << ((fail_ct)?"FAIL":"Pass");
    std::cout << std::endl << "    Success Count: " << pass_ct;
    std::cout << std::endl << "    Failure Count: " << fail_ct;
}


/*
    std::locale loc;
    for (std::string::size_type i=0; i<str.length(); ++i)
        std::cout << std::tolower(str[i],loc);
*/