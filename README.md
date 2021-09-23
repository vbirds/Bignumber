# CGMPBigInt 大整数计算

## Background
大整数类(gmp大整数封装)

## Install

项目使用直接将 `CGMPBigInt.h`、`CGMPBigInt.cpp`、`mini-gmp.h`、`mini-gmp.c`包含到自己项目源文件中即可，
`CGMPBigInt.h` 为大整数封装类，在使用的文件中包含头文件即可使用

```bash
├── CGMPBigInt.cpp  # 大整数封装实现源文件
├── CGMPBigInt.h    # 大整数封装头文件
├── CMakeLists.txt  # 测试工程cmake
├── LICENSE      
├── main.cpp     
├── mini-gmp.c      # gmp 的简化版本，接口和正式的一致，此实现的性能已经远超大部分库，如不想使用库直接用此源文件就可
├── mini-gmp.h      # gmp 的简化版本，接口和正式的一致，此实现的性能已经远超大部分库，如不想使用库直接用此源文件就可
└── README.md
```

## Usage


- 加/减/乘除/取模
    ```c++
        CGMPBigInt& Add(const CGMPBigInt& other);
        CGMPBigInt& Sub(const CGMPBigInt& other);
        CGMPBigInt& Mul(const CGMPBigInt& other);
        CGMPBigInt& Div(const CGMPBigInt& other);
        CGMPBigInt& MulRate(float fRatio);
        CGMPBigInt& DivRate(float fRatio);
        
        friend CGMPBigInt operator + (const CGMPBigInt& a, const CGMPBigInt& b);
        friend CGMPBigInt operator - (const CGMPBigInt& a, const CGMPBigInt& b);
        friend CGMPBigInt operator * (const CGMPBigInt& a, const CGMPBigInt& b);
        friend CGMPBigInt operator / (const CGMPBigInt& a, const CGMPBigInt& b);
        friend CGMPBigInt operator % (const CGMPBigInt& a, const CGMPBigInt& b);
    ```

- 比较大小
    ```c++
        bool IsZero() const;
        bool Equal(const CGMPBigInt& other) const;
        bool BiggerOrEqual(const CGMPBigInt& other) const;
        bool Bigger(const CGMPBigInt& other) const;
        int Cmp(const CGMPBigInt& other) const ;
        bool Smaller(const CGMPBigInt& other) const;
        bool SmallerOrEqual(const CGMPBigInt& other) const;
        
        friend bool operator < (const CGMPBigInt& a, const CGMPBigInt& b);
        friend bool operator > (const CGMPBigInt& a, const CGMPBigInt& b);
        friend bool operator <= (const CGMPBigInt& a, const CGMPBigInt& b);
        friend bool operator >= (const CGMPBigInt& a, const CGMPBigInt& b);
    ```
    
- 输出字符串
    ```c++
        void Retrieve(char src[256]);
        int ToString(char * str, int base = 10);
        std::string ToString();
    ```

## Example
