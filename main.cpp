#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(870, 870), "2048");
    window.setKeyRepeatEnabled(false);
    Texture pole;
    pole.loadFromFile("img/rash.jpg");
    Sprite sprite(pole);
    while (window.isOpen())
    {
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}