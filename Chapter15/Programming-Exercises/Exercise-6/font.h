#ifndef _FONT_H_
#define _FONT_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum STYLE { BOLD, ITALIC, UNDERLINE };

typedef struct _FONT_ {
    unsigned int FontID : 8;
    unsigned int FontSize : 7;
    unsigned int Alignment : 2;
    bool Bold : 1;
    bool Italic : 1;
    bool Underline : 1;
} font;

int GetChoice(font * ft);
void ShowFontStatus(font * ft);
void EatLine(void);
void ChangeFontSize(font * ft);
void ChangeAlignment(font * ft);
void ToggleStyle(font * ft, int style);
void ChangeFont(font * ft);

#endif