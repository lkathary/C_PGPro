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

   **0** – заданное уравнение не имеет действительных корней;

   **1** – заданное уравнение имеет один действительный корень (возвращаются `root1 == root2`);

   **2** – заданное уравнение имеет два действительных корня `root1` и `root2`.



3. Модуль решения квадратного уравнения корректно обрабатывает случаи, когда в качестве аргументов
   функции solve_equation «подаются»: INFINITY, -INFINITY, NAN – при этом уравнение считается врожденным и в этом случае считается,
   что заданное уравнение не имеет действительных корней (num_roots == 0).

6. Использована библиотека для разбора параметров командной строки JCommander:
   ```
    <groupId>com.beust</groupId>
    <artifactId>jcommander</artifactId>
    <version>1.82</version>
   ```
    В случае передачи утилите некорректных параметров командной строки, приложение выводит предусмотренный шаблон параметров и завершает работу.


7. Реализация приложения придерживается принципов SOLID, что позволит с минимальными затратами «расширять» функционал приложения:
    - загружать данные не только с исходный файлов (БД, сеть, и т.д.)
    - сохранять данные не только в выходные файлы (БД, сеть, и т.д.)
    - произвольно «строить» цепочки фильтрации по любым типам данных.


8. Так как тестовое задание не накладывает ограничение на «размерность» целых и вещественных чисел входных данных, то текущая цепочка фильтрации «выстроена» как:
    ```
    input data => BigInteger -> Double -> String => output data
    ```
    Если конкретизировать «размерность» целых и вещественных чисел входных данных, то с целью увеличения производительности стоит «перестроить» цепочку фильтрации, например:
    ```
    input data => Integer -> Float -> String => output data
    ```
9. При запуске утилиты с опцией **-o** (задать путь для результатов), приложение **не создает** указанную папку, т.е. если папка отсутствует или путь для выходных файлов некорректен, приложение обрабатывает ошибку (выводит сообщение) и завершает работу.


10. Проект собирался в **IDEA** IDE, для сборки из командной строки предусмотрен **Makefile** с целями
   `build` и `run`. Для сборки проекта используется `maven-wrapper`.


11. Пример запуска утилиты:
   ```
   java -jar util.jar -s -f -p sample- in1.txt in2.txt
   ```
