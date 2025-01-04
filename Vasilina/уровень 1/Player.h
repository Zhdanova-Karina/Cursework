#ifndef PLAYER_H
#define PLAYER_H

#define MAX_OPTION_LENGTH 100

class Player {
private:
    wchar_t name[MAX_OPTION_LENGTH];
    int score;
public:
    Player();
    Player(const wchar_t* playerName);
    const wchar_t* getName() const;
    int getScore() const;
    void incrementScore();
    void resetScore();
    void setName(const wchar_t* playerName);
};

#endif // PLAYER_H
