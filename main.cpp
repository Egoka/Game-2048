#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int arr[4][4];
class ICON {
private:
    string File;
    Image image;
    Texture texture;
public:
    int copy{};
    Sprite sprite;
    explicit ICON(const String& F) {
        File = F;
        image.loadFromFile(File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
    }
    void displacement(int x, int y) {
        sprite.setPosition(22 + 212 * x, 22 + 212 * y); }
};

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