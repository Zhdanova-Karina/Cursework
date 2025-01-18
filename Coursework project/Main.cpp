#define _CRT_SECURE_NO_WARNINGS

#define MAX_PHRASE_LENGTH 100
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3
#define MAX_PHRASES 3
#define MAX_HINTS 3
#define COUNT_LEVEL 5;

#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <locale.h>
#include <iostream>
#include "Puzzle.h"
#include "Player.h"
#include "Phrase.h"
#include "Game.h"
#include "Dalmatin.h"
#include "Level.h"
#include "Game1.h"
#include <vector>

using namespace std;
using namespace sf;

// Функция для обновления окна во время задержки 
void updateWindowWithDelay(sf::RenderWindow& window, sf::Sprite& backgroundSprite, sf::Text& questionText, sf::Text& optionText1, sf::Text& optionText2, sf::Text& optionText3, sf::Text& resultText, sf::Text& phraseText, int seconds) {
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < seconds) {
        window.clear();
        window.draw(backgroundSprite);
        // Отрисовка фона 
        window.draw(questionText);
        window.draw(optionText1);
        window.draw(optionText2);
        window.draw(optionText3);
        window.draw(resultText);
        window.draw(phraseText);
        window.display();
    }
}

// ФУНКЦИЯ ДЛЯ ЗАГРУЗКИ ТРЕТЬЕГО УРОВНЯ ИГРЫ
void startThirdLevel(RenderWindow& window) {

    // Загружаем шрифт
    Font font;
    if (!font.loadFromFile("C:/coursework/шрифт/troika.otf")) {
        cerr << "Ошибка загрузки шрифта" << endl;
        return;
    }

    // Загружаем изображение концовки
    Image imageEnding;
    if (!imageEnding.loadFromFile("C:/coursework/меню, предыстория/концовка.png")) {
        std::cerr << "Ошибка загрузки изображения истории" << std::endl;
        return;
    }

    sf::Texture textureImageEnding;
    textureImageEnding.loadFromImage(imageEnding);

    sf::Sprite spriteImageEnding;
    spriteImageEnding.setTexture(textureImageEnding);
    spriteImageEnding.setPosition(0, 0);

    // Текстура и спрайт фона
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/coursework/1 уровень/обложка.png")) {
        std::cerr << "Ошибка загрузки изображения первого уровня" << std::endl;
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Создаем текст правил
    sf::Text rulesText;
    rulesText.setFont(font); 
    rulesText.setCharacterSize(40);
    rulesText.setFillColor(sf::Color::Black); 
    rulesText.setString(L"                                    3 уровень\n\n                     Вам удалось попасть в дом!\n             Теперь Вам нужно найти щенков.\n          Нажимайте на предметы и проверяйте,\n                          есть ли там кто-то!");
    rulesText.setPosition(70, 180);
    
    // Создание кнопки "Далее"
    sf::RectangleShape buttonNext(sf::Vector2f(100, 30));
    buttonNext.setFillColor(sf::Color::White);
    buttonNext.setPosition(885, 10);

    sf::Text buttonNextText;
    buttonNextText.setFont(font);
    buttonNextText.setString(L"Далее");
    buttonNextText.setCharacterSize(16);
    buttonNextText.setFillColor(sf::Color::Red);
    buttonNextText.setPosition(910, 15);

    // Загружаем изображение уровня №3
    Image imageLVL3;
    if (!imageLVL3.loadFromFile("C:/coursework/3-4 уровни/спальня.png")) {
        cerr << "Ошибка загрузки изображения уровня" << endl;
        return ;
    }

    Texture textureLevel_3;
    textureLevel_3.loadFromImage(imageLVL3);
    Sprite spriteLevel_3;
    spriteLevel_3.setTexture(textureLevel_3);
    spriteLevel_3.setPosition(0, 0);

    Texture buttonTextureBed;
    if (!buttonTextureBed.loadFromFile("C:/coursework/3-4 уровни/imgBed.png")) {
        return; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки кровать
    RectangleShape buttonShapeBed(Vector2f(455, 360)); 
    buttonShapeBed.setTexture(&buttonTextureBed); // Установка текстуры в прямоугольник
    buttonShapeBed.setPosition(570, 220); // Установка позиции кнопки

    Texture buttonTextureCloset;
    if (!buttonTextureCloset.loadFromFile("C:/coursework/3-4 уровни/imgCloset.png")) {
        return ; // Ошибка загрузки текстуры
    }

    /*Далматинцы из кровати*/
    Texture textureAnswerBed;
    if (!textureAnswerBed.loadFromFile("C:/coursework/3-4 уровни/Ролли.png")) {
        return ; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerBed(Vector2f(175, 175));
    ShapeAnswerBed.setTexture(&textureAnswerBed);
    ShapeAnswerBed.setPosition(750, 300);

    // Создание прямоугольника кнопки ШКАФ
    RectangleShape buttonShapeCloset(Vector2f(200, 460)); 
    buttonShapeCloset.setTexture(&buttonTextureCloset); 
    buttonShapeCloset.setPosition(45, 130); // Установка позиции кнопки

    Texture buttonTextureDoor;
    if (!buttonTextureDoor.loadFromFile("C:/coursework/3-4 уровни/imgDoor.png")) {
        return ; // Ошибка загрузки текстуры
    }

    /*Далматинцы из шкафа*/
    Texture textureAnswerCloset;
    if (!textureAnswerCloset.loadFromFile("C:/coursework/3-4 уровни/Патч.png")) {
        return ; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerCloset(Vector2f(175, 175));
    ShapeAnswerCloset.setTexture(&textureAnswerCloset);
    ShapeAnswerCloset.setPosition(60, 400);

    // Создание прямоугольника кнопки ДВЕРЬ
    RectangleShape buttonShapeDoor(Vector2f(150, 360)); // Размер кнопки
    buttonShapeDoor.setTexture(&buttonTextureDoor); // Установка текстуры в прямоугольник
    buttonShapeDoor.setPosition(550, 70); // Установка позиции кнопки

    Texture buttonTextureShelf;
    if (!buttonTextureShelf.loadFromFile("C:/coursework/3-4 уровни/imgShelf.png")) {
        return ; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки ПОЛКА
    RectangleShape buttonShapeShelf(Vector2f(200, 200)); // Размер кнопки
    buttonShapeShelf.setTexture(&buttonTextureShelf); // Установка текстуры в прямоугольник
    buttonShapeShelf.setPosition(800, 30); // Установка позиции кнопки

    Texture buttonTextureCarpet;
    if (!buttonTextureCarpet.loadFromFile("C:/coursework/3-4 уровни/imgCarpet.png")) {
        return ; // Ошибка загрузки текстуры
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
    if (!imageLVL4.loadFromFile("C:/coursework/3-4 уровни/подвал.png")) {
        cerr << "Ошибка загрузки изображения уровня" << endl;
        return;
    }

    Texture textureLevel_4;
    textureLevel_4.loadFromImage(imageLVL4);
    Sprite spriteLevel_4;
    spriteLevel_4.setTexture(textureLevel_4);
    spriteLevel_4.setPosition(0, 0);

    /*Далматинцы из клетки*/
    Texture textureAnswerCage;
    if (!textureAnswerCage.loadFromFile("C:/coursework/3-4 уровни/далматинцы из клетки.jpg")) {
        return ; // Ошибка загрузки текстуры
    }
    RectangleShape ShapeAnswerCage(Vector2f(175, 175));
    ShapeAnswerCage.setTexture(&textureAnswerCage);
    ShapeAnswerCage.setPosition(780, 400);

    Texture buttonTextureCage;
    if (!buttonTextureCage.loadFromFile("C:/coursework/3-4 уровни/imgCage.jpg")) {
        return ; // Ошибка загрузки текстуры
    }

    // Создание прямоугольника кнопки клетка
    RectangleShape buttonShapeCage(Vector2f(155, 160)); // Размер кнопки
    buttonShapeCage.setTexture(&buttonTextureCage); // Установка текстуры в прямоугольник
    buttonShapeCage.setPosition(800, 400); // Установка позиции кнопки

    Texture buttonTextureBox;
    if (!buttonTextureBox.loadFromFile("C:/coursework/3-4 уровни/imgBox.jpg")) {
        return ; // Ошибка загрузки текстуры
    }
    // Создание прямоугольника кнопки коробки
    RectangleShape buttonShapeBox(Vector2f(350, 260)); // Размер кнопки
    buttonShapeBox.setTexture(&buttonTextureBox); // Установка текстуры в прямоугольник
    buttonShapeBox.setPosition(373, 200); // Установка позиции кнопки

    Texture buttonTextureBarrel;
    if (!buttonTextureBarrel.loadFromFile("C:/coursework/3-4 уровни/imgBarrel.jpg")) {
        return ; // Ошибка загрузки текстуры
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

    // Создание кнопки "Далее" для перехода к концовке
    sf::RectangleShape buttonToEnd(sf::Vector2f(100, 30));
    buttonToEnd.setFillColor(sf::Color::White);
    buttonToEnd.setPosition(875, 10);

    sf::Text buttonToEndText;
    buttonToEndText.setFont(font);
    buttonToEndText.setString(L"Далее");
    buttonToEndText.setCharacterSize(16);
    buttonToEndText.setFillColor(sf::Color::Red);
    buttonToEndText.setPosition(900, 15);

    // 3. Создание текстового объекта для отображения введенного текста
    Text inputText("", font, 14); // Крупный шрифт
    inputText.setFillColor(Color::Black);
    inputText.setPosition(120, 72); // Позиция текста внутри поля

    string inputString = ""; // Логика хранения вводимого текста
    bool isInputActive = false; // Флаг для определения состояния ввода
    string correctCode = "1996"; // Правильный код
    Color cellColor; // Цвет ячейки

    // Переменные для отслеживания текущего состояния игры
    Game1 isGameStarted = false;
    int dalmatinCount = 0;
    Level LVL4;
    Level LVL3;
    int placeLVL3 = 0;
    int placeLVL4 = 0;

    Dalmatin Patch = false;
    Dalmatin Rolly = false;
    Dalmatin Rex = false;

    bool questionWindowOpened = false; // Флаг для отслеживания открытия окна с вопросом

    bool isEnding = false;

    bool isShowingRules = true;
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

                    // Проверка нажатия кнопки "Далее"
                    if (buttonNext.getGlobalBounds().contains(mousePos))
                    {
                        isShowingRules = false;
                        LVL3 = true;

                        if (event.type == Event::Closed) window.close();
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
                            RenderWindow windowQUESTION(VideoMode(400, 200), L"На клетке замок! Нужен код!");
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
                                            RenderWindow windowHint(VideoMode(400, 200), L"Подсказка!");
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
                                            RenderWindow windowInputCode(VideoMode(400, 200), L"Введите код!");

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
                                                            Rex = false;
                                                            inputBox.setFillColor(Color::Green);
                                                        }
                                                        else {
                                                            Rex = true;
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
                        if (!Rex.getDalmatinFound()) {
                            // Первое нажатие, поздравляем с найденным Далматинцем
                            Rex = true;
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

        if (isShowingRules) {

            // Отображение фона
            window.draw(backgroundSprite);

            // Отображение правил
            window.draw(rulesText);

            // Отображение кнопки "Далее"
            window.draw(buttonNext);
            window.draw(buttonNextText);
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

        if (dalmatinCount == 3) {
            window.draw(buttonToEnd);
            window.draw(buttonToEndText);
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
            if (dalmatinCount == 3) {

                window.draw(buttonToEnd);
                window.draw(buttonToEndText);
            }
            Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));

            // Проверка нажатия кнопки "Далее", для перехода к концовке
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (buttonToEnd.getGlobalBounds().contains(static_cast<Vector2f>(mousePos))) {
                    isEnding = true; 
                }
            }

            if (isEnding) {
                window.clear();
                window.draw(spriteImageEnding);

                Text gameOverText;
                gameOverText.setFont(font); 
                gameOverText.setString( L"Конец игры");
                gameOverText.setCharacterSize(50); 
                gameOverText.setFillColor(Color::White); 
                gameOverText.setPosition(500, 10); 

                window.draw(gameOverText);
            }  
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
}

// ФУНКЦИЯ ДЛЯ ЗАГРУЗКИ ВТОРОГО УРОВНЯ ИГРЫ
void startSecondLevel(RenderWindow& window) {
    // Загрузка текстур домов
    sf::Texture houseTexture1, houseTexture2, houseTexture3, backgroundTexture;
    if (!houseTexture1.loadFromFile("C:/coursework/2 уровень/house1.png") ||
        !houseTexture2.loadFromFile("C:/coursework/2 уровень/house2.png") ||
        !houseTexture3.loadFromFile("C:/coursework/2 уровень/house3.png") ||
        !backgroundTexture.loadFromFile("C:/coursework/1 уровень/обложка.png")) {
        std::cerr << "Ошибка загрузки изображений" << std::endl;
        return;
    }

    // Создание спрайтов домов
    sf::Sprite houseSprite1, houseSprite2, houseSprite3;
    houseSprite1.setTexture(houseTexture1);
    houseSprite2.setTexture(houseTexture2);
    houseSprite3.setTexture(houseTexture3);

    vector<sf::Sprite> houseSprites = { houseSprite1, houseSprite2, houseSprite3 };
    int correctHouse = 1; // правильный дом 
    int attempt = 0;
    bool correct = false;

    // Создание и настройка спрайта фона
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Позиционирование спрайтов домов
    for (int i = 0; i < houseSprites.size(); i++) {
        houseSprites[i].setPosition(260 * (i), 70);
    }

    // Создание текста правил
    sf::Font font;
    if (!font.loadFromFile("C:/coursework/шрифт/troika.otf")) {
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return;
    }
    sf::Text rulesText;
    rulesText.setFont(font);
    rulesText.setString(L"                                    2 уровень\n\n                                     Правила:\n1. Выберете дом Круэллы, используя подсказки, \n полученные в прошлом уровне.\n2. У тебя есть 3 попытки.");
    rulesText.setCharacterSize(40);
    rulesText.setFillColor(sf::Color::Black);
    rulesText.setPosition(70, 180);

    // Создание кнопки "Далее"
    sf::RectangleShape button(sf::Vector2f(100, 30));
    button.setFillColor(sf::Color::White);
    button.setPosition(885, 10);

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString(L"Далее");
    buttonText.setCharacterSize(16);
    buttonText.setFillColor(sf::Color::Red);
    buttonText.setPosition(910, 15);

    // Создание текстов для сообщений
    sf::Text messageText;
    messageText.setFont(font);
    messageText.setCharacterSize(35);
    messageText.setFillColor(sf::Color::White);
    messageText.setPosition(150, 60);

    bool showHouses = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (!showHouses) {
                    if (button.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        showHouses = true;
                    }
                }
                else {

                    bool houseClicked = false;

                    for (int i = 0; i < houseSprites.size(); ++i) {
                        if (houseSprites[i].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            houseClicked = true;
                            if (i == correctHouse) {
                                messageText.setString(L"                          Мы очень рады,\n что Вы справились, отправляемся дальше!");
                                correct = true;
                            }
                            else {
                                attempt++;
                                if (attempt == 1) {
                                    messageText.setString(L"                  Неправильный выбор. \nПодсказка: У дома не зелёная дверь." );
                                }
                                else if (attempt == 2) {
                                    messageText.setString(L"                  Неправильный выбор. \n   Подсказка: Дом имеет красную крышу.");
                                }
                                else {
                                    messageText.setString(L"Очень жаль, что Вы не ответили на \n загадки и заставляешь их ждать.\n");
                                }
                            }
                            break; // Выход из цикла после нажатия на дом
                        }   
                    }
                    // После выхода из цикла проверяем, был ли нажат дом
                    if (houseClicked) {
                       
                        window.clear();
                       
                        window.draw(backgroundSprite);
                        window.draw(messageText); 
                        for (const auto& houseSprite : houseSprites) {
                            window.draw(houseSprite);
                        }
                        window.display();

                        if (correct) {
                            // Wait for a short pause before transitioning to the third level
                            sf::sleep(sf::seconds(2));
                            startThirdLevel(window);
                            return;
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite); 
        if (!showHouses) {
            window.draw(rulesText);
            window.draw(button);
            window.draw(buttonText);
        }
        else {
            for (const auto& houseSprite : houseSprites) {
                window.draw(houseSprite);
            }
            if (attempt > 0) {
                window.draw(messageText);
            }     
        }
        window.display();
    }
}

enum GameState {
    ShowRules,
    InputName,
    ShowPuzzles,
    ShowResults
};

// ФУНКЦИЯ ДЛЯ ЗАГРУЗКИ ПЕРВОГО УРОВНЯ ИГРЫ
void startFirstLevel(sf::RenderWindow& window) {

    int currentPuzzleIndex = 0;

    Game game;
    game.initializePuzzles();
    game.initializePhrases();

    // Создание объекта Player
    Player player;

    // Переменная для хранения имени игрока
    std::wstring playerName;

    // Переменная для состояния игры
    GameState gameState = ShowRules;

    // Текстура и спрайт фона
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/coursework/1 уровень/обложка.png")) {
        std::cerr << "Ошибка загрузки изображения первого уровня" << std::endl;
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Шрифт и тексты
    sf::Font font;
    if (!font.loadFromFile("C:/coursework/шрифт/troika.otf")) {
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return;
    }

    // Текст правил
    sf::Text rulesText;
    rulesText.setFont(font);
    rulesText.setCharacterSize(40);
    rulesText.setFillColor(sf::Color::Black);
    rulesText.setString(L"                                   1 уровень\n\n                    Всех щенков похитили!\n        Помогите им, выполнив все задания!\n\n                                     Правила:\n1. Ответьте на все загадки.\n2. Используйте подсказки при необходимости.\n3. Получите баллы за правильные ответы.\nНажмите 'Далее' для начала игры.");
    rulesText.setPosition(70, 82);

    // Кнопка "Далее"
    sf::Text nextButton;
    nextButton.setFont(font);
    nextButton.setCharacterSize(24);
    nextButton.setFillColor(sf::Color::Red);
    nextButton.setString(L"Далее");
    nextButton.setPosition(885, 10);

    // Текст для ввода имени игрока
    sf::Text nameInputText;
    nameInputText.setFont(font);
    nameInputText.setCharacterSize(50);
    nameInputText.setFillColor(sf::Color::Black);
    nameInputText.setString(L"Введите ваше имя:");
    nameInputText.setPosition(300, 200);

    sf::Text playerNameText;
    playerNameText.setFont(font);
    playerNameText.setCharacterSize(50);
    playerNameText.setFillColor(sf::Color::Red);
    playerNameText.setPosition(350, 270);

    // Тексты для уровня
    sf::Text questionText;
    sf::Text optionText1;
    sf::Text optionText2;
    sf::Text optionText3;
    sf::Text resultText;
    sf::Text resultText2;
    sf::Text hintText;
    sf::Text phraseText;
    sf::Text correctAnswersText;

    questionText.setFont(font);
    optionText1.setFont(font);
    optionText2.setFont(font);
    optionText3.setFont(font);
    resultText.setFont(font);
    resultText2.setFont(font);
    hintText.setFont(font);
    phraseText.setFont(font);
    correctAnswersText.setFont(font);

    questionText.setCharacterSize(50);
    optionText1.setCharacterSize(40);
    optionText2.setCharacterSize(40);
    optionText3.setCharacterSize(40);
    resultText.setCharacterSize(40);
    resultText2.setCharacterSize(40);
    hintText.setCharacterSize(24);
    phraseText.setCharacterSize(24);
    correctAnswersText.setCharacterSize(35);

    questionText.setFillColor(sf::Color::Black);
    optionText1.setFillColor(sf::Color::Black);
    optionText2.setFillColor(sf::Color::Black);
    optionText3.setFillColor(sf::Color::Black);
    resultText.setFillColor(sf::Color::Red);
    resultText2.setFillColor(sf::Color::Black);
    hintText.setFillColor(sf::Color::Black);
    phraseText.setFillColor(sf::Color::Black);
    correctAnswersText.setFillColor(sf::Color::Black);

    questionText.setPosition(150, 50);

    optionText1.setPosition(370, 250);
    optionText2.setPosition(370, 300);
    optionText3.setPosition(370, 350);

    resultText.setPosition(140, 450);
    resultText2.setPosition(310, 220);

    hintText.setPosition(140, 500);
    phraseText.setPosition(140, 500);
    correctAnswersText.setPosition(50, 550);

    // Функция для обновления текстов
    auto updateTexts = [&]() {
        const Puzzle& puzzle = game.getPuzzle(game.getCurrentPuzzleIndex());
        questionText.setString(puzzle.getQuestion());
        optionText1.setString(L"1) " + std::wstring(puzzle.getOption(0)));
        optionText2.setString(L"2) " + std::wstring(puzzle.getOption(1)));
        optionText3.setString(L"3) " + std::wstring(puzzle.getOption(2)));
        resultText.setString(L"");
        resultText2.setString(L"");
        hintText.setString(L"");
        phraseText.setString(L"");
        correctAnswersText.setString(L"Правильных ответов: " + std::to_wstring(player.getScore()));
        };

    game.startGame();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (gameState == InputName) {
                    // Обработка ввода имени игрока
                    if (event.text.unicode == '\b') {
                        if (!playerName.empty()) {
                            playerName.pop_back();
                        }
                    }
                    else if (event.text.unicode < 128) {
                        playerName += static_cast<wchar_t>(event.text.unicode);
                    }
                    playerNameText.setString(playerName);
                }
            }

            // Обработка нажатий мыши
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (nextButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    if (gameState == ShowRules) {
                        // Переход от правил к вводу имени
                        gameState = InputName;
                    }
                    else if (gameState == InputName) {
                        // Установка имени игрока и переход к загадкам
                        player.setName(playerName.c_str());
                        game.setPlayerName(playerName.c_str());
                        gameState = ShowPuzzles;
                        updateTexts(); // Обновление текстов загадок
                    }
                    else if (gameState == ShowResults) {
                        // Переход от результата к началу игры или повтору
                        if (player.getScore() == 0) {
                            game.startGame();
                        }
                        
                        gameState = ShowRules;
                    }
                }
                else if (gameState == ShowPuzzles) {
                    // Проверка правильности ответа
                    const Puzzle& currentPuzzle = game.getPuzzle(game.getCurrentPuzzleIndex());
                    int selectedOption = -1;
                    if (optionText1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        selectedOption = 0;
                    }
                    else if (optionText2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        selectedOption = 1;
                    }
                    else if (optionText3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        selectedOption = 2;
                    }

                    if (selectedOption != -1) {
                        Puzzle& currentPuzzle = game.getPuzzle(game.getCurrentPuzzleIndex());
                        bool correctAnswer = currentPuzzle.isCorrectOption(selectedOption);

                        if (correctAnswer) {
                            resultText.setString(L"Правильно! Молодец!");

                            // Получить случайную фразу про дом Круэллы 
                            phraseText.setString(game.getRandomPhrase());
                            phraseText.setString(game.getRandomPhrase());

                            player.incrementScore(); // Увеличиваем количество решённых загадок

                            // Задержка перед переходом к следующей загадке
                            updateWindowWithDelay(window, backgroundSprite, questionText, optionText1, optionText2, optionText3, resultText, phraseText, 2);

                            window.clear();
                            window.draw(backgroundSprite);
                            window.draw(questionText);
                            window.draw(optionText1);
                            window.draw(optionText2);
                            window.draw(optionText3);
                            window.draw(resultText);
                            window.draw(resultText2);
                            window.draw(phraseText);
                            window.display();

                            currentPuzzleIndex++;
                         
                            game.nextPuzzle();
                            updateTexts();
                        }
                        
                        else {
                            
                            currentPuzzle.incrementAttempts();
                            resultText.setString(L"Неправильно. Попробуйте снова.");
                            if (currentPuzzle.getAttempts() < MAX_ATTEMPTS) {
                                hintText.setString(L"Подсказка: " + std::wstring(currentPuzzle.getHint(currentPuzzle.getAttempts())));
                            } 
                            else {
                                resultText.setString(L"Три попытки истекли. \nПереход к следующей загадке.");
                                updateWindowWithDelay(window, backgroundSprite, questionText, optionText1, optionText2, optionText3, resultText, phraseText, 2);

                                window.clear();
                                window.draw(backgroundSprite);
                                window.draw(questionText);
                                window.draw(optionText1);
                                window.draw(optionText2);
                                window.draw(optionText3);
                                window.draw(resultText);
                                window.draw(resultText2);
                                window.display();

                                game.nextPuzzle();
                                currentPuzzleIndex++;
                                updateTexts();
                            }
                        } 
                    }       
                } 
                    if (currentPuzzleIndex == MAX_PUZZLES) {
                        // Показ экрана с результатами после третьей загадки
                        gameState = ShowResults;
                        resultText2.setString(L"    Уровень окончен!\nИгрок: " + std::wstring(player.getName()) + L"\nПравильных ответов: " + std::to_wstring(player.getScore()));

                        if (player.getScore() == 0) {
                            game.startGame();
                            player.resetScore();
                            currentPuzzleIndex = 0;
                        }
                    }
                }
            }
            window.clear();
            window.draw(backgroundSprite);
            if (gameState == ShowRules) {
                window.draw(rulesText);
                window.draw(nextButton);
            }
            else if (gameState == InputName) {
                window.draw(nameInputText);
                window.draw(playerNameText);
                window.draw(nextButton);
            }
            else if (gameState == ShowPuzzles) {
                window.draw(questionText);
                window.draw(optionText1);
                window.draw(optionText2);
                window.draw(optionText3);
                window.draw(resultText);
                window.draw(hintText);
                window.draw(phraseText);
                window.draw(correctAnswersText);
            }
            else if (gameState == ShowResults) {
                window.draw(resultText);
                window.draw(resultText2);
                if (player.getScore() == 0) {
                    window.draw(nextButton);
                    game.startGame();
                    player.resetScore();
                    currentPuzzleIndex = 0;
                }
                else {
                    updateWindowWithDelay(window, backgroundSprite, resultText2, resultText2, resultText2, resultText2, resultText2, resultText2, 3);
                    startSecondLevel(window);
                }
            }
            window.display();
        } 
    }    

int main() {

    setlocale(LC_ALL, "ru");
    srand(time(NULL)); // инициализация генератора случайных чисел

    // Загрузка иконки
    sf::Image icon;
    if (!icon.loadFromFile("C:/coursework/иконка.png"))
    {
        // Обработка ошибки
        return -1;
    }

    // Меню
    RenderWindow window(VideoMode(1000, 650), L"Спасите далматинцев!");

    // Установка иконки окна
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    // Загружаем изображение меню
    Image imageMenu;
    if (!imageMenu.loadFromFile("C:/coursework/меню, предыстория/меню.jpg")) {
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
    if (!font.loadFromFile("C:/coursework/шрифт/troika.otf")) {
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

    // Предыстория
    // Загружаем изображение истории 1
    Image imageHistoryOne;
    if (!imageHistoryOne.loadFromFile("C:/coursework/меню, предыстория/история1.jpg")) {
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
    if (!imageHistoryTwo.loadFromFile("C:/coursework/меню, предыстория/история2.jpg")) {
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
    if (!imageHistoryThree.loadFromFile("C:/coursework/меню, предыстория/история3.jpg")) {
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
    if (!imageHistoryFour.loadFromFile("C:/coursework/меню, предыстория/история4.jpg")) {
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

                        if (currentHistoryPage == 4) { 
                            startFirstLevel(window); // Вызываем первый уровень
                        }
                    }
                }
            }
        }

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