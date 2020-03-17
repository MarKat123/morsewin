using namespace std;

string MorseAlpha[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
  "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
  "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
  "-.--", "--..",  "-----", ".----", "..---", "...--", "....-", ".....", 
  "-....", "--...", "---..", "----.", " "};

// enum CapLoc { A , B , C , D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z } ;
const int A = 65 ;
const int Z = 90 ;
const int a = 97 ;
const int z = 122 ;
const int zero = 48 ;
const int nine = 57 ;
const int space = 32 ;
const int AlphaOffset = 0 ;
const int DigitOffset = 26 ;
const int SpaceOffset = 26 + 10 ;

  