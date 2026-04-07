
# Задача 1

### Клас `Product`

- **Private полета:**

  * `std::string name`

  * `std::string category`

  * `double price`

  * `int quantity`

- **Конструктор:**

  * `Product(std::string name, std::string category, double price, int quantity)`



- **Методи:**

  * `const std::string& getName() const`

  * `const std::string& getCategory() const`

  * `double getPrice() const`

  * `int getQuantity() const`

  * `double totalValue() const`


- **Оператори:**

  * `bool operator==(const Product& other) const`

  * `auto operator<=>(const Product& other) const` — първо по `price`, после по `name`

  * `friend std::ostream& operator<<(std::ostream&, const Product&)`



---



### Клас `Inventory`



- **Private полета:**

  * `std::vector<Product> products`



- **Методи:**

  * `void addProduct(const Product& p)`

  * `void removeByName(const std::string& name)`

  * `std::vector<Product> filterByCategory(const std::string& category) const`

  * `std::vector<Product> filterByPrice(double min, double max) const`

  * `double totalInventoryValue() const`

  * `void sortByPrice()`

  * `std::optional<Product> findCheapest() const`

  * `void print() const`


---



# Задача 2 


### Клас `Task`



- **Private полета:**

  * `std::string title`

  * `std::string description`

  * `int priority` (1–5)

  * `bool completed`



- **Конструктор:**

  * `Task(std::string title, std::string desc, int priority)`



- **Методи:**

  * `void markDone()`

  * `bool isCompleted() const`

  * `int getPriority() const`

  * `const std::string& getTitle() const`



- **Оператори:**

  * `auto operator<=>(const Task& other) const` — по `priority` (по-висок приоритет първо)

  * `friend std::ostream& operator<<(std::ostream&, const Task&)`



---



### Клас `TaskManager`



- **Private полета:**

  * `std::vector<Task> tasks`



- **Методи:**

  * `void addTask(const Task& t)`

  * `void removeCompleted()`

  * `std::vector<Task> getCompleted() const`

  * `std::vector<Task> getPending() const`

  * `std::vector<Task> filterByPriority(int minPriority) const`

  * `void sortByPriority()`

  * `std::optional<Task> findMostImportant() const`

  * `void printAll() const`



---



# Задача 3 


### Клас `Vehicle`



- **Private полета:**

  * `std::string brand`

  * `std::string model`

  * `int year`

  * `double mileage`



- **Конструктор:**

  * `Vehicle(std::string brand, std::string model, int year, double mileage)`



- **Методи:**

  * `int getYear() const`

  * `double getMileage() const`

  * `const std::string& getBrand() const`



- **Оператори:**

  * `auto operator<=>(const Vehicle& other) const` — по `year`, после по `mileage`

  * `friend std::ostream& operator<<(std::ostream&, const Vehicle&)`



---



### Клас `Garage`



- **Private полета:**

  * `std::vector<Vehicle> vehicles`



- **Методи:**

  * `void addVehicle(const Vehicle& v)`

  * `void removeOld(int yearThreshold)`

  * `std::vector<Vehicle> filterByMileage(double maxMileage) const`

  * `std::vector<Vehicle> filterByBrand(const std::string& brand) const`

  * `void sortByYear()`

  * `double averageMileage() const`

  * `std::optional<Vehicle> newestVehicle() const`

  * `void print() const`



---



# Задача 4 

### Клас `Message`



- **Private полета:**

  * `std::string sender`

  * `std::string content`

  * `long timestamp`



- **Конструктор:**

  * `Message(std::string sender, std::string content, long timestamp)`



- **Методи:**

  * `const std::string& getSender() const`

  * `long getTimestamp() const`



- **Оператори:**

  * `auto operator<=>(const Message& other) const` — по `timestamp`

  * `friend std::ostream& operator<<(std::ostream&, const Message&)`



---



### Клас `Chat`

- **Private полета:**

  * `std::vector<Message> messages`



- **Методи:**

  * `void sendMessage(const Message& m)`

  * `std::vector<Message> getMessagesFrom(const std::string& sender) const`

  * `std::vector<Message> getMessagesInRange(long from, long to) const`

  * `void deleteMessagesFrom(const std::string& sender)`

  * `void sortByTime()`

  * `std::optional<Message> latestMessage() const`

  * `void print() const`

---

