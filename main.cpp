#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(870, 870), "2048");
    window.setKeyRepeatEnabled(false);
    while (window.isOpen())
    {
        window.clear();
        window.display();
    }
    return 0;
}