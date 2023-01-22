#include <conio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib> 
#include <ctime> 
#include <vector>
#include <Windows.h>
#include <stdlib.h>

using namespace std;


int main() {
    //SRand function to generate a more random seed based off time
    srand((unsigned)time(NULL));

    // Get a random number
    int random = rand();



    vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int> v2 = { 11,12,13,14,15 };
    for (int i = 0; i < random % 10; i++) {

        random_shuffle(v1.begin(), v1.end());

    }
    // the randomizer shuffles the bombs around


    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);



    for (int i = 0; i < random % 10; i++) {

        random_shuffle(v2.begin(), v2.end());
    }
    for (int i = 0; i < v1.size(); i++) {

    }

    for (int i = 0; i < v2.size(); i++) {

    }


    int bombCount = 0;
    bool bombActive1 = true;
    bool bombActive2 = true;
    bool bombActive3 = true;
    bool bombActive4 = true;
    bool bombActive5 = true;
    bool bombActive6 = true;
    bool bombActive7 = true;
    bool bombActive8 = true;
    bool bombActive9 = true;
    bool bombActive10 = true;
    // initializing all bombs

    cout << "Welcome, there are 10 bombs" << endl;
    bool running = true;
    // while loop from 1 to 5
    const int x = 15;
    const int y = 10;

    string XYPLANe[y][x];
    int pHy = 0;
    int indexX = 0;
    int indexY = 0;
    int pHx = 0;
    
    while (pHy < y) {
        
        SetConsoleTextAttribute(h, 11);


        indexY = 0;
        pHx = 0;

        while (pHx < (x)) {
            SetConsoleTextAttribute(h, 11);
            XYPLANe[indexX][indexY] = "-";

            indexY++;



            ++pHx;
        };

        indexX++;
        ++pHy;
    };

    SetConsoleTextAttribute(h, 7);
    cout << "Try to hit less than 80% of all bombs" << endl;
    int ObjXVal{ 0 };
    int ObjYVal{ 0 };


    SetConsoleTextAttribute(h, 11);
    XYPLANe[ObjYVal][ObjXVal] = "X";
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            cout << XYPLANe[i][j];
        cout << endl;
    };




    char ch;
    int BorderValuex;
    int BorderValuey;


   
    while (running == true) {
        SetConsoleTextAttribute(h, 11);
        XYPLANe[ObjYVal][ObjXVal] = "-";
        SetConsoleTextAttribute(h, 7);
        cout << "enter a key: " << endl;

        ch = _getch();
        if (ch == 'd' || ch == 'D') {
            ObjXVal = ObjXVal + 1;
            system("CLS");
        }
        else if (ch == 's' || ch == 'S') {
            ObjYVal = ObjYVal + 1;// y value is reversed due to building structure of a plane (XY)
            system("CLS");
        }
        else if (ch == 'a' || ch == 'A') {
            ObjXVal = ObjXVal - 1;
            system("CLS");
        }
        else if (ch == 'w' || ch == 'W') {
            ObjYVal = ObjYVal - 1;// y value is reversed due to building structure of a plane (XY)
            system("CLS");
        }
        else if (ch == 'q') {
            system("CLS");
            running = false;
        }
        else {
            system("CLS");
            SetConsoleTextAttribute(h, 12);
            cout << "Invalid Move" << endl;
        }
        BorderValuex = ObjXVal + 1;
        BorderValuey = y - ObjYVal;
        //BOMB CHECKER



        SetConsoleTextAttribute(h, 7);
        if (BorderValuey == v1[0] && BorderValuex == v1[1] && bombActive1 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive1 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[1] && BorderValuex == v2[0] && bombActive2 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive2 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[2] && BorderValuex == v1[3] && bombActive3 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive3 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[3] && BorderValuex == v2[1] && bombActive4 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive4 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[4] && BorderValuex == v1[5] && bombActive5 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive5 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[5] && BorderValuex == v2[2] && bombActive6 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive6 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[6] && BorderValuex == v1[7] && bombActive7 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive7 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[7] && BorderValuex == v2[3] && bombActive8 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive8 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[8] && BorderValuex == v1[9] && bombActive9 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive9 = false;
            bombCount = bombCount + 1;
        }
        else if (BorderValuey == v1[9] && BorderValuex == v2[4] && bombActive10 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive10 = false;
            bombCount = bombCount + 1;
        }
        //BOMB CHECKER

        cout << bombCount << "<--This many bombs were stepped on!" << endl;
        if (BorderValuex >= 1 && BorderValuey >= 1 && BorderValuex <= 15 && BorderValuey <= 10) {
            cout << "Enter a move [WASD] or [Q] to quit" << endl;
            SetConsoleTextAttribute(h, 11);
            XYPLANe[ObjYVal][ObjXVal] = "X";
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++)          //THIS IS A LOOP TO PRINT A PLANE
                    cout << XYPLANe[i][j];
                cout << endl;
                

            };
            SetConsoleTextAttribute(h, 7);
        }
        else {
            cout << "You can not go further!!!" << endl;
            SetConsoleTextAttribute(h, 11);
            if (ch == 'd' || ch == 'D') {
                ObjXVal = ObjXVal - 1;
            }
            else if (ch == 's' || ch == 'S') {
                ObjYVal = ObjYVal - 1;// y value is reversed due to building structure of a plane (XY)
            }
            else if (ch == 'a' || ch == 'A') {
                ObjXVal = ObjXVal + 1;
            }
            else if (ch == 'w' || ch == 'W') {
                ObjYVal = ObjYVal + 1;// y value is reversed due to building structure of a plane (XY)
            }
            else {
                running = false;
            }
            SetConsoleTextAttribute(h, 11);
            XYPLANe[ObjYVal][ObjXVal] = "X";
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++)          //THIS IS A LOOP TO PRINT A PLANE
                    cout << XYPLANe[i][j];
                cout << endl;
            } 
        }//end of running loop
        if (BorderValuey == 1 && BorderValuex == 15) {
            SetConsoleTextAttribute(h, 12);
            cout << "Y";
            SetConsoleTextAttribute(h, 14);
            cout << "o"; 
            SetConsoleTextAttribute(h, 10);
            cout << "u"; 
            SetConsoleTextAttribute(h, 6);
            cout << " ";
            SetConsoleTextAttribute(h, 11);
            cout << "w"; 
            SetConsoleTextAttribute(h, 9);
            cout << "i"; 
            SetConsoleTextAttribute(h, 5);
            cout << "n"; 
            SetConsoleTextAttribute(h, 7);
            cout << "!";
            return 0;
        }
    };
}