#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class zamiana{
       ifstream plik1;
       ofstream plik2;

  public:
        zamiana();
        ~zamiana();
       
        void licz();        
};

zamiana::zamiana(){ //konstruktor otwiera pliki
    plik1.open("C:\\Users\\Eryk\\Desktop\\palindromy\\x.txt");
    plik2.open("C:\\Users\\Eryk\\Desktop\\palindromy\\y.txt");
}

void zamiana::licz(){
    int licznik; //ilo�� wyst�pie� znaku
    string napis; //wczytany napis z pliku
    char znak; //wczytany znak z pliku

    while(!plik1.eof()){ //czyta plik linia po linii
        getline(plik1,napis); //czyta napis z pliku
        
        
        
        int back = napis.length()-1; //ostatnia litera s
        bool palindrome = true; //zak�adamy �e jest
        for (int i=0; i<napis.length()/2 && palindrome; i++) //tylko do po�owy stringu
                if (napis[i] != napis[back--]) //back po podstawieniu zmniejszy si� o 1 z ostatniej na przedostatni� itd.
                	{
						palindrome = false;
        				plik2 << "{\n \"string\" : " << napis << ", \n \"palindrom\" : \"nie\" \n}\n";
					}
				else
					{
						palindrome = false;
        				plik2 << "{\n \"string\" : " << napis << ", \n \"palindrom\" : \"tak\" \n}\n";
					}
				
					
					   
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
zamiana::~zamiana(){ //destruktor - niejawnie wywo�any przy zamkni�ciu main(), zamyka pliki
    plik1.close();
    plik2.close();
}

int main() {
    zamiana z1; //tworzymy obiekt klasy zamiana - tu uruchamia si� konstruktor
    z1.licz(); //wywo�ujemy metod�, g��wn� p�tl�
    return 0;
}
