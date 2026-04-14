# `templates` в C++
 
Шаблоните позволяват писане на **обобщен код**, който работи с различни типове, без да се дублира логиката.

## ВАЖНО!!! Шаблонните класове и функции не могат да бъдат разделени в `.cpp` файлове, защото компилаторът генерира код за конкретен тип едва когато шаблонът бъде използван (инстанциран). Поради тази причина всичко ще пишем в `.hpp` файлове, където целият код на шаблона е видим за компилатора в момента на инстанциране.

## Шаблон на функция
 
```cpp
template <typename T>
T max_val(T a, T b) {
    return (a > b) ? a : b;
}
 
cout << max_val(3, 7);         // int   → 7
cout << max_val(3.14, 2.71);   // double → 3.14
cout << max_val('a', 'z');     // char  → 'z'
```
 
### Явно указване на типа
 
```cpp
cout << max_val<int>(3, 7);       // явно — <int>
cout << max_val<double>(3, 7);    // принуждава double: 3.0, 7.0
```
 
### Множество шаблонни параметри
 
```cpp
template <typename T, typename U>
void print_pair(T a, U b) {
    cout << a << " и " << b << "\n";
}
 
print_pair(42, "hello");     // int + const char*
print_pair(3.14, true);      // double + bool
```
 
---
 
## Шаблон на клас
 
```cpp
template <typename T>
class Box {
public:
    T value;
 
    Box(T v) : value(v) {}
 
    T get() const { return value; }
 
    void set(T v) { value = v; }
};
 
Box<int> intBox(42);
Box<string> strBox("hello");
 
cout << intBox.get();   // 42
cout << strBox.get();   // hello
```
---

## Специализация
 
Позволява **различна имплементация** за конкретен тип.
 
### Пълна специализация на функция
 
```cpp
template <typename T>
string describe(T val) {
    return "Обща стойност";
}
 
// Специализация само за bool:
template <>
string describe<bool>(bool val) {
    return val ? "true" : "false";
}
 
cout << describe(42);     // "Обща стойност"
cout << describe(true);   // "true"
```
 
---
 
## Concepts (C++20)
 
`concept` дефинира **ограничения** върху шаблонните параметри.
Дава ясни грешки при компилиране вместо дълги съобщения.
 
### Дефиниране на concept
 
```cpp
#include <concepts>
 
// Тип T трябва да поддържа +, -, *, /
template <typename T>
concept Numeric = requires(T a, T b) {
    { a + b } -> same_as<T>;
    { a - b } -> same_as<T>;
    { a * b } -> same_as<T>;
    { a / b } -> same_as<T>;
};
```
 
### Употреба с `requires`
 
```cpp
template <typename T>
requires Numeric<T>
T average(T a, T b) {
    return (a + b) / 2;
}
 
cout << average(10, 20);      // 15
cout << average(1.5, 2.5);    // 2.0
// average("a", "b");         // ГРЕШКА при компилиране
```
 
### Съкратен синтаксис
 
```cpp
// Вместо requires клауза, директно в параметрите:
template <Numeric T>
T square(T x) {
    return x * x;
}

```
 
### Вградени concepts от `<concepts>`
 
```cpp
#include <concepts>
 
template <integral T>        // само цели числа (int, long, char...)
T factorial(T n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
 
template <floating_point T>  // само числа с плаваща запетая
T circle_area(T r) {
    return 3.14159 * r * r;
}
 
template <typename T>
requires copyable<T>         // T трябва да е копируем
void duplicate(T val) {
    T copy = val;            // гарантирано работи
    cout << copy;
}
```
 
| Concept              | Описание                                   |
|----------------------|--------------------------------------------|
| `integral`           | Цели числа (`int`, `long`, `char`...)       |
| `floating_point`     | Числа с плаваща запетая (`float`, `double`) |
| `signed_integral`    | Знакови цели числа                         |
| `unsigned_integral`  | Беззнакови цели числа                      |
| `copyable`           | Може да се копира                          |
| `movable`            | Може да се мести                           |
| `equality_comparable`| Поддържа `==` и `!=`                       |
| `totally_ordered`    | Поддържа `<`, `>`, `<=`, `>=`, тоест (<=>) |
| `same_as<U>`         | Точно същия тип като `U`                   |
| `derived_from<Base>` | Наследява от `Base`                        |
| `convertible_to<U>`  | Конвертируем към `U`                       |

---
 
## Variadic Templates
 
Позволяват **произволен брой** шаблонни параметри.
 
### Основен синтаксис
 
```cpp
// typename... Ts означава "нула или повече типове"
template <typename... Ts>
void print_all(Ts... args) {
    // args... разпакова пакета от аргументи
    (cout << ... << args);   // fold expression (C++17)
}
 
print_all(1, " hello ", 3.14, true);  // 1 hello 3.14 1
```
 
### Fold Expressions (C++17)
 
```cpp
template <typename... Ts>
auto sum(Ts... args) {
    return (... + args);      // ((a + b) + c) + d...
}
 
cout << sum(1, 2, 3, 4, 5);   // 15
cout << sum(1.1, 2.2, 3.3);   // 6.6
 
template <typename... Ts>
bool all_true(Ts... args) {
    return (... && args);
}
 
cout << all_true(true, true, true);   // 1
cout << all_true(true, false, true);  // 0
```
 
### sizeof... — брой аргументи в пакета
 
```cpp
template <typename... Ts>
void show_count(Ts... args) {
    cout << "Брой аргументи: " << sizeof...(args) << "\n";
    cout << "Брой типове:    " << sizeof...(Ts)   << "\n";
}
 
show_count(1, "hi", 3.14);
// Брой аргументи: 3
// Брой типове: 3
```

---
 
## Бързо напомняне — таблица
 
| Синтаксис                              | Описание                                   |
|----------------------------------------|--------------------------------------------|
| `template <typename T>`                | Шаблон с един тип                          |
| `template <typename T, typename U>`    | Шаблон с два типа                          |
| `template <typename... Ts>`            | Вариадичен шаблон                          |
| `sizeof...(Ts)`                        | Брой параметри в пакета                    |
| `(... + args)`                         | Fold expression — ляво сгъване             |
| `(args + ...)`                         | Fold expression — дясно сгъване            |
| `template <>`                          | Специализация                              |
| `concept Foo = requires(...) {...}`    | Дефиниране на concept (C++20)              |
| `template <Foo T>`                     | Ограничен шаблон с concept                 |
 
