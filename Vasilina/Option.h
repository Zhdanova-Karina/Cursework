#ifndef OPTION_H
#define OPTION_H

#define MAX_OPTION_LENGTH 100

class Option {
private:
    wchar_t text[MAX_OPTION_LENGTH];
public:
    Option();
    Option(const wchar_t* optionText);
    const wchar_t* getText() const;
    void setText(const wchar_t* optionText);
};

#endif // OPTION_H

