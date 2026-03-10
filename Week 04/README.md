
### Задача 1
Създайте клас `Student` и клас `StudentRepository`, както следва:

* **Private полета:**  
  * `id`  
  * `name`  
  * `facultyNumber`

* **Конструктори:**  
  * **Parameterized constructor** – задава всички полета  
  * **Default constructor = default**

* **Student – Методи:**  
  * `print()` – извежда информацията за студента  

* **StudentRepository – Private полета:**  
  * `std::vector<Student> students`  
  * `std::string filename` – файлът, в който се съхраняват студентите  
  * `static int nextId` – генерира следващото ID  

* **StudentRepository – Конструктор:**  
  * `StudentRepository(const std::string& filename)` – задава файла и зарежда студентите от него при създаване на repository-то  

* **StudentRepository – Методи:**  
  * `void addStudent(const std::string& name, const std::string& facultyNumber)` – създава студент с автоматично генерирано `id` и го добавя в repository-то  
  * `std::optional<Student> findById(int id)` – намира студент по `id`
  * `bool updateStudent(int id, const std::string& name, const std::string& facultyNumber)` – обновява информацията за студент по `id`  
  * `bool deleteStudent(int id)` – изтрива студент по `id`  
  * `void save()` – записва всички студенти във файла  
  * `void load()` – зарежда студентите от файла  
  * `std::vector<Student> getAll()` – връща всички студенти
 
### Задача 2
Създайте клас `ValidationUtils`, който съдържа статични методи за валидиране на най-често използвани типове данни.

* **Клас:**  
  * `ValidationUtils` – съдържа само `static` методи и не изисква създаване на обект

* **Конструктори:**  
  * `ValidationUtils() = delete` – забранява създаването на обекти от класа

* **ValidationUtils – Методи:**  
  * `static bool isEmpty(const std::string& value)` – проверява дали даден текст е празен  
  * `static bool isNumber(const std::string& value)` – проверява дали текстът съдържа само цифри  
  * `static bool isValidEmail(const std::string& email)` – проверява дали даден текст е валиден имейл адрес  
  * `static bool isValidLength(const std::string& value, size_t min, size_t max)` – проверява дали дължината на текста е в даден интервал  
  * `static bool isAlphabetic(const std::string& value)` – проверява дали текстът съдържа само букви  
  * `static bool isAlphanumeric(const std::string& value)` – проверява дали текстът съдържа само букви и цифри  
  * `static bool isInRange(int value, int min, int max)` – проверява дали число е в даден интервал  
  * `static bool isValidFacultyNumber(const std::string& fn)` – проверява дали факултетният номер е във валиден формат  
  * `static bool startsWith(const std::string& value, const std::string& prefix)` – проверява дали текстът започва с даден префикс  
  * `static bool endsWith(const std::string& value, const std::string& suffix)` – проверява дали текстът завършва с даден суфикс  
