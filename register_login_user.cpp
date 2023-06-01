#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

void login();
void registers();
void forgot();

int main(){
    int choice;
    cout << "-------------- Welcome to Login Page! --------------\n" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Forgot Password" << endl;
    cout << "4. Exit" << endl;
    cout << "-->> ";
    cin >> choice;

    switch(choice){
        case 1:
            login();
            break;
        case 2:
            registers();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "Thank you for using the program!" << endl;
            break;
        default:
            system("cls");
            cout << "Invalid Choice! Choose one of displayed options!\n\n" << endl;
            main();
    }
}

void login(){
    int count;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t\n Please enter your username and password: " << endl;
    cout << "\t\t\t USERNAME -> ";
    cin >> userID;
    cout << "\t\t\t PASSWORD -> ";
    cin >> password;

    ifstream input("records.txt");

    while(input>>id>>pass){
        if(id==userID && pass==password){
            count= 1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout << "\n Your login was successful! Thank you!\n" << endl;
    }
    else{
            cout << "\n Invalid username or password! Please try again.\n" << endl;
            login();
        }
}

void registers(){
    string nuserID, npassword, nid, npass;
    system("cls");
    cout << "Enter username: ";
    cin >> nuserID;
    cout << "Enter password: ";
    cin >> npassword;
    
    ofstream f1("records.txt", ios::app);
    f1 << nuserID << " " << npassword << endl;
    system("cls");
    cout << "\n Your registration was successfully completed!\n";
    main();
}

void forgot(){

    int option;
    system("cls");
    cout << "\t\t\t\n Your forgot your password?\n";
    cout << "Press 1 to search your ID by username " << endl;
    cout << "Press 2 to go back to the main page " << endl;
    cout << "\t\t\t Enter your choice --> ";
    cin >> option;

    switch(option){
        case 1:
            int cnt = 0;
            string muserID, mID, mpass;
            cout << "\n\t\tEnter the username which you remember: ";
            cin >> muserID;
            ifstream f2("records.txt");
            while(f2 >> mID >> mpass){
                if(mID==muserID){
                    cnt = 1;
                }
            }
            f2.close();
            if(cnt == 1){
                cout << "\n\n Your account has been found! \n";
                cout << "\n\n Your password is ->> " << mpass;
                main();
            }
            else{
                cout << "\n\n We couldn't find your account! \n";
                main();
            }
        case 2:
            main();
        default:
            cout << "\n Wrong choice! Select again!\n";
            forgot();
    }
}