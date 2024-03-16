#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits>
#include <iostream>

int main()
{
    system("color f4");

    char c = 'c';
    char minCharValue = std::numeric_limits<char>::min();
    char maxCharValue = std::numeric_limits<char>::max();
    printf("Char: size %zu \n\t - min val is %d \n \t - max val is %d\n", sizeof(c), minCharValue, maxCharValue);

    bool b = false; // can be {true, false}
    printf("Bool: %zu\n", sizeof(b));

    short s = 10;
    short minShortValue = std::numeric_limits<short>::min();
    short maxShortValue = std::numeric_limits<short>::max();
    printf("Short: size %zu \n\t - min val is %hi \n \t - max val is %hi \n", sizeof(s), minShortValue, maxShortValue);

    int i = -560;
    int minIntValue = std::numeric_limits<int>::min();
    int maxIntValue = std::numeric_limits<int>::max();
    printf("int: size %zu \n\t - min val is %d \n \t - max val is %d \n", sizeof(i), minIntValue, maxIntValue);

    int ui = 560;
    unsigned int minUIntValue = std::numeric_limits<unsigned int>::min();
    unsigned int maxUIntValue = std::numeric_limits<unsigned int>::max();
    printf("unsigned int: size %zu \n\t - min val is %u \n \t - max val is %u \n", sizeof(ui), minUIntValue, maxUIntValue);

    long l = 49509394;
    long minLongValue = std::numeric_limits<long>::min();
    long maxLongValue = std::numeric_limits<long>::max();
    printf("long: size %zu \n\t - min val is %ld \n \t - max val is %ld \n", sizeof(l), minLongValue, maxLongValue);

    long long ll = maxIntValue + 2950458;
    long long minLongLongValue = std::numeric_limits<long long>::min();
    long long maxLongLongValue = std::numeric_limits<long long>::max();
    printf("long long: size %zu \n\t - min val is %lld \n \t - max val is %lld \n", sizeof(ll), minLongLongValue, maxLongLongValue);

    float f = 3.141592653589793238462643383279502884197169399375105820974944592307816406286f;
    float minFloatValue = std::numeric_limits<float>::min();
    float maxFloatValue = std::numeric_limits<float>::max();
    printf("float: %.20f, size %zu \n\t - minmum positive val is %e \n \t - max val is %e \n", f, sizeof(f), minFloatValue, maxFloatValue);

    double d = 3.141592653589793238462643383279502884197169399375105820974944592307816406286;
    double minDoubleValue = std::numeric_limits<double>::min();
    double maxDoubleValue = std::numeric_limits<double>::max();
    printf("double: %.12f, size %zu \n\t - minum positive val is %e \n \t - max val is %e \n", d, sizeof(d), minDoubleValue, maxDoubleValue);

    getchar();

    // pointers
    char* p = &c;
    printf("Pointer to char: %zu\n", sizeof(p));
    printf("Pointer to int: %zu\n", sizeof(int*));
    printf("Pointer to double: %zu\n", sizeof(double*));

    system("pause");
    return 0;
}
