# C_PGPro

**Тестовое задание**

---

1. Решение оформлено в виде библиотеки с заголовочном файлом:
    `quadratic_equation.h`
  	
  	Cигнатура функции для решения квадратного уравнения:
  	
  	`EquationResult solve_equation(double a, double b, double c);`
  	
  	Решение уравнения возвращается в виде структуры:
  	```
    typedef struct {
      int num_roots;
      double root1;
      double root2;
    } EquationResult;
   ```
   
   **num_roots** – количество корней квадратного управления;

   **root1**, **root2** – действительные корни квадратного уравнения;

   где **num_roots** принимает значения:

   **-1** - бесконечное количество решений, пар `root1` и `root2` (в качестве одного из решений возвращаются нулевые значения);

   **0** – заданное уравнение не имеет действительных корней (при этом `root1 == NAN` и `root2 == NAN`, чтобы поля структуры были инициализированы);

   **1** – заданное уравнение имеет один действительный корень (возвращаются `root1 == root2`);

   **2** – заданное уравнение имеет два действительных корня `root1` и `root2`;

   **-2** – переполнение при вычислении дискриминанта (**INFINITY**, **-INFINITY** или **NAN**).
   Так как используем для вычисления дискриминанта тип **double** (**long double** не используем, так как он платформозависим), при определенных коэффициентах уравнения можем получить переполнение по **double**.
   При этом возвращаем `root1 == NAN` и `root2 == NAN`, чтобы поля структуры были инициализированы.
   Еще одним из вариантов обработки такого случая может быть применение в качестве типа данных для дискриминанта **BigDecimal**, но тогда теряем в производительности.

3. Модуль решения квадратного уравнения корректно обрабатывает случаи, когда в качестве аргументов
   функции `solve_equation` «подаются»: **INFINITY**, **-INFINITY**, **NAN** – при которых уравнение становится вырожденным, в этом случае считаем,
   что заданное уравнение не имеет действительных корней (`num_roots == 0`, `root1 == NAN`, `root2 == NAN`).

4. Так как для решения уравнения в действительных числах используется тип **double**, то используем сравнения с заданной точностью:
   
    `#define EPSILON 1e-6`
  	
5. Сборка проекта осуществляется с помощью **Makefile** со следующими целями:
    - `make quadratic_equation.a` – сборка библиотеки с параметрами `-Wall -Werror -Wextra -std=c11`
    - `make check` – Unit тестирование (100% покрытие) с помощью **Google Test Framework**  https://github.com/google/googletest
    - `make test` – Unit тестирование (100% покрытие) с помощью **Check Unit Testing Framework for C**  https://libcheck.github.io/check
    - `make cppcheck` - тестирование анализатором кода **cppcheck**
    - `make clang` – проверка форматирования кода с помощью **clang-format (GoogleStyle)**
    - `make clang_fix` – форматирование кода под **GoogleStyle**
    - `make leaks` - проверка на утечки памяти (в данном контексте неактуально, так как не работаем с динамикой)
    - `make arhive` – создание архива **quadratic_equation.tar** 
    - `make clean` – удаление бинарных фалов проекта
    - `make rebuild` – пересобрать проект
  
**P.S.**
- В ТЗ не было указано, что решение должно быть в действительных или комплексных числах. Решение было выполнено в действительных числах, однако переделать его в комплексные не составляет большого труда.
  На мой взгляд решение в комплексных числах проще.
- ТГ бот просит предоставить решение в виде ссылки:
  
  `Ответ принимаю в виде ссылки на твой репозиторий Git, либо на облачное хранилище. Успехов!`

  В ТЗ же просят предоставить в качестве решения архив,
  поэтому отправляю ссылку на сам репозиторий, в котором будет дополнительно размещен архив решения **quadratic_equation.tar**
