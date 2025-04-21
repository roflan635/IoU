#include <iostream>

struct Rect
{
    int x1, y1; // координаты верхнего левого угла области
    int x2, y2; // координаты нижнего правого угла области
};

double IoU(const Rect& region1, const Rect& region2)
{
    Rect small;
    double smallSquare, square1, square2, generalSquare, result;
    if (region1.x2 < region2.x1 && region1.y2 < region2.y1) //проверка на пересечение областей
        return -1;
    square1 = (region1.x2 - region1.x1) * (region1.y2 - region1.y1);
    square2 = (region2.x2 - region2.x1) * (region2.y2 - region2.y1);
    if (region2.x1 <= region1.x1 && region2.y1 <= region1.y1)
    {
        small.x1 = region2.x1; 
        small.y1 = region2.y1; 
        small.x2 = region2.x2; 
        small.y2 = region1.y2;
    }
    else if (region2.x1 >= region1.x1 && region2.y1 >= region1.y1)
    {
        small.x1 = region1.x1; 
        small.y1 = region1.y1; 
        small.x2 = region2.x2; 
        small.y2 = region1.y2;
    }
    else if (region2.x1 >= region1.x1 && region2.y1 >= region1.y1 || region2.x1 <= region1.x1 && region2.y1 <= region1.y1)
    {
        small.x1 = region2.x1 - region1.x1; 
        small.y1 = region1.y1 + region2.y1; 
        small.x2 = region2.x2; 
        small.y2 = region1.y2;
    }
    smallSquare = (small.x2 - small.x1) * (small.y2 - small.y1);
    generalSquare = square1 + square2 - smallSquare;
    return result = smallSquare / generalSquare;
}

int main()
{
    //region1 - объект
    //region2 - фото нейросети
    //Rect r1{ 0,0,30,40 }, r2{ 15,15,120,25 };
    //double result1 = IoU(Rect{ 0,0,5,5 }, Rect{ 2,2,3,3});
    //double result1 = IoU(Rect{ 0,0,1,1 }, Rect{ 2,2,3,3 });
    double result1 = IoU(Rect{ 2,1,4,4 }, Rect{ 2,3,6,6 });
    std::cout << result1 << std::endl;
}
