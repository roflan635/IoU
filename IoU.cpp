#include <iostream>
#include <vector>
#include <algorithm>    //используется для сортировки

struct Rect
{
    int x1, y1; // координаты верхнего левого угла области
    int x2, y2; // координаты нижнего правого угла области
};

double IoU(const Rect& region1, const Rect& region2)
{
    Rect small; //создание структуры, в которую будут вноситься координаты пересечения прямоугольных областей
    double smallSquare, square1, square2, generalSquare, result;
    std::vector <int> regX{ region1.x1, region1.x2, region2.x1, region2.x2 };   //создание вектора с координатами по оси X и сортировка по возрастанию для того, чтобы всегда выбирать 1 и 2 координаты
    std::sort(regX.begin(), regX.end());
    std::vector <int> regY{ region1.y1, region1.y2, region2.y1, region2.y2 };   //создание вектора с координатами по оси Y и сортировка по возрастанию для того, чтобы всегда выбирать 1 и 2 координаты
    std::sort(regY.begin(), regY.end());
    if (region1.x2 < region2.x1 && region1.y2 < region2.y1) //проверка на пересечение областей
        return -1;
    small.x1 = regX[1];
    small.x2 = regX[2];
    small.y1 = regY[1];
    small.y2 = regY[2];
    square1 = (region1.x2 - region1.x1) * (region1.y2 - region1.y1);
    square2 = (region2.x2 - region2.x1) * (region2.y2 - region2.y1);
    smallSquare = (small.x2 - small.x1) * (small.y2 - small.y1);
    generalSquare = square1 + square2 - smallSquare;
    return result = smallSquare / generalSquare;
}

int main()
{
    //region1 - объект
    //region2 - фото нейросети
    //Rect r1{ 0,0,30,40 }, r2{ 15,15,120,25 };
    //double result1 = IoU(Rect{ 0,0,5,5 }, Rect{ 2,2,3,3});    //0,04
    //double result1 = IoU(Rect{ 0,0,1,1 }, Rect{ 2,2,3,3 });   //не пересекаются
    //double result1 = IoU(Rect{ 2,3,6,6 }, Rect{ 2,1,4,4 });   //0,125
    //double result1 = IoU(Rect{ 3,1,6,4 }, Rect{ 2,2,7,3 });   //0,272727
    double result1 = IoU(Rect{ 1,1,2,2 }, Rect{ 1,1,2,2 });   //1
    std::cout << result1 << std::endl;
}
