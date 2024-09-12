#include "Hotel.h"
#include<iostream>
#include<string.h>
#include<sstream>
#include<iomanip>

void Hotel::menu()
{
    int choice;
    /* The below code is printing a welcome message to the console. It is displaying a header with the
    text "Welcome To CKR Hotels" surrounded by a border made of dashes. */
    std::cout << "\t\t----------------------------------------------------------" << std::endl;
    std::cout << "\t\t|                         Welcome                        |" << std::endl;
    std::cout << "\t\t|                            To                          |" << std::endl;
    std::cout << "\t\t|                       CKR Hotels                       |" << std::endl;
    std::cout << "\t\t----------------------------------------------------------" << std::endl
        << std::endl;

    /* The below code is displaying a menu for a hotel management system. It provides options for an
    administrator to login, book a room or check in a guest, check out a guest, or exit the program. */
    std::cout << "\t\t\t-----------------------------------------------" << std::endl;
    std::cout << "\t\t\t|          1) Administrator Login             |" << std::endl;
    std::cout << "\t\t\t|          2) Book a room / Check in          |" << std::endl;
    std::cout << "\t\t\t|          3) Check out                       |" << std::endl;
    std::cout << "\t\t\t|          4) Exit                            |" << std::endl;
    std::cout << "\t\t\t-----------------------------------------------" << std::endl
        << std::endl;

    /* The below code is implementing a menu-driven program. It prompts the user to enter a
    choice and based on the choice, it calls different functions. */
    do
    {
        std::cout << "Choice -  ";
        std::cin >> choice;


        switch (choice)
        {
        case 1:
            administrator();
            break;

        case 2:
            booking();
            break;

        case 3:
            receipt(2);
            break;

        case 4:
            exit(0);

        default:
            std::cout << "Invalid Choice..!!!" << std::endl;
        }

    } while (choice != 4);
}

void Hotel::administrator()
{
    int i = 0;
    int choice;
    std::string email, apassword;
m:
    /* The below code is displaying an admin login page and prompting the user to enter their email and
    password. The entered values are then stored in the variables 'email' and 'apassword'. */
    std::cout << "-----------------Admin Login Page---------------------" << std::endl
        << std::endl;

    std::cout << "Email - ";
    std::cin >> email;
    std::cout << "Password - ";
    std::cin >> apassword;
    std::cout << std::endl
        << std::endl;

    /* The below code is checking if the email and password entered by the user match the specified
    values. If they do, it displays a menu with three options: modify hotel details, see customer
    details, or go back to the main menu. It then prompts the user to enter a choice and uses a
    switch statement to execute the corresponding function based on the choice. After executing the
    chosen function, it goes back to the menu and prompts the user for another choice. */
    if (email == "chinturajwal@gmail.com" && apassword == "LNN030")
    {
    s:
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "|               1) Modify Hotel Details                 |" << std::endl;
        std::cout << "|               2) See the customer details             |" << std::endl;
        std::cout << "|               3) Back to Main                         |" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl
            << std::endl;

        std::cout << "Enter your Choice -  ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            modify();
            break;

        case 2:
            cdetails();
            break;

        case 3:
            menu();
            break;

        default:
            std::cout << "Invalid Choice...!!!" << std::endl;
        }
        goto s;
    }
    /* The below code is checking for invalid credentials. If the credentials
    are invalid, it will print "Invalid Credentials...!!" and then it will go to the label "m". */
    else
    {
        std::cout << "Invalid Credentials...!!" << std::endl;
    }
    goto m;
}

void Hotel::booking()
{
    int token = 0;
    int u;
    int available_rooms;
    std::fstream f1;
    std::fstream s1;
    std::fstream hotelDetails;
    std::fstream mobNo;
    s1.open("staticData.txt", std::ios::in);
    s1 >> u;
    s1.close();
    static int uCode = u;
    hotelDetails.open("HotelDetails.txt", std::ios::in);
    if (!hotelDetails)
    {
        hotelDetails.open("HotelDetails.txt", std::ios::out);
        available_rooms = 50;
        hotelDetails << available_rooms;
        hotelDetails.close();
    }
    else
    {
        hotelDetails >> available_rooms;
        hotelDetails.close();
    }

    int m;
    int choice;

    /* The below code is a program that prompts the user to enter their details such as first name,
    last name, mobile number, age, and address. It uses the `std::cout` and `std::cin` functions to
    display prompts and read user input respectively. The `getline` function is used to read the
    address, which allows for spaces in the input. */
    std::cout << "-----------------Welcome to Booking System----------------" << std::endl
        << std::endl;
    std::cout << "Enter your Details - " << std::endl;
    std::cout << "First Name - ";
    std::cin >> fname;
    std::cout << "Last Name - ";
    std::cin >> lname;
    std::cout << "Mobile Number - ";
    std::cin >> m;
    std::cout << "Age - ";
    std::cin >> age;
    std::cout << "Enter the no. of Rooms - ";
    std::cin >> room_no;


    /* The below code is opening a file named "Database.txt" in input mode. */
    f1.open("hotelData.txt", std::ios::in);

    /* The below code is checking if the file "Database.txt" is not open. If it is not open, it opens
    the file in append and output mode, writes a header line to the file, and then writes the values
    of variables ucode, fname, lname, mob, age, and address to the file. Finally, it closes the file
    and increments the value of ucode. */
    if (!f1)
    {
        f1.open("hotelData.txt", std::ios::app | std::ios::out);
        f1  << std::setw(6)  << std::left << "S.no"
            << std::setw(15) << std::left << "First Name"
            << std::setw(15) << std::left << "Last Name"
            << std::setw(15) << std::left << "Mobile Number"
            << std::setw(5)  << std::left << "Age" << std::endl
            << "________________________________________________________"
            << std::endl << std::endl;
        f1.close();
    }
    /* The below code is reading data from a file and checking if a specific value (stored in the
    variable "mob") matches the value in the file. If there is a match, it increments the variable
    "token". The code continues reading the file until the end is reached. Finally, it closes the
    file. */
    else
    {
        mobNo.open("MobileNumbers.txt", std::ios::in);
        mobNo >> mob;
        while (!mobNo.eof())
        {
            if (mob == m)
            {
                token++;
                break;
            }
            mobNo >> mob;
        }
        mobNo.close();
    }

    /* The below code is checking if the value of the
    variable "token" is equal to 1. If it is, then it prompts the user to enter the number of rooms
    they want. It then checks the availability of rooms by calling the "checkStatus()" function. If
    there are enough rooms available, it opens a file named "HotelDetails.txt" and writes the number
    of available rooms after deducting the requested number of rooms. It then prompts the user to
    enter the period of time in days and calls the "receipt()" function. If */
    if (token == 1)
    {
    g:
        /* The below code is checking the status using the `checkStatus()` function. If the status is
        true, it opens a file named "HotelDetails.txt" in input mode. If the file does not exist, it
        creates the file and writes the value `50 - room_no` to it. If the file already exists, it
        opens the file in output mode and writes the value of `available_rooms` to it. Then, it
        prompts the user to enter the period of time in days and calls the `receipt()` function with
        the `token` parameter. */
        if (checkStatus())
        {
            available_rooms -= room_no;
            std::fstream h1;
            h1.open("HotelDetails.txt", std::ios::out);
            h1 << available_rooms;
            h1.close();
            std::cout << "Enter the period of time in days - ";
            std::cin >> days;
            receipt(token, room_no, uCode, days);
        }
        /* The below code is a part of a larger program and it is handling a situation where there are
        not enough rooms available. It prints a message indicating the number of available rooms and
        then prompts the user if they want to retry or not. If the user chooses to retry, it goes
        back to a label "g" in the code. If the user chooses to exit, the program terminates. If the
        user enters an invalid choice, it prompts again until a valid choice is entered. */
        else
        {
            std::fstream h2;
            h2.open("HotelDetails.txt", std::ios::in);
            h2 >> available_rooms;
            h2.close();

            printf("Only %d rooms available\n", available_rooms);
        v:
            std::cout << "Do you want to retry...?[1 for Yes/0 for No]" << std::endl;
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                goto g;
                break;
            case 2:
                exit(0);
                break;

            default:
                std::cout << "Invalid choice....!!" << std::endl;
                goto v;
            }
        }
    }
    /* The below code is handling the registration process for a hotel. */
    else
    {
        /* The below code is opening a file named "Database.txt" in append mode and writing the values
        of variables ucode, fname, lname, mob, age, and address to the file, separated by tabs.
        After writing the values, the file is closed. The value of ucode is then incremented, and a
        success message is printed to the console. */
        std::fstream f2;
        f2.open("hotelData.txt", std::ios::app | std::ios::out);
        f2  <<std::setw(6)<<std::left<<uCode
            <<std::setw(15)<<std::left<<fname 
            <<std::setw(15)<<std::left<<lname
            <<std::setw(15)<<std::left<<m
            <<std::setw(15)<<std::left<<age << std::endl;
        f2.close();
        mobNo.open("MobileNumbers.txt", std::ios::app | std::ios::out);
        mobNo << m << std::endl;
        mobNo.close();
        uCode++;
        s1.open("staticData.txt", std::ios::out);
        s1 << uCode;
        std::cout << "Successfully registered..." << std::endl<<std::endl;
        /* The below code is checking the status using the `checkStatus()` function. If the status is
        true, it opens a file named "HotelDetails.txt" in input mode. If the file does not exist, it
        creates the file and writes the value `50 - room_no` to it. If the file already exists, it
        opens the file in output mode and writes the value of `available_rooms` to it. Then, it
        prompts the user to enter the period of time in days and calls the `receipt()` function with
        the `token` parameter. */
        if (checkStatus())
        {
            std::fstream h1;
            h1.open("HotelDetails.txt", std::ios::in);
            if (!h1)
            {
                h1.open("HotelDetails.txt", std::ios::app | std::ios::out);
                h1 << 50 - room_no;
                h1.close();
            }
            else
            {
                h1.open("HotelDetails.txt", std::ios::in);
                h1 >> available_rooms;
                h1.close();
                h1.open("HotelDetails.txt", std::ios::out);
                available_rooms -= room_no;
                h1 << available_rooms;
                h1.close();
            }
            std::cout << "Enter the period of time in days - ";
            std::cin >> days;
            receipt(token, room_no, uCode, days);
        }
        /* The below code is a part of a larger program and it is handling a situation where there are
        no available rooms. It prints a message indicating the number of available rooms and then
        prompts the user to retry or exit the program. If the user chooses to retry, it goes back to
        a label "g" in the code. If the user chooses to exit, the program terminates. If the user
        enters an invalid choice, it prompts the user again until a valid choice is entered. */
        else
        {
            std::fstream h1;
            h1.open("HotelDetails.txt", std::ios::in);
            h1 >> available_rooms;
            printf("Only %d rooms available\n", available_rooms);
            h1.close();
        z:
            std::cout << "Do you want to retry...?[1 for Yes / 0 for No]" << std::endl;
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                goto g;
                break;
            case 2:
                exit(0);
                break;

            default:
                std::cout << "Invalid choice....!!" << std::endl;
                goto z;
            }
        }
    }
}

/**
 * The `modify` function allows the user to change the availability of rooms or the pricing in a hotel
 * system.
 *
 * @return The function does not return any value. It has a void return type.
 */
void Hotel::modify()
{
    int i = 0;
    int change;
    int available_rooms;
    std::fstream h3;
    h3.open("HotelDetails.txt", std::ios::in);
    h3 >> available_rooms;
    h3.close();
    int choice;
r:
    /* The below code is displaying a menu with three options: "Changing room availability", "Pricing",
    and "Exit". */
    std::cout << "--------------Modify----------------" << std::endl;
    std::cout << " 1. Changing room availability" << std::endl;
    std::cout << " 2. Pricing" << std::endl;
    std::cout << " 3. Exit" << std::endl;

    std::cin >> choice;

    switch (choice)
    {

        /* The below code is a case statement. It is asking the user whether they want to
        increase or decrease the number of available rooms. If the user chooses to increase, it
        prompts for the amount of change and adds it to the available_rooms variable. If the user
        chooses to decrease, it prompts for the amount of change and subtracts it from the
        available_rooms variable. If the user enters an invalid choice, it displays an error message
        and goes back to the beginning of the case statement. */
    case 1:
        printf("Currently %d Rooms are available.\n", available_rooms);
        std::cout << "Do you want to increase or decrease? [1 for increase / 2 for decrease]" << std::endl;
        std::cin >> i;
        if (i == 1)
        {
            std::fstream HData;
            HData.open("HotelDetails.txt", std::ios::in | std::ios::out);
            HData >> available_rooms;
            std::cout << "Enter the change :- ";
            std::cin >> change;
            available_rooms += change;
            HData << available_rooms;
            HData.close();

        }
        else if (i == 2)
        {
            std::fstream HData;
            HData.open("HotelDetails.txt", std::ios::in | std::ios::out);
            HData >> available_rooms;
            std::cout << "Enter the change :- ";
            std::cin >> change;
            available_rooms -= change;
            HData << available_rooms;
            HData.close();
        }
        else
        {
            std::cout << "Invalid choice...!!!" << std::endl;
            goto r;
        }
        break;

        /* The below code is a case statement. It is asking the user whether they want to
        increase or decrease the price. If the user chooses to increase, it prompts for the amount
        of change and adds it to the price. If the user chooses to decrease, it prompts for the
        amount of change and subtracts it from the price. If the user enters an invalid choice, it
        displays an error message and goes back to the beginning of the case statement. */
    case 2:
        printf("Currently Price is %I64d \n", price);
        std::cout << "Do you want to increase or decrease? [1 for increase / 2 for decrease]" << std::endl;
        std::cin >> i;
        if (i == 1)
        {
            std::cout << "Enter the change :- ";
            std::cin >> change;
            price += change;
        }
        else if (i == 2)
        {
            std::cout << "Enter the change :- ";
            std::cin >> change;
            price -= change;
        }
        else
        {
            std::cout << "Invalid choice...!!!" << std::endl;
            goto r;
        }
        break;

        /* The below code is a case statement. It is checking if the value of the variable
        "case" is equal to 3. If it is, it will print "Exiting....." to the console and then return
        from the current function. */
    case 3:
        std::cout << "Exiting....." << std::endl << std::endl;
        return;
        break;
        /* The below code is handling an invalid choice in a switch statement. If the user enters an
        invalid choice, it will display "Invalid Choice....!!!" and then go back to the beginning of
        the switch statement using a goto statement. */
    default:
        std::cout << "Invalid Choice....!!!" << std::endl << std::endl;
        goto r;
        break;
    }
}

/* The `cdetails()` function in the `HotelSystem` class is used to display the details of all the
customers who have registered in the hotel. It reads the customer details from the "Database.txt"
file and prints them on the console in a tabular format. The details include the serial number,
first name, last name, mobile number, age, and address of each customer. */
void Hotel::cdetails()
{
    int code;
    std::fstream data;
    data.open("hotelData.txt", std::ios::in);
    if (!data)
    {
        std::cout << "No record found!!!" << std::endl;
    }
    else {
        std::cout << "\n\n------------------Details------------------" << std::endl;
        std::cout << "________________________________________________________________________________________________________" << std::endl;
        std::cout << "S.no\t\tFirst name\t\tLast name\t\tMobile Number\t\tAge" << std::endl;
        std::cout << "________________________________________________________________________________________________________" << std::endl;
        data >> code >> fname >> lname >> mob >> age >> address;

        /* The below code is reading data from a file and printing it to the console. It uses a while loop
        to iterate until the end of the file is reached. Inside the loop, it prints the values of
        variables code, fname, lname, mob, age, and address to the console. Then, it reads the next set
        of values from the file into these variables. */
        while (!data.eof())
        {
            std::cout << code << "\t\t" << fname << "\t\t" << lname << "\t\t" << mob << "\t\t" << age << "\t\t" << address << "\n";
            data >> code >> fname >> lname >> mob >> age >> address;
        }
    }
    /* The below code is closing a file named "data". */
    data.close();
}


//Below Function is not Completed !!
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------

void Hotel::receipt(int t, int room, int ucode, int d)
{
    std::cout << "This section is not completed yet"<<std::endl;
}


bool Hotel::checkStatus()
{
    return true;
}
