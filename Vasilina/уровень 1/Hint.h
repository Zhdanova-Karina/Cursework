#ifndef HINT_H
#define HINT_H

#define MAX_HINT_LENGTH 200

class Hint {
private:
    wchar_t text[MAX_HINT_LENGTH];
public:
    Hint();
    Hint(const wchar_t* hintText);
    const wchar_t* getText() const;
    void setText(const wchar_t* hintText);
};

#endif // HINT_H
