#include <iostream>

struct Rect
{
    int x1, y1; // координаты верхнего левого угла области
    int x2, y2; // координаты нижнего правого угла области
};

double IoU(const Rect& region1, const Rect& region2)
{
    // ... Разместите здесь свой код
}

int main()
{
    Rect r1{ 0,0,30,40 }, r2{ 15,15,120,25 };
    double result1 = IoU(Rect{ 0,0,5,5 }, Rect{ 2,2,3,3, });
}

