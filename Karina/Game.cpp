// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>

#include "Dalmatin.h"
#include "Level.h"
#include "Game.h"

#define COUNT_LEVEL 5;

using namespace sf;
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    /*МЕНЮ*/
    RenderWindow window(VideoMode(1000, 650), "Спасите далматинцев!");

    // Загружаем изображение меню
    Image imageMenu;
    if (!imageMenu.loadFromFile("C:/Users/Karina/Desktop/menu.png")) {
        cerr << "Ошибка загрузки изображения меню" << endl;
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
    button.setPosition(100, 100); // Позиция кнопки по центру

    // Загружаем шрифт
    Font font;
    if (!font.loadFromFile("C:/Users/Karina/Desktop/Curse/font/Roboto/Roboto-Black.ttf")) {
        cerr << "Ошибка загрузки шрифта" << endl;
        return -1;
    }

    // Создаем текст кнопки
    Text buttonText(L"Начать игру", font, 24);
    buttonText.setFillColor(Color::Blue); // Цвет текста
    buttonText.setPosition(130, 110); // Позиция текста по центру кнопки

    // Создаем текст
    Text nameText(L"Спасите далматинцев!", font, 35);
    nameText.setFillColor(Color::White); // Цвет текста
    nameText.setPosition(40, 30); // Позиция текста 

    /*ПРЕДЫСТОРИЯ*/
    // Загружаем изображение истории 1
    Image imageHistoryOne;
    if (!imageHistoryOne.loadFromFile("C:/Users/Karina/Desktop/Curse/img/стр 1 история.png")) {
        cerr << "Ошибка загрузки изображения истории" << endl;
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
        cerr << "Ошибка загрузки изображения истории" << endl;
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
        cerr << "Ошибка загрузки изображения истории" << endl;
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
        cerr << "Ошибка загрузки изображения истории" << endl;
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

    // Загружаем изображение уровня №3
    Image imageLVL3;
    if (!imageLVL3.loadFromFile("C:/Users/Karina/Desktop/Curse/img/спальня.png")) {
        cerr << "Ошибка загрузки изображения уровня" << endl;
        return -1;
    }

    Texture textureLevel_3;
    textureLevel_3.loadFromImage(imageLVL3);
    Sprite spriteLevel_3;
    spriteLevel_3.setTexture(textureLevel_3);
    spriteLevel_3.setPosition(0, 0);

    Texture buttonTextureBed;
    if (!buttonTextureBed.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgBed.png")) {
        return -1; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки кровать
    RectangleShape buttonShapeBed(Vector2f(455, 360)); // Размер кнопки
    buttonShapeBed.setTexture(&buttonTextureBed); // Установка текстуры в прямоугольник
    buttonShapeBed.setPosition(570, 220); // Установка позиции кнопки

    Texture buttonTextureCloset;
    if (!buttonTextureCloset.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgCloset.png")) {
        return -1; // Ошибка загрузки текстуры
    }

    /*Далматинцы из кровати*/
    Texture textureAnswerBed;
    if (!textureAnswerBed.loadFromFile("C:/Users/Karina/Desktop/Curse/img/Ролли.png")) {
        return -1; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerBed(Vector2f(175, 175));
    ShapeAnswerBed.setTexture(&textureAnswerBed);
    ShapeAnswerBed.setPosition(750, 300);

    // Создание прямоугольника кнопки ШКАФ
    RectangleShape buttonShapeCloset(Vector2f(200, 460)); // Размер кнопки
    buttonShapeCloset.setTexture(&buttonTextureCloset); // Установка текстуры в прямоугольник
    buttonShapeCloset.setPosition(45, 130); // Установка позиции кнопки

    Texture buttonTextureDoor;
    if (!buttonTextureDoor.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgDoor.png")) {
        return -1; // Ошибка загрузки текстуры
    }

    /*Далматинцы из шкафа*/
    Texture textureAnswerCloset;
    if (!textureAnswerCloset.loadFromFile("C:/Users/Karina/Desktop/Curse/img/Патч.png")) {
        return -1; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerCloset(Vector2f(175, 175));
    ShapeAnswerCloset.setTexture(&textureAnswerCloset);
    ShapeAnswerCloset.setPosition(60, 400);

    // Создание прямоугольника кнопки ДВЕРЬ
    RectangleShape buttonShapeDoor(Vector2f(150, 360)); // Размер кнопки
    buttonShapeDoor.setTexture(&buttonTextureDoor); // Установка текстуры в прямоугольник
    buttonShapeDoor.setPosition(550, 70); // Установка позиции кнопки

    Texture buttonTextureShelf;
    if (!buttonTextureShelf.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgShelf.png")) {
        return -1; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки ПОЛКА
    RectangleShape buttonShapeShelf(Vector2f(200, 200)); // Размер кнопки
    buttonShapeShelf.setTexture(&buttonTextureShelf); // Установка текстуры в прямоугольник
    buttonShapeShelf.setPosition(800, 30); // Установка позиции кнопки

    Texture buttonTextureCarpet;
    if (!buttonTextureCarpet.loadFromFile("C:/Users/Karina/Desktop/Curse/img/imgCarpet.png")) {
        return -1; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника КОВЁР
    RectangleShape buttonShapeCarpet(Vector2f(620, 140)); // Размер кнопки
    buttonShapeCarpet.setTexture(&buttonTextureCarpet); // Установка текстуры в прямоугольник
    buttonShapeCarpet.setPosition(150, 450); // Установка позиции кнопки

    //Создаём текст найдено:
    Text FoundText(L"Найдено: 0", font, 25);
    FoundText.setFillColor(Color::White); // Цвет текста
    FoundText.setPosition(800, 600); // Позиция текста 

    // Создаем кнопку следующий уровень
    RectangleShape buttonLastLVL(Vector2f(250, 50));
    buttonLastLVL.setFillColor(Color::White); // Белый цвет фона кнопки
    buttonLastLVL.setPosition(740, 590); // Позиция кнопки по центру

    // Создаем текст кнопки следующий уровень
    Text buttonLastLVLText(L"Следующий уровень", font, 24);
    buttonLastLVLText.setFillColor(Color::Black); // Цвет текста
    buttonLastLVLText.setPosition(747, 600); // Позиция текста по центру кнопки

    // Загружаем изображение уровня №4
    Image imageLVL4;
    if (!imageLVL4.loadFromFile("C:/Users/Karina/Desktop/Curse/img/подвал.png")) {
        cerr << "Ошибка загрузки изображения уровня" << endl;
        return -1;
    }

    Texture textureLevel_4;
    textureLevel_4.loadFromImage(imageLVL4);
    Sprite spriteLevel_4;
    spriteLevel_4.setTexture(textureLevel_4);
    spriteLevel_4.setPosition(0, 0);

    /*Далматинцы из клетки*/
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
    // 2. Создание текстового поля
    RectangleShape inputBox(Vector2f(170, 30)); // Размеры поля
    inputBox.setFillColor(Color::White);
    inputBox.setOutlineThickness(1);
    inputBox.setOutlineColor(Color::Black);
    inputBox.setPosition(100, 70); // Позиция поля ввода

    // 3. Создание текстового объекта для отображения введенного текста
    Text inputText("", font, 14); // Крупный шрифт
    inputText.setFillColor(Color::Black);
    inputText.setPosition(120, 72); // Позиция текста внутри поля

    string inputString = ""; // Логика хранения вводимого текста
    bool isInputActive = false; // Флаг для определения состояния ввода
    string correctCode = "1996"; // Правильный код
    Color cellColor; // Цвет ячейки
    // Переменные для отслеживания текущего состояния игры
    Game isGameStarted = false;
    int dalmatinCount = 0;
    Level LVL4;
    Level LVL3;
    int placeLVL3 = 0;
    int placeLVL4 = 0;

    Dalmatin Patch=false;
    Dalmatin Rolly = false;
    Dalmatin dalmatins = false;
    bool questionWindowOpened = false; // Флаг для отслеживания открытия окна с вопросом
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
                    if (buttonLast.getGlobalBounds().contains(mousePos) && isGameStarted.getGame())
                    {
                        currentHistoryPage++; // Переход к следующей странице истории
                        if (currentHistoryPage > 3) { // Проверяем, если превышена последняя страница
                            if (event.type == Event::Closed)
                                window.close();
                            LVL3 = true;
                        }
                    }
                    // Проверка нажатия кнопки "КРОВАТЬ"
                    if (buttonShapeBed.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (!Patch.getDalmatinFound()) {
                            // Первое нажатие, поздравляем с найденным Далматинцем
                            Patch = true;
                            dalmatinCount++;
                            placeLVL3 = 1; // Устанавливаем место для отрисовки сообщения
                            FoundText.setString(L"Найдено: " + to_wstring(dalmatinCount));
                        }
                        else {
                            // Последующие нажатия, выводим сообщение что никого нет
                            placeLVL3 = 3; // Устанавливаем место для отрисовки сообщения
                        }
                    }
                    // Проверка нажатия кнопки "ШКАФ"
                    if (buttonShapeCloset.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        if (!Rolly.getDalmatinFound()) {
                            // Первое нажатие, поздравляем с найденным Далматинцем
                            Rolly = true;
                            dalmatinCount++;
                            placeLVL3 = 2; // Устанавливаем место для отрисовки сообщения
                            FoundText.setString(L"Найдено: " + to_wstring(dalmatinCount));
                        }
                        else {
                            // Последующие нажатия, выводим сообщение что никого нет
                            placeLVL3 = 3; // Устанавливаем место для отрисовки сообщения
                        }
                    }
                    // Проверка нажатия кнопки "ДВЕРЬ"
                    if (buttonShapeDoor.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        placeLVL3 = 3;
                    }
                    // Проверка нажатия кнопки "ПОЛКИ"
                    if (buttonShapeShelf.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        placeLVL3 = 3;
                    }

                    // Проверка нажатия кнопки "LAST LEVEL"
                    if (buttonLastLVL.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        LVL4 = true;
                        LVL3 = false;
                    }
                    // Проверка нажатия кнопки "Клетка"
                    if (buttonShapeCage.getGlobalBounds().contains(mousePos)) {
                        if (!questionWindowOpened) {
                            questionWindowOpened = true; // Устанавливаем флаг, что окно открыто
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
                                                Event inputEvent;
                                                while (windowInputCode.pollEvent(inputEvent)) {
                                                    if (inputEvent.type == Event::Closed) {
                                                        windowInputCode.close();
                                                    }
                                                    // Проверка нажатия на кнопку возврата
                                                    if (inputEvent.type == Event::MouseButtonPressed && inputEvent.mouseButton.button == Mouse::Left) {
                                                        Vector2i inputMousePos = Mouse::getPosition(windowInputCode);
                                                        if (buttonToBack.getGlobalBounds().contains(static_cast<Vector2f>(inputMousePos))) {
                                                            windowInputCode.close();
                                                        }
                                                    }
                                                    if (inputEvent.type == Event::MouseButtonPressed && inputEvent.mouseButton.button == Mouse::Left) {
                                                        // Проверка, находится ли курсор в пределах inputBox
                                                        if (inputBox.getGlobalBounds().contains(static_cast<Vector2f>(Mouse::getPosition(windowInputCode)))) {
                                                            inputString.clear();
                                                            isInputActive = true; // Активируем поле ввода
                                                        }
                                                        else {
                                                            isInputActive = false; // Деактивируем, если кликнули вне
                                                        }
                                                    }

                                                    if (isInputActive) {
                                                        if (inputEvent.type == Event::TextEntered) {
                                                            // Если вводимый символ не является Backspace
                                                            if (inputEvent.text.unicode < 128) { // Проверяем на ASCII
                                                                if (inputEvent.text.unicode == '\b') { // Обработка Backspace
                                                                    if (!inputString.empty())
                                                                        inputString.pop_back(); // Удаляем последний символ
                                                                }
                                                                else {
                                                                    inputString += static_cast<char>(inputEvent.text.unicode); // Добавление символа
                                                                }
                                                            }
                                                            inputText.setString(inputString); // Обновляем текст
                                                        }
                                                    }
                                                }
                                                if (inputEvent.type == Event::MouseButtonPressed && inputEvent.mouseButton.button == Mouse::Left) {
                                                    Vector2i inputMousePos = Mouse::getPosition(windowInputCode);
                                                    if (buttonEnter.getGlobalBounds().contains(static_cast<Vector2f>(inputMousePos))) {
                                                        if (inputString == correctCode) {
                                                            dalmatins = false;
                                                            inputBox.setFillColor(Color::Green);
                                                        }
                                                        else {
                                                            dalmatins = true;
                                                            inputBox.setFillColor(Color::Red);
                                                        }
                                                    }
                                                }
                                                windowInputCode.clear(Color::White);
                                                windowInputCode.draw(buttonToBack);
                                                windowInputCode.draw(buttonToBackText);
                                                windowInputCode.draw(buttonEnter);
                                                windowInputCode.draw(buttonEnterText);
                                                windowInputCode.draw(inputBox); // Поле ввода
                                                windowInputCode.draw(inputText); // Отображаемый текст
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
                        }
                        if (!dalmatins.getDalmatinFound()) {
                            // Первое нажатие, поздравляем с найденным Далматинцем
                            dalmatins = true;
                            placeLVL4 = 1; // Устанавливаем место для отрисовки сообщения
                            dalmatinCount++;
                            FoundText.setString(L"Найдено: " + to_wstring(dalmatinCount));
                        }
                        else {
                            // Последующие нажатия, выводим сообщение что никого нет
                            placeLVL4 = 2; // Устанавливаем место для отрисовки сообщения
                        }
                    }
                    // Проверка нажатия кнопки "Коробки"
                    if (buttonShapeBarrel.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        placeLVL4 = 2;
                    }
                    // Проверка нажатия кнопки "Коробки"
                    if (buttonShapeBox.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                        placeLVL4 = 2;
                    }
                   
                    window.display();
                }
            }
        }

        window.clear();

        if (isGameStarted.getGame()) {
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
        if (LVL3.getlvl()) {
            window.clear();
            window.draw(spriteLevel_3);
            window.draw(buttonShapeCarpet);
            window.draw(buttonShapeBed);
            window.draw(buttonShapeCloset);
            window.draw(buttonShapeDoor);
            window.draw(buttonShapeShelf);
            window.draw(FoundText);
        }
        
        if (placeLVL3 == 1)
        {
            window.clear();
            window.draw(spriteLevel_3);
            window.draw(buttonShapeCarpet);
            window.draw(buttonShapeBed);
            window.draw(buttonShapeCloset);
            window.draw(buttonShapeDoor);
            window.draw(buttonShapeShelf);
            window.draw(ShapeAnswerBed);
            window.draw(FoundedText);
            window.draw(FoundText);
        }
        else if (placeLVL3 == 2)
        {
            window.clear(); 
            window.draw(spriteLevel_3);
            window.draw(buttonShapeCarpet);
            window.draw(buttonShapeBed);
            window.draw(buttonShapeCloset);
            window.draw(ShapeAnswerCloset);
            window.draw(buttonShapeDoor);
            window.draw(buttonShapeShelf);
            window.draw(FoundedText);
            window.draw(FoundText);
        }
        else if (placeLVL3 == 3)
        {
            window.clear();
            window.draw(spriteLevel_3);
            window.draw(buttonShapeCarpet);
            window.draw(buttonShapeBed);
            window.draw(buttonShapeCloset);
            window.draw(buttonShapeDoor);
            window.draw(buttonShapeShelf);
            window.draw(notFoundedText);
            window.draw(FoundText);
        }

        /*переход на уровень ПОДВАЛ*/
        if (dalmatinCount == 2) {
            window.draw(buttonLastLVL);
            window.draw(buttonLastLVLText);
        }

        if (LVL4.getlvl()) {
            window.clear();
            window.draw(spriteLevel_4);
            window.draw(buttonShapeCage);
            window.draw(buttonShapeBox);
            window.draw(buttonShapeBarrel);
            window.draw(FoundText);
        }

        if (placeLVL4 == 1)
        {
            window.clear();
            window.draw(spriteLevel_4);
            window.draw(buttonShapeBox);
            window.draw(buttonShapeBarrel);
            window.draw(FoundedText);
            window.draw(ShapeAnswerCage);
            window.draw(FoundText);
        }
        else if (placeLVL4 == 2)
        {
            window.clear();
            window.draw(spriteLevel_4);
            window.draw(notFoundedText);
            window.draw(buttonShapeCage);
            window.draw(buttonShapeBarrel);
            window.draw(buttonShapeBox);
            window.draw(FoundText);
        }
        window.display();
    }

    return 0;
}
