#include "headfilepack_of_cplusplus_compiler_and_running.h"
using namespace std;
string helptext="Use it on terminal: c++cr yourcodename ISO(-std=c++??) compilerandrunningtype(c or r)";
int main(int argc,char* argv[]){
    if(argc==1){
        cout<<"This is a fast c++ compiler and runner.\nUs it: c++cr yourcodename ISO compilerandrunningtype(c or r).\nUse c++cr help to read the help.\nVersion:1.3";
        exit(0);
    }
    if(argc==2){
        string read=argv[1];
        if(read=="help")cout<<helptext<<endl;
        exit(0);
    }
    try{
        if(argc>4){
            throw runtime_error("Too many arguments.");
        }
        if(argc<4){
            throw runtime_error("Too few arguments.");
        }
    }catch(runtime_error& error){
        cout<<error.what()<<endl;
        cout<<"Use c++cr help to read the help."<<endl;
        exit(1);
    }
    int retcode=system(NULL);
    if(retcode==0){
        cerr<<"Sorry.Your computer has no terminal";
        exit(1);
    }
    string compilercodename=argv[1];
    string usinggnutype=argv[2];
    string compilerorrunningtype=argv[3];
    string command=(compilerorrunningtype=="c"?"g++ \""+compilercodename+".cpp\""+" -o \""+compilercodename+".exe\""+" -O2 -std=c++"+usinggnutype:"\""+compilercodename+"\"");
    cout<<(compilerorrunningtype=="c"?"Code begin compiling.":"Code begin running.")<<endl;
    retcode=system(command.c_str());
    if(compilerorrunningtype=="c"){
        if(retcode!=0){
            cout<<"Compiling error!"<<endl;
            exit(1);
        }
        cout<<"Code begin running."<<endl;
        command="\""+compilercodename+"\"";
        system(command.c_str());
    }
    return 0;
}
