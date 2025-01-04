#define _CRT_SECURE_NO_WARNINGS
// ConsoleApplication20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
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
#include <vector>



#define MAX_PHRASE_LENGTH 100
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3
#define MAX_PHRASES 3
#define MAX_HINTS 3


void updateWindowWithDelay(sf::RenderWindow& window, sf::Sprite& backgroundSprite, sf::Text& questionText, sf::Text& optionText1, sf::Text& optionText2, sf::Text& optionText3, sf::Text& resultText, sf::Text& hintText, int seconds) {
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
        window.display();
    }
}
// Функция для первого уровня игры
void startFirstLevel(sf::RenderWindow& window) {
    Game game;
    game.initializePuzzles();
    game.initializePhrases();

    // Загрузка текстуры фона
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("C:/coursework/picture-1.png")) {
        std::cerr << "Ошибка загрузки изображения первого уровня" << std::endl;
        return;
    }

    // Создание спрайта фона
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Шрифт и тексты
    sf::Font font;
    if (!font.loadFromFile("C:/coursework/troika.otf")) {
        std::cerr << "Ошибка загрузки шрифта" << std::endl;
        return;
    }

    // Тексты для уровня
    sf::Text questionText;
    sf::Text optionText1;
    sf::Text optionText2;
    sf::Text optionText3;
    sf::Text resultText;
    sf::Text hintText;
    sf::Text phraseText;

    questionText.setFont(font);
    optionText1.setFont(font);
    optionText2.setFont(font);
    optionText3.setFont(font);
    resultText.setFont(font);
    hintText.setFont(font);
    phraseText.setFont(font);

    questionText.setCharacterSize(50);
    optionText1.setCharacterSize(20);
    optionText2.setCharacterSize(20);
    optionText3.setCharacterSize(20);
    resultText.setCharacterSize(24);
    hintText.setCharacterSize(24);
    phraseText.setCharacterSize(24);

    questionText.setFillColor(sf::Color::Black);
    optionText1.setFillColor(sf::Color::Black);
    optionText2.setFillColor(sf::Color::Black);
    optionText3.setFillColor(sf::Color::Black);
    resultText.setFillColor(sf::Color::Red);
    hintText.setFillColor(sf::Color::Black);
    phraseText.setFillColor(sf::Color::Black);

    questionText.setPosition(150, 50);
    optionText1.setPosition(50, 150);
    optionText2.setPosition(50, 200);
    optionText3.setPosition(50, 250);
    resultText.setPosition(50, 400);
    hintText.setPosition(50, 450);
    phraseText.setPosition(50, 450);

    // Функция для обновления текстов
    auto updateTexts = [&]() {
        const Puzzle& puzzle = game.getPuzzle(game.getCurrentPuzzleIndex());
        questionText.setString(puzzle.getQuestion());
        optionText1.setString(L"1) " + std::wstring(puzzle.getOption(0)));
        optionText2.setString(L"2) " + std::wstring(puzzle.getOption(1)));
        optionText3.setString(L"3) " + std::wstring(puzzle.getOption(2)));
        resultText.setString(L"");
        hintText.setString(L"");
        phraseText.setString(L"");
        };

    game.startGame();
    updateTexts();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Обработка нажатий мыши
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Обрабатываем ответы на загадки
                bool correctAnswer = false;
                if (optionText1.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    correctAnswer = game.checkAnswer(game.getCurrentPuzzleIndex(), 0);
                }
                else if (optionText2.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    correctAnswer = game.checkAnswer(game.getCurrentPuzzleIndex(), 1);
                }
                else if (optionText3.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    correctAnswer = game.checkAnswer(game.getCurrentPuzzleIndex(), 2);
                }

                if (correctAnswer) {
                    resultText.setString(L"Правильно! Молодец!");
                    phraseText.setString(game.getRandomPhrase());

                    // Задержка перед переходом к следующей загадке
                    updateWindowWithDelay(window, backgroundSprite, questionText, optionText1, optionText2, optionText3, resultText, hintText, 2);

                    window.clear();
                    window.draw(backgroundSprite);
                    window.draw(questionText);
                    window.draw(optionText1);
                    window.draw(optionText2);
                    window.draw(optionText3);
                    window.draw(resultText);
                    window.draw(hintText);
                    window.draw(phraseText);
                    window.display();

                    game.nextPuzzle();
                    updateTexts();
                }
                else {
                    const Puzzle& puzzle = game.getPuzzle(game.getCurrentPuzzleIndex());
                    resultText.setString(L"Неправильно. Попробуйте снова.");
                    if (puzzle.getAttempts() < MAX_ATTEMPTS) {
                        hintText.setString(L"Подсказка: " + std::wstring(puzzle.getHint(puzzle.getAttempts())));
                    }
                    else {
                        resultText.setString(L"Три попытки истекли. Переход к следующей загадке.");
                        updateWindowWithDelay(window, backgroundSprite, questionText, optionText1, optionText2, optionText3, resultText, hintText, 2);

                        window.clear();
                        window.draw(backgroundSprite);
                        window.draw(questionText);
                        window.draw(optionText1);
                        window.draw(optionText2);
                        window.draw(optionText3);
                        window.draw(resultText);
                        window.draw(hintText);
                        window.draw(phraseText);
                        window.display();

                        game.nextPuzzle();
                        updateTexts();
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        window.draw(questionText);
        window.draw(optionText1);
        window.draw(optionText2);
        window.draw(optionText3);
        window.draw(resultText);
        window.draw(hintText);
        window.draw(phraseText);
        window.display();
    }
}

using namespace sf;

int main() {
    setlocale(LC_ALL, "ru");

    /*МЕНЮ*/
    RenderWindow window(VideoMode(1000, 650), L"Спасите далматинцев!");

    // Загружаем изображение меню
    Image imageMenu;
    if (!imageMenu.loadFromFile("C:/coursework/обложка.jpg")) {
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
    if (!font.loadFromFile("C:/coursework/troika.otf")) {
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
    if (!imageHistoryOne.loadFromFile("C:/coursework/история1.jpg")) {
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
    if (!imageHistoryTwo.loadFromFile("C:/coursework/история2.jpg")) {
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
    if (!imageHistoryThree.loadFromFile("C:/coursework/история3.jpg")) {
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
    if (!imageHistoryFour.loadFromFile("C:/coursework/история4.jpg")) {
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
                        if (currentHistoryPage == 4) { // Проверяем, если превышена последняя страница
                            startFirstLevel(window); // Вызываем первый уровень
                        }
                    }
                }
            }
        }

        //window.clear();

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