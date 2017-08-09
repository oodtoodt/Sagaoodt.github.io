#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

map<char, char>change;

int main(){
    freopen("/Users/ecooodt/Desktop/c++ and acm/_集训/T1/a.txt","r",stdin);
    change['`']='`';
    change['~']='~';
    change['1']='1';
    change['!']='!';
    change['2']='2';
    change['@']='@';
    change['3']='3';
    change['#']='#';
    change['4']='4';
    change['$']='$';
    change['5']='5';
    change['%']='%';
    change['6']='6';
    change['^']='^';
    change['7']='7';
    change['&']='&';
    change['8']='8';
    change['*']='*';
    change['9']='9';
    change['(']='(';
    change['0']='0';
    change[')']=')';
    change['-']='[';
    change['_']='{';
    change['=']=']';
    change['{']='?';
    change['}']='+';
    change['[']='/';
    change[']']='=';
    change['+']='}';
    change['q']='\'';
    change['Q']='"';
    change['w']=',';
    change['W']='<';
    change['e']='.';
    change['E']='>';
    change['r']='p';
    change['R']='P';
    change['t']='y';
    change['T']='Y';
    change['y']='f';
    change['Y']='F';
    change['u']='g';
    change['U']='G';
    change['i']='c';
    change['I']='C';
    change['o']='r';
    change['O']='R';
    change['p']='l';
    change['P']='L';
    change['[']='/';
    change['\\']='\\';
    change['|']='|';
    change['a']='a';
    change['A']='A';
    change['s']='o';
    change['S']='O';
    change['d']='e';
    change['D']='E';
    change['f']='u';
    change['F']='U';
    change['g']='i';
    change['G']='I';
    change['h']='d';
    change['H']='D';
    change['j']='h';
    change['J']='H';
    change['k']='t';
    change['K']='T';
    change['l']='n';
    change['L']='N';
    change[';']='s';
    change[':']='S';
    change['\'']='-';
    change['"']='_';
    change['z']=';';
    change['Z']=':';
    change['x']='q';
    change['X']='Q';
    change['c']='j';
    change['C']='J';
    change['v']='k';
    change['V']='K';
    change['b']='x';
    change['B']='X';
    change['n']='b';
    change['N']='B';
    change['m']='m';
    change['M']='M';
    change[',']='w';
    change['<']='W';
    change['.']='v';
    change['>']='V';
    change['/']='z';
    change['?']='Z';
    change[' ']=' ';
    char c;
    while (1){
        c=getchar();
        if(c == '\r' || c == '\n') printf("\n");
        else if (c==EOF)
            break;
        else{
            printf("%c",change[c]);
        }
    }

    return 0;
}