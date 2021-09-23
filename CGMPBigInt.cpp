#include "CGMPBigInt.h"
#include <vector>
#include <string.h>

CGMPBigInt::CGMPBigInt()
{
    mpz_init(m_value);
}

CGMPBigInt::CGMPBigInt(const char *str)
{
    mpz_init_set_str(m_value, str, 10);
}

CGMPBigInt::CGMPBigInt(const std::string & str)
{
    mpz_init_set_str(m_value, str.c_str(), 10);
}

CGMPBigInt::CGMPBigInt(uint32_t value)
{
    mpz_init_set_ui(m_value, value);
}

CGMPBigInt::CGMPBigInt(int32_t value)
{
    mpz_init_set_si(m_value, value);
}

CGMPBigInt::CGMPBigInt(uint64_t value)
{
    mpz_init_set_d(m_value, static_cast<double >(value));
}

CGMPBigInt::CGMPBigInt(const CGMPBigInt &other)
{
    mpz_init(m_value);
    mpz_set(m_value, other.m_value);
}

CGMPBigInt::~CGMPBigInt()
{
    mpz_clear(m_value);
}

CGMPBigInt &CGMPBigInt::Add(const CGMPBigInt &other)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_add(temp, m_value, other.m_value);
    mpz_set(m_value, temp);
    mpz_clear(temp);
    return *this;
}

CGMPBigInt &CGMPBigInt::Sub(const CGMPBigInt &other)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_sub(temp, m_value, other.m_value);
    mpz_set(m_value, temp);
    mpz_clear(temp);
    return *this;
}

CGMPBigInt &CGMPBigInt::Mul(const CGMPBigInt &other)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_mul(temp, m_value, other.m_value);
    mpz_set(m_value, temp);
    mpz_clear(temp);
    return *this;
}

CGMPBigInt &CGMPBigInt::Div(const CGMPBigInt &other)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_fdiv_q(temp, m_value, other.m_value);
    mpz_set(m_value, temp);
    mpz_clear(temp);
    return *this;
}

CGMPBigInt &CGMPBigInt::MulRate(float fRatio)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_mul_si(temp, m_value, (long)(fRatio*1000));
    mpz_fdiv_q_ui(m_value, temp, 1000);
    mpz_clear(temp);
    return *this;
}

CGMPBigInt &CGMPBigInt::DivRate(float fRatio)
{
    mpz_t temp;
    mpz_init(temp);
    mpz_fdiv_q_ui(temp, m_value, (long)(fRatio*1000));
    mpz_mul_si(m_value, temp, 1000);
    mpz_clear(temp);
    return *this;
}

void CGMPBigInt::Set(const char * str)
{
    mpz_t temp;
    mpz_init_set_str(temp, str, 10);
    mpz_set(m_value, temp);
    mpz_clear(temp);
}

CGMPBigInt operator + (const CGMPBigInt& a, const CGMPBigInt& b)
{
    CGMPBigInt c;
    mpz_add(c.m_value, a.m_value, b.m_value);
    return c;
}

CGMPBigInt operator - (const CGMPBigInt& a, const CGMPBigInt& b)
{
    CGMPBigInt c;
    mpz_sub(c.m_value, a.m_value, b.m_value);
    return c;
}

CGMPBigInt operator * (const CGMPBigInt& a, const CGMPBigInt& b)
{
    CGMPBigInt c;
    mpz_mul(c.m_value, a.m_value, b.m_value);
    return c;
}

CGMPBigInt operator / (const CGMPBigInt& a, const CGMPBigInt& b)
{
    CGMPBigInt c;
    mpz_fdiv_q(c.m_value, a.m_value, b.m_value);
    return c;
}

CGMPBigInt operator % (const CGMPBigInt& a, const CGMPBigInt& b)
{
    CGMPBigInt c;
    mpz_mod(c.m_value, a.m_value, b.m_value);
    return c;
}

CGMPBigInt &CGMPBigInt::operator=(const CGMPBigInt &other)
{
    if (this != &other)
    {
        mpz_set(m_value, other.m_value);
    }
    return *this;
}

CGMPBigInt &CGMPBigInt::operator = (int32_t value)
{
    mpz_set_si(m_value, value);
    return *this;
}

int CGMPBigInt::ToString(char *str, int base)
{
    mpz_get_str(str, base, m_value);
    return 0;
}

int CGMPBigInt::ToInt()
{
    return mpz_get_si(m_value);
}

unsigned int CGMPBigInt::ToUint()
{
    return mpz_get_ui(m_value);
}


float CGMPBigInt::GetFloatRate(const CGMPBigInt &other) const
{
    if (IsZero() || other.IsZero())
    {
        return 0.0;
    }
    mpz_t t1;
    mpz_t t2;
    mpz_init(t1);
    mpz_init(t2);
    mpz_mul_si(t1, m_value, 1000);
    mpz_fdiv_q(t2, t1, other.m_value);

    long int iFixRatio = mpz_get_si(t2);
    mpz_clear(t1);
    mpz_clear(t2);

    return iFixRatio * 1.0 / 1000;
}

bool CGMPBigInt::IsZero() const
{
    return mpz_sgn(m_value) == 0 ? true : false;
}

bool CGMPBigInt::Equal(const CGMPBigInt &other) const
{
    if (mpz_cmp(m_value, other.m_value) == 0)
    {
        return true;
    }
    return false;
}

bool CGMPBigInt::BiggerOrEqual(const CGMPBigInt &other) const
{
    if (mpz_cmp(m_value, other.m_value) >= 0)
    {
        return true;
    }
    return false;
}

bool CGMPBigInt::Bigger(const CGMPBigInt &other) const
{
    if (mpz_cmp(m_value, other.m_value) > 0)
    {
        return true;
    }
    return false;
}

int CGMPBigInt::Cmp(const CGMPBigInt &other) const
{
    return mpz_cmp(m_value, other.m_value);
}

bool CGMPBigInt::Smaller(const CGMPBigInt &other) const
{
    if (mpz_cmp(m_value, other.m_value) < 0)
    {
        return true;
    }
    return false;
}

bool CGMPBigInt::SmallerOrEqual(const CGMPBigInt &other) const
{
    if (mpz_cmp(m_value, other.m_value) <= 0)
    {
        return true;
    }
    return false;
}

bool operator < (const CGMPBigInt& a, const CGMPBigInt& b)
{
    if (mpz_cmp(a.m_value, b.m_value) < 0)
    {
        return true;
    }
    return false;
}

bool operator > (const CGMPBigInt& a, const CGMPBigInt& b)
{
    if (mpz_cmp(a.m_value, b.m_value) > 0)
    {
        return true;
    }
    return false;
}

bool operator <= (const CGMPBigInt& a, const CGMPBigInt& b)
{
    if (mpz_cmp(a.m_value, b.m_value) <= 0)
    {
        return true;
    }
    return false;
}

bool operator >= (const CGMPBigInt& a, const CGMPBigInt& b)
{
    if (mpz_cmp(a.m_value, b.m_value) >= 0)
    {
        return true;
    }
    return false;
}

void CGMPBigInt::Retrieve(char *src)
{
    mpz_get_str(src, 10, m_value);
}

std::string CGMPBigInt::ToString()
{
	char tmp[256] = { 0 };
	mpz_get_str(tmp, 10, m_value);;
	std::string str(tmp);
    return str;
}
