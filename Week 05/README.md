
## Live Coding
Създайте клас `MyString`, който управлява динамично заделена памет за текст.  

- **Private полета:**  
  * `char* data` – указател към динамичния масив с символи  
  * `size_t len` – текуща дължина на текста  
  * `size_t capacity` – капацитет на масива  

- **Конструктори и деструктор:**  
  * `MyString(const char* str)` – създава нова инстанция от C-style низ  
  * `MyString(const MyString& other)` – копиращ конструктор  
  * `MyString& operator=(const MyString& other)` – оператор за присвояване  
  * `~MyString()` – освобождава паметта  

- **Методи:**  
  * `MyString& append(const MyString& other)` – добавя друг низ към текущия  
  * `const char* c_str() const` – връща указател към символния низ  
  * `size_t getLen() const` 
  * `size_t getCapacity() const` 
  * `char& operator[](size_t idx)` – достъп до символ за промяна  
  * `const char& operator[](size_t idx) const` – достъп до символ за четене  
  * `MyString reversed() const` – връща нов стринг, обърнат  

### Задача 1 - Matrix

- **Private полета:**  
  * `double** data` – указател към динамично заделена 2D матрица  
  * `size_t rows` – брой редове  
  * `size_t cols` – брой колони  

- **Конструктори и деструктор:**  
  * `Matrix(size_t r, size_t c)` – създава нова матрица с r реда и c колони, инициализирана с 0.0  
  * `Matrix(const Matrix& other)`
  * `Matrix& operator=(const Matrix& other)`
  * `~Matrix()`

- **Методи:**  
  * `double& at(size_t r, size_t c)` – достъп до елемент за промяна  
  * `const double& at(size_t r, size_t c) const` – достъп до елемент за четене  
  * `Matrix transposed() const` – връща нова транспонирана матрица  
  * `size_t getRows() const`  
  * `size_t getCols() const`  

### Задача 2

- **Car клас – Private полета:**  
  * `std::string brand`
  * `std::string model`
  * `int year`

- **Car клас – Конструктори:**  
  * `Car()`   
  * `Car(const std::string& brand, const std::string& model, int year)`

- **Parking клас – Private полета:**  
  * `Car* cars`
  * `size_t count` 
  * `size_t capacity`

- **Parking клас – Конструктори и деструктор:**  
  * `Parking(size_t cap = 10)`
  * `Parking(const Parking& other)`
  * `Parking& operator=(const Parking& other)` 
  * `~Parking()`

- **Parking клас – Методи:**  
  * `void addCar(const Car& car)` – добавя нов автомобил, преоразмерява масива ако е необходимо  
  * `Car& getCar(size_t idx)` – достъп до автомобил за промяна  
  * `const Car& getCar(size_t idx) const` – достъп до автомобил за четене  
  * `void removeCar(size_t idx)` – премахва автомобил и пренарежда масива  
  * `size_t getCount() const`  
  * `size_t getCapacity() const`
