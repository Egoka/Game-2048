#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
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
    void changingArray(int x, int y, int h2, int h1) {
        arr[x][y] = h1 + 10 * h2; }
};
ICON Number[16][8] = { {ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg"), ICON("img/2.jpg") },
                       { ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg"), ICON("img/4.jpg") },
                       { ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg"), ICON("img/8.jpg") },
                       { ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg"), ICON("img/16.jpg") },
                       { ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg"), ICON("img/32.jpg") },
                       { ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg"), ICON("img/64.jpg") },
                       { ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg"), ICON("img/128.jpg") },
                       { ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg"), ICON("img/256.jpg") },
                       { ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg"), ICON("img/512.jpg") },
                       { ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg"),ICON("img/1024.jpg")},
                       { ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg"),ICON("img/2048.jpg")},
                       { ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg"),ICON("img/4096.jpg")},
                       { ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg"),ICON("img/8192.jpg")},
                       { ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg"),ICON("img/16384.jpg")},
                       { ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg"),ICON("img/32768.jpg")},
                       { ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg"),ICON("img/65536.jpg")} };
void randomTwo(int, int);
void randomСoordinate(int&, int&, int);

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
    for (auto& h : Number)
        for (auto& n : h)
            n.copy = 0;
    while (window.isOpen())
    {
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}
void randomTwo(int stepsSum, int numberOfEmptyCells) {
    if (stepsSum > 0) {
        int rows, columns;
        randomСoordinate(rows, columns, numberOfEmptyCells);
    }
}
void randomСoordinate(int& rows, int& columns, int numberOfEmptyCells) {
}