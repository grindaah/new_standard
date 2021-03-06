// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <string>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
//#include <locale>
#include <iostream>

#include "templ_out.h"
#include "unique_vector.hpp"


int main()
{
    {
        std::cout << "Задание 1" << std::endl;
        // Задаем тип явно - массив займет меньше в памяти
        enum class months :unsigned char { January, February, March/*...*/ };
        enum class weekDays { Monday, Tuesday /*...*/ };

        //months m = January;
        months m = months::January;
        //а) уберите проблемы

        if (m == months::February)
            std::cout << "OK";
        //б) оптимизируйте использование памяти
        months year[] = { months::January, months::February, months::March };
        size_t n = sizeof(year); //???


        std::cout << "size of year[] = " << n << std::endl;

    }

    //////////////////////////////////////////////////////////////////////////////////
    //Задание 2. Создайте и с помощью списка инициализации заполните значениями вектор с
    //элементами - string
    //С помощью range-based for преобразуйте все буквы в верхний регистр
    //а остальные символы должны остаться неизменными
    {
        std::cout << "Задание 2" << std::endl;
        std::vector<std::string> v1 = { "asd", "fgh", "mars", "saturn" };

        for (auto& x : v1)
        {
            std::transform(x.begin(), x.end(), x.begin(), ::toupper);
        }

        print_all(v1);
        //__asm

    }

    /////////////////////////////////////////////////////////////////////
    ///Задание 3. Создайте и с помощью списка инициализации заполните значениями
    //map таким образом, чтобы он содержал в качестве ключа букву, а в качестве значения 
    //отсортированную по алфавиту совокупность слов (string), начинающихся с этой буквы

    //С помощью range-based for распечатайте содержимое, например: A: any, apple, away
    {
        std::cout << "Задание 3" << std::endl;
        std::map<char, std::set<std::string> > m1 = {
            {'d', { "doctor", "drew", "doubt" } },
            {'a', { "any", "apple", "away" } },
            { 's',{ "steer", "subtle", "solar", "say" } },
            { 'l',{ "low", "lead", "layer" } },
        };
        //};

        for (const auto& it : m1)
        {
            std::cout << it.first << ": {";
            for (const auto& set_it : it.second)
                std::cout << set_it << " ";
            std::cout << "}" << std::endl;
        }
          
        //print_all(m1);
    }
    //__asm
    /////////////////////////////////////////////////////////////////////
    ///Задание 4. создать функцию для вывода на печать элементов последовательностей, заданных ниже

    {
        std::cout << "Задание 4" << std::endl;
        std::vector<double> vd = { 1.1,2.2,3.3 };
    print_all(vd);
    //PrintAnyCont(vd);

    std::string s("abc");
    print_all(s);
    //PrintAnyCont(s);

    int ar[] = { 1, 2, 3 };
    print_all(ar);
    //PrintAnyCont(ar);

    std::initializer_list<int> il{ 3,4,5 };
    print_all(il);
    //PrintAnyCont(il);


    //__asm
    }

        /////////////////////////////////////////////////////////////////////
        ///Задание 5.     
        //создать функцию для "отрицания" значений, например:
        // было: {1, -2, 5}, стало: {-1, 2, -5})
        // изменение объектов типа std::string может выглядеть "aBc1" -> "AbC1"
        //элементов последовательностей, заданных ниже:

    {
        std::cout << "Задание 5" << std::endl;
        std::vector<double> vd{ 1.1,2.2,3.3 };
        negate_all(vd);
        //NegateAll(vd);

        std::list<std::string> ls{ "aBc", "Qwerty", "n12" };
        negate_all(ls);
        print_all(ls);
        //NegateAll(ls);

        int ar[]{ 1, 2, 3 };
        negate_all(ar);
        //NegateAll(ar);
        print_all(ar);

        //__asm

    }



    /// 6?
    ///Задание 4а. создать функцию для инкремента элементов последовательностей, заданных ниже

    {
        std::cout << "Задание 6" << std::endl;
        std::vector<double> vd = { 1.1, 2.2, 3.3 };
        //IncAnyCont(vd);


        int ar[] = { 1, 2, 3 };
        //IncAnyCont(ar);

        std::string s("123");
        //IncAnyCont(s);


        //__asm
    }
    ///7?
    //////////////////////////////////////////////////////////////////////////////////
    //Задание 5. Реализовать функцию сортировки по модулю элементов последовательностей, заданных ниже
    //Собственно для сортировки можно использовать обобщенный алгоритм sort(), 
    //а для задания условия - лямбда-функцию
    {
        std::cout << "Задание 7" << std::endl;
        //auto absSort = [](auto& cont)
        //{
        //    std::sort(my_begin(cont)
        //            , my_end(cont)
        //            , [](const auto& it1, const auto& it2)->bool {return abs(it1) < abs(it2); }
        //    );
        //};
        //std::vector<double> vd = { -3.3,  2.2, -1.1 };
        //absSort(vd);
        //print_all(vd);


        //int ar[] = { -3, 2, -1 };
        //absSort(ar);
        //print_all(ar);

        //__asm
    }

    ///8?
    //////////////////////////////////////////////////////////////////////////////////
    //Задание 6.
    //напишите функцию, которая будет формировать и возвращать вектор, каждый элемент 
    //которого является суммой элементов двух последовательностей 
    //РАЗНОЙ длины и с элементами РАЗНОГО типа.
    //
    //например:
    {
        std::cout << "Задание 8" << std::endl;
        std::vector<int> v{ 1,2,3,4 };
        std::list<double> l{ 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
        std::deque<unsigned char> d{};
        //std::list<int>l { 1.1, 2.2, 3.3, 4.4, 5.5 };

        auto v2 = SumCont2(v, l);
        auto v3 = SumCont2(v, d);
        print_all(v2);
        print_all(v3);

        //__asm
    }


    ///9?
    //////////////////////////////////////////////////////////////////////////////////
    //Задание 7. Реализуйте функцию, которая принимает следующие парметры:    
    //сформированную последовательность любого типа с элементами любого типа, 
    //два (пустых) контейнера любого типа из vector, list, deque, set с элементами того же 
    //типа, что и у сформированной последовательности 

    //Функция должна "разложить" значения заданной последовательности в два пустых контейнера 
    //согласно заданному условию. Условие задать лябда-функцией
    //Исходная последовательность при этом не меняется
    {
        //Например:
        std::cout << "Задание 9" << std::endl;
        std::vector<int> v{ 1,2,3,4,5 };
        std::list<int> l; //сюда четные
        std::deque<int> d; //а сюда нечетные
                           //OddEven(v, l, d, <условие>);

        auto comp = triple_comp< decltype(v)::value_type >();
        OddEven(v, l, d);

        print_all(l);
        print_all(d);

        l = {};
        d = {};
        ///TODO give functor with template deduction
        OddEven(v, l, d, comp );
        print_all(l);
        print_all(d);
        //__asm
    }

    ///10?
    //////////////////////////////////////////////////////////////////////////////////
    //Задание 8. C помощью алгоритма for_each()!!! (а не count_if()) посчитать сколько 
    //букв в верхнем регистре
    //  Использовать лямбда функцию
    {
//        std::cout << "Задание 10" << std::endl;
//        
//        char s[] = "Hello World!";
//        int count = 0;
//        std::for_each(my_begin(s)
//            , my_end(s)
//            , [&count](const auto& c1) { if (isalpha(c1) && isupper(c1)) count++; }
//        );
//
//            std::cout << "Count of upper = " << count << std::endl;
//
            //__asm
    }


    //////////////////////////////////////////////////////////////////////////////////
    //Задание 9a. Создайте класс, который должен быть "оберткой" для вектора с УНИКАЛЬНЫМИ значениями
    //любого типа. 
    //Для хранения элементов используйте std::vector

    //Реализуйте конструктор, который может принимать любое количество значений (значения могут повторяться)
    //Реализуйте метод добавления любого количества значений (значения могут повторяться)
    //Реализуйте метод удаления любого количества значений (значения могут повторяться)
    //Реализуйте метод сортировки, который будет принимать в качестве параметра признак по возрастанию / по убыванию





    //Задание 9b. Модифицируйте класс из предыдущего задания (или создайте новый) таким образом,
    //чтобы значения не только были бы уникальными, но и находились в заданном диапазоне.
    //Замечание: такой класс в общем виде (для любых данных) смысла, наверно, не имеет, но его можно
    //использовать для таких типов данных, как целых, плавающих и тех пользовательских, для которых
    //имеют смысл операции сравнения (больше, меньше)
    //Подумайте: какие данные нужно добавить в класс и какие методы нужно модифицировать 

    {
        std::set<std::string> s1 = {"an", "doctor", "a", "day", "keeps", "those", "apples", "away"};

        std::vector <int> v1 {1, 4, 6, 5, 1, 1, 1, 1, 1, 11 };

        std::vector <double> v2 {1.0, 2.2, 2.2, 3.3, 0.0, 600, 50000.2};
        //std::vector <int> v2_ins = static_cast<std::vector <int> >

        unique_vector <std::string> ss1(s1.begin(), s1.end());
        unique_vector <int> sv1(v1.begin(), v1.end());

        unique_vector <double> sv2(v2.begin(), v2.end()); //, std::greater<double>() );

        std::cout<< "ss1" << std::endl;
        for (const auto& it : ss1)
            std::cout << it << " ";
        std::cout << std::endl;
        std::cout<< "sv1" << std::endl;
        for (const auto& it : sv1)
            std::cout << it << " ";
        std::cout << std::endl;
        std::cout<< "sv2" << std::endl;
        for (const auto& it : sv2)
            std::cout << it << " ";
        std::cout << std::endl;

        std::cout << "====================" << std::endl;
        std::cout << "====Finding=========" << std::endl;
        std::cout << "ss1: find day" << *( ss1.find("day")) << std::endl;

        std::cout << "====================" << std::endl;
        std::cout << "====Insertion=======" << std::endl;

        std::set <std::string> v_ins_string = {"Here", "goes", "some", "more", "strings", "I", "will", "paste", "first", "five"};

        ss1.insert_into(v_ins_string.begin(), v_ins_string.find("some"), ss1.get_iter(4));

        std::cout<< "ss1" << std::endl;
        for (const auto& it : ss1)
            std::cout << it << " ";
        std::cout << std::endl;

        std::vector <int> v_ins {1111, 4, 6, 5, 1, 12, 1, 1, 1, 1, 11 };
        sv1.insert_into(v_ins.begin(), v_ins.end(), sv1.get_iter(4));

        std::cout<< "sv1" << std::endl;
        for (const auto& it : sv1)
            std::cout << it << " ";
        std::cout << std::endl << "=========================" << std::endl;
        std::cout << "========Erasing========" << std::endl;

        std::cout << "1,4,6,6,6,6,7,12,222, 1111" << std::endl;
        sv1.erase({1,4,6,6,6,6,7,12,222, 1111});
        std::cout<< "sv1" << std::endl;
        for (const auto& it : sv1)
            std::cout << it << " ";
    }



    //////////////////////////////////////////////////////////////////////////////////
    //Задание 10*. Реализовать конвертацию enum в строковое представление  - enumToString
    // и наоборот - stringToEnum

    //Подсказки: 
    //***********
    //1. Соответствующие именованным константам строки все равно нужно где-то хранить =>
    //1.1 Именованные константы в перечислении должны быть уникальными => соответствующие строки
    //тоже должны быть уникальными, => уникальные строки могут быть использованы в качестве
    //ключа в std::map

    //1.2 а вот значения (соответствующие именованым константам)
    //могут быть любыми и даже могут повторяться => подходит контейнер std::map<string,<значение> >

    //1.3 Согласно стандарту С++11 переменные перечислимого типа могут разного размера, а хотелось бы
    //обеспечить универсальную конвертацию (то есть все контейнеры должны хранить пары одинакового типа) 
    //=> можно использовать контейнер std::map<string,int>,
    //чтобы в контейнере можно было хранить значения, соответствующие переречислениям любого типа

    //***********
    //2. Так как типы перечислений разные, то enumToString и stringToEnum должны быть шаблонными
    //2.1 Пользователь может ошибиться или злонамеренно передать в функции значения, которым
    //   ничего не соответствует => защита!
    //2.2 В функциях enumToString и stringToEnum (в зависимости от типа перечисления) нужно будет
    //   анализировать соответствующий используемому типу перечисления контейнер
    //2.3 Пользователь может сформировать строчку в ЛЮБОМ регистре => обеспечить независимость


    {

    }

    return 0;
}

