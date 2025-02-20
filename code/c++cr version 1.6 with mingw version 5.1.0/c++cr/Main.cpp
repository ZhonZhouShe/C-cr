#include "headfilepack_of_cplusplus_compiler_and_running.h"
using namespace std;
const string V="Version:1.6";
const string englishhelptext="c++cr help text\nAdd this exe to the system path,then you can use it on terminal: c++cr yourcodename ISO(-std=c++??) compilerandrunningtype(c or r)\n"+V+"\nThank you for your use it!\n";
const string chinesehelptext="c++cr帮助手册\n您可以将c++cr加入到电脑中的环境变量中，然后您可以在终端中使用以下的命令来使用c++cr：c++cr 你的代码名字（不需要.cpp后缀名，对于具有空格的代码，请将其包含在\"\"中） 代码标准（-std=c++??） 编译运行选项（输入c是编译并运行，r是运行，oc是编译）\n例子： c++cr \"hello world\" 14 c";
bool chinese=false;
int main(int argc,char* argv[]){
    int retcode=system("chcp 65001");
    if(retcode==0){cout<<"中文简体已启用"<<endl;chinese=true;}
    else cout<<"Sorry,your terminal can't use the GDK code";
    if(argc==1){
        if(chinese)
            cout<<"这是一个方便快捷的c++编译运行插件。\n在命令行中使用：c++cr 你代码名字 ISO标准 "
        else   
            cout<<"This is a fast c++ compiler and runner.\nUs it: c++cr yourcodename ISO compilerandrunningtype(c or r).\nUse c++cr help to read the help.\n"+V+"\n";
        exit(0);
    }
    if(argc==2){
        string read=argv[1];
        if(read=="/?" || read=="-?" || read=="-H" || read=="-h" || read=="help" || read=="Help")
            if(chinese)cout<<chinesehelptext<<endl;
            else cout<<englishhelptext<<endl;
        if(read=="/V" ||read=="-V" ||read=="-v" || read=="/v" || read=="version" || read=="Version")cout<<V<<endl;
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
        if(chinese) cout<<"使用c++cr help读取帮助"<<endl;
        else cout<<"Use c++cr help to read the help."<<endl;
        exit(1);
    }
    retcode=system(NULL);
    if(retcode==0){
        cerr<<"Sorry.Your computer has no terminal";
        exit(1);
    }
    string compilercodename=argv[1];
    string usinggnutype=argv[2];
    string compilerorrunningtype=argv[3];
    string command=(compilerorrunningtype=="c"||compilerorrunningtype=="or"?
                    "g++ \""+compilercodename+".cpp\""+" -o \""+compilercodename+".exe\""+" -O2 -std=c++"+usinggnutype :
                    "\""+compilercodename+"\"");
    cout<<(compilerorrunningtype=="c"||compilerorrunningtype=="oc"?"Code begin compiling.":"Code begin running.")<<endl;
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