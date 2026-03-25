# Задачи

## Задача 1 — `MovieCD`

Създайте клас `MovieCD`, който пази информация за филм във видеотека.

### Private полета

- `char* title`
- `double rentalPrice`
- `int availableCopies`

### Методи

- `double getTotalRentalValue() const` — връща общата стойност на всички налични копия
- `bool isAvailable() const` — проверява дали има налични копия
- `void print() const` — извежда информация за филма

### Изисквания

- Да се имплементира коректно **Rule of Five**
- Където е необходимо, да се реализират подходящи `set` и `get` методи

> **Rule of Five speedrun** — не я мислете много, пишете!

---

## Задача 2 — `Matrix`

Създайте клас `Matrix`, който представя матрица от цели числа.

### Private полета

- `int** data`
- `size_t rows`
- `size_t cols`

### Конструктори

- `Matrix(size_t rows, size_t cols)` — създава матрица с даден брой редове и колони
- `Matrix(const Matrix& other)` — copy constructor

### Оператори

- `Matrix& operator=(const Matrix& other)` — copy assignment operator
- `int* operator[](size_t row)` — достъп до ред на матрицата (и съответно води до достъп на колона)
- `const int* operator[](size_t row) const` — константен достъп до ред на матрицата
- `Matrix operator+(const Matrix& other) const` — събира две матрици
- `Matrix operator-(const Matrix& other) const` — изважда две матрици
- `Matrix operator*(const Matrix& other) const` — умножава две матрици
- `Matrix operator*(int scalar) const` — умножава матрица по число
- `bool operator==(const Matrix& other) const` — сравнява две матрици
- `bool operator!=(const Matrix& other) const` — проверява дали две матрици са различни
- `std::ostream& operator<<(std::ostream& os, const Matrix& matrix);` — извежда матрицата в конзолата
- `std::istream& operator>>(std::istream& is, Matrix& matrix);` — въвежда матрицата от конзолата

### Деструктор

- `~Matrix()`

### Методи

- `size_t getRows() const` — връща броя редове
- `size_t getCols() const` — връща броя колони
- `bool isSquare() const` — проверява дали матрицата е квадратна

### Изисквания

- Да се проверява дали размерите позволяват умножение

### Да се демонстрира в `main()`

- работа с `[][]`

---

## Задача 3 — `BigNumber`

Създайте клас `BigNumber`, който представя голямо неотрицателно цяло число с произволен брой цифри.


### Private полета

- `char* digits`
- `size_t size`

### Методи

- `size_t length() const` — връща броя цифри на числото
- `bool isZero() const` — проверява дали числото е `0`
- `void removeLeadingZeros()` — премахва водещите нули, ако има такива

### Оператори

- `operator+` — 
- `operator-` — 
- `operator*` — 
- `operator[]` — осигурява достъп до цифра по индекс
- `operator==` — 
- `operator!=` —
- `operator<` — 
- `operator>` — 
- `operator<=>` — реализира трипосочно сравнение между две големи числа
- `operator<<` — извежда числото в конзолата
- `operator>>` — въвежда числото от конзолата
- `operator/` —  може да го оставите за накрая.
- `operator%` —  може да го оставите за накрая.

### Изисквания

- При изваждане приемете, че първото число винаги е по-голямо или равно на второто
- При деление и остатък приемете, че делителят е положително цяло число, различно от `0`
- Да се поддържа винаги валидно състояние на обекта
