# `std::string` в C++

`std::string` е клас от стандартната библиотека на C++, предназначен за работа с текстови низове. За разлика от класическите C-style низове (`char*`), `std::string` автоматично управлява паметта си, може да променя размера си динамично и предлага множество удобни методи за манипулация на текст.

```cpp
#include <string>
using namespace std;
```

---

## Създаване (Инициализация)

```cpp
string s1;                     // празен низ
string s2 = "Hello";           // инициализация с текст
string s3("World");            // инициализация чрез конструктор
string s4(5, 'A');             // низ от 5 еднакви символа: "AAAAA"
string s5 = s2;                // копие на s2
```

---

## Добавяне и конкатенация

### Оператор `+=` и `append()` — добавяне в края
Най-лесният начин да слепиш два низа или да добавиш текст.

```cpp
string s = "Hello";
s += " World";         // s = "Hello World"
s.append("!");         // s = "Hello World!"
```

### `push_back(char)` — добавя един символ в края
```cpp
string s = "C+";
s.push_back('+');      // s = "C++"
```

### `insert(pos, str)` — вмъква текст на дадена позиция
```cpp
string s = "I C++";
s.insert(2, "love ");  // вмъква "love " започвайки от индекс 2
// s = "I love C++"
```

---

## Премахване на елементи

### `pop_back()` — премахва последния символ
```cpp
string s = "Hello!";
s.pop_back();
// s = "Hello"
```

### `erase(pos, len)` — премахва `len` на брой символи, започвайки от `pos`
```cpp
string s = "I love bugs in C++";
s.erase(7, 8);         // премахва 8 символа, започвайки от индекс 7 ("bugs in ")
// s = "I love C++"
```

### `clear()` — премахва всички символи
```cpp
string s = "Delete me";
s.clear();
// s = "" , s.length() == 0
```

---

## Достъп до символи

### `s[i]` — достъп по индекс (без проверка на граници)
```cpp
string s = "C++";
cout << s[0];  // 'C'
```

### `s.at(i)` — достъп по индекс (с проверка, хвърля изключение)
```cpp
string s = "C++";
cout << s.at(1);   // '+'
cout << s.at(10);  // хвърля std::out_of_range
```

### `front()` и `back()` — първи и последен символ
```cpp
string s = "Word";
cout << s.front();  // 'W'
cout << s.back();   // 'd'
```

---

## Размер и капацитет

### `length()` и `size()` — дължина на низа
Двата метода правят абсолютно едно и също нещо при `std::string`.
```cpp
string s = "Hello";
cout << s.length();  // 5
cout << s.size();    // 5
```

### `empty()` — проверява дали низът е празен
```cpp
string s;
if (s.empty()) {
    cout << "Низът е празен!";
}
```

---

## Търсене и поднизове

### `substr(pos, len)` — извличане на подниз
Връща нов низ, който започва от `pos` и има дължина `len`. Ако `len` се пропусне, взима до края.
```cpp
string s = "Hello World";
string sub1 = s.substr(0, 5);   // "Hello"
string sub2 = s.substr(6);      // "World"
```

### `find(str)` — търсене на текст
Връща индекса на първото срещане. Ако не намери нищо, връща константата `string::npos`.
```cpp
string s = "Searching for a needle in a haystack";
size_t pos = s.find("needle");

if (pos != string::npos) {
    cout << "Намерено на индекс: " << pos;
} else {
    cout << "Не е намерено";
}
```

---

## Итерация (обхождане)

### С `for` цикъл и индекс
```cpp
string s = "C++";
for (int i = 0; i < s.length(); i++) {
    cout << s[i] << " ";
}
```

### С range-based `for` (препоръчително)
```cpp
string s = "C++";
for (char c : s) {
    cout << c << " ";
}
```

---

## Преобразуване между числа и низове

### `to_string(val)` — от число към низ
```cpp
int num = 42;
string s = to_string(num);  // s = "42"
```

### `stoi()`, `stod()` — от низ към число (от `<string>`)
* `stoi` (string to integer)
* `stod` (string to double)
* `stof` (string to float)

```cpp
string sInt = "123";
int n = stoi(sInt);         // n = 123

string sDouble = "3.14";
double d = stod(sDouble);   // d = 3.14
```

---

## Бързо напомняне — таблица с функции

| Функция             | Описание                                  |
|---------------------|-------------------------------------------|
| `+=` / `append()`   | Добавя текст в края                       |
| `push_back(char)`   | Добавя един символ в края                 |
| `pop_back()`        | Премахва последния символ                 |
| `insert(pos, str)`  | Вмъква текст на позиция                   |
| `erase(pos, len)`   | Премахва `len` символа от позиция         |
| `clear()`           | Изчиства целия низ                        |
| `length()` / `size()`| Връща броя на символите                  |
| `empty()`           | Проверява дали низът е празен             |
| `at(i)`             | Достъп със защита извън граници           |
| `substr(pos, len)`  | Връща част от низа (подниз)               |
| `find(str)`         | Търси текст (връща индекс или `npos`)     |
| `to_string(val)`    | Превръща число в `string`                 |
| `stoi(str)`         | Превръща `string` в `int`                 |
