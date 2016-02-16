// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <memory>
#include <map>
#include <functional>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <iterator>
#include <regex>
#include <cmath>

#include "templ_out.h"

#include "books.h"


int main()
{

    //////////////////////////////////////////////////////////////////////////////////////////////
    //Задание 1. Регулярные выражения


    // 1a Обеспечить прием от пользователя целых значений в десятичной форме.
    // Необходимо учесть специфику пользователя, который должен ввести целое,
    //                а может ввести все, что угодно,
    //                число может предворяться знаком -/+,
    //                количество цифр может быть любым (в частности может превышать sizeof(int))
    //                
    //Подсказки:
    //            a) std::string может принять строчку с любым содержимым
    //            б) нужно проанализировать, соответствует ли введенное значение целому в допустимом диапазоне
    //            в) и, если соответствует, перевести из строкового представления в значение типа int
    //                    (для преобразования удобно использовать С++11 - std::stoi())

    {
        std::regex re1("[+|-]?[0-9]+");
        std::string inp = "";
        std::vector <int> myints = {};
        std::cout << "Enter decimal:";
        while (inp != "q")
        {
            std::cin >> inp;
            if (std::regex_match(inp, re1))
            {
                std::cout << "decimal OK" << std::endl;
                myints.push_back(std::stoi(inp));
            }
            else
                std::cout << "decimal very-on failed" << std::endl;
        }
        std::cout << "Ints in container:" << myints.size() / sizeof(int) << std::endl;
        //__asm nop
    }
    // 1b ООбеспечить прием от пользователя целых значений в шестнадцатеричной форме.
    {
        std::regex re2("[+|-]?0x[0-9|a-f|A-F]+");
        std::string inp = "";
        std::vector <int> myints = {};
        std::cout << "Enter hexadecimal:";
            while (inp != "q")
            {
                std::cin >> inp;
                if (std::regex_match(inp, re2))
                {
                    std::cout << "hexadecimal OK" << std::endl;
                    myints.push_back(std::stoi(inp));
                }
                else
                    std::cout << "hexadecimal very-on failed" << std::endl;
            }
        std::cout << "Ints in container:(not working for now)" << myints.size() / sizeof(int) << std::endl;
        //__asm nop
    }


    // 1с Обеспечить прием от пользователя плавающих значений в форматах
    //      -2.33 или +1.23e+06 или 0.245E10
    {
        std::regex re2("[+|-]?[0-9]\.[0-9]+(E[0-9]+|e[+][0-9]+)*");
        std::string inp = "";
        std::vector <int> myints = {};
        std::cout << "Enter number in scientific format:";
        while (inp != "q")
        {
            std::cin >> inp;
            if (std::regex_match(inp, re2))
            {
                std::cout << "scientific OK" << std::endl;
                myints.push_back(std::stoi(inp));
            }
            else
                std::cout << "scientific very-on failed" << std::endl;
        }
        std::cout << "Ints in container:(not working for now)" << myints.size() / sizeof(int) << std::endl;
        //__asm nop
    }

    // 1d Требуется узнать - есть ли хотя бы одна десятичная цифра в строке
    {
        std::regex re1("(\\s+|^)[+|-]?[0-9]+(\\s+|$)");
        std::string inp = "";

        std::cout << "Enter string containing number:";
        while(inp != "q")
        {
            std::getline(std::cin, inp, '\n');
            if (std::regex_search(inp, re1))
            {
                ///\TODO smatch here
                std::cout << "OK it contains " << std::endl;
            }
            else
                std::cout << "no decimal found" << std::endl;
        }

        //__asm nop
    }


    //1e Требуется найти все десятичные цифры в строке
    {
        std::regex re1("(\\s+|^)[+|-]?[0-9]+(\\s+|$)");
        std::string inp = "";

        std::cout << "Enter string containing number:";
        //std::unique_ptr<std::smatch> sm = std::make_unique(std::smatch());
        std::smatch sm;
        while (inp != "q")
        {
            std::getline(std::cin, inp, '\n');
            if (std::regex_search(inp, sm, re1))
            {
                ///\TODO smatch here
                std::cout << "OK it contains " << sm.size() << std::endl;

            }
            else
                std::cout << "no decimal found" << std::endl;
        }


    }
    ////////////////////////////////////////////////////////////////////////////////
    //Задание 2 variadic template - функция
    //Реализуйте функцию, которая умеет печатать любое количество параметров любого типа,
    //Например: MyPrint(4,8.8, A(1), std::string("dfg") );
    {
        MyPrint(4, 8.8, A(1), std::string("dfg"));
    }

    ////////////////////////////////////////////////////////////////////////////////
    //Задание 3 function
    //3a Реализуйте "калькулятор", который будет выполнять простейшие действия: +,-,*,/,^
    //     над операндами типа double:
    // '+' - посредством шаблона глобальной функции
    // '-' - посредством шаблона std::minus 
    // '*' - посредством функционального объекта 
    // '/' - посредством лямбда-функции
    // '^' - посредством функции pow() (перегруженный вариант для double)
    // '%' - дробную часть от результата плавающего деления посредством std::bind()
    //* '?' - наибольшее из двух значений посредством std::bind() и метода Вашего класса  
    // 
    //Для хранения значка операции и соответствующего ему действия логично использовать
    //std::map<char, ???> 
    {
        using namespace std::placeholders;
        MyCalc<double> c;
        c('-', std::minus<double>() );
        c('+', &my_plus<double>);
        c('*', my_multiply<double>());
        c('/', [](const double& a, const double& b)
                { 
                return a / b;
                }
         );
        c('^', pow);
        ///\TODO 2 binds more
        ///c('%', std::bind(division_res));


        std::cout << "484.3 + 4949 = " << (c['+'])(484.3, 4949) << std::endl;
        std::cout << "484.3 - 4949 = " << (c['-'])(484.3, 4949) << std::endl;
        std::cout << "484.3 * 4949 = " << (c['*'])(484.3, 4949) << std::endl;
        std::cout << "4949 / 484.3 = " << (c['/'])(4949, 484.3) << std::endl;
        std::cout << "484.3 ^ 2.1 = " << (c['^'])(484.3, 2.1) << std::endl;
        //std::map <char, std::function<double (double&, double&)> >;
        /// calc Cl = {1, "+", 4, "-", 1, "^", 4, "/", 2, "*", 1, "%", 2};
        
        //__asm nop
    }


    //3б Рекурсивная лямбда функция. Посредством std::function и лямбда функции реализуйте
    //вычисление суммы натурального ряда (x+(x-1)+ (x-2)+...+1).
    //Подсказка: так как существование любой переменной начинается с момента определения, 
    //например: int x=x; - бессмысленно, но корректно
    // => переменную типа function можно использовать в списке захвата  - ... f = [&f]...
    {

    }

    //////////////////////////////////////////////////////////////////////////////////
    //Задание 4 std::tuple
    //Создайте класс book (автор, заглавие, год издания...). 
    //Создайте библиотеку таким образом, чтобы книги хранились в упорядоченном виде.
    //Чтобы упорядочить совокупность книжек, нужно сформировать условие сравнения, то есть
    //перегрузить, например operator<. При реализации оператора хочется сформировать условие
    //с учетом всех данных!!! 

    //Подсказка: Для упорядочения удобно использовать шаблон std::tuple,
    //так как для std::tuple перегружены операторы ==,!=,<,<=,>,>=
    //,которые сравнивают два кортежа лексиграфически (в порядке следования членов).


    //Для проверки распечатайте библиотеку

    {
        std::vector<std::string> authors = {"Jack London", "Joanne Rowling", "Arthur Conan Doyle",
         "Ernest Heminguey", "Chuck Palahniuk", "Albert Einstein", "Steven Hawking", "Francesco Petrarka"
        , "John Fawls", "Victor Pelevin", "Lev Tolstoy"};
        std::vector<std::string> names = {"Hero of our Time", "Harry Potter", "War and Peace",
            "Fight Club", "The Grand Design", "Life of Insects", "The Magus",
            "Martin Iden", "A Study in Red", "Oldman"};

        typedef std::tuple <std::string, std::string, int, Genre> tuple_book;
        std::vector<tuple_book> books_vec;
        tuple_book book1 {"aa1", "bb1", 1111, Genre::scifi};

        for (int i = 0; i < 10; ++i)
            books_vec.push_back(
                   tuple_book{ names[i]
                   , authors[i]
                   , rand() % 2000
                   , static_cast<Genre>(rand() % static_cast<int>(Genre::unspecified))
                   } );
        for (const auto& b : books_vec)
            std::cout << b << std::endl;
        //std::tuple <std::string, std::string, int, Genre> book1 = {names[0], authors[0], 1111, Genre::scifi};

        //std::tuple<

    }

    /////////////////////////////////////////////////////////////////
    //Задание 5. shared_ptr и weak_ptr
    //Создаем генеалогическое дерево посредством класса human. В классе хранятся:
    //имя - string
    //возможно признак: жив или уже нет...
    //родители - shared_ptr (родители не всегда известны...)
    //дети - контейнер из weak_ptr (чтобы избежать циклических зависимостей)

    //Методы класса human:
    //конструктор - для инициализации имени и признака
    //конструктор копирования, оператор присваивания, move ???
    //статический метод child() - 
    //                должен создать создать и вернуть обертку для родившегося человека
    //                + сформировать все связи ребенка с родителями и наоборот

    //Ввести возможность распечатать генеалогическое дерево для указанного индивидума

    {
        //История должна с кого-то начинаться => "Жили-были дед да баба, например, Адам и Ева"
        //(то есть на самом деле два деда и две бабы):


        //std::shared_ptr<human> grandM1(new human("Eva"));
        //...

        //у них появились дети - child():


        //а у детей в свою очередь свои дети:


        //...
        //__asm nop
    }

    int a;
    std::cin >> a;

}
