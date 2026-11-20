#include <iostream>
#include <windows.h>
#include "Fraction.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=======================================================" << endl;
    cout << " 1. ¡¿«Œ¬»…  À¿— Array (≥Ì‰ÂÍÒÛ‚‡ÌÌˇ Ú‡ rangeCheck)" << endl;
    cout << "=======================================================" << endl;

    Array a1(4, 3); // 3333
    cout << "a1 (≥Ì≥ˆ≥‡Î≥Á‡ˆ≥ˇ): " << a1 << endl;
    a1[0] = 9;
    a1[3] = 1;
    cout << "a1 Ô≥ÒÎˇ ÁÏ≥ÌË ˜ÂÂÁ []: " << a1 << endl;
    cout << "rangeCheck(2): " << (a1.rangeCheck(2) ? "‚ ÏÂÊ‡ı" : "ÔÓÁ‡ ÏÂÊ‡ÏË") << endl;
    cout << "rangeCheck(10): " << (a1.rangeCheck(10) ? "‚ ÏÂÊ‡ı" : "ÔÓÁ‡ ÏÂÊ‡ÏË") << endl;

    cout << "\n=======================================================" << endl;
    cout << " 2. —“¬Œ–≈ÕÕﬂ Œ¡'™ “≤¬ “¿ Ã¿—»¬≤¬ Fraction" << endl;
    cout << "=======================================================" << endl;

    Fraction fDefault;                 //  ÓÌÒÚÛÍÚÓ ·ÂÁ ‡„ÛÏÂÌÚ≥‚ (0.0)
    Fraction fInit(4, 2, '-', 5);      //  ÓÌÒÚÛÍÚÓ ≥Ì≥ˆ≥‡Î≥Á‡ˆ≥ø (-55.55)
    Fraction fStr1("12.75");           //  ÓÌÒÚÛÍÚÓ ≥Á ˇ‰Í‡
    Fraction fStr2("-3.25");
    Fraction fCopy(fStr1);             //  ÓÌÒÚÛÍÚÓ ÍÓÔ≥˛‚‡ÌÌˇ
    Fraction* fDyn = new Fraction("0.50"); // ƒËÌ‡Ï≥˜ÌËÈ Ó·'∫ÍÚ

    cout << "fDefault: " << fDefault << endl;
    cout << "fInit:    " << fInit << endl;
    cout << "fStr1:    " << fStr1 << endl;
    cout << "fStr2:    " << fStr2 << endl;
    cout << "fCopy:    " << fCopy << endl;
    cout << "*fDyn:    " << *fDyn << endl;

    // ƒÓÒÚÛÔ ‰Ó ÓÍÂÏÓø ˆËÙË ˜ÂÂÁ ÛÒÔ‡‰ÍÓ‚‡ÌËÈ operator[]
    cout << "ÃÓÎÓ‰¯‡ ˆËÙ‡ fStr1[0]: " << (int)fStr1[0] << endl;
    cout << "œË‚Â‰ÂÌÌˇ ‰Ó string:   " << string(fStr1) << endl;

    delete fDyn;

    cout << "\n=======================================================" << endl;
    cout << " 3. ¿–»‘Ã≈“» ¿ “¿ Œœ≈–¿÷≤Ø « œ–»—¬Œﬁ¬¿ÕÕﬂÃ" << endl;
    cout << "=======================================================" << endl;

    cout << fStr1 << " + " << fStr2 << " = " << (fStr1 + fStr2) << endl;
    cout << fStr1 << " - " << fStr2 << " = " << (fStr1 - fStr2) << endl;
    cout << fStr1 << " * " << fStr2 << " = " << (fStr1 * fStr2) << endl;

    Fraction fAcc("10.00");
    fAcc += Fraction("2.50");
    cout << "10.00 += 2.50  -> " << fAcc << endl;
    fAcc -= Fraction("4.25");
    cout << "12.50 -= 4.25  -> " << fAcc << endl;
    fAcc *= Fraction("2.00");
    cout << "8.25  *= 2.00  -> " << fAcc << endl;

    cout << "\n=======================================================" << endl;
    cout << " 4. Œœ≈–¿÷≤Ø œŒ–≤¬ÕﬂÕÕﬂ" << endl;
    cout << "=======================================================" << endl;

    cout << fStr1 << " == " << fCopy << " : " << (fStr1 == fCopy ? "“‡Í" : "Õ≥") << endl;
    cout << fStr1 << " != " << fStr2 << " : " << (fStr1 != fStr2 ? "“‡Í" : "Õ≥") << endl;
    cout << fStr1 << " >  " << fStr2 << " : " << (fStr1 > fStr2 ? "“‡Í" : "Õ≥") << endl;
    cout << fStr2 << " <  " << fStr1 << " : " << (fStr2 < fStr1 ? "“‡Í" : "Õ≥") << endl;

    cout << "\n=======================================================" << endl;
    cout << " 5. Ã¿—»¬ Œ¡'™ “≤¬ “¿ ¬¬≈ƒ≈ÕÕﬂ «  À¿¬≤¿“”–»" << endl;
    cout << "=======================================================" << endl;

    Fraction arr[2];
    cout << "¬‚Â‰≥Ú¸ ÔÂ¯ËÈ ‰≥· (Ì‡ÔËÍÎ‡‰, 4.25 ‡·Ó -1.5): ";
    cin >> arr[0];
    cout << "¬‚Â‰≥Ú¸ ‰Û„ËÈ ‰≥·: ";
    cin >> arr[1];

    cout << "\n¬‚Â‰ÂÌ≥ ÁÌ‡˜ÂÌÌˇ:" << endl;
    cout << "arr[0] = " << arr[0] << endl;
    cout << "arr[1] = " << arr[1] << endl;
    cout << "—ÛÏ‡ arr[0] + arr[1] = " << (arr[0] + arr[1]) << endl;

    return 0;
}