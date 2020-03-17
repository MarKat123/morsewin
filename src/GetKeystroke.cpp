#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <Morse.h>

using namespace std;

void getKeystrokes(void);
void sendChars(void);

const int BfrSz = 15;
char KeyBfr[BfrSz];
int KeyBfrHead = 0;
int KeyBfrTail = 0;

bool repeat = true;

int main()
{
    thread th1(getKeystrokes);
    thread th2(sendChars);

    th1.join();
    th2.join();
    
    return 0;
}

void sendChars(void)
{
    int AlphabetIndex = 0;
    while (repeat)
    {
        Sleep(50);
        if (KeyBfrHead != KeyBfrTail)
        {
            if ((KeyBfr[KeyBfrTail] >= A ) && (KeyBfr[KeyBfrTail] <= Z )) {
                AlphabetIndex = KeyBfr[KeyBfrTail] - A + AlphaOffset ;
            }
            else if ((KeyBfr[KeyBfrTail] >= a ) && (KeyBfr[KeyBfrTail] <= z )) {
                AlphabetIndex = KeyBfr[KeyBfrTail] - a + AlphaOffset ;
            }
            else if ((KeyBfr[KeyBfrTail] >= zero ) && (KeyBfr[KeyBfrTail] <= nine)) {
                AlphabetIndex = KeyBfr[KeyBfrTail] - zero + DigitOffset ;
            }
             else if (KeyBfr[KeyBfrTail] == space )  {
                AlphabetIndex = KeyBfr[KeyBfrTail] - space + SpaceOffset ;
            }
            else
            {
                cout << "\nNo Code!!!" << endl;
            }
            cout << KeyBfr[KeyBfrTail] << " " ;
            cout << MorseAlpha[AlphabetIndex] << endl;
            KeyBfrTail = (KeyBfrTail + 1) % BfrSz  ;
        }
    }
    return;
}

void getKeystrokes(void)
{
    char ch;
    while (repeat)
    {
        Sleep(50);
        if (kbhit())
        {
            Sleep(50);
            ch = getch();
            int decode = (int)(ch);
            switch (decode)
            {
            case 27: // press ESC to exit
                repeat = false;
                break;
            case 13: // cr
            case 10: // lf
                cout << "\n";
                break;
            default:
                KeyBfr[KeyBfrHead] = ch;
                if (( KeyBfrHead > KeyBfrTail ) && (( KeyBfrHead - KeyBfrTail ) < 2 )) {
                    cout << "Boundary!!" << endl; 
                    Sleep(1000);
                }
                if (( KeyBfrHead < KeyBfrTail ) && ( ( KeyBfrHead + BfrSz - KeyBfrTail ) < 2 ) ) {
                    cout << "Neg Boundary!!" << endl; 
                    Sleep(1000);
                }
                KeyBfrHead = (KeyBfrHead + 1) % BfrSz ;
                break;
            }
        }
    }
    return;
}