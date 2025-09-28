#pragma once
#include <string>

using namespace std;

/*
  провер¤ет, что строка начинаетс¤ с шаблона
*/
bool startWith(string tmpl, string& s);

/*
  провер¤ет, что строка начинаетс¤ с шаблона
  верси¤ дл¤ c-style строки (нужно дл¤ оптимизации других функций)
*/
bool startWith(string tmpl, const char* s);

/*
  находит позицию начина¤ с которой встречаетс¤ шаблон. ¬озвращает -1 если шаблона нет.
*/
int findFirst(string tmpl, string& s);

/*
  делит строку на подстроку до шаблона (которую возвращает) и после (до которой обрезает переданную по ссылке)
*/
string splitBy(string tmpl, string& s);

/*
  удал¤ет строку до шаблона. ѕри несовпадении очищает строку полностью.
*/
void skipuntil(string tmpl, string& s);

/*
  возвращает участок строки от шаблона from до шаблона to
*/
string segment(string from, string to, string s);

/*
  определ¤ет, ¤вл¤етс¤ ли символ буквой
*/
bool isLetter(char c);

/*
  определ¤ет, ¤вл¤етс¤ ли символ цифрой
*/
bool isDigit(char c);

/*
  провер¤ет корректность строки в качестве имени пользовател¤
*/
bool correctName(string s);