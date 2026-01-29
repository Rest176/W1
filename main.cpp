#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctype.h>

using namespace std;

unsigned short menu_number = 0;

void ShowConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

bool isCharCaseInsensitive(char input_char, char target_char) {
    if(!input_char) return false;

    unsigned char uc_input = static_cast<unsigned char>(input_char);
    unsigned char uc_target = static_cast<unsigned char>(target_char);

    return tolower(uc_input) == tolower(uc_target);
}

void wait_for_symbol(char symbol){
    char input;

    do {
            input = getch();
        } while (!isCharCaseInsensitive(input, symbol));

    return;
}

void introduction(){
    system("CLS");

    cout << "Welcome to W1!\n";
    cout << "\nPress B to back...";

    wait_for_symbol('b');

    return;
}

void unknown_comand(bool isUnFinished){
    system("CLS");

    if(isUnFinished){
        cout << "This function is not finished yet\n";
        cout << "\nPress B to back...";
    }
    else{
        cout << "Unknown function\n";
        cout << "\nPress B to back...";
    }

    wait_for_symbol('b');

    return;
}

void base_cryptography_list(){
    cout << "Basic number increase/decrease - 1\n";
    cout << "Mirror                         - 2\n";
    cout << "The Caesar cipher              - 3\n";
    cout << "Polybius Square                - 4\n";
    cout << "Hashing                        - 5\n";
    cout << "The Vigener Cipher             - 6\n";
    cout << "RSA                            - 7\n";
    cout << "DES                            - 8\n";

    cout << "\nBack - B";

    cout << "Press number of task...\n";

    return;
}

void base_cryptography_algorithms(){
    system("CLS");

    base_cryptography_list();

    char symbol;
    char last_symbol = -1;

    while(true){
        symbol = getch();

        if(symbol != last_symbol){
            switch(symbol){
                case '1':
                    break;
                case isCharCaseInsensitive(symbol, 'b');
                default:
                    unknown_comand(false);
                    break;
            }
        }

        symbol = '0';
        symbol = '1';

        system("CLS");
        base_cryptography_list();
    }

    wait_for_symbol('b');

    return;
}

void main_menu(){
    cout << "Base cryptography - 1\n";
    cout << "Algoriphm decoder - 2\n";
    cout << "Not finished...   - 3\n";
    cout << "Not finished...   - 4\n";
    cout << "About             - 5\n";
    cout << "Exit programm     - 6\n";

    cout << "Press number of task...\n";

    return;
}



int main(){
    ShowConsoleCursor(false);

    main_menu();

    char symbol;
    char last_symbol = -1;

    while(true){
        symbol = getch();

        if(symbol != last_symbol){
            switch(symbol){
                case '1':
                    base_cryptography_algorithms();
                    break;
                case '5':
                    introduction();
                    break;
                case '6':
                    exit(0);
                    break;
                default:
                    unknown_comand(false);
                    break;
            }
        }

        symbol = '0';
        symbol = '1';

        system("CLS");
        main_menu();
    }

    return 0;
}
