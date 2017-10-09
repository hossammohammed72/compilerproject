#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{   ifstream in ("in.txt");
    ofstream out ("out.txt");

    /*
    a b c d e  26
    0 1 2 9 #
    */
    char chr[] = {'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_','$'};
    char digit[]= {'0','1','2','3','4','5','6','7','8','9'};
    char oper[] = {'+','-','/','*'};
    char spce[] = {'\'','\"',':','{','}','[',']','(',')'};
    string keywords = {"if","set","as","then"};
    string loper[] = {"&&",">","<","==","!=","||","!"} ;
    string type[] = {"int","char"};
    string temp ;

    while( !in.eof()){
    bool contflag = false;
    in >> temp  ;
    if(in.eof()) break;
    cout << temp << endl ;
    for(int i =0;i<(sizeof type)/32 ; i++)
        if(temp == type[i]){
            out << "<dataType " + type[i] << ">"<< endl ;
            contflag = true; }

    for(int i=0;i<(sizeof loper)/32;i++)
        if(temp==loper[i]){
            out << "<logicalOperator "+temp << ">"<< endl;
            contflag = true; }
       if (contflag) {continue;}
    //btbd2 7rf 7rf
    pair<string,string> x ;
    bool cflag, nflag;
    for(int i=0 ; i<temp.length();i++){
        cflag = false;
        nflag = false ;
        for(int j=0;j<(sizeof digit) ; j++){
                if(temp[i] == digit[j]) {
                    nflag = true;
                    x.second+= temp[i];
                    if(x.first != "word")
                    x.first = "number";
                    else{
                        nflag = false ;
                        cflag = true ;
                        }
                }
            }
          for(int j=0;j<sizeof chr ; j++){
                if(temp[i] == chr[j]) {
                cflag = true ;
                x.second+= temp[i];
                if(x.first == "number")
                {
                    out << "error wrong format"<<endl;return 0 ;
                }
                x.first = "word";
                }

            }
          if (nflag == false && cflag == false) {
                if(x.second !=""){
            out << "<" + x.first + " " + x.second + ">" << endl;
            x.first = "";
            x.second = "";}
            if(temp[i] == ';')
            out << "<terminal ;>"<<endl;
            if(temp[i]=='=')
                out << "<assign =>"<<endl ;
            for(int k=0;k<sizeof oper ; k++){
                if(temp[i]==oper[k]){

                    out << "<operator " << oper[k] << ">"<<endl ;}
            }
          }

    }
    if(nflag){
    nflag = false ;
    out << "<number "+x.second+">"<<endl;
    x.second="";
    }
    if(cflag){
    nflag = false ;
    out << "<word "+x.second+">"<<endl;
    x.second="";
    }


    }


    return 0;
}
