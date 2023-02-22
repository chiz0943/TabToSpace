# include <iostream>
# include <fstream>
# include <cstdio>

using namespace std ;

int main( int argc, char *argv[] ) {
    ifstream ifs(argv[1],ifstream::in) ;
    ofstream ofs(argv[2],ifstream::out) ;
    char ch = '\0';
    char lastCh = '\0' ;
    cout << argv[1] << argv[2] << endl ;
    int count = 0 ;
    do {
        ifs.get(ch) ;
        if( ifs.eof() ) {
            break ;
        }
        cout << ch ;
        if ( ch == ' ' ) {
            count += 1 ;
        }
        else {

            for ( int i = 0 ; i < count ; i += 1 ) {
                ofs.put(' ') ;
            }
            if ( ch == '(' || ch == ')' ) {
                char tempch = ch ;
                ifs.get(ch) ; 
                if ( tempch == '(' ) {
                    if ( ch != ' ' && ch !='\''&& ch !='\"'&& ch !=')' ) {
                        ofs.write("( ",2) ;
                    }
                    else {
                        ofs.put('(') ;
                    }
                }
                else{
                    if ( lastCh != ' ' && lastCh !='\''&& lastCh !='\"'&& lastCh !='(' ) {
                        ofs.write(" )",2) ;
                    }
                    else {
                        ofs.put(')') ;
                    }
                }
                ifs.putback(ch) ;
                ch = tempch ;
            }
            else {
                ofs.put(ch) ;
                count = 0 ;
            }
        }
        if ( count == 4 ) {
            ofs.put(' ') ;
            ofs.put(' ') ;
            count = 0 ;
        }
        lastCh = ch ;
    } while( ! ifs.eof() ) ;
    ifs.close() ;
    ofs.close() ; 
    
}

// author :gaxzipTGO