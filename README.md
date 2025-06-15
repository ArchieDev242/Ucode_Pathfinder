# <h1 align = "center">Ucode Pathfinder Repository</h1>

<p align = "center">
  <a href = "https://campus.kpi.kharkov.ua/ua/">
    <img src = "imgs/Cumpus.png" alt = "Innovation Campus" width = "300" height = "300">
  </a>
  <br>
  <h2 align = "center"><strong>Innovation Campus | Pathfinder | 2024</strong></h2>
</p>

<details open>
  <summary>Українська 🇺🇦</summary>

<span style = "margin-top: 5px;"></span>

> ⚠️ **УВАГА:**
>
> Цей репозиторій містить реалізацію алгоритму пошуку найкоротших шляхів між островами, розроблену в рамках Track C в Innovation Campus.  
> Код перевірений на коректність та ефективність, з дотриманням строгих стандартів кодування.
>
> **Без зовнішніх залежностей** — тільки чистий C та кастомна бібліотека libmx!

---

### Вступ

Ласкаво просимо до репозиторію **Ucode Pathfinder**! Цей проєкт є частиною Track C, де завданням є реалізація алгоритму пошуку найкоротших шляхів між пунктами на карті. Розробка цього алгоритму дозволяє глибше зрозуміти роботу графових алгоритмів та їх застосування в реальному житті.

### Головна ідея

Основна ідея цього завдання — реалізувати ефективний алгоритм для знаходження всіх найкоротших маршрутів між пунктами на карті, з урахуванням ваг шляхів.

### Основне питання

Які алгоритми можуть допомогти ефективно використовувати час та ресурси для пошуку оптимальних маршрутів?

### Завдання

Розробити програму, яка знаходить всі найкоротші маршрути між усіма парами островів на карті. Програма приймає на вхід файл з описом мостів між островами та їх довжинами, а виводить всі унікальні найкоротші маршрути між кожною парою островів.

---

### Встановлення та використання

```bash
# Клонувати репозиторій
git clone https://github.com/ArchieDev242/Ucode_Pathfinder.git

# Перейти до директорії проєкту
cd Ucode_Pathfinder

# Зібрати проєкт
make all 

# Запустити програму
./pathfinder [файл_з_даними]
```

### Особливості реалізації

- Використання алгоритму Дейкстри для пошуку найкоротших шляхів
- Ефективне зберігання графу у вигляді матриці суміжності
- Оптимізація пам'яті та часу виконання
- Детальна обробка помилок у вхідних даних

### Структура проєкту

```
Ucode_Pathfinder/
├── inc/               # Заголовочні файли
│   └── pathfinder.h   # Головний заголовний файл
├── src/               # Вихідні файли
│   ├── main.c         # Головний файл програми
│   ├── mx_errors_handling.c  # Обробка помилок
│   └── mx_paths_handling.c   # Логіка роботи з шляхами
├── libmx/             # Власна бібліотека функцій
├── Makefile           # Інструкції для збірки
└── README.md          # Документація
```

### 🖥️ Приклади використання

#### Формат вхідного файлу

```
[кількість_островів]
[острів1]-[острів2],[довжина_моста]
...
```

#### Приклад 1: Просте використання

**Вхідний файл (input.txt):**
```
3
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
```

**Вивід програми:**
```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
```

#### Приклад 2: Складніший граф з альтернативними маршрутами

**Вхідний файл (graph.txt):**
```
5
A-B,11
A-C,10
B-D,5
C-D,6
C-E,15
D-E,4
```

**Вивід програми:**
```
========================================
Path: A -> B
Route: A -> B
Distance: 11
========================================
========================================
Path: A -> C
Route: A -> C
Distance: 10
========================================
========================================
Path: A -> D
Route: A -> B -> D
Distance: 11 + 5 = 16
========================================
========================================
Path: A -> D
Route: A -> C -> D
Distance: 10 + 6 = 16
========================================
========================================
Path: A -> E
Route: A -> B -> D -> E
Distance: 11 + 5 + 4 = 20
========================================
========================================
Path: A -> E
Route: A -> C -> D -> E
Distance: 10 + 6 + 4 = 20
========================================
========================================
Path: B -> C
Route: B -> D -> C
Distance: 5 + 6 = 11
========================================
========================================
Path: B -> D
Route: B -> D
Distance: 5
========================================
========================================
Path: B -> E
Route: B -> D -> E
Distance: 5 + 4 = 9
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 4 = 10
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 4
========================================
```

### Повідомлення про помилки

- `usage: ./pathfinder [filename]` - невірна кількість аргументів
- `error: file [filename] does not exist` - файл не існує
- `error: file [filename] is empty` - файл порожній
- `error: line [n] is not valid` - невірний формат рядка n
- `error: invalid number of islands` - кількість островів не відповідає вказаній
- `error: duplicate bridges` - виявлено дублюючі мости
- `error: sum of bridges lengths is too big` - сума довжин перевищує INT_MAX


### <h1 align = "center"> 🔧 Використані технології 🛠️ </h1>

<div align = "center">
  <table>
    <tr>
      <td align = "center"><h4>🧰 Мови</h4></td>
      <td align = "center"><h4>🔨 Інструменти розробки</h4></td>
      <td align = "center"><h4>💻 Платформи</h4></td>
      <td align = "center"><h4>📝 Редактори</h4></td>
    </tr>
    <tr>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://en.wikipedia.org/wiki/C_(programming_language)">
            <img src = "https://skillicons.dev/icons?i=c" alt = "C" width = "50" height = "50">
          </a>
          <br><strong>C</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/bash/">
            <img src = "https://skillicons.dev/icons?i=bash" alt = "Bash" width = "50" height = "50">
          </a>
          <br><strong>Bash</strong>
        </p>
        <p>
          <a href = "https://www.markdownguide.org/">
            <img src = "https://skillicons.dev/icons?i=md" alt = "Markdown" width = "50" height = "50">
          </a>
          <br><strong>Markdown</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://git-scm.com/">
            <img src = "https://skillicons.dev/icons?i=git" alt = "Git" width = "50" height = "50">
          </a>
          <br><strong>Git</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/make/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/2/22/Heckert_GNU_white.svg" alt = "Make" width = "50" height = "50">
          </a>
          <br><strong>Make</strong>
        </p>
        <p>
          <a href = "https://gcc.gnu.org/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/a/af/GNU_Compiler_Collection_logo.svg" alt = "GCC" width = "50" height = "50">
          </a>
          <br><strong>GCC</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://www.linux.org/">
            <img src = "https://skillicons.dev/icons?i=linux" alt = "Linux" width = "50" height = "50">
          </a>
          <br><strong>Linux</strong>
        </p>
        <p>
          <a href = "https://www.microsoft.com/windows/">
            <img src = "https://skillicons.dev/icons?i=windows" alt = "Windows" width = "50" height = "50">
          </a>
          <br><strong>Windows</strong>
        </p>
        <p>
          <a href = "https://www.apple.com/macos/">
            <img src = "https://skillicons.dev/icons?i=apple" alt = "macOS" width = "50" height = "50">
          </a>
          <br><strong>macOS</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://code.visualstudio.com/">
            <img src = "https://skillicons.dev/icons?i=vscode" alt = "VSCode" width = "50" height = "50">
          </a>
          <br><strong>VSCode</strong>
        </p>
        <p>
          <a href = "https://www.vim.org/">
            <img src = "https://skillicons.dev/icons?i=vim" alt = "Vim" width = "50" height = "50">
          </a>
          <br><strong>Vim</strong>
        </p>
        <p>
          <a href = "https://neovim.io/">
            <img src = "https://skillicons.dev/icons?i=neovim" alt = "NeoVim" width = "50" height = "50">
          </a>
          <br><strong>NeoVim</strong>
        </p>
      </td>
    </tr>
    <tr>
      <td colspan = "4" align = "center">
        <h4>☁️ Хмарні сервіси</h4>
        <p>
          <a href = "https://github.com/">
            <img src = "https://skillicons.dev/icons?i=github" alt = "GitHub" width = "50" height = "50">
          </a>
          <strong>GitHub</strong>
          &nbsp;&nbsp;&nbsp;&nbsp;
          <a href = "https://about.gitlab.com/">
            <img src = "https://skillicons.dev/icons?i=gitlab" alt = "GitLab" width = "50" height = "50">
          </a>
          <strong>GitLab</strong>
        </p>
      </td>
    </tr>
  </table>
  
  <div>
    <p><i>🚀 Цей проєкт було створено з використанням цих потужних технологій 🚀</i></p>
  </div>
</div>

## <h1 align = "center"> ✨ ОСОБЛИВА ПОДЯКА ✨ </h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Дякуємо-AADmitriy-purple?style=for-the-badge&logo=github" alt = "Дякуємо AADmitriy">
  <br><br>
  
  <h3>🌟 Сердечна вдячність 🌟</h3>
  
  <p>
    Особлива подяка 
    <a href = "https://github.com/AADmitriy"><b>AADmitriy</b></a> 
    за безцінний репозиторій 
    <a href = "https://github.com/AADmitriy/pathfinder-checker"><b>pathfinder-checker</b></a>.
  </p>
  
  <img src = "https://img.shields.io/badge/Інструмент-pathfinder--checker-blue?style=flat-square" alt = "pathfinder-checker">
</div>


<br>

### 📌 Що таке pathfinder-checker?

Це спеціалізований інструмент тестування, призначений для перевірки реалізації Pathfinder на:
- Коректність роботи алгоритму
- Витоки пам'яті
- Обробку помилок у вхідних даних
- Відповідність вимогам завдання

<div align = "center">
  <table>
    <tr>
      <td align = "center">
        <h3>🧪</h3>
        <b>Тестування</b>
      </td>
      <td align = "center">
        <h3>🐛</h3>
        <b>Налагодження</b>
      </td>
      <td align = "center">
        <h3>🚀</h3>
        <b>Продуктивність</b>
      </td>
    </tr>
  </table>
</div>

> Без таких фантастичних внесків від спільноти проєкти на кшталт цього були б значно складнішими!

<div align = "center">
  <br>
  <a href = "https://github.com/AADmitriy/pathfinder-checker">
    <img src = "https://img.shields.io/badge/Відвідати_репозиторій-pathfinder--checker-6a0dad?style=for-the-badge&logo=github" alt = "Відвідати репозиторій pathfinder-checker">
  </a>
  <br><br>
</div>

## <h1 align = "center">🌟 Мої висновки 🌟</h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Досвід-Трансформаційний-brightgreen?style=for-the-badge" alt = "Досвід">
</div>

### 💡 Технічне зростання

Робота над проєктом Pathfinder трансформувала мій підхід до розробки графових алгоритмів. Ця подорож принесла кілька переваг:

- **Опанування графових алгоритмів:**
  - Отримав глибоке розуміння графів, матриць суміжності та алгоритмів пошуку шляхів
  - Навчився ефективно реалізовувати алгоритм Дейкстри для пошуку найкоротших шляхів
  - Реалізував систему обробки помилок для різних вхідних даних

- **Навички оптимізації:**
  - Навчився оптимізувати роботу з матрицями для ефективного зберігання графів
  - Впровадив кешування результатів для уникнення повторних обчислень
  - Оптимізував алгоритми для роботи з великими графами

- **Кваліфікована обробка помилок:**
  - Розробив систему детальної обробки помилок для різних типів вхідних даних
  - Навчився аналізувати та виявляти проблемні випадки в графі
  - Реалізував ефективні механізми відновлення після помилок

### 🤝 Співпраця і процес

Цей проєкт не лише про код — він трансформував мій спосіб роботи з іншими:

- **Навчання з колегами:**
  - Удосконалив рішення через перевірку коду та спільне відлагодження
  - Ділився знаннями, пояснюючи вибір алгоритмів
  - Документував граничні випадки, виявлені під час групових сесій тестування

- **Дисципліна розробки:**
  - Прийняв обмеження для написання чистішого, швидшого, більш підтримуваного коду
  - Впровадив систематичні підходи до тестування для кожної функції
  - Розробив методології усунення проблем для комплексних проблем з графами

### 🚀 Довгостроковий вплив

Навички, розвинені під час цього проєкту, виходять далеко за межі самого коду:

- **Передавані знання:**
  - Вивчені шаблони застосовуються до розробки графових алгоритмів на будь-якій мові
  - Створено повторно використовувані компоненти, які прискорять майбутні проєкти
  - Розвинуто інтуїцію щодо оптимізації графових алгоритмів

- **Спосіб мислення для вирішення проблем:**
  - Навчився розбивати складні операції на логічні, керовані кроки
  - Розвинув стійкість при зіткненні зі складними помилками або проблемами дизайну
  - Набув впевненості у вирішенні нечітких або неоднозначних вимог

    ---

    <p align = "center"><i>Давайте програмувати наш шлях до успіху!</i> 💻</p>

    </details>

<details>
  <summary>English 🇬🇧</summary>

<span style = "margin-top: 5px;"></span>

> ⚠️ **WARNING:**
>
> This repository contains an implementation of a shortest path finding algorithm between islands, developed as part of Track C at Innovation Campus.  
> The code has been verified for correctness and efficiency, adhering to strict coding standards.
>
> **No external dependencies** — just pure C and the custom libmx library!

---

### Introduction

Welcome to the **Ucode Pathfinder** repository! This project is part of Track C, where the challenge is to implement an algorithm for finding the shortest paths between points on a map. Developing this algorithm provides a deeper understanding of graph algorithms and their real-world applications.

### The Big Idea

The main idea of this task is to implement an efficient algorithm for finding all shortest routes between points on a map, taking into account path weights.

### Essential Question

What algorithms can help effectively use time and resources to find optimal routes?

### The Challenge

Develop a program that finds all shortest routes between all pairs of islands on a map. The program takes as input a file describing bridges between islands and their lengths, and outputs all unique shortest routes between each pair of islands.

---

### Installation and Usage

```bash
# Clone the repository
git clone https://github.com/ArchieDev242/Ucode_Pathfinder.git

# Navigate to the project directory
cd Ucode_Pathfinder

# Build the project
make all

# Run the program
./pathfinder [data_file]
```

### Implementation Features

- Dijkstra's algorithm for finding shortest paths
- Efficient graph storage as an adjacency matrix
- Memory and runtime optimization
- Detailed input data error handling

### 🖥️ Usage Examples

#### Input File Format

```
[number_of_islands]
[island1]-[island2],[bridge_length]
...
```

#### Example 1: Basic Usage

**Input file (input.txt):**
```
3
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
```

**Program output:**
```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
```

#### Example 2: Complex Graph with Alternative Routes

**Input file (graph.txt):**
```
5
A-B,11
A-C,10
B-D,5
C-D,6
C-E,15
D-E,4
```

**Program output:**
```
========================================
Path: A -> B
Route: A -> B
Distance: 11
========================================
========================================
Path: A -> C
Route: A -> C
Distance: 10
========================================
========================================
Path: A -> D
Route: A -> B -> D
Distance: 11 + 5 = 16
========================================
========================================
Path: A -> D
Route: A -> C -> D
Distance: 10 + 6 = 16
========================================
========================================
Path: A -> E
Route: A -> B -> D -> E
Distance: 11 + 5 + 4 = 20
========================================
========================================
Path: A -> E
Route: A -> C -> D -> E
Distance: 10 + 6 + 4 = 20
========================================
========================================
Path: B -> C
Route: B -> D -> C
Distance: 5 + 6 = 11
========================================
========================================
Path: B -> D
Route: B -> D
Distance: 5
========================================
========================================
Path: B -> E
Route: B -> D -> E
Distance: 5 + 4 = 9
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 4 = 10
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 4
========================================
```

### Error Messages

- `usage: ./pathfinder [filename]` - invalid number of arguments
- `error: file [filename] does not exist` - file doesn't exist
- `error: file [filename] is empty` - file is empty
- `error: line [n] is not valid` - invalid format in line n
- `error: invalid number of islands` - number of islands doesn't match the specified count
- `error: duplicate bridges` - duplicate bridges detected
- `error: sum of bridges lengths is too big` - sum of lengths exceeds INT_MAX

### Project Structure

```
Ucode_Pathfinder/
├── inc/               # Header files
│   └── pathfinder.h   # Main header file
├── src/               # Source files
│   ├── main.c         # Main program file
│   ├── mx_errors_handling.c  # Error handling
│   └── mx_paths_handling.c   # Path handling logic
├── libmx/             # Custom function library
├── Makefile           # Build instructions
└── README.md          # Documentation
```

### <h1 align = "center"> 🔧 Technologies Used 🛠️ </h1>

<div align = "center">
  <table>
    <tr>
      <td align = "center"><h4>🧰 Languages</h4></td>
      <td align = "center"><h4>🔨 Development Tools</h4></td>
      <td align = "center"><h4>💻 Platforms</h4></td>
      <td align = "center"><h4>📝 Editors</h4></td>
    </tr>
    <tr>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://en.wikipedia.org/wiki/C_(programming_language)">
            <img src = "https://skillicons.dev/icons?i=c" alt = "C" width = "50" height = "50">
          </a>
          <br><strong>C</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/bash/">
            <img src = "https://skillicons.dev/icons?i=bash" alt = "Bash" width = "50" height = "50">
          </a>
          <br><strong>Bash</strong>
        </p>
        <p>
          <a href = "https://www.markdownguide.org/">
            <img src = "https://skillicons.dev/icons?i=md" alt = "Markdown" width = "50" height = "50">
          </a>
          <br><strong>Markdown</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://git-scm.com/">
            <img src = "https://skillicons.dev/icons?i=git" alt = "Git" width = "50" height = "50">
          </a>
          <br><strong>Git</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/make/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/2/22/Heckert_GNU_white.svg" alt = "Make" width = "50" height = "50">
          </a>
          <br><strong>Make</strong>
        </p>
        <p>
          <a href = "https://gcc.gnu.org/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/a/af/GNU_Compiler_Collection_logo.svg" alt = "GCC" width = "50" height = "50">
          </a>
          <br><strong>GCC</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://www.linux.org/">
            <img src = "https://skillicons.dev/icons?i=linux" alt = "Linux" width = "50" height = "50">
          </a>
          <br><strong>Linux</strong>
        </p>
        <p>
          <a href = "https://www.microsoft.com/windows/">
            <img src = "https://skillicons.dev/icons?i=windows" alt = "Windows" width = "50" height = "50">
          </a>
          <br><strong>Windows</strong>
        </p>
        <p>
          <a href = "https://www.apple.com/macos/">
            <img src = "https://skillicons.dev/icons?i=apple" alt = "macOS" width = "50" height = "50">
          </a>
          <br><strong>macOS</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://code.visualstudio.com/">
            <img src = "https://skillicons.dev/icons?i=vscode" alt = "VSCode" width = "50" height = "50">
          </a>
          <br><strong>VSCode</strong>
        </p>
        <p>
          <a href = "https://www.vim.org/">
            <img src = "https://skillicons.dev/icons?i=vim" alt = "Vim" width = "50" height = "50">
          </a>
          <br><strong>Vim</strong>
        </p>
        <p>
          <a href = "https://neovim.io/">
            <img src = "https://skillicons.dev/icons?i=neovim" alt = "NeoVim" width = "50" height = "50">
          </a>
          <br><strong>NeoVim</strong>
        </p>
      </td>
    </tr>
    <tr>
      <td colspan = "4" align = "center">
        <h4>☁️ Cloud Services</h4>
        <p>
          <a href = "https://github.com/">
            <img src = "https://skillicons.dev/icons?i=github" alt = "GitHub" width = "50" height = "50">
          </a>
          <strong>GitHub</strong>
          &nbsp;&nbsp;&nbsp;&nbsp;
          <a href = "https://about.gitlab.com/">
            <img src = "https://skillicons.dev/icons?i=gitlab" alt = "GitLab" width = "50" height = "50">
          </a>
          <strong>GitLab</strong>
        </p>
      </td>
    </tr>
  </table>
  
  <div>
    <p><i>🚀 This project was crafted with these powerful technologies 🚀</i></p>
  </div>
</div>

## <h1 align = "center"> ✨ SPECIAL THANKS ✨ </h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Thank_You-AADmitriy-purple?style=for-the-badge&logo=github" alt = "Thank You AADmitriy">
  <br><br>
  
  <h3>🌟 Heartfelt Gratitude 🌟</h3>
  
  <p>
    A special thanks to 
    <a href = "https://github.com/AADmitriy"><b>AADmitriy</b></a> 
    for the invaluable 
    <a href = "https://github.com/AADmitriy/pathfinder-checker"><b>pathfinder-checker</b></a> 
    repository.
  </p>
  
  <img src = "https://img.shields.io/badge/Tool-pathfinder--checker-blue?style=flat-square" alt = "pathfinder-checker">
</div>


<br>

### 📌 What is pathfinder-checker?

This is a specialized testing tool designed to check Pathfinder implementation for:
- Algorithm correctness
- Memory leaks
- Input data error handling
- Compliance with task requirements

<div align = "center">
  <table>
    <tr>
      <td align = "center">
        <h3>🧪</h3>
        <b>Testing</b>
      </td>
      <td align = "center">
        <h3>🐛</h3>
        <b>Debugging</b>
      </td>
      <td align = "center">
        <h3>🚀</h3>
        <b>Performance</b>
      </td>
    </tr>
  </table>
</div>

> Without such fantastic contributions from the community, projects like this would be significantly more challenging!

<div align = "center">
  <br>
  <a href = "https://github.com/AADmitriy/pathfinder-checker">
    <img src = "https://img.shields.io/badge/Visit_Repository-pathfinder--checker-6a0dad?style=for-the-badge&logo=github" alt = "Visit pathfinder-checker Repository">
  </a>
  <br><br>
</div>

## <h1 align = "center">🌟 My Conclusions 🌟</h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Experience-Transformational-brightgreen?style=for-the-badge" alt = "Experience">
</div>

### 💡 Technical Growth

Working on the Pathfinder project transformed my approach to developing graph algorithms. This journey brought several benefits:

- **Mastering Graph Algorithms:**
  - Gained deep understanding of graphs, adjacency matrices, and pathfinding algorithms
  - Learned to efficiently implement Dijkstra's algorithm for shortest path search
  - Implemented error handling systems for various input data

- **Optimization Skills:**
  - Learned to optimize matrix operations for efficient graph storage
  - Implemented result caching to avoid redundant calculations
  - Optimized algorithms for working with large graphs

- **Professional Error Handling:**
  - Developed detailed error handling systems for different types of input data
  - Learned to analyze and identify problematic cases in graphs
  - Implemented efficient error recovery mechanisms

### 🤝 Collaboration & Process

This project wasn't just about code — it transformed how I work with others:

- **Learning with Colleagues:**
  - Improved solutions through code review and collaborative debugging
  - Shared knowledge by explaining algorithm choices
  - Documented edge cases discovered during group testing sessions

- **Development Discipline:**
  - Adopted constraints to write cleaner, faster, more maintainable code
  - Implemented systematic testing approaches for each function
  - Developed troubleshooting methodologies for complex graph problems

### 🚀 Long-term Impact

The skills developed during this project extend far beyond the code itself:

- **Transferable Knowledge:**
  - Learned patterns apply to graph algorithm development in any language
  - Created reusable components that will speed up future projects
  - Developed intuition for graph algorithm optimization

- **Problem-solving Mindset:**
  - Learned to break down complex operations into logical, manageable steps
  - Developed resilience when facing complex bugs or design problems
  - Gained confidence in solving unclear or ambiguous requirements

---

<p align = "center"><i>Let's code our way to success!</i> 💻</p>

</details>

<details>
  <summary>Deutsch 🇩🇪</summary>

<span style = "margin-top: 5px;"></span>

> ⚠️ **ACHTUNG:**
>
> Dieses Repository enthält eine Implementierung eines Algorithmus zur Suche nach den kürzesten Wegen zwischen Inseln, entwickelt als Teil von Track C am Innovation Campus.  
> Der Code wurde auf Korrektheit und Effizienz überprüft und entspricht strengen Kodierungsstandards.
>
> **Keine externen Abhängigkeiten** — nur reines C und die benutzerdefinierte libmx-Bibliothek!

---

### Einführung

Willkommen im **Ucode Pathfinder** Repository! Dieses Projekt ist Teil von Track C, bei dem die Herausforderung darin besteht, einen Algorithmus zur Suche nach den kürzesten Wegen zwischen Punkten auf einer Karte zu implementieren. Die Entwicklung dieses Algorithmus ermöglicht ein tieferes Verständnis von Graphenalgorithmen und deren Anwendungen in der Praxis.

### Die große Idee

Die Hauptidee dieser Aufgabe besteht darin, einen effizienten Algorithmus zur Suche aller kürzesten Routen zwischen Punkten auf einer Karte unter Berücksichtigung von Pfadgewichten zu implementieren.

### Wesentliche Frage

Welche Algorithmen können dabei helfen, Zeit und Ressourcen effektiv für die Suche nach optimalen Routen zu nutzen?

### Die Herausforderung

Entwickeln Sie ein Programm, das alle kürzesten Routen zwischen allen Inselpaaren auf einer Karte findet. Das Programm nimmt eine Datei mit der Beschreibung von Brücken zwischen Inseln und deren Längen entgegen und gibt alle eindeutigen kürzesten Routen zwischen jedem Inselpaar aus.

---

### Installation und Verwendung

```bash
# Repository klonen
git clone https://github.com/ArchieDev242/Ucode_Pathfinder.git

# Zum Projektverzeichnis navigieren
cd Ucode_Pathfinder

# Projekt erstellen
make all

# Programm ausführen
./pathfinder [Datendatei]
```

### Implementierungsmerkmale

- Dijkstra-Algorithmus zur Suche nach kürzesten Wegen
- Effiziente Speicherung des Graphen als Adjazenzmatrix
- Speicher- und Laufzeitoptimierung
- Detaillierte Fehlerbehandlung für Eingabedaten

### 🖥️ Anwendungsbeispiele

#### Eingabedatei-Format

```
[Anzahl_der_Inseln]
[Insel1]-[Insel2],[Brückenlänge]
...
```

#### Beispiel 1: Grundlegende Verwendung

**Eingabedatei (eingabe.txt):**
```
3
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
```

**Programmausgabe:**
```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
```

#### Beispiel 2: Komplexer Graph mit alternativen Routen

**Eingabedatei (graph.txt):**
```
5
A-B,11
A-C,10
B-D,5
C-D,6
C-E,15
D-E,4
```

**Programmausgabe:**
```
========================================
Path: A -> B
Route: A -> B
Distance: 11
========================================
========================================
Path: A -> C
Route: A -> C
Distance: 10
========================================
========================================
Path: A -> D
Route: A -> B -> D
Distance: 11 + 5 = 16
========================================
========================================
Path: A -> D
Route: A -> C -> D
Distance: 10 + 6 = 16
========================================
========================================
Path: A -> E
Route: A -> B -> D -> E
Distance: 11 + 5 + 4 = 20
========================================
========================================
Path: A -> E
Route: A -> C -> D -> E
Distance: 10 + 6 + 4 = 20
========================================
========================================
Path: B -> C
Route: B -> D -> C
Distance: 5 + 6 = 11
========================================
========================================
Path: B -> D
Route: B -> D
Distance: 5
========================================
========================================
Path: B -> E
Route: B -> D -> E
Distance: 5 + 4 = 9
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 4 = 10
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 4
========================================
```

### Fehlermeldungen

- `usage: ./pathfinder [filename]` - Ungültige Anzahl von Argumenten
- `error: file [filename] does not exist` - Datei existiert nicht
- `error: file [filename] is empty` - Datei ist leer
- `error: line [n] is not valid` - Ungültiges Format in Zeile n
- `error: invalid number of islands` - Anzahl der Inseln stimmt nicht mit der angegebenen überein
- `error: duplicate bridges` - Doppelte Brücken erkannt
- `error: sum of bridges lengths is too big` - Summe der Längen übersteigt INT_MAX

### Projektstruktur

```
Ucode_Pathfinder/
├── inc/               # Header-Dateien
│   └── pathfinder.h   # Haupt-Header-Datei
├── src/               # Quelldateien
│   ├── main.c         # Hauptprogrammdatei
│   ├── mx_errors_handling.c  # Fehlerbehandlung
│   └── mx_paths_handling.c   # Pfadverarbeitungslogik
├── libmx/             # Benutzerdefinierte Funktionsbibliothek
├── Makefile           # Build-Anweisungen
└── README.md          # Dokumentation
```

### <h1 align = "center"> 🔧 Verwendete Technologien 🛠️ </h1>

<div align = "center">
  <table>
    <tr>
      <td align = "center"><h4>🧰 Sprachen</h4></td>
      <td align = "center"><h4>🔨 Entwicklungswerkzeuge</h4></td>
      <td align = "center"><h4>💻 Plattformen</h4></td>
      <td align = "center"><h4>📝 Editoren</h4></td>
    </tr>
    <tr>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://en.wikipedia.org/wiki/C_(programming_language)">
            <img src = "https://skillicons.dev/icons?i=c" alt = "C" width = "50" height = "50">
          </a>
          <br><strong>C</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/bash/">
            <img src = "https://skillicons.dev/icons?i=bash" alt = "Bash" width = "50" height = "50">
          </a>
          <br><strong>Bash</strong>
        </p>
        <p>
          <a href = "https://www.markdownguide.org/">
            <img src = "https://skillicons.dev/icons?i=md" alt = "Markdown" width = "50" height = "50">
          </a>
          <br><strong>Markdown</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://git-scm.com/">
            <img src = "https://skillicons.dev/icons?i=git" alt = "Git" width = "50" height = "50">
          </a>
          <br><strong>Git</strong>
        </p>
        <p>
          <a href = "https://www.gnu.org/software/make/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/2/22/Heckert_GNU_white.svg" alt = "Make" width = "50" height = "50">
          </a>
          <br><strong>Make</strong>
        </p>
        <p>
          <a href = "https://gcc.gnu.org/">
            <img src = "https://upload.wikimedia.org/wikipedia/commons/a/af/GNU_Compiler_Collection_logo.svg" alt = "GCC" width = "50" height = "50">
          </a>
          <br><strong>GCC</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://www.linux.org/">
            <img src = "https://skillicons.dev/icons?i=linux" alt = "Linux" width = "50" height = "50">
          </a>
          <br><strong>Linux</strong>
        </p>
        <p>
          <a href = "https://www.microsoft.com/windows/">
            <img src = "https://skillicons.dev/icons?i=windows" alt = "Windows" width = "50" height = "50">
          </a>
          <br><strong>Windows</strong>
        </p>
        <p>
          <a href = "https://www.apple.com/macos/">
            <img src = "https://skillicons.dev/icons?i=apple" alt = "macOS" width = "50" height = "50">
          </a>
          <br><strong>macOS</strong>
        </p>
      </td>
      <td align = "center" valign = "top">
        <p>
          <a href = "https://code.visualstudio.com/">
            <img src = "https://skillicons.dev/icons?i=vscode" alt = "VSCode" width = "50" height = "50">
          </a>
          <br><strong>VSCode</strong>
        </p>
        <p>
          <a href = "https://www.vim.org/">
            <img src = "https://skillicons.dev/icons?i=vim" alt = "Vim" width = "50" height = "50">
          </a>
          <br><strong>Vim</strong>
        </p>
        <p>
          <a href = "https://neovim.io/">
            <img src = "https://skillicons.dev/icons?i=neovim" alt = "NeoVim" width = "50" height = "50">
          </a>
          <br><strong>NeoVim</strong>
        </p>
      </td>
    </tr>
    <tr>
      <td colspan = "4" align = "center">
        <h4>☁️ Cloud-Dienste</h4>
        <p>
          <a href = "https://github.com/">
            <img src = "https://skillicons.dev/icons?i=github" alt = "GitHub" width = "50" height = "50">
          </a>
          <strong>GitHub</strong>
          &nbsp;&nbsp;&nbsp;&nbsp;
          <a href = "https://about.gitlab.com/">
            <img src = "https://skillicons.dev/icons?i=gitlab" alt = "GitLab" width = "50" height = "50">
          </a>
          <strong>GitLab</strong>
        </p>
      </td>
    </tr>
  </table>
  
  <div>
    <p><i>🚀 Dieses Projekt wurde mit diesen leistungsstarken Technologien erstellt 🚀</i></p>
  </div>
</div>

## <h1 align = "center"> ✨ BESONDERER DANK ✨ </h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Danke-AADmitriy-purple?style=for-the-badge&logo=github" alt = "Danke AADmitriy">
  <br><br>
  
  <h3>🌟 Herzlicher Dank 🌟</h3>
  
  <p>
    Besonderer Dank geht an 
    <a href = "https://github.com/AADmitriy"><b>AADmitriy</b></a> 
    für das wertvolle 
    <a href = "https://github.com/AADmitriy/pathfinder-checker"><b>pathfinder-checker</b></a> 
    Repository.
  </p>
  
  <img src = "https://img.shields.io/badge/Werkzeug-pathfinder--checker-blue?style=flat-square" alt = "pathfinder-checker">
</div>


<br>

### 📌 Was ist pathfinder-checker?

Dies ist ein spezialisiertes Testwerkzeug, das entwickelt wurde, um die Pathfinder-Implementierung auf Folgendes zu überprüfen:
- Korrektheit des Algorithmus
- Speicherlecks
- Fehlerbehandlung der Eingabedaten
- Einhaltung der Aufgabenanforderungen

<div align = "center">
  <table>
    <tr>
      <td align = "center">
        <h3>🧪</h3>
        <b>Testen</b>
      </td>
      <td align = "center">
        <h3>🐛</h3>
        <b>Debugging</b>
      </td>
      <td align = "center">
        <h3>🚀</h3>
        <b>Leistung</b>
      </td>
    </tr>
  </table>
</div>

> Ohne solch fantastische Beiträge aus der Community wären Projekte wie dieses deutlich schwieriger!

<div align = "center">
  <br>
  <a href = "https://github.com/AADmitriy/pathfinder-checker">
    <img src = "https://img.shields.io/badge/Repository_besuchen-pathfinder--checker-6a0dad?style=for-the-badge&logo=github" alt = "pathfinder-checker Repository besuchen">
  </a>
  <br><br>
</div>

## <h1 align = "center">🌟 Meine Schlussfolgerungen 🌟</h1>

<div align = "center">
  <img src = "https://img.shields.io/badge/Erfahrung-Transformational-brightgreen?style=for-the-badge" alt = "Erfahrung">
</div>

### 💡 Technisches Wachstum

Die Arbeit am Pathfinder-Projekt transformierte meinen Ansatz zur Entwicklung von Graphenalgorithmen. Diese Reise brachte mehrere Vorteile:

- **Beherrschung von Graphenalgorithmen:**
  - Tiefes Verständnis von Graphen, Adjazenzmatrizen und Pfadsuchalgorithmen erworben
  - Gelernt, den Dijkstra-Algorithmus für die Suche nach kürzesten Wegen effizient zu implementieren
  - Fehlerbehandlungssysteme für verschiedene Eingabedaten implementiert

- **Optimierungsfähigkeiten:**
  - Gelernt, Matrixoperationen für effiziente Graphenspeicherung zu optimieren
  - Ergebnis-Caching implementiert, um redundante Berechnungen zu vermeiden
  - Algorithmen für die Arbeit mit großen Graphen optimiert

- **Professionelle Fehlerbehandlung:**
  - Detaillierte Fehlerbehandlungssysteme für verschiedene Arten von Eingabedaten entwickelt
  - Gelernt, problematische Fälle in Graphen zu analysieren und zu identifizieren
  - Effiziente Fehlerwiederherstellungsmechanismen implementiert

### 🤝 Zusammenarbeit & Prozess

Dieses Projekt handelte nicht nur von Code — es transformierte, wie ich mit anderen arbeite:

- **Lernen mit Kollegen:**
  - Lösungen durch Code-Review und kollaboratives Debugging verbessert
  - Wissen geteilt, indem Algorithmus-Entscheidungen erklärt wurden
  - Grenzfälle dokumentiert, die während Gruppentestsitzungen entdeckt wurden

- **Entwicklungsdisziplin:**
  - Beschränkungen übernommen, um saubereren, schnelleren, wartbareren Code zu schreiben
  - Systematische Testansätze für jede Funktion implementiert
  - Fehlerbehebungsmethodologien für komplexe Graphenprobleme entwickelt

### 🚀 Langfristige Auswirkungen

Die während dieses Projekts entwickelten Fähigkeiten gehen weit über den Code selbst hinaus:

- **Übertragbares Wissen:**
  - Gelernte Muster gelten für die Entwicklung von Graphenalgorithmen in jeder Sprache
  - Wiederverwendbare Komponenten erstellt, die zukünftige Projekte beschleunigen werden
  - Intuition für die Optimierung von Graphenalgorithmen entwickelt

- **Problemlösungsmentalität:**
  - Gelernt, komplexe Operationen in logische, handhabbare Schritte zu unterteilen
  - Widerstandsfähigkeit bei komplexen Fehlern oder Designproblemen entwickelt
  - Vertrauen in die Lösung unklarer oder mehrdeutiger Anforderungen gewonnen

---

<p align = "center"><i>Lass uns unseren Weg zum Erfolg programmieren!</i> 💻</p>

</details>
