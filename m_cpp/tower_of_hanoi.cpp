#include <iostream>
#include <string>
#include <map>
using namespace std;


void towerOfHanoi(int n, string from, string to, string aux){
    if (n == 0){
        return;
    }
    towerOfHanoi(n - 1, from, aux, to );
    cout << "disk " << n << " moved from " << from << " " << to<<endl;
    towerOfHanoi(n - 1, aux, to, from);
}


int main(){
    towerOfHanoi(3, "A", "C", "B");
}


//func (from, to, aux)
//first (from, aux, to)
//second (aux, to, from)