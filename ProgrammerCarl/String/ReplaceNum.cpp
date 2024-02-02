#include <cstdlib>
#include <iostream>
#include <String>

int main(){
    char temp;
    std::string s = "";
    while((temp = std::cin.get()) != '\n'){
        if(temp - '0' < 9){
            s += "number";
        }        
        else{
            s += temp;
        }
    }
    std::cout << s;
    system("pause");
    
    return 0;
}