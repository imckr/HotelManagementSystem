#pragma once
#include<string.h>
#include<iostream>
#include<fstream>
class Hotel
{
private:
    std::string fname, lname, user, password, cPassword, admin_name, Email_admin, address;
    int days;
    int room_no;
    static int count;
    int age;
    uint64_t mob;
    __int64 price = 5000;

public:
    void menu();
    void administrator();
    void booking();
    void modify();
    void cdetails();
    void receipt(int t, int room = 0, int ucode = 0, int d = 0);
    //  void additional();
    bool checkStatus();
};
