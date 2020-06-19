#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>

using namespace std ;
bool jestFolderem(string sciezka) ;
void pobierzNazweUsera() ;
void ulozLokalizacje() ;
//string lokalizacja ;
string nazwaUsera ;
string md5zpliku(string lokalizacjapliku) ;
std::string replaceFirstOccurrence(std::string& s, const std::string& toReplace, const std::string& replaceWith) ;

std::string replaceAll(
    std::string& s,
    const std::string& toReplace,
    const std::string& replaceWith) ;

int main(int argc, char** argv)
{
  cout << "Wyliczanie MD5 wszystkich plików... " ;
  //sleep(1) ;
  //ulozLokalizacje() ;
  FILE *polecenie ;
	polecenie = popen((string("find ") + string(argv[1])).c_str(), "r") ;
cout << (string("find ") + string(argv[1])).c_str() << endl ;

  ofstream foldery, pliki ;
  foldery.open("d.txt") ;
  pliki.open("f.txt") ;

  while(1)
  {
    char nazwapliku[256] = {0} ;
	  fgets(nazwapliku, sizeof(nazwapliku), polecenie) ;
    string FajnaNazwaPliku = nazwapliku ;

    //FajnaNazwaPliku = replaceFirstOccurrence(FajnaNazwaPliku, "\n", "") ;

    if(nazwapliku[1] == 0)
    {
      break ;
    }

	//old working version
    /*if(FajnaNazwaPliku.find(".DGConfig/DGFiles/assets") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/config") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/libraries") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/llibrary") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/mods") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/scripts") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/versions") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/resources") != string::npos || FajnaNazwaPliku.find(".DGConfig/DGFiles/resourcepacks") != string::npos)
    {
      if(jestFolderem(FajnaNazwaPliku))
      {
        foldery << FajnaNazwaPliku.substr(lokalizacja.length(), FajnaNazwaPliku.length()) ;
      }
      else
      {
        pliki << FajnaNazwaPliku.substr(lokalizacja.length(), FajnaNazwaPliku.length()) <<  md5zpliku(string(FajnaNazwaPliku)) << '\n' ;
      }
    }*/

      if(jestFolderem(FajnaNazwaPliku))
      {
        //foldery << FajnaNazwaPliku.substr(lokalizacja.length(), FajnaNazwaPliku.length()) ;
		foldery << FajnaNazwaPliku.substr(FajnaNazwaPliku.find("/"), FajnaNazwaPliku.length()) ;
      }
      else
      {
        //pliki << FajnaNazwaPliku.substr(lokalizacja.length(), FajnaNazwaPliku.length()) <<  md5zpliku(string(FajnaNazwaPliku)) << '\n' ;
		pliki << FajnaNazwaPliku.substr(FajnaNazwaPliku.find("/"), FajnaNazwaPliku.length()) <<  md5zpliku(string(FajnaNazwaPliku)) << '\n'  ;
      }
    

  }

  foldery.close() ;
  pliki.close() ;

  cout << "Gotowe! \n" ;

  return 0 ;
}

string md5zpliku(string lokalizacjapliku)
{

  lokalizacjapliku = replaceAll(lokalizacjapliku, " ", "\\ ") ;
  lokalizacjapliku = replaceAll(lokalizacjapliku, "\'", "\\'") ;

  lokalizacjapliku = replaceAll(lokalizacjapliku, "(", "\\(") ;
  lokalizacjapliku = replaceAll(lokalizacjapliku, ")", "\\)") ;
  lokalizacjapliku = replaceAll(lokalizacjapliku, "$", "\\$");

  string polecenie = string("md5sum ") + lokalizacjapliku ;
  FILE *wykon ;
	wykon = popen(polecenie.c_str(), "r") ;

  char wynik[33] = {0} ;
  fgets(wynik, 33, wykon) ;
  pclose(wykon) ;
  return string(wynik) ;
}

bool jestFolderem(string sciezka)
{
  sciezka = sciezka.substr(0, sciezka.length()-1) ;
  string polecenie = string("[ -d \"") + sciezka + string("\" ] && echo 1\n") ;
  FILE *wykon ;
	wykon = popen(polecenie.c_str(), "r") ;
  //cout << polecenie ;

  if(fgetc(wykon) == '1')
  {
    pclose(wykon) ;
    return true ;
  }
  pclose(wykon) ;
  return false ;

}
/*
void pobierzNazweUsera()
{
	FILE *nazwa ;
	nazwa = popen("whoami", "r") ;
char useranazwa[256] = {0} ;
	fgets(useranazwa, sizeof(useranazwa), nazwa) ;
nazwaUsera = useranazwa ;
	if(nazwaUsera[nazwaUsera.length()-1] = '\n')
	{
		nazwaUsera = nazwaUsera.substr(0, nazwaUsera.length()-1) ;
	}

	pclose(nazwa) ;
}

void ulozLokalizacje()  //ukladanie folderu z mc
{
	pobierzNazweUsera() ;
	lokalizacja.clear() ;
	lokalizacja.append("/home/") ;
	lokalizacja.append(nazwaUsera) ;
	lokalizacja.append("/.DGConfig/") ;
	lokalizacja = lokalizacja + "DGFiles/" ;
}
*/
std::string replaceFirstOccurrence(
    std::string& s,
    const std::string& toReplace,
    const std::string& replaceWith)
{
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return s;
    return s.replace(pos, toReplace.length(), replaceWith);
}

std::string replaceAll(
    std::string& s,
    const std::string& toReplace,
    const std::string& replaceWith)
{
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos) return s;
    s =  s.replace(pos, toReplace.length(), replaceWith);

    pos = s.find(toReplace, pos+2);
    if (pos == std::string::npos) return s;
    s =  s.replace(pos, toReplace.length(), replaceWith);

    pos = s.find(toReplace, pos+2);
    if (pos == std::string::npos) return s;
    s =  s.replace(pos, toReplace.length(), replaceWith);

    pos = s.find(toReplace, pos+2);
    if (pos == std::string::npos) return s;
    s =  s.replace(pos, toReplace.length(), replaceWith);

    pos = s.find(toReplace, pos+2);
    if (pos == std::string::npos) return s;
    s =  s.replace(pos, toReplace.length(), replaceWith);

    pos = s.find(toReplace, pos+2);
    if (pos == std::string::npos) return s;
    return s.replace(pos, toReplace.length(), replaceWith);
}
