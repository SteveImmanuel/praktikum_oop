#include <iostream>
#include "RestoranRamen.hpp"

using namespace std;

int main(){
    RestoranRamen R;
    R.cetakMeja();
    R.tambahOrder(1,50000);
    R.tambahOrder(2,10000);
    R.tambahOrder(3,44000);
    R.tambahOrder(1,30000);
    R.tambahOrder(4,50000);
    R.cetakMeja();
    return 0;
}