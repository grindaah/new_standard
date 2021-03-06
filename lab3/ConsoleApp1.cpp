// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

#include <ctime>

#include "util_hdr.h"
#include "in_constraints.hpp"


//using namespace std;



int main()
{

    //Задание 1. Сырые строковые литералы (Raw String Literals)
    //Выведите строку, например: my name is "Marina"
    //а) без использования Raw String Literals
    //б) посредством Raw String Literals
    //в) добавьте разделители (Delimeter)
    {
        std::cout << "Задание 1" << std::endl;
        std::cout << "My name is Marina";
        std::cout << "My name is "_name;
        std::string s2 = R"(My name is Marina)";
        std::cout << s2 << std::endl;
        //__asm nop
    }



    //////////////////////////////////////////////////////////////////////////////////////////////
    //Задание 2. Реализуйте вычисление факториала с помощью constexpr-функции.
    //
    //Подсказки/напоминания: 
    //        - constexpr – функция должна состоять из единственной инструкции return <выражение>; (пока!)
    //        - но это выражение может включать вызов другой constexpr – функции, в частности рекурсивный
    //            вызов 
    //        - если параметр рекурсивной constexpr- функции - это константа, компилятор вычислит результат
    //            на этапе компиляции



    //Проверьте тот факт, что компилятор вычисляет значение на этапе компиляции (если в качестве
    //                параметра используется константа, известная компилятору на этапе компиляции).
    //                Для проверки достаточно создать встроенный массив с размерностью, вычисляемой
    //                посредством constexpr-функции:

    {//Например:
        std::cout << "Задание 2" << std::endl;
        int ar[factr(3)];

        std::cout << "sizeof arr (elems)= " << sizeof(ar) / sizeof(int) << std::endl;
     //или
        constexpr int n = factr(5);
        int ar1[n];
        std::cout << "sizeof ar1 = " << sizeof(ar1) << std::endl;
     //попробуйте:
     int m = 7;
     factr(7);
     //constexpr int n1 = factr(m);
     //int ar1[n1];

     //std::cout << "sizeof arr2 = " << sizeof(ar1) << std::endl;

     //а так?
     int n2 = factr(m);
     std::cout << "n2" << n2 << std::endl;
        //__asm nop
    }




    //////////////////////////////////////////////////////////////////////////////////////////////


    //Задание 3a. Перевод с помощью пользовательского литерала из двоичного представления строкового
    //в значение, например: строку "100000000" -> в значение 256
    //Проверить результат посредством префикса 0b
    //Чтобы вызов пользовательского литерала выглядел просто и читаемо, например: 100000000_b
    //логично использовать пользовательский литерал с единственным параметром - const char*



    //Так как речь идет о литералах, логично вычислять значения на этапе компиляции
    // => реализуйте пользовательский литерал посредством constexpr - функций
    //Подсказка/напоминание: 
    //        - constexpr – функция должна состоять из единственной инструкции return <выражение>;
    //        - но это выражение может включать вызов другой constexpr – функции,
    //        - которая может быть рекурсивной (если параметр такой функции - это константа,
    //                    компилятор вычислит результат вызова рекурсивной функции на этапе компиляции)


    {
        std::cout << "Задание 3а" << std::endl;
        std::cout << "Binary (my operand): 110001010=" << 110001010_b << std::endl;
        std::cout << "Binary (native operand): 110001010=" << 0b110001010 << std::endl;
        //__asm nop

    }

    //Задание 3b. Перевод в строковое двоичное представление, например: 256 -> "0b100000000"
    //Так как строка может быть любой длины, логичнее и проще возвращать объект std::string
    //=> возвращаемое значение не может быть constexpr!
    //Подсказка: манипулятора std::bin пока нет => преобразование в двоичную строку
    //придется делать вручную
    //Подсказка: количество разрядов в байте определяет константа CHAR_BIT - <cstdint>


    //std::string sBin= 256_toBinStr;
    //__asm nop
    {
        std::cout << "Задание 3b" << std::endl;
        std::cout << "To Binary (my operand): 256=" << 256_toBinStr << std::endl;
        std::cout << "To Binary (my operand): 749=" << 749_toBinStr << std::endl;
        std::cout << "To Binary (my operand): 854873749=" << 854873749_toBinStr << std::endl;
        //__asm nop

    }


    //////////////////////////////////////////////////////////////////////////////////////////////
    //Задание 4а. constexpr - объекты 
    //Создать класс (шаблон класса?) для хранения и манипулирования диапазоном значений.
    //В классе должны быть:
    //    переменные для хранения минимального и максимального значений,
    //    методы для получения каждого из значений
    //    метод для проверки - попадает ли указанное значение в диапазон
    //    метод, который получает любое значение данного типа и формирует результирующее значение:
    //                            если принадлежит диапазону, то его и возвращаем
    //                            если меньше минимального значения, возвращаем минимальное
    //                            если больше максимального значения, возвращаем максимальное



    //Проверьте тот факт, что компилятор вычисляет значение на этапе компиляции. 
    //                Для проверки достаточно создать встроенный массив с размерностью, вычисляемой
    //                посредством constexpr-метода:
    {
        constexpr InConstraints<int> ic = InConstraints<int>(1,10);
        int ar[ic.get(14)];
        std::cout << "sizeof int ar[InConstraints] = " << sizeof(ar) << std::endl
            << ", count of elems: " << sizeof(ar) / (sizeof(int)) <<std::endl;
        //__asm nop
    }


        //Задание 4b. constexpr класс с битовыми полями
        //Часто в задачах требуется получать разные наборы констант в зависимости от
        //разных условий. Причем диапазон значений констант может быть существенно меньше
        //диапазона значений, предоставляемых типом char или unsigned char

        //Посредством constexpr класса и битовых полей реализуйте получение и 
        //использование констант на этапе компиляции

    {
        //__asm nop
    }

    //////////////////////////////////////////////////////////////////////////////////////////////
    //Задание 5. unique_ptr
    {

        //5.а - обеспечьте корректное выполнение фрагмента
        {
            std::cout << "Задание 5a,b,c" << std::endl;
            std::vector< std::unique_ptr< std::string > >  v;
            ///\note i did firstly unique_ptr, was it meant here??
            //possibly i was have to call delete manually when going out of scope
            v.emplace_back( std::make_unique<std::string>("aa") );
            v.emplace_back( std::make_unique<std::string>("bb") );
            v.emplace_back( std::make_unique<std::string>("cc") );

            auto Suff_1 = [] (const auto& s) {
                return *s += "_1";
            };
            std::for_each(v.begin(), v.end(), Suff_1);
                //{  new std::string("aa"), new std::string("bb"), new std::string("cc") };
        
            //Распечатайте все строки
            for (const auto& it : v)
                std::cout << *it << " ";
            std::cout << std::endl;
            //__asm nop
            //???
        } //???

          //5.b - модифицируйте задание 1.а:
          //обеспечьте посредством std::unique_ptr: 
          //эффективное заполнение (вспомните про разные способы формирования std::unique_ptr), 
          //безопасное хранение указателей на динамически создаваемые объекты std::string, 
          //манипулирование,
          //и освобождение ресурсов
          //

        {
            //Распечатайте все строки

            //__asm nop
            //??? Уничтожение динамически созданных объектов?
        } //???

        {//5.c - дополните задание 5.b добавьте возможность изменять хранящиеся строки
         //следующим образом (например, добавить указанный суффикс: "AAA" -> "AAA_1")  



            //__asm nop
        }

        {//5.d - динамический массив объектов    

         //Создайте unique_ptr, который является оберткой для динамического массива
         //с элементами std::string
         //С помощью unique_ptr::operator[] заполните обернутый массив значениями
         //Когда происходит освобождения памяти?
            std::cout << "Задание 5d" << std::endl;
            std::unique_ptr<std::string []> arrStrPtr (new std::string[3] );
            arrStrPtr[0] = std::string("dynarray[0]");
            arrStrPtr[1] = std::string("dynarray[1]");
            arrStrPtr[2] = std::string("dynarray[2]");
            std::cout << arrStrPtr[2] << std::endl;

            ///Deleter[] called here
            //==4715== LEAK SUMMARY:
            //==4715==    definitely lost: 0 bytes in 0 blocks
            //==4715==    indirectly lost: 0 bytes in 0 blocks
            //==4715==      possibly lost: 0 bytes in 0 blocks
            //__asm nop
        }

        {//5.e - массивы динамических объектов и пользовательская delete-функция (функтор)
         //Задан стековый массив указателей на динамически созданные объекты
         //Создайте unique_ptr для такого массива
         //Реализуйте пользовательскую delete-функцию (функтор) для корректного 
         //освобождения памяти
            {
                /*
                int n = 5;
                std::unique_ptr<int* [] > p(new int* [n]{new int(1),new int(2), new int(3),new int (4), new int(5)});
                auto p1 = std::make_unique<int* []>(n); //unique_ptr<A[], std::default_delete<A[]>>
                for (int i = 0; i < n; ++i)
                {
                    *p[i] = i;
                    std::cout << *p[i] << std::endl;
                }*/
            } //???
            std::unique_ptr<std::string* [], void(*)(std::string*[])> p_arStr  (
                    new std::string*[3] {new std::string("aa"), new std::string("bb"), new std::string("cc")} ,
                    [](auto* ptr)
                    {
                    ///note array don't know its size here, memory leaking
                    //should cycle through elems and delete 'em
                        delete[] ptr;
                    }
            );
                    for (int i = 0; i < 3; ++i)
                        std::cout << *p_arStr[i] << " ";

            //__asm nop
        }

        {//5.f Создайте и заполните вектор, содержащий unique_ptr для указателей на std::string
         //Посредством алгоритмя copy() скопируйте элементы вектора в пустой список с элементами 
         //того же типа
         //Подсказка: перемещающие итераторы и шаблон std::make_move_iterator
            //typedef std::unique_ptr<std::string> str_ptr;
            typedef std::vector< std::unique_ptr<std::string> >::iterator Iter;
            std::vector< std::unique_ptr<std::string> > m_vec_str;

            m_vec_str.emplace_back( std::make_unique<std::string>("aa") );
            m_vec_str.emplace_back( std::make_unique<std::string>("bb") );
            m_vec_str.emplace_back( std::make_unique<std::string>("cc") );

            std::vector< std::unique_ptr<std::string> > str_cpy;

            std::copy(std::make_move_iterator(m_vec_str.begin() )
                      , std::make_move_iterator(m_vec_str.end() )
                      , std::back_inserter(str_cpy));


            std::cout << "Initial vector contains not valid pointers: " << m_vec_str.size() << std::endl;
            for (auto it = m_vec_str.begin(); it!=m_vec_str.end(); ++it )
                if (*it)
                    std::cout << *(*it) << " ";
                else
                    std::cout << "Not valid " << " ";
            std::cout << std::endl;
            /*std::cout << std::endl << "Copy vector contains" << std::endl;*/

            std::cout << "second vector contains" << std::endl;
            for (auto it = str_cpy.begin(); it!=str_cpy.end(); ++it )
                std::cout << *(*it) << " ";
            //std::cout << std::endl << "Copy vector contains" << std::endl;
            //for (auto it : str_cpy)
            //    std::cout << *it << " ";
            /*{ std::make_unique<std::string>("aa_vec")
                        , std::make_unique<std::string>("bb_vec")
                        , std::make_unique<std::string>("cc_vec")
                        };*/


            //__asm nop

        }
        //__asm nop

    }

    ////////////////////////////////////////////////////////////////////////////////
    //Задание 6.shared_ptr + пользовательская delete-функция 

    //Реализовать возможность записи в файл данных (строчек) из разных источников 
    //(для упрощения пусть источниками являются два массива)
    //Так как все "писатели" будут по очереди записывать свои данные в один и тот же файл,
    //логично предоставить им возможность пользоваться одним и тем же указателем FILE* =>
    //безопасной оберткой для такого указателя является shared_ptr
    //а. Первый владелец должен открыть/создать файл для записи
    //б. Все остальные писатели должны присоединиться к использованию
    //в. Последний владелец указателя должен закрыть файл

    //Подсказка: имитировать порядок записи можно с помощью функции rand()
    {

    //"писатели":
    //Создать writer1, writer2
    std::cout << "Задание 6" << std::endl;
    std::shared_ptr<FILE > Writer1(fopen ("test.txt", "w"), &fclose);
    std::shared_ptr<FILE > Writer2(Writer1);

    //например, источники данных:
    const char ar1[] = "Writer1\n";
    const char ar2[] = "Writer2\n";

    int steps = 1000;

    std::srand(unsigned(std::time(0)));
    for (int i = 0; i < steps; ++i)
    {
        if (std::rand() % 2 == 0)
            fputs(ar1, Writer1.get());
        else 
            fputs(ar2, Writer2.get());
    }
    //заданное число итераций случайным образом позволяем одному из "писателей" записать в файл
    //свою строчку
    //Подсказка: строчки удобно записывать в файл посредством функции fputs()
    ///\note strace on getting out from scope:
    //  write(3, "Writer2\nWriter2\nWriter1\nWriter2\n"..., 4096) = 4096
    //  write(3, "Writer2\nWriter2\nWriter1\nWriter2\n"..., 3904) = 3904
    //  close(3)                                = 0

    //__asm nop
    }//закрытие файла???

    
    int n = 0;
    std::cin >> n;
}
