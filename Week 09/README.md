## Задача 1: `Vector<T>`

Реализирайте клас `Vector<T>`, който представлява динамичен масив от елементи от тип `T`. Класът трябва да следва **Rule of 5**.

### Изисквания:

#### Private полета:
- `T* data`
- `size_t size`
- `size_t capacity` 

#### Конструктори и деструктор:
- `Vector()` - създава празен вектор
- `Vector(size_t initialCapacity)` – създава вектор с даден начален капацитет
- `Vector(const Vector<T>& other)` 
- `Vector(Vector<T>&& other) noexcept`
- `~Vector()` – деструктор
- `Vector<T>& operator=(const Vector<T>& other)` 
- `Vector<T>& operator=(Vector<T>&& other) noexcept` 

#### Гетъри
- `size_t getSize() const`
- `size_t getCapacity() const`
- `bool isEmpty() const`

#### Методи за манипулация:
- `void push_back(const T& value)` – добавя елемент в края, преоразмерява при нужда
- `void push_back(T&& value)` – move версия
- `void pop_back()` – премахва последния елемент
- `void clear()` – изчиства всички елементи
- `void resize(size_t newSize)` – променя размера

#### Оператори
- `T& operator[](size_t index)`
- `const T& operator[](size_t index) const`

#### Итератори:
- `T* begin()`
- `const T* begin() const`
- `T* end()`
- `const T* end() const`

---

## Задача 2: `Pair<K,V>` и `Map<K,V>`

### Част 1: Клас `Pair<K,V>`

Реализирайте шаблонен клас `Pair<K,V>`, който съхранява двойка ключ-стойност.

#### Private полета:
- `K key`
- `V value`

#### Конструктори:
- `Pair()`
- `Pair(const K& k, const V& v)`
- `Pair(K&& k, V&& v)`

#### Методи:
- `const K& getKey() const`
- `const V& getValue() const`
- `V& getValue()`
- `void setValue(const V& v)`
- `void setValue(V&& v)`

#### Оператори:
- `bool operator==(const Pair<K,V>& other) const` – сравнява само по ключ
- `auto operator<=>(const Pair<K,V>& other) const` – сравнява само по ключ

---

### Част 2: Клас `Map<K,V>`

Реализирайте шаблонен клас `Map<K,V>`, който използва вашия `Vector<Pair<K,V>>` за имплементация. Ключовете трябва да са уникални.

#### Private полета:
- `Vector<Pair<K,V>> data`

#### Методи:
- `void insert(const K& key, const V& value)` – добавя нова двойка или обновява съществуваща
- `void insert(K&& key, V&& value)` – move версия
- `bool remove(const K& key)` – премахва по ключ, връща `true` при успех
- `bool contains(const K& key) const` – проверява дали ключ съществува
- `V& operator[](const K& key)` – връща референция към стойността; ако ключът не съществува, го създава с default стойност
- `const V& operator[](const K& key) const` – връща стойността; ако не съществува ключа, принтира грешка
- `std::optional<V> get(const K& key) const` – връща стойността, ако ключът съществува
- `size_t size() const`
- `bool empty() const`
- `void clear()`
- `Vector<K> keys() const` – връща вектор от всички ключове
- `Vector<V> values() const` – връща вектор от всички стойности

#### Итератори:
- `Pair<K,V>* begin()`
- `const Pair<K,V>* begin() const`
- `Pair<K,V>* end()`
- `const Pair<K,V>* end() const`

---

## Задача 3: `SharedPtr<T>`

### Изисквания:

#### Private полета:
- `T* ptr` 
- `size_t* refCount` – указател към брояча на референции

#### Конструктори:
- `SharedPtr()` – създава празен указател
- `explicit SharedPtr(T* rawPtr)` – поема собственост върху raw pointer
- `SharedPtr(const SharedPtr<T>& other)` – copy constructor, увеличава брояча
- `SharedPtr(SharedPtr<T>&& other) noexcept` – move constructor, прехвърля собственост
- `~SharedPtr()` – намалява брояча, изтрива обекта при нужда

#### Оператори:
- `SharedPtr<T>& operator=(const SharedPtr<T>& other)`
- `SharedPtr<T>& operator=(SharedPtr<T>&& other) noexcept`
- `T& operator*() const` – дереференциране
- `T* operator->() const` – достъп до членове

#### Методи:
- `T* get() const` 
- `size_t use_count() const` – връща броя референции
- `explicit operator bool() const` – проверява дали сочи към обект
- `void reset()` – освобождава текущия обект
- `void reset(T* rawPtr)` – освобождава текущия и поема нов
