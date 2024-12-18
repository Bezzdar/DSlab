#include"Validator.h"

//????????? ???????? ???????? ??? ?????????.
int ValidCin()
{
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

//????????? ??????? ???????. ??????? ??????? ?? numbOfFirstCommand ? ?? numbOfLastCommnad.
int ValidInputMenu(int numbOfFirstCommand, int numbOfLastCommnad)
{
    int Input;
    while ((!(cin >> Input)) || Input > numbOfLastCommnad || Input < numbOfFirstCommand) {

        cout << "\x1b[2K";
        cout << "\x1b[1A";
        cout << "\r";
        cout << "Invalid input. Please enter an integer! " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Input;
}