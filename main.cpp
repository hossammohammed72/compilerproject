#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
void lexical();
string line;
vector <string> statement ;
void getwords(string *words);
void syntax();
bool term(int i){
if(i==statement.size())
    return false ;
if(statement[i]=="terminal" && (statement[i-1] == "word" || statement[i-1] == "number") )
    return true ;
else if(statement[i]=="operator" && (statement[i-1] == "word" || statement[i-1] == "number") )
return true ;
else
    return false ;
}
int main(){
    lexical();
    syntax();
    return 0;
    }
void lexical(){
    ifstream in ("in.txt");
    ofstream out ("lexicalOut.txt");

    /*
    a b c d e  26
    0 1 2 9 #
    */
    char chr[] = {'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','_','$'};
    char digit[]= {'0','1','2','3','4','5','6','7','8','9'};
    char oper[] = {'+','-','/','*'};
    char spec[] = {'(',')'};
    string keywords[] = {"set","as"};
    string loper[] = {"&&",">","<","==","!=","||","!"} ;
    string type[] = {"int","char"};
    string temp ;
    // starts reading the file
    while( !in.eof()){
        bool globalflag = false ;
        bool contflag = false;
        //reads a word.
        in >> temp  ;
    //breaks if end of file
        if(in.eof()) break;
    // debugging
        cout << temp << endl ;
   // check if the word is a reserved data type
        for(int i =0;i<(sizeof type)/32 ; i++)
            if(temp == type[i]){
                out << "<dataType " + type[i] << ">"<< endl ;
                contflag = true;
                 }
   // check if the word is a reserved keyword
        for(int i =0;i<(sizeof keywords)/32 ; i++)
            if(temp == keywords[i]){
                out << "<keyWord " + keywords[i] << ">"<< endl ;
                contflag = true;
                }
   // check if the word is a reserved logical operator

        for(int i=0;i<(sizeof loper)/32;i++)
            if(temp==loper[i]){
                out << "<logicalOperator "+temp << ">"<< endl;
                contflag = true; }
        if (contflag) {continue;}
    //btbd2 7rf 7rf
        pair<string,string> x ;
        bool cflag, nflag;
        for(int i=0 ; i<temp.length();i++){
            globalflag = false ;
            cflag = false;
            nflag = false ;
            for(int j=0;j<(sizeof digit) ; j++){
                    if(temp[i] == digit[j]) {
                        nflag = true;
                        globalflag = true ;
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
                    globalflag = true ;
                    x.second+= temp[i];
                    x.first = "word";
                    }

                }
              if (nflag == false && cflag == false) {
                    if(x.second !=""){
                        out << "<" + x.first + " " + x.second + ">" << endl;
                        x.first = "";
                        x.second = "";}
                    if(temp[i] == ';'){
                        out << "<terminal ;>"<<endl;
                         globalflag = true ;
                        }
                    if(temp[i]=='='){
                        out << "<assign =>"<<endl ;
                         globalflag = true ;
                        }
                    for(int k=0;k<sizeof oper ; k++){
                        if(temp[i]==oper[k]){
                            globalflag = true ;
                            out << "<operator " << oper[k] << ">"<<endl ;}
                    }
                     for(int k=0;k<sizeof spec ; k++){
                        if(temp[i]==spec[k]){
                            globalflag = true ;
                            out << "<specialChar " << spec[k] << ">"<<endl ;}
                    }
              }
                if(!globalflag) {
        out << "Error: undefined token \n";
        }


        }
        if(nflag){
            nflag = false ;
            out << "<number "+x.second+">"<<endl;
            x.second="";
        }
        else if(cflag){
            nflag = false ;
            out << "<word "+x.second+">"<<endl;
            x.second="";
        }


    }


}
void getwords(string *words){
int cnt = 0 ;
for(int i=0;i<line.length() && cnt < 3;i++)
    if( line[i] != ' ' )
    words[cnt]+= line[i];
    else
        cnt++;

}
void syntax(){
  ifstream in ("lexicalOut.txt");
  ofstream out ("Errors.txt");
    int numlines = 0 ;
    while(getline(in,line)){
        string words[3];
        getwords(words);
        if(words[0][0] == 'E');
        else if (words[0][0]=='<'){
            string toktype = words[0].substr(1);
        if(toktype != "terminal")
            statement.push_back(toktype);
        else{
            numlines++;
            statement.push_back(toktype);
            if(statement[0] == "dataType"){
                if ( statement.size() > 2 && statement[1] == "word" && statement[2] == "terminal");
                else if (statement.size()> 4 && statement[1] == "word" && statement[2] == "assign"){
                   if(!term(4) )
                    out <<"Syntax Error in line (" <<numlines << ")"<< endl ;
                }
                else  {
                out <<"Syntax Error in line (" <<numlines << ")"<< endl ;
                }
            }else if (statement.size() > 3 && statement[0] =="word" && statement[1] == "assign"){
            if(!term(3))
            out <<"Syntax Error in line (" <<numlines << ")"<< endl ;
            }else {
            out <<"Syntax Error in line (" <<numlines << ")"<< endl ;
            }
            statement.clear();
            }

        }
    line.clear();
    }
}
