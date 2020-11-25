#ifndef _SMARTARRAY_H_
#define _SMARTARRAY_H_
#include <fcntl.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
class SmartArray{
    private: 
    uint8_t* arr;           // The array itself.
    int size;               // Size value to check for array value.
    int bitWidth;           // Size of the array in bitsize.
    void Clear(void);
    void Reallocate(int);
    public:
    SmartArray(void);
    // Note that these values will be in bits, not in array length.
    SmartArray(int);
    SmartArray(const SmartArray&);
    ~SmartArray(void);
    SmartArray& operator= (const SmartArray&);
    uint8_t operator[](int) const;
    uint8_t& operator[](int);
    int Size(void);
    int Bit(void);
    void Convert(uint16_t);
    void Convert(uint32_t);
    void Convert(uint64_t);
    void Convert(int64_t);
    operator uint16_t(void) const;
    operator uint32_t(void) const;
    operator uint64_t(void) const;
    operator int64_t(void) const;
};

#endif