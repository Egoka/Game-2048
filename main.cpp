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
    bool copy{};
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
            n.copy = false;
    randomTwo(1, 16);
    ////////////////////////////////////////////////////
    while (window.isOpen())
    {
        Event act{};
        while (window.pollEvent(act))
            if (act.type == Event::Closed) window.close();
        if (Keyboard::isKeyPressed(Keyboard::Left)) {}
        if (Keyboard::isKeyPressed(Keyboard::Right)) {}
        if (Keyboard::isKeyPressed(Keyboard::Up)) {}
        if (Keyboard::isKeyPressed(Keyboard::Down)) {}
        window.clear();
        window.draw(sprite);
        for (auto& h : arr)
            for (int n : h)
                if (n != 0)
                    window.draw(Number[n / 10 - 1][n - (n / 10) * 10 - 1].sprite);
        window.display();
    }
    return 0;
}
void randomTwo(int stepsSum, int numberOfEmptyCells) {
    if (stepsSum > 0) {
        int rows, columns;
        randomСoordinate(rows, columns, numberOfEmptyCells);
        for (int numberCopy = 0; numberCopy < 8; numberCopy++)
            if (!Number[0][numberCopy].copy) {
                Number[0][numberCopy].displacement(columns, rows);
                Number[0][numberCopy].changingArray(rows, columns, 1, numberCopy + 1);
                Number[0][numberCopy].copy = true;
                break;
            }
    }
}
void randomСoordinate(int& rows, int& columns, int numberOfEmptyCells) {
    srand(time(nullptr));
    int randomNumber = 0 + rand() % numberOfEmptyCells, number = 0;
    for (rows = 0; rows <= 3; rows++) {
        for (columns = 0; columns <= 3; columns++)
            if (arr[rows][columns] == 0) {
                if (number == randomNumber) return;
                number++;
            }
    }
}