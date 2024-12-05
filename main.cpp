#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>

#include "Level.h"
#include "Game.h"
#include "Place.h"

#define COUNT_LEVEL 5;

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

    // Создаем кнопку начать игру
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

    // Загружаем изображение уровня №4
    Image imageLVL4;
    if (!imageLVL4.loadFromFile("C:/Users/Karina/Desktop/Curse/img/подвал.png")) {
        std::cerr << "Ошибка загрузки изображения уровня" << std::endl;
        return -1;
    }

    Texture textureLevel;
    textureLevel.loadFromImage(imageLVL4);
    Sprite spriteLevel;
    spriteLevel.setTexture(textureLevel);
    spriteLevel.setPosition(0, 0);

    Texture textureAnswerCage;
    if (!textureAnswerCage.loadFromFile("C:/Users/Karina/Desktop/Curse/img/далматинцы из клетки.jpg")) {
        return -1; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerCage(Vector2f(175, 175));
    ShapeAnswerCage.setTexture(&textureAnswerCage);
    ShapeAnswerCage.setPosition(780, 400);

    Texture buttonTextureCage;
    if (!buttonTextureCage.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgCage.jpg")) {
        return -1; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки клетка
    RectangleShape buttonShapeCage(Vector2f(155, 160)); // Размер кнопки
    buttonShapeCage.setTexture(&buttonTextureCage); // Установка текстуры в прямоугольник
    buttonShapeCage.setPosition(800, 400); // Установка позиции кнопки

    Texture buttonTextureBox;
    if (!buttonTextureBox.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgBox.jpg")) {
        return -1; // Ошибка загрузки текстуры
    }
    // Создание прямоугольника кнопки коробки
    RectangleShape buttonShapeBox(Vector2f(350, 260)); // Размер кнопки
    buttonShapeBox.setTexture(&buttonTextureBox); // Установка текстуры в прямоугольник
    buttonShapeBox.setPosition(373, 200); // Установка позиции кнопки

    Texture buttonTextureBarrel;
    if (!buttonTextureBarrel.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgBarrel.jpg")) {
        return -1; // Ошибка загрузки текстуры
    }
    // Создание прямоугольника кнопки бочек
    RectangleShape buttonShapeBarrel(Vector2f(132, 156)); // Размер кнопки
    buttonShapeBarrel.setTexture(&buttonTextureBarrel); // Установка текстуры в прямоугольник
    buttonShapeBarrel.setPosition(30, 410); // Установка позиции кнопки

    // Создаем текст
    Text codeText(L"О нет! Клетка закрыта на замок! Нужен код!", font, 16);
    codeText.setFillColor(Color::Black); // Цвет текста
    codeText.setPosition(30, 30); // Позиция текста 

    // Создаем кнопку "Я знаю код"
    RectangleShape buttonInputCode(Vector2f(170, 30));
    buttonInputCode.setFillColor(Color::Yellow); //цвет фона кнопки
    buttonInputCode.setPosition(100, 100); // Позиция кнопки по центру

    // Создаем текст кнопки "Я знаю код"
    Text buttonInputCodeText(L"Я знаю код", font, 14);
    buttonInputCodeText.setFillColor(Color::Black); // Цвет текста
    buttonInputCodeText.setPosition(145, 105); // Позиция текста по центру кнопки


    // Создаем кнопку "Получить подсказку"
    RectangleShape buttonHint(Vector2f(170, 30));
    buttonHint.setFillColor(Color::Yellow); //цвет фона кнопки
    buttonHint.setPosition(100, 140); // Позиция кнопки по центру

    // Создаем текст кнопки "Получить подсказку"
    Text buttonHintText(L"Получить подсказку", font, 14);
    buttonHintText.setFillColor(Color::Black); // Цвет текста
    buttonHintText.setPosition(115, 145); // Позиция текста по центру кнопки

    // Создаем текст подсказки
    Text hintText(L"В каком году был создан мультфильм 101 далматинец?", font, 14);
    hintText.setFillColor(Color::Black); // Цвет текста
    hintText.setPosition(10, 10); // Позиция текста 

    // Создаем кнопку "назад"
    RectangleShape buttonToBack(Vector2f(170, 30));
    buttonToBack.setFillColor(Color(192, 192, 192)); //цвет фона кнопки
    buttonToBack.setPosition(100, 140); // Позиция кнопки по центру

    // Создаем текст кнопки "назад"
    Text buttonToBackText(L"Назад", font, 16);
    buttonToBackText.setFillColor(Color::Black); // Цвет текста
    buttonToBackText.setPosition(160, 143); // Позиция текста по центру кнопки

    //Создаём текст увы, тут никого нет
    Text notFoundedText(L"Увы, здесь никого нет!", font, 20);
    notFoundedText.setFillColor(Color::Red); // Цвет текста
    notFoundedText.setPosition(50, 610); // Позиция текста 

    //Создаём текст Поздравляем вы нашли далматинца
    Text FoundedText(L"Поздравляем! Вы нашли далматинца!", font, 20);
    FoundedText.setFillColor(Color::Green); // Цвет текста
    FoundedText.setPosition(50, 610); // Позиция текста 
    // Создаем кнопку "Ввести ->"
    RectangleShape buttonEnter(Vector2f(30, 30));
    buttonEnter.setFillColor(Color::Yellow); //цвет фона кнопки
    buttonEnter.setPosition(270, 70); // Позиция кнопки по центру

    // Создаем текст кнопки "Ввести ->"
    Text buttonEnterText(L"->", font, 17);
    buttonEnterText.setFillColor(Color::Black); // Цвет текста
    buttonEnterText.setPosition(280, 72); // Позиция текста по центру кнопки



    // Переменные для отслеживания текущего состояния игры
    bool isGameStarted = false;
    Level LVL4;
    Place cage = true;
    int place = 0;
    bool dalmatianFound = false;
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
                        if (currentHistoryPage > 3) { // Проверяем, если превышена последняя страница
                            if (event.type == Event::Closed)
                                window.close();
                            LVL4 = true;
                        }
                    }
                    // Проверка нажатия кнопки "Клетка"
                    if (buttonShapeCage.getGlobalBounds().contains(mousePos)) {
                        RenderWindow windowQUESTION(VideoMode(400, 200), "На клетке замок! Нужен код!");
                        while (windowQUESTION.isOpen()) {
                            Event event;
                            while (windowQUESTION.pollEvent(event)) {
                                if (event.type == Event::Closed) {
                                    windowQUESTION.close();
                                }

                                // Проверка нажатия мыши в окне вопроса
                                if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                                    Vector2i mousePos = Mouse::getPosition(windowQUESTION); // Получаем позицию мыши

                                    // Проверяем, нажата ли кнопка buttonHint
                                    if (buttonHint.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                                        RenderWindow windowHint(VideoMode(400, 200), "Подсказка!");
                                        while (windowHint.isOpen()) {
                                            Event hintEvent;
                                            while (windowHint.pollEvent(hintEvent)) {
                                                if (hintEvent.type == Event::Closed) {
                                                    windowHint.close();
                                                }

                                                // Проверка нажатия на кнопку возврата
                                                if (hintEvent.type == Event::MouseButtonPressed && hintEvent.mouseButton.button == Mouse::Left) {
                                                    Vector2i hintMousePos = Mouse::getPosition(windowHint); // Получаем позицию мыши для подсказки
                                                    if (buttonToBack.getGlobalBounds().contains(static_cast<Vector2f>(hintMousePos))) {
                                                        windowHint.close();
                                                    }
                                                }
                                            }
                                            windowHint.clear(Color::White);
                                            windowHint.draw(hintText);
                                            windowHint.draw(buttonToBack);
                                            windowHint.draw(buttonToBackText);
                                            windowHint.display();
                                        }
                                    }
                                    else if (buttonInputCode.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                                        RenderWindow windowInputCode(VideoMode(400, 200), "Введите код!");
                                        while (windowInputCode.isOpen()) {
                                            Event hintEvent;
                                            while (windowInputCode.pollEvent(hintEvent)) {
                                                if (hintEvent.type == Event::Closed) {
                                                    windowInputCode.close();
                                                }
                                                // Проверка нажатия на кнопку возврата
                                                if (hintEvent.type == Event::MouseButtonPressed && hintEvent.mouseButton.button == Mouse::Left) {
                                                    Vector2i hintMousePos = Mouse::getPosition(windowInputCode); // Получаем позицию мыши для подсказки
                                                    if (buttonToBack.getGlobalBounds().contains(static_cast<Vector2f>(hintMousePos))) {
                                                        windowInputCode.close();
                                                    }
                                                }
                                            }
                                            windowInputCode.clear(Color::White);
                                            windowInputCode.draw(hintText);
                                            windowInputCode.draw(buttonToBack);
                                            windowInputCode.draw(buttonToBackText);
                                            windowInputCode.draw(buttonEnter);
                                            windowInputCode.draw(buttonEnterText);
                                            windowInputCode.display();
                                        }
                                    }
                                }
                            }
                            // Отрисовка основного окна вопроса
                            windowQUESTION.clear(Color::White);
                            windowQUESTION.draw(buttonHint);
                            windowQUESTION.draw(buttonHintText);
                            windowQUESTION.draw(codeText);
                            windowQUESTION.draw(buttonInputCode);
                            windowQUESTION.draw(buttonInputCodeText);
                            windowQUESTION.display();
                        }
                        if (!dalmatianFound) {
                            // Первое нажатие, поздравляем с найденным Далматинцем
                            dalmatianFound = true;
                            place = 1; // Устанавливаем место для отрисовки сообщения
                        }
                        else {
                            // Последующие нажатия, выводим сообщение что никого нет
                            place = 2; // Устанавливаем место для отрисовки сообщения
                        }
                    }
                    // Проверка нажатия кнопки "Коробки"
                    if (buttonShapeBarrel.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        place = 2;
                    }
                    // Проверка нажатия кнопки "Коробки"
                    if (buttonShapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        place = 2;
                    }

                    window.display();
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
        if (LVL4.getlvl()) {
            window.draw(spriteLevel);
            window.draw(buttonShapeCage);
            window.draw(buttonShapeBox);
            window.draw(buttonShapeBarrel);
        }
        if (place == 1)
        {
            window.clear();
            window.draw(spriteLevel);
            window.draw(buttonShapeBox);
            window.draw(buttonShapeBarrel);
            window.draw(FoundedText);
            window.draw(ShapeAnswerCage);
        }
        else if (place == 2)
        {
            window.clear();
            window.draw(spriteLevel);
            window.draw(notFoundedText);
            window.draw(buttonShapeCage);
            window.draw(buttonShapeBarrel);
            window.draw(buttonShapeBox);
        }

        window.display();
    }

    return 0;
}
