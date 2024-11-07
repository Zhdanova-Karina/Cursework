// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>

using namespace sf;

int main()
{
    setlocale(LC_ALL, "ru");
    RenderWindow window(VideoMode(1000, 650), "Спасите далматинцев!");

    // Загружаем изображение героя
    Image heroimage;
    if (!heroimage.loadFromFile("C:/Users/Karina/Desktop/menu.png")) {
        std::cerr << "Ошибка загрузки изображения" << std::endl;
        return -1;
    }

    Texture herotexture;
    herotexture.loadFromImage(heroimage);
    Sprite herosprite;
    herosprite.setTexture(herotexture);
    herosprite.setPosition(0, 0);

    // Создаем кнопку
    RectangleShape button(Vector2f(200, 50));
    button.setFillColor(Color::White); // Белый цвет фона кнопки
    button.setPosition(60, 500); // Позиция кнопки по центру

    // Загружаем шрифт
    Font font;
    if (!font.loadFromFile("C:/Users/Karina/Desktop/Curse/font/Roboto/Roboto-Black.ttf")) { // Укажите путь к вашему шрифту
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return -1;
    }

    // Создаем текст
    Text buttonText(L"Начать игру", font, 24);
    buttonText.setFillColor(Color::Blue); // Цвет текста
    buttonText.setPosition(90, 510); // Позиция текста по центру кнопки

    // Создаем текст
    Text nameText(L"Спасите далматинцев!", font, 35);
    nameText.setFillColor(Color::White); // Цвет текста
    nameText.setPosition(90, 60); // Позиция текста 
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // Проверка клика мыши
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                    if (button.getGlobalBounds().contains(mousePos))
                    {
                        std::cout << "Кнопка нажата! Начать игру!" << std::endl;
                        // Здесь можно добавить код для начала игры
                    }
                }
            }
        }

        window.clear();
        window.draw(herosprite);
        window.draw(button);
        window.draw(buttonText);
        window.draw(nameText);
        window.display();
    }

    return 0;
}
