
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
typedef struct { float Re, Im; } Complex;
Complex ComplexAdd(Complex X, Complex Y)
{
    Complex Result;
    Result.Re = X.Re + Y.Re;
    Result.Im = X.Im + Y.Im;
    return Result;
};
Complex ComplexMult(Complex X, Complex Y)
{
    Complex Result;
    Result.Re = X.Re * Y.Re - X.Im * Y.Im;
    Result.Im = X.Re * Y.Im + X.Im * Y.Re;
    return Result;
};
float ComplexAbs(Complex X)
{
    return X.Re * X.Re + X.Im * X.Im;
};
void PutPixel(unsigned int x, unsigned int y, char col, RenderWindow&window) {

}
void main()
{
    const float MinX = -1.5, MinY = -1.5, MaxX = 1.5, MaxY = 1.5; 
    int i, x, y;
    float dx, dy;
    Complex Z, C;
    RenderWindow window(VideoMode(320, 480), "Fractal");
    while (window.isOpen())
    {
        // Обрабатываем события в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }

        printf("Введите действительную часть параметра C: ");
        cin >> C.Re;
        printf("Введите мнимую часть параметра C: ");
        cin >> C.Im;
        dx = (MaxX - MinX) / 320; //приращения аргументов
        dy = (MaxY - MinY) / 480;
        window.clear();
        for (y = 0; y < 480; y++)
            for (x = 0; x < 320; x++) //поточечно вывоодим рисунок
            {
                Z.Re = MinX + x * dx; Z.Im = MinY + y * dy; //Преобразование экранных координат в комплексные
                for (i = 0; (i < 256) & (ComplexAbs(Z) < 4); i++) //Итерационный процесс проверки на принадлежность точки множеству Жулиа
                    Z = ComplexAdd(ComplexMult(Z, Z), C);  //Z(n+1) = Z(n)^2 + C
                Vertex point(sf::Vector2f(10, 10), sf::Color::Blue);
                window.draw(&point, 1, sf::Points);
            };
        window.display();
    }
 }


