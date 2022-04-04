/*
1. Создать класс Person(человек) с полями : имя, возраст, пол и вес.Определить методы переназначения имени, изменения возраста и веса.
Создать производный класс Student(студент), имеющий поле года обучения.Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов.В функции main() создать несколько(не больше трёх) студентов.Вывести информацию о них.

2. Создать классы Apple(яблоко) и Banana(банан), которые наследуют класс Fruit(фрукт).У Fruit есть две переменные - члена : name(имя) и color(цвет).
Добавить новый класс GrannySmith, который наследует класс Apple. */

#include <iostream>

class Person
{
private:
    std::string name;
    int age;
    std::string sex;
    int weight;
public:
    Person(std::string name, int age, std::string sex, int weight) {
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->weight = weight;
    }
    std::string getName() const { return name; }
    int getAge() { return age; }
    std::string getSex() const { return sex; }
    int getWeight() { return weight; }

    void changeWeight() {
        std::cout << "Input new weight: \n";
        std::cin >> weight;
    }
    void changeAge() {
        std::cout << "Input new age: \n";
        std::cin >> age;
    }
};
class Student : public Person
{
private:
    int year;
    static int count;
public:
    Student(std::string name, int age, std::string sex, int weight, int year) : Person (name, age, sex, weight) {
        this->year = year;
        ++count;
    }
    int getYear() { return year; }
    ~Student()
    {
        --count;
    }
    void increaseYear() {
        year += year;
    }
    void info() {
        printf("%s is %d years old, sex: %s , weight: %d , year of education: %d \n", getName().c_str(), getAge(), getSex().c_str(), getWeight(), getYear());
    }
    static int studentCount() { return count; }
};

int Student::count = 0;

void count() {
    std::cout << "Total Students: " << Student::studentCount() << std::endl;
}





class Fruit
{
private:
    std::string name;
    std::string color;
public:
    Fruit(std::string name, std::string color) {
        this->name = name;
        this->color = color;
    }
    std::string getName() const { return name; }
    std::string getColor() const { return color; }
    void info() {
        printf("%s is %s \n", getName().c_str(), getColor().c_str());
    }
};

class Apple : public Fruit
{
public:
    Apple(std::string name, std::string color) : Fruit(name, color) {}
};
class Banana : public Fruit
{
public:
    Banana(std::string name, std::string color) : Fruit(name, color) {}
};
class GrannySmith : public Apple
{
public:
    GrannySmith (std::string name, std::string color) : Apple (name, color) {}
};



int main()
{
    std::cout << "Task #1 \n" << std::endl;
    Student s0("Kevin", 12, "Male", 45, 6);
    s0.info();
    Student s1("Mary", 17, "Female", 53, 10);
    s1.info();
    Student s2("Jeremy", 7, "Male", 34, 3);
    s2.info();
    count();
    std::cout << "\nTask #2 \n" << std::endl;
    Apple a0("Golden Apple", "light yellow");
    Banana b0("Mini Banana", "yellow");
    GrannySmith g0("Garden Apple", "green");
    a0.info();
    b0.info();
    g0.info();

    /*
    3. Изучить правила игры в Blackjack.Подумать, как написать данную игру на С++, используя объектно - ориентированное программирование.
    Сколько будет классов в программе ? 
        Семь (Card, Hand, Deck, BasicPlayer, Player, House, Game)
    Какие классы будут базовыми, а какие производными ? 
        Базовые: Card, Hand, Game
        Производные: Deck, BasicPlayer, Player, House
    Продумать реализацию игры с помощью классов и записать результаты в виде комментария в основном файле сдаваемой работы.
        В классе Card опишу значение карты (двойка, тройка, валет и тд.), масть карт, положение карты (перевернута или нет), метод переворачивания карты.
        В классе Hand опишу метод с указателями на объект Card, сумму очков полученных карт, метод очистки полученных карт.
        В классе Deck опишу создание калоды карт (52), метод тасования карт, метод раздачи карт, метод дополнительной раздачи карт (по просьбе игрока)
        В классе BasicPlayer опишу имя игрока, функцию потребности игрока в дополнительной карте (да/нет), функцию перебора суммы очков у игрока (да/нет), извещение игрока о переборе по очкам
        В классе Player опишу функцию перебора суммы очков у игрока (да/нет), методы объявление победы/проигрыша/ничьи игрока
        В классе House опишу запрос к игроку о потребности в карте, переворот первой карты
        В классе Game опишу колоду карт, дилера карт, группу игроков-людей, метод проведения игры*/

}

