// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>

using namespace sf;

int main()
{
    setlocale(LC_ALL, "ru");

    /*МЕНЮ*/
    RenderWindow window(VideoMode(1000, 650), "Спасите далматинцев!");

    // Загружаем изображение меню
    Image imageMenu;
    if (!imageMenu.loadFromFile("C:/Users/Karina/Desktop/menu.png")) {
        std::cerr << "Ошибка загрузки изображения меню" << std::endl;
        return -1;
    }

    Texture textureMenu;
    textureMenu.loadFromImage(imageMenu);
    Sprite spriteMenu;
    spriteMenu.setTexture(textureMenu);
    spriteMenu.setPosition(0, 0);

    // Создаем кнопку
    RectangleShape button(Vector2f(200, 50));
    button.setFillColor(Color::White); // Белый цвет фона кнопки
    button.setPosition(60, 500); // Позиция кнопки по центру

    // Загружаем шрифт
    Font font;
    if (!font.loadFromFile("C:/Users/Karina/Desktop/Curse/font/Roboto/Roboto-Black.ttf")) {
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return -1;
    }

    // Создаем текст кнопки
    Text buttonText(L"Начать игру", font, 24);
    buttonText.setFillColor(Color::Blue); // Цвет текста
    buttonText.setPosition(90, 510); // Позиция текста по центру кнопки

    // Создаем текст
    Text nameText(L"Спасите далматинцев!", font, 35);
    nameText.setFillColor(Color::White); // Цвет текста
    nameText.setPosition(90, 60); // Позиция текста 

    /*ПРЕДЫСТОРИЯ*/
    // Загружаем изображение истории 1
    Image imageHistoryOne;
    if (!imageHistoryOne.loadFromFile("C:/Users/Karina/Desktop/Curse/img/стр 1 история.png")) {
        std::cerr << "Ошибка загрузки изображения истории" << std::endl;
        return -1;
    }

    Texture textureHistoryOne;
    textureHistoryOne.loadFromImage(imageHistoryOne);
    Sprite spriteHistoryOne;
    spriteHistoryOne.setTexture(textureHistoryOne);
    spriteHistoryOne.setPosition(0, 0);

    // Загружаем изображение истории 2
    Image imageHistoryTwo;
    if (!imageHistoryTwo.loadFromFile("C:/Users/Karina/Desktop/Curse/img/стр 2 история.png")) {
        std::cerr << "Ошибка загрузки изображения истории" << std::endl;
        return -1;
    }

    Texture textureHistoryTwo;
    textureHistoryTwo.loadFromImage(imageHistoryTwo);
    Sprite spriteHistoryTwo;
    spriteHistoryTwo.setTexture(textureHistoryTwo);
    spriteHistoryTwo.setPosition(0, 0);

    // Загружаем изображение истории 3
    Image imageHistoryThree;
    if (!imageHistoryThree.loadFromFile("C:/Users/Karina/Desktop/Curse/img/стр 3 история.png")) {
        std::cerr << "Ошибка загрузки изображения истории" << std::endl;
        return -1;
    }

    Texture textureHistoryThree;
    textureHistoryThree.loadFromImage(imageHistoryThree);
    Sprite spriteHistoryThree;
    spriteHistoryThree.setTexture(textureHistoryThree);
    spriteHistoryThree.setPosition(0, 0);

    // Загружаем изображение истории 4
    Image imageHistoryFour;
    if (!imageHistoryFour.loadFromFile("C:/Users/Karina/Desktop/Curse/img/стр 4 история.png")) {
        std::cerr << "Ошибка загрузки изображения истории" << std::endl;
        return -1;
    }

    Texture textureHistoryFour;
    textureHistoryFour.loadFromImage(imageHistoryFour);
    Sprite spriteHistoryFour;
    spriteHistoryFour.setTexture(textureHistoryFour);
    spriteHistoryFour.setPosition(0, 0);

    // Создаем кнопку "Далее"
    RectangleShape buttonLast(Vector2f(100, 30));
    buttonLast.setFillColor(Color::White); // Белый цвет фона кнопки
    buttonLast.setPosition(885, 10); // Позиция кнопки по центру

    // Создаем текст кнопки "Далее"
    Text buttonLastText(L"Далее", font, 16);
    buttonLastText.setFillColor(Color::Black); // Цвет текста
    buttonLastText.setPosition(910, 15); // Позиция текста по центру кнопки

    // Переменные для отслеживания текущего состояния игры
    bool isGameStarted = false;
    int currentHistoryPage = 0; // Переменная для отслеживания текущей страницы истории
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

                    // Проверка нажатия кнопки "Начать игру"
                    if (button.getGlobalBounds().contains(mousePos))
                    {
                        isGameStarted = true; // Начинаем игру
                    }

                    // Проверка нажатия кнопки "Далее"
                    if (buttonLast.getGlobalBounds().contains(mousePos) && isGameStarted)
                    {
                        currentHistoryPage++; // Переход к следующей странице истории
                        if (currentHistoryPage > 4) { // Проверяем, если превышена последняя страница
                            //вызываем 1 уровень
                        }
                    }
                }
            }
        }

        window.clear();

        if (isGameStarted) {
            // Отображение текущей страницы истории
            if (currentHistoryPage == 0) {
                window.draw(spriteHistoryOne);
            }
            else if (currentHistoryPage == 1) {
                window.draw(spriteHistoryTwo);
            }
            else if (currentHistoryPage == 2) {
                window.draw(spriteHistoryThree);
            }
            else if (currentHistoryPage == 3) {
                window.draw(spriteHistoryFour);
            }

            window.draw(buttonLast);
            window.draw(buttonLastText);
        }
        else {
            // Отображаем главное меню
            window.draw(spriteMenu);
            window.draw(nameText);
            window.draw(button);
            window.draw(buttonText);
        }

        window.display();
    }

    return 0;
}
