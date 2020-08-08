#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int arr[4][4];
int main()
{
    RenderWindow window(VideoMode(870, 870), "2048");
    window.setKeyRepeatEnabled(false);
    Texture pole;
    pole.loadFromFile("img/rash.jpg");
    Sprite sprite(pole);
    for (auto& i : arr)
        for (int& j : i)
            j = 0;
    while (window.isOpen())
    {
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}