#pragma once

struct ssVector;
template<typename T> class ssList;

// SuperScript's compact owning string. The instance layout is fixed by PDB
// type 13285; the standalone recovery uses the CRT heap until the original
// idGameSuperInterface allocator is reconstructed.
class ssString {
public:
    ssString();
    explicit ssString(const char* text);
    explicit ssString(int value);
    ssString(float value, int precision);
    ssString(const ssVector& value, const char* format);
    ssString(const ssList<int>& values, const char* separator);
    ssString(const ssString& text);
    ~ssString();

    int Cmp(const char* text) const;
    static int Icmp(const char* text, const char* text2);
    int Find(char value, int start = 0) const;
    int Find(const ssString& value, int start = 0) const;

    void ToLower();
    void ToUpper();
    void Empty();
    void Reverse();

    void operator=(const ssString& text);
    void operator=(const char* text);
    void operator=(char value);
    char& operator[](int index);
    const char& operator[](int index) const;

    ssString Left(int count) const;
    ssString Right(int count) const;
    ssString Skip(int count) const;
    ssString Mid(int start, int count) const;

    void Append(char value);
    void Append(const ssString& value);
    void Append(const char* value);

    const char* c_str() const { return data != nullptr ? data : ""; }
    int Length() const { return len; }

    int len;
    char* data;
    int alloced;
    int threadId;

private:
    void Init();
    void Allocate(int count);
    void EnsureAllocated(int count);
};

ssString operator+(const ssString& lhs, const ssString& rhs);
ssString operator+(const ssString& lhs, const char* rhs);
ssString operator+(const char* lhs, const ssString& rhs);

#if defined(_WIN32) && !defined(_WIN64)
static_assert(sizeof(ssString) == 16,
    "Recovered SuperScript string ABI changed");
#endif
