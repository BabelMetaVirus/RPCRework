#include "SmartArray.h"
void SmartArray::Reallocate(int _bw){
    if(this->bitWidth != _bw){
        this->Clear();
        this->size = _bw / 8;
        this->bitWidth = _bw;
        this->arr = new uint8_t[size];
    }
}
void SmartArray::Clear(void){
    if(this->arr != nullptr){
        delete [] arr;
        this->arr = nullptr;
        this->size = 0;
        this->bitWidth = 0;
    }
}
SmartArray::SmartArray(void){
    this->arr = nullptr;
    this->size = 0;
    this->bitWidth = 0;
}
// Note that these values will be in bits, not in array length.
SmartArray::SmartArray(int _bw){
    this->size = _bw / 8;
    this->bitWidth = _bw;
    this->arr = new uint8_t[this->size];
}
SmartArray::SmartArray(const SmartArray& _cpy){
    this->size = _cpy.size;
    this->bitWidth = _cpy.bitWidth;
    this->arr = new uint8_t[this->size];

    for(int i = 0; i < this->size; i++){
        this->arr[i] = _cpy[i];
    }
}
SmartArray::~SmartArray(void){
    this->Clear();
}
SmartArray& SmartArray::operator= (const SmartArray& _cpy){
    this->Clear();
    this->size = _cpy.size;
    this->bitWidth = _cpy.bitWidth;
    this->arr = new uint8_t[this->size];

    for(int i = 0; i < this->size; i++){
        this->arr[i] = _cpy[i];
    }
    return *this;
}
uint8_t SmartArray::operator[](int n) const{
    return this->arr[n];
}
uint8_t& SmartArray::operator[](int n){
    return this->arr[n];
}
int SmartArray::Size(void){
    return this->size;
}
int SmartArray::Bit(void){
    return this->bitWidth;
}
// TODO: Test this!
void SmartArray::Convert(uint16_t _v){
    if(this->bitWidth < 16){
        this->Reallocate(16);
    }
    for(int i = this->size; i >= 0; i--){
        int shift = (this->size - i) * 8;
        this->arr[i] = (_v >> shift) & 0xff;
    }
}
void SmartArray::Convert(uint32_t _v){
    if(this->bitWidth < 32){
        this->Reallocate(32);
    }
    for(int i = this->size; i >= 0; i--){
        int shift = (this->size - i) * 8;
        this->arr[i] = (_v >> shift) & 0xff;
    }
}
void SmartArray::Convert(uint64_t _v){
    if(this->bitWidth < 64){
        this->Reallocate(64);
    }
    for(int i = this->size; i >= 0; i--){
        int shift = (this->size - i) * 8;
        this->arr[i] = (_v >> shift) & 0xff;
    }
}
void SmartArray::Convert(int64_t _v){
    if(this->bitWidth < 64){
        this->Reallocate(64);
    }
    for(int i = this->size; i >= 0; i--){
        int shift = (this->size - i) * 8;
        this->arr[i] = (_v >> shift) & 0xff;
    }
}
SmartArray::operator uint16_t(void) const{
    uint16_t r = 0;
    for(int i = this->size; i >= 0; i--){
        r = r << 8;
        r += this->arr[i];
    }
    return r;
}
SmartArray::operator uint32_t(void) const{
    uint32_t r = 0;
    for(int i = this->size; i >= 0; i--){
        r = r << 8;
        r += this->arr[i];
    }
    return r;
}
SmartArray::operator uint64_t(void) const{
    uint64_t r = 0;
    for(int i = this->size; i >= 0; i--){
        r = r << 8;
        r += this->arr[i];
    }
    return r;
}
SmartArray::operator int64_t(void) const{
    int64_t r = 0;
    for(int i = this->size; i >= 0; i--){
        r = r << 8;
        r += this->arr[i];
    }
    return r;
}