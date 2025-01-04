#ifndef PHRASE_H
#define PHRASE_H

#define MAX_PHRASE_LENGTH 100

class Phrase {
private:
    wchar_t text[MAX_PHRASE_LENGTH];
public:
    Phrase();
    Phrase(const wchar_t* phraseText);
    const wchar_t* getText() const;
    void setText(const wchar_t* phraseText);
};

#endif // PHRASE_H

