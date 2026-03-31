### Какво ще се изведе?

```cpp
class Box {
    std::string data;

public:
    Box(std::string d) : data(std::move(d)) {}

    void append(const std::string& s) {
        data += s;
    }

    void print() const {
        std::cout << "[" << data << "]\n";
    }
};

int main() {
    std::string txt = "hi";
    Box b1(std::move(txt));

    txt += "!!!";

    b1.append(" world");

    std::cout << "txt=" << txt << "\n";
    b1.print();
}
```

```cpp
class Unique {
public:
    Unique() = default;
    Unique(const Unique&) = delete;
};

int main() {
    Unique x;
    Unique y(x);
    std::cout << "ok";
}
```

```cpp
struct Point {
    int x, y;
    auto operator<=>(const Point&) const = default;
};

int main() {
    Point a{2, 3}, b{2, 5};
    std::cout << (a == b) << " "
              << (a < b)  << " "
              << (a != b) << "\n";
}
```

```cpp
class Cache {
    mutable int accessCount = 0;
    int value = 42;

public:
    int get() const { 
        accessCount++; 
        return value; 
    }

    void report() const {
        std::cout << "Accessed " << accessCount << " times" << std::endl;
    }
};

int main() {
    const Cache c;
    c.get();
    c.get();
    c.report();
}
```

```cpp
struct Celsius {
    double val;
    explicit Celsius(double v) : val(v) {}
};

struct Fahrenheit {
    double val;
    Fahrenheit(double v) : val(v) {}
};

void print(Fahrenheit f) { std::cout << f.val << "\n"; }

int main() {
    print(98.6);
    print(Fahrenheit(100.0));
    print(Celsius(37.0));
}
```

```cpp
class Scoreboard {
    int score = 0;

public:
    void addPoint() { ++score; std::cout << "point! score=" << score << "\n"; }
    void reset()    { score = 0; std::cout << "reset\n"; }
    int  get() const{ return score; }
};
int main() {
    const Scoreboard s;
    std::cout << s.get() << "\n";
    s.addPoint();
    s.reset();
}
```

```cpp
class Account {
    double balance = 100.0;
    static double rate;

public:
    static void setRate(double r) { rate = r; }

    static void printBalance() {
        std::cout << "balance=" << balance << "\n";
    }

    void printAll() const {
        std::cout << balance << " @ " << rate << "\n";
    }
};

double Account::rate = 0.05;

int main() {
    Account a;
    Account::setRate(0.07);
    Account::printBalance();
    a.printAll();
}
```

Създайте клас `Song` и клас `Playlist`, които управляват песни и плейлисти.

# Задачи

### Клас Song

- **Private полета:**
  * `char* title`
  * `char* artist`
  * `int duration`

- **Rule of Five:**
  * `Song(const char* title, const char* artist, int duration)`
  * `Song(const Song& other)`
  * `Song(Song&& other)`
  * `Song& operator=(const Song& other)` 
  * `Song& operator=(Song&& other)`
  * `~Song()` 

- **Методи:**
  * `const char* getTitle() const`
  * `const char* getArtist() const`
  * `int getDuration() const`

- **Оператори:**
  * `auto operator<=>(const Song& other) const` – сравнява по `duration`, после лексикографски по `title`
  * `bool operator==(const Song& other) const`
  * `friend std::ostream& operator<<(std::ostream& os, const Song& s)`
---

### Клас `Playlist`

- **Private полета:**
  * `Song* songs`
  * `size_t count`
  * `size_t capacity`

- **Rule of Five:**
  * `Playlist(size_t cap = 8)`
  * `Playlist(const Playlist& other)`
  * `Playlist(Playlist&& other)`
  * `Playlist& operator=(const Playlist& other)`
  * `Playlist& operator=(Playlist&& other)`
  * `~Playlist()`

- **Методи:**
  * `void addSong(const Song& s)` – добавя копие, преоразмерява при нужда
  * `void addSong(Song&& s)` – добавя чрез move
  * `void removeSong(size_t idx)` – премахва по индекс, пренарежда
  * `Song& operator[](size_t idx)` – достъп за промяна
  * `const Song& operator[](size_t idx) const` – достъп за четене
  * `size_t getCount() const`
  * `int totalDuration() const` – сума от всички `duration`
  * `void sortByDuration()` – сортира песните (ползвайте `operator<=>`)
  * `void print() const` – отпечатва всички песни с `operator<<`

