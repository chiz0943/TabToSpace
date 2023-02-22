# include <iostream>
# include <fstream>
# include <cstdio>

using namespace std ;

int main( int argc, char *argv[] ) {
    ifstream ifs(argv[1],ifstream::in) ;
    ofstream ofs(argv[2],ifstream::out) ;
    char ch = '\0';
    cout << argv[1] << argv[2] << endl ;
    int count = 0 ;
    do {
        ifs.get(ch) ;
        cout << ch ;
        if ( ch == ' ' ) {
            count += 1 ;
        }
        else {
            for ( int i = 0 ; i < count ; i += 1 ) {
                ofs.put(' ') ;
            }
            ofs.put(ch) ;
            count = 0 ;
        }
        if ( count == 4 ) {
            ofs.put(' ') ;
            ofs.put(' ') ;
            count = 0 ;
        }
    } while( ! ifs.eof() ) ;
    
}