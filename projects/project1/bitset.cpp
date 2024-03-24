#include "bitset.hpp"

Bitset::Bitset() {
    isValid=true;
    bitArray=new uint8_t[8];
    for(int i=0;i<8;i++){
        bitArray[i]=0;
    }
    sizeofArray = 8;
}

Bitset::Bitset(intmax_t size) {
    if(size>0){
        isValid=true;
    } else {
        isValid=false;
    }
 
    bitArray=new uint8_t[size];
    for(int i=0;i<size;i++){
        bitArray[i]=0;
    }
    sizeofArray = size;
}

Bitset::Bitset(const std::string & value) {
    isValid=true;
    for(char c : value) {
        if(c!='0' && c!='1'){
            isValid=false;
        }
    }

    intmax_t n=value.size();
    bitArray = new uint8_t[n];
    for(int i=0;i<n;i++){
        if(value[i] == '1'){
            bitArray[i] = 1;
        } else {
            bitArray[i] = 0;
        }
    }
    
    sizeofArray = n;
}

Bitset::~Bitset() {
    delete[] bitArray;
}

intmax_t Bitset::size() const{
    return sizeofArray;
}

bool Bitset::good() const{
    return isValid;
}

void Bitset::set(intmax_t index){
    if (index<0 || index>Bitset::size()-1){
        isValid=false;
    }

    bitArray[index]=1;
}

void Bitset::reset(intmax_t index){
    if (index<0 || index>Bitset::size()-1){
        isValid=false;
    }

    bitArray[index]=0;
}

void Bitset::toggle(intmax_t index){
    if (index<0 || index>Bitset::size()-1){
        isValid=false;
    }

    if(bitArray[index]==0){
        bitArray[index]=1;
    }else{
        bitArray[index]=0;
    }
}

bool Bitset::test(intmax_t index){
    if (index<0 || index>Bitset::size()-1){
        isValid=false;
        return isValid;
    }else{
        if(bitArray[index]==1){
            return true;
        }else{
            return false;
        }
    }
}

std::string Bitset::asString() const{
    std::string value;
    for(int i=0;i<Bitset::size();i++){
        if(bitArray[i] == 1){
            value += '1';
        } else {
            value += '0';
        }
    }
    return value;
}
