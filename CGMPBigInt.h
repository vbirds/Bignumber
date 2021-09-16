#pragma once

#include "mini-gmp.h"
//#include "gmp.h"
#include <stdint.h>
#include <string>

class CGMPBigInt
{
public:
    explicit CGMPBigInt();
    explicit CGMPBigInt(const char * str);
    explicit CGMPBigInt(const std::string & str);
    CGMPBigInt(uint32_t value);
    CGMPBigInt(int32_t value);
    CGMPBigInt(uint64_t value);
    CGMPBigInt(const CGMPBigInt & other);

    ~CGMPBigInt();

public:
    CGMPBigInt& Add(const CGMPBigInt& other);
    CGMPBigInt& Sub(const CGMPBigInt& other);
    CGMPBigInt& Mul(const CGMPBigInt& other);
    CGMPBigInt& Div(const CGMPBigInt& other);
    CGMPBigInt& MulRate(float fRatio);
    CGMPBigInt& DivRate(float fRatio);

    void Set(const char * str);

    CGMPBigInt &operator = (const CGMPBigInt & other);
    CGMPBigInt &operator = (int32_t value);
    friend CGMPBigInt operator + (const CGMPBigInt& a, const CGMPBigInt& b);
    friend CGMPBigInt operator - (const CGMPBigInt& a, const CGMPBigInt& b);
    friend CGMPBigInt operator * (const CGMPBigInt& a, const CGMPBigInt& b);
    friend CGMPBigInt operator / (const CGMPBigInt& a, const CGMPBigInt& b);
    friend CGMPBigInt operator % (const CGMPBigInt& a, const CGMPBigInt& b);

    friend bool operator < (const CGMPBigInt& a, const CGMPBigInt& b);
    friend bool operator > (const CGMPBigInt& a, const CGMPBigInt& b);
    friend bool operator <= (const CGMPBigInt& a, const CGMPBigInt& b);
    friend bool operator >= (const CGMPBigInt& a, const CGMPBigInt& b);

    void Retrieve(char src[256]);
    int ToString(char * str, int base = 10);
    std::string ToString();

    int ToInt();
    unsigned int ToUint();
    float GetFloatRate(const CGMPBigInt& other) const;

    bool IsZero() const;
    bool Equal(const CGMPBigInt& other) const;
    bool BiggerOrEqual(const CGMPBigInt& other) const;
    bool Bigger(const CGMPBigInt& other) const;
    int Cmp(const CGMPBigInt& other) const ;
    bool Smaller(const CGMPBigInt& other) const;
    bool SmallerOrEqual(const CGMPBigInt& other) const;


private:
    mpz_t m_value;
};


