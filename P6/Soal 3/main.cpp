#include <iostream>
#include "sekretaris.h"
using namespace std;

int main(){
    Sekretaris* S=new Sekretaris();
    S->buatMemo("Worldasaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","Joe");
    S->buatMemo("World","Ban");
    S->buatMemo("Helloasdasdasdsdasdasdas","Joe");
    S->buatMemo("Worldaaaaaaa","Ban");
    S->buatMemo("awawaw","Ban");
    S->printStatus();
    delete S;
    return 0;
}