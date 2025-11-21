# 前言
## 类的六大关系
- **泛化**
  子类继承父类后，子类是父类的**特化**，父类是子类的**泛化**。
- **实现**
  子类实现一个或多个抽象接口父类。
- **组合**
  一个类的对象中，带有另一个类的示例对象，并且里面这个示例的生命周期完全依同于外面的对象，对象创建，里面示例成员就创建；对象销毁，里面的示例就销毁。
  如：老虎类里的 腿类示例 完全依赖老虎，老虎对象创建腿就创建；老虎对象销毁腿就销毁。
- **聚合**
  一个类的对象中，带有另一个类的示例对象的*指针*或*引用*，里面这个示例的生命周期可以不同于外层对象，也就是即可以先创建外层对象，也可以先创建内层对象。
  如：轮胎可以比车先创建，可以比车晚销毁。
- **关联**
  一个类知道另一个类的属性和方法。（不需要像**组合**一样强相关，只是一个知道的关系。体现在代码中和**组合 聚合**的结构一样）
- **依赖**
  一个类使用另一个类的实现，当一个类发生变化时，其他类也会收到影响。
## 设计模式三原则
————高内聚、低耦合、开闭原则。
### 单一职责原则 Single Responsibility Principle
- **概念**
  *高内聚：* 利用面向对象中类的三大特性中的封装性，即==每个类负责一项单一且明确的事务==。
- **注意**
  一个类的功能要尽可能单一化，避免出现"万能类"。
### 开放封闭原则 Open-Closed Principle
- **概念**
  *开闭原则：* ==出现当前类中不能完成的事项时==，不去修改其本身，而是==创建一个新的可以解决它的类==。可以更接近单一职责原则的同时；降低了因修改，而导致原本类不能执行的问题的概率。（前提是已经封装好了的类）
  *开放：* 对扩展开放。（需要新加功能时，可以新增类来实现）
  *封闭：* 对封装好的类封闭。（已经封装好的类不去修改其代码）
- **实现**
  在父类中提前预留接口，遇到新逻辑时，直接在子类中重写其对应函数。
### 依赖倒置原则 Dependency Inversion Principle
————要满足依赖倒置原则必须满足里氏代换原则。
- **概念**
  *低耦合：* 
  1. ==高层模块不依赖低层模块，两个都要依赖抽象==。
  2. ==抽象不依赖细节，细节依赖抽象==。
- **解释**
  1. *高层模块：* 上层应用，基本指业务层。
  2. *低层模块：* 底层接口，封装好的API，动态库等。
  3. *抽象：* 抽象类和接口，带虚函数的父类。（逻辑上的抽象，不是完全代指抽象类，也可以是提供接口的父类）
- **实现：（概念翻译过来就是）**
  在功能实现（高层）和API接口（低层）中间加一个抽象层（抽象类，要有低层的接口），用一个新类实现其抽象类对应低层的接口。调用的时候直接用抽象类的引用或指针来调用，就利用`C++`的多态完成了中间层的实现。
- **示例**
  一个项目中使用了很多`MySql`的数据接口，但是后期要切换到`Oracle`数据库，由于代码实现直接使用了底层接口，所有接口都需要修改，这样无法实现高层代码的直接复用。但是，如果在其中间加一层类封装一遍低层，高层直接调用这个类来调用低层的接口，后面即使低层改变，也只需要新增`Oracle`的实现类，然后将其传给抽象类。
## 其他核心思想
### 里氏代换原则
- **概念**
  ==子类类型必须能够替换父类类型==。即父类的属性必须与每个子类的属性一致，或者留出对应的接口。
- **示例**
  父类成绩范围0~100，但是子类重写后变成了-1~100，此时如果让 -1 去参加父类各种运算，极有可能导致出错。
### 接口隔离原则
- **概念**
  1. 用户端不应该依赖他不需要的接口。
  2. 一个类对另一个类的依赖，一个建立在最小接口上。
  3. 接口尽量细分，不要在一个接口放过多方法。
  总结：即子类所继承的抽象父类中，不应该包有这个子类不需要的接口。
- **示例**
  1. *问题描述：*
  一个有着添加、查询、删除接口的父类，继承给一个学生类和一个老师类，此时老师类可以操作全部函数没有问题；但学生类本应该只包含查询的接口，不应该有删除和添加的权限。
  2. *解决方法：*
  将原本的类分为多个部分，让拥有不同权限的类去继承不同的抽象父类。在上述例子中，可以将其分为添加接口，查询接口，删除接口（没有多继承的语言只能将其都写为纯虚函数），学生只继承查询，老师继承这三个。
### 迪米特原则（最少知识原则）
- **概念**
  一个对象应该对其他对象有最少的了解。
- **示例**
  1. *问题描述：*
  一个电脑类，实现关机功能时，需要调用10多个接口（保存程序、释放资源…）；有一个人的类，将电脑对象传给人对象的关电脑函数后，要按顺序调用这10多个接口，此时这个人对象就对电脑对象了解10多个接口。
  2. *解决方法：*
  将电脑类的这10多个接口改为私有，并提供一个关电脑的共有函数，内部按顺序调用这些接口；此时人对象要实现关电脑时，只需要调用 1 个关机接口，对电脑对象的了解就降低到了 1 个接口。
- **拓展**
  总结此原则：每个对象只与*直接朋友*通信，关于*直接朋友*在代码上的联系方式：
  1. 成员对象。
  2. 方法参数。
  3. 方法返回值。
  注意：局部变量中的对象，不是直接朋友。
### 合成复用原则
> 可解决属性过多导致的类数量爆炸问题。
- **概念**
  当一个类是另一个类的属性、部分时，使用组合而不是继承。
- **示例**
  一个汽车类有不同颜色：
  1. 使用继承：有 5 种颜色就要写 5 个子类，如果车的种类有 6 种，那么就要写 30 个子类。
  2. 使用组合：直接将颜色作为汽车类的成员对象，实现时，只需要将不同颜色组合给不同汽车类。
- **拓展**
  如何判断使用继承还是组合：
  1. 二者之间是`Is A`关系时（如：学生是人），使用继承。
  2. 二者之间是`Has A`关系时（如：学生有腿），使用组合。
# 创建型模式
### 简单工厂模式 Simple Factory Pattern（不满足开闭原则，非23种设计模式之一）
- **概念**
  类的对象都由一个工厂类来创建，根据参数不同来创建不同对象。
- **实现**
  在一个工厂类中，重载不同的创建对象的函数。
- **优点**
  实现简单，是工厂模式的简易版本。
- **缺点**
  1. 新增类型时需要修改原有代码，不满足开闭原则。
  2. 此类负责的功能太多，不符合低耦合。
#### 代码实现（其中Father的产品满足开闭原则，但是工厂依然需要修改源代码）
##### 工厂实现
```cpp
#pragma once

#include <iostream>

class Father
{
public:
    virtual void introduce() = 0;

    virtual ~Father() = default;
};

class Child1 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child1." << std::endl;
    }

};

class Child2 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child2." << std::endl;
    }
};

enum class ChildType : char
{
    Child1,
    Child2
};

class SimpleFactory
{
public:
    Father* create(ChildType type)
    {
        switch(type)
        {
        case ChildType::Child1:
            return new Child1;
        case ChildType::Child2:
            return new Child2;
        default:
            return nullptr;
        }
    }
};
```
##### main函数调用
```cpp
int main()

{
    // Simple Factory
    SimpleFactory* factory = new SimpleFactory;
    Father* child1 = factory->create(ChildType::Child1);
    child1->introduce();
    Father* child2 = factory->create(ChildType::Child2);
    child2->introduce();

    delete factory;
    return 0;

}
```
## 工厂(方法)模式 Factory Method Pattern
————简单工厂模式的进阶，满足了开闭原则。
- **概念**
  在简单工厂模式的基础上，对工厂类也进行抽象化处理。
- **实现**
  将工厂也抽象一个纯虚父类出来，将每个要创建的产品都对应一个工厂父类的子类出来，后续用对应的工厂来生产对应的产品。
### 代码实现
#### 工厂类实现
```cpp
#pragma once

#include <iostream>

class Father
{
public:
    virtual void introduce() = 0;

    virtual ~Father() = default;
};

class Child1 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child1." << std::endl;
    }

};

class Child2 : public Father
{
public:
    void introduce() override
    {
        std::cout << "I am a child2." << std::endl;
    }
};



class SimpleFactory
{
public:
    virtual Father* create() = 0;

    virtual ~SimpleFactory() = default;
};

class Child1Factory : public SimpleFactory
{
public:
    Father* create() override
    {
        return new Child1();
    }
};

class Child2Factory : public SimpleFactory
{
public:
    Father* create() override
    {
        return new Child2();
    }
};

```
#### main调用
```cpp
int main()
{
    // Factory Method
    SimpleFactory* factory = new Child1Factory();
    Father* child1 = factory->create();
    child1->introduce();
    delete factory;
    factory = new Child2Factory();
    Father* child2 = factory->create();
    child2->introduce();
    delete factory;
    delete child1;
    delete child2;

    return 0;
}
```
## 抽象工厂模式 Abstract Factory Pattern
————工厂方法模式的进阶，进一步抽象了产品层，形成不同族，来让对应抽象工厂层去生产不同族。
- **概念**
  将产品根据不同属性的不同种类都封装成类，让工厂子类去调用不同的产品的属性的种类，形成族的概念。
  例如：低端手机的内存为128GB，运存为12GB；高端的内存为1TB，运存为32GB。就可以将这四种属性的种类都封装成抽象的子类，在不同工厂分别调用即可。此时低端手机为一族，高端手机为一族。
- **实现**
  1. 将产品的不同属性抽象成不同的纯虚父类，再对每个属性里面的种类要分别基于父类实现他们的子类。
  2. 让产品父类持有其各个属性的父类指针，再根据不同的工厂子类调用属性种类的子类构造，完成不同的产品构建。
### 代码实现
#### 工厂模式实现
```cpp
#pragma once

#include <iostream>

class HDD
{
public:
    virtual void size() = 0;

    virtual ~HDD() { }
};

class LowHDD : public HDD
{
public:
    void size()
    {
        std::cout << "HDD is 128GB" << std::endl;
    }
};

class HighHDD : public HDD
{
public:
    void size()
    {
        std::cout << "HDD is 1TB" << std::endl;
    }
};

class RAM
{
public:
    virtual void size() = 0;

    virtual ~RAM() { }
};

class LowRAM : public RAM
{
public:
    void size()
    {
        std::cout << "RAM is 4GB" << std::endl;
    }
};

class HighRAM : public RAM
{
public:
    void size()
    {
        std::cout << "RAM is 16GB" << std::endl;
    }
};

class Computer
{
public:
    Computer(HDD* hdd, RAM* ram) 
        : hdd_(hdd)
        , ram_(ram)
    { }

    ~Computer()
    {
        delete hdd_;
        delete ram_;
    }

    void display()
    {
        hdd_->size();
        ram_->size();
    }

protected:
    HDD* hdd_;
    RAM* ram_;
};

class AbstractFactory
{
public:
    virtual Computer* createComputer() = 0;

    virtual ~AbstractFactory() { }
};

class BasicFactory : public AbstractFactory
{
    Computer* createComputer()
    {
        HDD* hdd = new LowHDD();
        RAM* ram = new LowRAM();
        return new Computer(hdd, ram);
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Computer* createComputer()
    {
        HDD* hdd = new HighHDD();
        RAM* ram = new HighRAM();
        return new Computer(hdd, ram);
    }
};
```
#### main调用
```cpp
int main()
{
    // Abstract Factory
    AbstractFactory* factory = new StandardFactory();
    Computer* computer = factory->createComputer();
    computer->display();
    delete factory;
    delete computer;
    factory = new BasicFactory();
    computer = factory->createComputer();
    computer->display();
    delete factory;
    delete computer;

    return 0;
}
```
## 单例模式 Singleton Pattern
- **概念**
  在某作用域内， 一个类的==实例化只有一次==。
- **使用**
  需要使用的话，传入这个单一的对象，然后用这个类提供的方式来使用这个对象，可以避免全局变量的不安全。
- **示例**
  全局的任务队列（为程序提供一个处理时间的方法，队伍成员可以用函数指针、function等）。
### 饿汉模式 Eager Initialization
- **特点**
    加载时就创建。默认线程安全。
- **实现**
  1. 将无参构造，拷贝构造，赋值运算符都设为私用或者`delete`掉（构造只能设为私有）。使得外部无法创建新的该对象。
  2. 只能使用类名来访问静态的构造函数。
  3. 将其指针写在类的内部，并设为静态成员，在外部初始化。外部静态接口返回这个静态成员，可保证第一次时创建，后面都不动。
#### 代码示例（使用指针 + 类外创建）
- **注意**
  由于返回指针，需要将析构delete掉来防止外部释放此资源造成的*静态销毁顺序问题*，对堆内存释放问题交给OS。
```cpp
#pragma once

#include <iostream>

class SingletonPattern
{
public:
    static SingletonPattern* GetInstance()
    {
        return m_task;
    }

    void print()
    {
        std::cout << "Singleton Pattern" << std::endl;
    }

public:
    SingletonPattern& operator=(const SingletonPattern& single) = delete;
    SingletonPattern(const SingletonPattern& single) = delete;
    ~SingletonPattern() = delete;

private:
    SingletonPattern() = default;

private:
    static SingletonPattern* m_task;

};

SingletonPattern* SingletonPattern::m_task = new SingletonPattern();

```
### 懒汉模式 Lazy Initialization
- **特点**
  首次调用时才创建。默认线程不安全，需使用C++11的==局部静态变量初始化规则==（函数内初始化静态变量时，自动对初始化的那条代码加锁，因此实现了线程安全）。
- **实现**
  与饿汉模式类似，不同的是，此模式使用的是函数内的静态变量，而不是类的静态成员变量：
  在`get`函数内初始化一个静态当前对象，直接返回这个对象。后续调用时，初始化不会执行。
#### 代码示例（使用指针 + 函数静态变量）
- **注意**
  由于返回指针，需要将析构delete掉来防止外部释放此资源造成的*静态销毁顺序问题*，对堆内存释放问题交给OS。
```cpp
class SingletonPattern1
{
public:
    static SingletonPattern1* GetInstance()
    {
        static SingletonPattern1 task;
        return &task;
    }

    void print()
    {
        std::cout << "Singleton Pattern" << std::endl;
    }

    ~SingletonPattern1() { }

public:
    SingletonPattern1& operator=(const SingletonPattern1& single) = delete;
    SingletonPattern1(const SingletonPattern1& single) = delete;
    ~SingletonPattern1() = delete;

private:
    SingletonPattern1() = default;

};
```
## 生成器 / 建造者模式 Builder Pattern
> 当对象复杂时，需要诸多变量进行初始化工作，此时如果都写到构造函数里，又难维护又会导致构造函数多且复杂。
- **概念**
  将一个==复杂对象==的构建分离，使得相同的构建过程，可以创造出不同产品。也就是将对象的构造代码抽出来，放在一个独立的对象里。
- **实现**
  1. 实现时，通常需要包含三个部分：
    `[1]` 产品类。（有具体的属性和功能）
    `[2]` 生成器父类，及其不同子类。（需要持有产品本体的指针，用来修改产品对象）
    `[3]` 指挥(管理)者类。（通过传入的不同生成器对象，以相同的接口调用其构建函数）
  2. 调用接口：
    `[1]` 初始化一个管理者对象。
    `[2]` 初始化不同的生成器对象，使用生成器父类指针接收。
    `[3]` 调用管理者对象的产品创建函数，将不同的生成器对象指针当作参数传过去。
    `[4]` 此时根据不同的生成器，管理者返回了不同对象。
- **注意**
  生成器持有产品对象的指针，所以在输出产品后，需要将该产品指针置空。同时析构函数依然需要`delete`这个指针，防止创建好对象后，对象指针没有被外界接收时，生成器就被删除的情况。
### 代码实现
#### 生成器示例
```cpp
#pragma once

#include <string>

class Computer
{
protected:
    std::string m_cpu;
    std::string m_memory;
    std::string m_disk;

public:
    void setCpu(const std::string& cpu)
    {
        m_cpu = cpu;
    }

    void setMemory(const std::string& memory)
    {
        m_memory = memory;
    }

    void setDisk(const std::string& disk)
    {
        m_disk = disk;
    }

    std::string display()
    {
        return "CPU: " + m_cpu + "\nMemory: " + m_memory + "\nDisk: " + m_disk;
    }

};

class Builder
{
public:
    virtual void builderCpu() = 0;
    virtual void builderMemory() = 0;
    virtual void builderDisk() = 0;
    virtual void reset() = 0;
    virtual Computer* getComputer() = 0;

    virtual ~Builder() = default;

protected:
    Computer* m_computer;

};

class OfficeBuilder : public Builder
{
public:
    void builderCpu() override
    {
        m_computer->setCpu("i5-12490F");
    }

    void builderMemory() override
    {
        m_computer->setMemory("16GB");
    }

    void builderDisk() override
    {
        m_computer->setDisk("512GB");
    }

    void reset() override
    {
        m_computer = new Computer();
    }

    Computer* getComputer() override
    {
        Computer* computer = m_computer;
        m_computer = nullptr;
        return computer;
    }

    ~OfficeBuilder() override
    {
        delete m_computer;
    }

};

class GameBuilder : public Builder
{
public:
    void builderCpu() override
    {
        m_computer->setCpu("9800x3D");
    }

    void builderMemory() override
    {
        m_computer->setMemory("32GB");
    }

    void builderDisk() override
    {
        m_computer->setDisk("2TB");
    }

    void reset() override
    {
        m_computer = new Computer();
    }

    Computer* getComputer() override
    {
        Computer* computer = m_computer;
        m_computer = nullptr;
        return computer;
    }

    ~GameBuilder() override
    {
        delete m_computer;
    }

};

class Director
{
public:
    Computer* construct(Builder* builder)
    {
        builder->reset();
        builder->builderCpu();
        builder->builderMemory();
        builder->builderDisk();
        return builder->getComputer();
    }
};

```
#### 接口调用
```cpp
#include <iostream>
#include "Builder.h"

int main()
{
    // Builder
    Director* director = new Director();
    Builder* builder_office = new OfficeBuilder();
    Builder* builder_game = new GameBuilder();
    Computer* computer_office = director->construct(builder_office);
    Computer* computer_game = director->construct(builder_game);
    std::cout << "Office Computer : " << computer_office->display() << std::endl;
    std::cout << "Game Computer : " << computer_game->display() << std::endl;
    delete director;
    delete builder_office;
    delete builder_game;
    delete computer_office;
    delete computer_game;

    return 0;
}


/* 输出：

Office Computer : CPU: i5-12490F
Memory: 16GB
Disk: 512GB
Game Computer : CPU: 9800x3D
Memory: 32GB
Disk: 2TB

*/
```
## 原型模式 Prototype Pattern
> 使得对象创建不需要工厂或管理者对象，让对象自己就可以复制一个自己的对象。避免了：
> 1. 交给**创建**工厂时：需要加载过多数据库、大型文件的性能消耗。**创建**工厂被提前销毁的情况无法处理。
> 2. 使用类似复制构造时：
>   `[1]` 给**创建**工厂一个`clone`函数：破坏工厂对象的单一原则，增加耦合。**创建**工厂被提前销毁的情况无法处理。
>   `[2]` 产品自己的复制构造：不同的子类需要`new`不同的类型，无法在外界用同样的接口满足这个要求。
> 
> 使用原型模式`clone`时，对象自己可以返回自己的类型，虚函数表可以帮我们决定调用哪个`clone`。此时也可以新增一个**复制**工厂(非**创建**工厂)来完成这个功能。
- **概念**
  将对象的复制交给对象自己（新增一个`clone`函数），而不是让工厂函数或复制构造来完成创建。
- **实现 1**
  ————对象本身持有复制能力来*拷贝对象*。
  1. 实现需要包含的部分：
    `[1]` 产品父类，以及产品子类。（要带有一个`clone`函数，用于调用自身的拷贝构造）
    `[2]` （可选）拷贝工厂，让它去调用对象的`clone`。
  2. 接口调用：
    `[1]` 创建拷贝工厂。
    `[2]` 用产品父类指针接收子类对象。
    `[3]` 将对象作为函数参数给拷贝工厂，在工厂内部调用`clone`，并返回其指针。
- **实现 2**
  ————让创建工厂以对应对象的`clone`的形式来*创建对象*。
 1. 实现需要包含的部分：
    `[1]` 产品父类，以及产品子类。（要带有一个`clone`函数，用于调用自身的拷贝构造）
    `[2]` 实现每个子类对象的枚举。
    `[3]` 创建工厂（包含一个哈希表）。在构造时，在哈希表中给每个枚举创建对应的：枚举为`key`、枚举相应的对象为`value`的数据。创建时，以外部传来的枚举值作为`key`，在哈希表找到对应的`value`，调用这个`value`的`clone`函数来创建对象，再返回产品父类指针。
  2. 接口调用：
    `[1]` 创建拷贝工厂。
    `[2]` 将枚举变量当参数传给工厂的创建函数，让工厂根据枚举查找哈希表，调用对应对象的`clone`，最后用产品父类指针接收。
### 代码实现（实现 1 ：对象的复制）
#### 原型模式实现
```cpp
#pragma once

#include <string>

class Character
{
public:
    virtual Character* clone() const = 0;
    virtual std::string display() const = 0;

    virtual ~Character() = default;

protected:
    unsigned int HP = 0;

};

class Minion : public Character
{
public:
    Minion()
    {
        HP = 200;
    }

    Minion(const Minion& other) = default;
    Minion& operator=(const Minion& other) = default;

    std::string display() const override
    {
        return "HP = " + std::to_string(HP);
    }

    Minion* clone() const override
    {
        return new Minion(*this);
    }

};

class Boss : public Character
{
public:
    Boss()
    {
        HP = 5000;
    }

    Boss(const Boss& other) = default;
    Boss& operator=(const Boss& other) = default;

    std::string display() const override
    {
        return "HP = " + std::to_string(HP);
    }

    Boss* clone() const override
    {
        return new Boss(*this);
    }

};
```
#### 接口调用
```cpp
int main()
{
    // Prototype
    Character* minion = new Minion();
    Character* boss = new Boss();
    Character* copy1 = minion->clone();
    Character* copy2 = boss->clone();
    std::cout << "Minion HP : " << minion->display() << std::endl;
    std::cout << "Boss HP : " << boss->display() << std::endl;
    std::cout << "Copy1 HP : " << copy1->display() << std::endl;
    std::cout << "Copy2 HP : " << copy2->display() << std::endl;
    delete minion;
    delete boss;
    delete copy1;
    delete copy2;

    return 0;
}


/* output：

Minion HP : HP = 200
Boss HP : HP = 5000
Copy1 HP : HP = 200
Copy2 HP : HP = 5000

*/
```
# 结构型模式
## 外观模式 Facade Pattern
> 最常用，最简单的模式。
> 
> 虽然本身违反了单一职责原则，但是极大促进了迪米特原则。
- **核心**
  封装 集成某一功能 的函数。
- **概念**
  将达成某个目的所需的所有步骤包装为一个类，使用户只需要调用它就可以实现某项功能。
- **实现**
  1. 实现部分：
    `[1]` 需要达成功能的各种类。
    `[2]` 一个集成了他们功能的类。
  2. 接口调用：
    直接调用集成功能的类即可。
- **注意**
  要遵循迪米特原则的*直接朋友*通信，也就是说让集成类管理其他类的方法，只有传入参数、返回对象值、自带对应成员函数这三种方法。
### 代码实现
#### 外观模式实现
```cpp
#pragma once

#include <string>

class TV
{
public:
    std::string turnOn()
    {
        return "The TV is turned on.";
    }

};

class SpeakerBluetooth
{
public:
    std::string turnOn()
    {
        return "The bluetooth speaker is turned on.";
    }

};

class Housekeeper
{
public:
    std::string watchTV(TV* tv, SpeakerBluetooth* sb)
    {
        return tv->turnOn() + "\n" + sb->turnOn();
    }

};
```
#### 接口调用
```cpp
// Facade
    TV* tv = new TV();
    SpeakerBluetooth* sb = new SpeakerBluetooth();
    Housekeeper* hk = new Housekeeper();
    std::cout << hk->watchTV(tv, sb) << std::endl;
    delete tv;
    delete sb;
    delete hk;
    
    
/*

output:

The TV is turned on.
The bluetooth speaker is turned on.

*/
```
## 代理模式 Proxy Pattern
> 可以解决一个类因无权限被滥用的问题，或增加附加功能。
- **核心**
  调用另一个对象的函数，来使用原本对象的功能。
- **概念**
  为其他对象提供一种代理，控制对这个对象的访问。
- **实现**
  1. *实现结构*
    接口父类。
    Real类，继承接口父类，并实现所有功能。
    Proxy类，继承接口父类并包含一个Real对象，根据权限选择是否调用Real对象的功能。（可附加新功能）
  2. *接口调用*
    创建Proxy对象，用父类指针接收。
    调用Proxy的函数，该对象会自己判断当前权限是否可以调用。
- **场景示例**
  1. *远程代理*
    可以自己调用 远程某个对象功能的 对象。
  2. *虚拟代理*
    对创建成本高的对象，使用一个''占位对象''来暂时代替，后期延迟再加载。如：加载图片时，先加载一个框来占位，此时这个框就是虚拟代理。
  3. *安全代理*
    控制访问权限。
### 代码实现
#### 代码模式实现
```cpp
#pragma once

#include <string>

class Image
{
public:
	virtual ~Image() = default;

public:
	virtual void loadImage(const std::string& user, const std::string& path) = 0;
	virtual std::string render(const std::string& user) = 0;

protected:
	std::string path_;

};

class RealImage : Image
{
public:
	void loadImage(const std::string& user, const std::string& path) override
	{
		Image::path_ = path;
	}

	std::string render(const std::string& user) override
	{
		return user + " render : " + Image::path_;
	}

};

class ProxyImage : Image
{
public:
	ProxyImage(const std::string s)
		: user_(s)
		, real_(new RealImage())
	{ }

	~ProxyImage()
	{
		delete real_;
	}

public:
	void loadImage(const std::string& user, const std::string& path) override
	{
		if (user_ == user)
		{
			return real_->loadImage(user_, path);
		}
		else
		{
			throw "is not manager!";
		}
	}

	std::string render(const std::string& user) override
	{
		if (user_ == user)
		{
			return real_->render(user_);
		}
		else
		{
			return "is not manager!";
		}
	}

protected:
	RealImage* real_;
	std::string user_;

};
```
#### 接口调用
```cpp
    // Proxy
    ProxyImage* proxy = new ProxyImage("jenny");
    proxy->loadImage("jenny", "D:/download/0.png");
    std::cout << proxy->render("join") << std::endl;
    std::cout << proxy->render("jenny") << std::endl;
    delete proxy;
    
    
/*

output:

is not manager!
jenny render : D:/download/0.png

*/
```
## 适配器模式 Adapter Pattern
> 将一个类原本的接口转换为另一个的接口，使得原本不兼容的格式、文件有相同的接口去支持同一操作。
- **核心**
  将**不同输入**格式转换为**同一输出**格式。
### 类适配器
> 能继承两个类的编程语言较少，所以使用较少。
- **概念**
  将 待适配的类型 直接继承给 接口子类，使对象可以直接访问两个类。
- **实现**
  1. 实现时，要包含三个部分：
    `[1]` 写一个输出目标形式的`接口类`（抽象类）。
    `[2]` 写几个对应格式的处理器类（抽象类），实现其功能。
    `[3]` 写几个继承上述两个类的适配器类，重写`接口类`的函数；让其 调用适配器**类**的函数 或 实现对应逻辑 。
  2. 调用接口
    `[1]` 初始化一个适配器对象，使用`接口类`指针接收。
    `[2]` 直接用指针调用接口。
#### 代码实现
##### 适配器实现
```cpp
#pragma once

#include <string>

class PNGProcessor
{
public:
    virtual ~PNGProcessor() = default;

public:
    virtual std::string processPNG()
    {
        return "PNG image";
    }

};

class JPGProcessor
{
public:
    virtual ~JPGProcessor() = default;

public:
    virtual std::string processJPG()
    {
        return "JPG image";
    }

};

class AdapterJPG : public PNGProcessor, public JPGProcessor
{
public:
    std::string processPNG() override
    {
        return "PNG image from JPG image";
    }

};
```
##### 接口调用
```cpp
// Adapter
    PNGProcessor* image1 = new AdapterJPG();
    PNGProcessor* image2 = new PNGProcessor();
    std::cout << image1->processPNG() << std::endl;
    std::cout << image2->processPNG() << std::endl;
    delete image1;
    delete image2;
    
    
/*

output:

PNG image from JPG image
PNG image

*/
```
### 对象适配器
> 更常用的模式。
- **概念**
  将 待适配的类型 作为 接口子类的成员，使 接口子类 可以通过此 待适配成员 来访问两个类。
- **实现**
  1. 实现，模板为：
    `[1]` 写一个输出目标形式的`接口类`（抽象类）。
    `[2]` 写几个对应格式的处理器类（抽象类），实现其功能。
    `[3]` 写几个继承了`接口类`的适配器类（包含一个处理器类的指针）；让其 调用适配器**对象**的函数 或 实现对应逻辑。
  2. 接口调用：
    `[1]` 使用适配器类创建一个对象，使用`接口类`指针接收。
    `[2]` 直接用指针调用接口。
#### 代码实现
##### 对象适配器模式实现
```cpp
// object adapter
class Image
{
public:
    virtual ~Image() = default;

public:
    // The format of the image is png.
    virtual std::string getImage() = 0;

};

class Processor_ImagePNG
{
public:
    Processor_ImagePNG(std::string path)
        : path(path)
    { }

    ~Processor_ImagePNG() = default;

public:
    std::string getImage()
    {
        return path + " is PNG format.";
    }

protected:
    std::string path;

};

class Processor_ImageJPG
{
public:
    Processor_ImageJPG(std::string path)
        : path(path)
    { }

    ~Processor_ImageJPG() = default;

public:
    std::string getImage()
    {
        return path + " to be PNG format.";
    }

protected:
    std::string path;

};

class AdapterPNG : public Image
{
public:
    AdapterPNG(std::string path)
        : processor(new Processor_ImagePNG(path))
    { }

    ~AdapterPNG()
    {
        delete processor;
    }

public:
    std::string getImage() override
    {
        return processor->getImage();
    }

protected:
    Processor_ImagePNG* processor;

};

class AdapterJPG : public Image
{
public:
    AdapterJPG(std::string path)
        : processor(new Processor_ImageJPG(path))
    { }

    ~AdapterJPG()
    {
        delete processor;
    }

public:
    std::string getImage() override
    {
        // convert the image to png format
        std::string toPNG = processor->getImage() + "It is PNG format now.";
        return toPNG;
    }

protected:
    Processor_ImageJPG* processor;

};

```
##### 接口调用
```cpp
// Adapter Object
    Image* img1 = new AdapterJPG("/res/image.jpg");
    Image* img2 = new AdapterPNG("/res/image.png");
    std::cout << "img1 : " << img1->getImage() << std::endl;
    std::cout << "img2 : " << img2->getImage() << std::endl;
    delete img1;
    delete img2;


/*

output:

img1 : /res/image.jpg to be PNG format.It is PNG format now.
img2 : /res/image.png is PNG format.

*/
```
## 装饰器模式 Decorator Pattern
> 与桥接模式类似，可以解决因不同属性造成的子类数量爆炸问题。
- **核心**
  修饰对象时，使用一种类似于链表的结构，做到多层修饰。
- **概念**
  让外层装饰指向内层装饰或个体，做到无限制的装饰。
- **注意**
  其层层动态修饰的特点，使得这种结构可以做到重复修饰，故而需要注意对其每个修饰修饰范围做出限定。（如：武器每次可以叠加30点属性，但上限为100点）
- **实现**
  1. *实现结构：*
    如图，定义一个抽象父类作为接口，让 有着相同组件的 不同产品 继承此父类（如：电视和音响都有遥控器组件）；再创建一个 继承自抽象父类的 装饰器抽象类，下面实现具体的装饰。
```
    抽象组件（产品抽象类）
       |______ 具体组件（同一产品的不同分类）
       |______ 抽象装饰器类（产品装饰器的抽象类）
                   |______ 具体装饰器（各种装饰器的实现）
	                   .
	                   .
	                   .
```
  2. *接口调用：*
    `[1]` 优先创建一个 具体组件 。
    `[2]` 将它传给具体装饰器，完成一次加装。
    `[3]` 后续再将生成的具体装饰器对象传给下一个具体装饰器（可相同），再完成一次加装。
    注意：所有接收的指针都应该为抽象父类指针。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <string>

class MilkTea
{
public:
    virtual ~MilkTea() = default;

public:
    virtual int getPrice() = 0;

    virtual std::string ingredientsList() = 0;

};

class IcedMilkTea : public MilkTea
{
public:
    virtual ~IcedMilkTea() = default;

public:
    virtual int getPrice() override
    {
        return 5;
    }

    virtual std::string ingredientsList() override
    {
        return "Ingredients list of Iced Milk Tea:\n - Ice\n - Milk\n - Tea\n";
    }

};

class HotMilkTea : public MilkTea
{
public:
    virtual ~HotMilkTea() = default;

public:
    virtual int getPrice() override
    {
        return 5;
    }

    virtual std::string ingredientsList() override
    {
        return "Ingredients list of Hot Milk Tea:\n - Milk\n - Tea\n";
    }

};

class MilkTeaDecorator : public MilkTea
{
public:
    MilkTeaDecorator(MilkTea* body)
        : body(body)
    { }

    virtual ~MilkTeaDecorator()
    {
        delete body;
    }

public:
    virtual int getPrice() override
    {
        return body->getPrice();
    }

    virtual std::string ingredientsList() override
    {
        return body->ingredientsList();
    }

protected:
    MilkTea* body;

};

class Orange : public MilkTeaDecorator
{
public:
    Orange(MilkTea* body)
        : MilkTeaDecorator(body)
    { }

public:
    int getPrice() override
    {
        return money + MilkTeaDecorator::getPrice();
    }

    std::string ingredientsList() override
    {
        return MilkTeaDecorator::ingredientsList() + " - orange\n";
    }

protected:
    static constexpr int money = 1;

};

class Lemon : public MilkTeaDecorator
{
public:
    Lemon(MilkTea* body)
        : MilkTeaDecorator(body)
    { }

public:
    int getPrice() override
    {
        return money + MilkTeaDecorator::getPrice();
    }

    std::string ingredientsList() override
    {
        return MilkTeaDecorator::ingredientsList() + " - Lemon\n";
    }

protected:
    static constexpr int money = 2;

};
```
#### 接口调用
```cpp
// Decorator
    MilkTea* step1 = new IcedMilkTea();
    MilkTea* step2 = new Lemon(step1);
    step1 = nullptr;
    MilkTea* step3 = new Orange(step2);
    step2 = nullptr;
    std::cout << "The price is " << step3->getPrice() << ".\n" << std::endl;
    std::cout << step3->ingredientsList() << std::endl;
    delete step3;
    
    
/*

output:

The price is 8.

Ingredients list of Iced Milk Tea:
 - Ice
 - Milk
 - Tea
 - Lemon
 - orange

*/
```
## 桥接模式 Bridge Pattern
> 当类中的属性关联性较低，但数量较多时（如形状和颜色），会产生 n * m 个类（假如 n 种颜色，m 种形状），此时可以使用桥接模式对其进行解耦。简单来说就是防止多层继承带来的类数量爆炸问题。 
- **核心**
  将可能 独立变化 的部分分为不同属性，给这个指针赋值不同属性，形成不同产品。
- **概念**
  让抽象类持有一个实现类的指针（桥接点），将不同属性单独抽象出来，把指针赋值不同的实现子类。
- **实现**
  1. 实现所需的结构：
    `[1]` 产品抽象类（有不同的属性指针做i为 桥接点 ）。
    `[2]` 每个属性的抽象类，及其对应子类。
    `[3]` 使不同产品带有不同属性。
  2. 调用接口：
    `[1]` 创建不同的属性子类。
    `[2]` 将不同属性作为参数传给产品，创建出不同的产品子类。
### 代码实现
#### 桥接模式实现
```cpp
#pragma once

#include <string>

class Color
{
public:
    virtual ~Color() = default;

public:
    virtual std::string getColor() = 0;

};

class Red : public Color
{
public:
    std::string getColor() override
    {
        return "Red";
    }

};

class Green : public Color
{
public:
    std::string getColor() override
    {
        return "Green";
    }

};

class Shape
{
public:
    virtual ~Shape() = default;

public:
    virtual std::string getShape() = 0;

};

class Circle : public Shape
{
public:
    std::string getShape() override
    {
        return "Circle";
    }

};

class Body
{
public:
    Body(Color* color, Shape* shape)
        : color(color)
        , shape(shape)
    { }

    virtual ~Body()
    {
        delete color;
        delete shape;
    }

public:
    std::string display()
    {
        return "Color : " + color->getColor() + "   Shape : " + shape->getShape();
    }

protected:
    Color* color;
    Shape* shape;

};

```
#### 接口调用
```cpp
// Bridge
    Body* body1 = new Body(new Red(), new Circle());
    Body* body2 = new Body(new Green(), new Circle());
    std::cout << "Body1 : " << body1->display() << std::endl;
    std::cout << "Body2 : " << body2->display() << std::endl;
    delete body1;
    delete body2;


/*

output:

Body1 : Color : Red   Shape : Circle
Body2 : Color : Green   Shape : Circle

*/
```
## 组合模式 Composite Pattern
> 一个系可以分成很多学院，一个学院又可以分成很多年级，最后是每个人，怎么用逻辑的方式实现这种结构。
- **核心**
  叶子和子容器。
- **概念**
  将对象封装为树状结构，以满足其逻辑上的分布式。
- **实现**
  1. *实现结构*
    叶子和树干的抽象父类。带有添加，删除，访问等接口。
    实现叶子类，继承自父类，带有最后分级的信息。需要对增加，删除接口做特殊处理。
    实现树干类，继承自父类，带有一个父类指针为元素的容器。
  2. *接口调用*
    创建好树叶和树干。
    将树叶传参给树干的添加函数。
### 代码实现
#### 组合模式实现
```cpp
#pragma once

#include <string>
#include <vector>

class Component
{
public:
	virtual ~Component() = default;

public:
	virtual std::string getName() = 0;
	virtual int getSize() = 0;
	
	virtual void add(Component* com) = 0;
	virtual void remove(Component* com) = 0;

};

class Folder : public Component
{
public:
	Folder(const std::string& n)
		: name_(n)
		, size_(0)
	{ }
	
public:
	std::string getName() override
	{
		return name_;
	}
	
	int getSize() override
	{
		return size_;
	}

	void add(Component* com) override
	{
		for (auto temp : vec)
		{
			if (temp->getName() == com->getName())
			{
				throw "the name cannot be duplicate.";
			}
		}
		vec.push_back(com);
		size_ += com->getSize();
	}

	void remove(Component* com) override
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (com->getName() == vec[i]->getName())
			{
				size_ -= vec[i]->getSize();
				vec.erase(vec.begin() + i);
			}
		}
	}

protected:
	std::string name_;
	int size_;
	std::vector<Component*> vec;

};

class File : public Component
{
public:
	File(const std::string& n, int size)
		: name_(n)
		, size_(size)
	{ }
	
public:
	std::string getName() override
	{
		return name_;
	}
	
	int getSize() override
	{
		return size_;
	}

	void add(Component* com) override
	{
		throw "is not folder!";
	}

	void remove(Component* com) override
	{
		throw "is not folder!";
	}
	
protected:
	std::string name_;
	int size_;

};
```
#### 接口调用
```cpp
    // Composite
    Component* file1 = new File("10001.png", 12);
    Component* file2 = new File("11.wav", 1476);
    Component* folder = new Folder("res");
    folder->add(file1);
    folder->add(file2);
    std::cout << folder->getSize() << std::endl;
    folder->remove(file1);
    folder->remove(file2);
    std::cout << folder->getSize() << std::endl;
    delete file1;
    delete file2;
    delete folder;


/*

output:

1488
0

*/
```
## 享元模式 Flyweight Pattern
> 享元模式是为了解决重复对象过多的问题。如，一个地区有1万人口上下班，但是只有500辆共享单车即可满足要求。
> 
> 当这些对象剔除**外部状态**后都是相同的对象，并且有大量重复使用这些对象，需要消耗大量资源。此时就可以用享元模式。
     内部状态：不受外部环境改变，对象本身的属性。
     外部状态：外部所调用它的对象等。
- **核心**
  统一申请这个对象的工厂。
- **概念**
  使用工厂来统一管理少量对象，将其共享给有需要的地方。
- **实现**
  1. *基本结构*
    对象抽象父类，及其子类实现。
    工厂类。需要满足两个条件：创建和管理子类对象；给用户提供的合理接口（根据实际需要判断全部对象被占用是否创建新的，并且需不需要销毁对象）。
  2. *接口调用*
    创建工厂对象。
    使用工厂得到最终对象。
- **场景示例**
  内存池，字符串拘留池，线程池。
### 代码实现
#### 享元模式实现
```cpp
#pragma once

#include <list>

class FlyweightBike
{
public:
    virtual ~FlyweightBike() = default;

public:
    virtual void apply() = 0;

    virtual void back() = 0;

    virtual bool isUse() = 0;

protected:
    int id;
    bool inUse;

};

class Yellow : public FlyweightBike
{
public:
    Yellow(int id)
    {
        FlyweightBike::id = id;
    }

public:
    void apply() override
    {
        FlyweightBike::inUse = true;
    }

    void back() override
    {
        FlyweightBike::inUse = false;
    }

    bool isUse() override
    {
        return FlyweightBike::inUse;
    }

};

class Factory
{
public:
    Factory(int count)
        : id_(0)
    {
        while (id_ < count)
        {
            list_.push_front(new Yellow(id_++));
        }
    }

    ~Factory()
    {
        for (FlyweightBike* temp : list_)
        {
            delete temp;
        }
    }

public:
    FlyweightBike* apply()
    {
        for (std::list<FlyweightBike*>::iterator it = list_.begin(); it != list_.end(); ++it)
        {
            if (!(*it)->isUse())
            {
                (*it)->apply();
                return (*it);
            }
        }
        return nullptr;
    }

    void back(FlyweightBike*& bike)
    {
        bike->back();
        bike = nullptr;
    }

protected:
    std::list<FlyweightBike*> list_;
    int id_;

};
```
#### 接口调用
```cpp
    // Flyweight
    Factory* fact = new Factory(2);
    for (int i = 0; i < 3; ++i)
    {
        FlyweightBike* temp = fact->apply();
        if(temp)
        {
            std::cout << i << " application is successful.";
        }
        else
        {
            std::cout << i << " application isn't successful.";
        }
        std::cout << std::endl;
    }
    delete fact;



/*

output:

0 application is successful.
1 application is successful.
2 application isn't successful.

*/
```
# 行为模式
## 模板方法模式 Template Method Pattern
> 行为的步骤相同，但不同类型每一步的细节不同时，可以采用相同的步骤，但步骤细节挪到子类实现。
> 
> 可使得子类不改变一个算法结构就重定义一些实现。
- **核心**
  将实现过程分为几步。不同的实现子类。
- **概念**
  定义一个算法骨架，将一些实现延迟到子类。
- **实现**
  1. 实现部分：
    `[1]` 抽象父类（禁用总函数，将步骤函数作为接口）。
    `[2]` 子类重写父类接口。
  2. 接口调用：
    `[1]` 初始化子类对象，用父类指针接收。
    `[2]` 调用父类接口。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>

class AbstractClass
{
public:
    virtual ~AbstractClass() = default;

    virtual void templateMethod() final
    {
        step1();
        step2();
        step3();
    }
protected:
    void step1()
    {
        std::cout << "father class : Fixed step1." << std::endl;
    }

    void step3()
    {
        std::cout << "father class : Fixed step3." << std::endl;
    }

    virtual void step2() = 0;
};

class Component : public AbstractClass
{
protected:
    void step2()
    {
        std::cout << "variable step2." << std::endl;
    }
};
```
#### 接口调用
```cpp
    // template method
    std::unique_ptr<AbstractClass> t1 = std::make_unique<Component>();
    t1->templateMethod();
    
    
/*

output:

father class : Fixed step1.
variable step2.
father class : Fixed step3.

*/
```
## 策略模式 Strategy Pattern
> 对于 不同策略下 行为不同 的对象，可使用策略成员去调用不同的行为。（不同策略由客户端调用切换）
- **核心**
  不同行为交给策略实现。
- **概念**
  封装不同算法/行为，让客户端动态切换。
- **实现**
  1. 实现部分：
    `[1]` 定义策略父类（包含行为接口）。以及不同的状态实现。
    `[2]` 定义产品类（包含策略指针）。
  2. 接口调用：
    `[1]` 初始化产品对象。
    `[2]` 调用产品对象的行为和策略切换函数。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>
#include <memory>

class Strategy
{
public:
    virtual ~Strategy() = default;

    virtual void pay(double amount) = 0;
};

class AlipayStrategy : public Strategy
{
public:
    void pay(double amount) override
    {
        std::cout << "alipay : " << amount << std::endl;
    }
};

class WechatStrategy : public Strategy
{
    void pay(double amount) override
    {
        std::cout << "wechat : " << amount << std::endl;
    }
};

class Order
{
public:
    void setStrategy(std::unique_ptr<Strategy> p)
    {
        strategy_ = std::move(p);
    }

    void pay(double amount)
    {
        if (nullptr != strategy_)
        {
            strategy_->pay(amount);
        }
        else
        {
            std::cout << "Choose your payment method." << std::endl;
        }
    }

private:
    std::unique_ptr<Strategy> strategy_;
};
```
#### 接口调用
```cpp
    // Strategy
    std::unique_ptr<Order> order = std::make_unique<Order>();
    std::unique_ptr<Strategy> a = std::make_unique<AlipayStrategy>();
    order->setStrategy(std::move(a));
    order->pay(100.0);
    std::unique_ptr<Strategy> w = std::make_unique<WechatStrategy>();
    order->setStrategy(std::move(w));
    order->pay(30.0);
    
    
/*

output:

alipay : 100
wechat : 30

*/
```
## 命令模式 Command Pattern
> 对于需要用命令驱动，可以将命令封装成对象去调用。
- **核心**
  命令抽象类和其子类。给客户端的触发者。
- **概念**
  将命令抽象化为对象，从而对不同客户、命令参数化。
- **实现**
  1. 模式实现
    `[1]` 具体命令执行者（具体命令接口）。
    `[2]` 命令抽象类（execute执行接口）。以及具体命令子类。
    `[3]` 触发者，用于给客户端触发命令。
  2. 接口调用
    `[1]` 创建触发者。
    `[2]` 使用触发者触发不同命令。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>

class Light
{
public:
    void turnOn()
    {
        if (!light_)
        {
            std::cout << "turn on." << std::endl;
            light_ = !light_;
        }
        else
        {
            std::cout << "has been turn on." << std::endl;
        }
    }
    void turnOff()
    {
        if (light_)
        {
            std::cout << "turn off." << std::endl;
            light_ = !light_;
        }
        else
        {
            std::cout << "has been turn off." << std::endl;
        }
    }
private:
    bool light_ = false;
};

class Command
{
public:
    virtual ~Command() = default;

    virtual void execute(Light* light) = 0;
};

class CommandTurnOn : public Command
{
public:
    void execute(Light* light) override
    {
        light->turnOn();
    }
};

class CommandTurnOff : public Command
{
public:
    void execute(Light* light) override
    {
        light->turnOff();
    }
};

class Control
{
public:
    Control(Light* light) : light_(light) { }

    void switchover(Command* command)
    {
        current_ = command;
    }

    void execute()
    {
        if (current_)
        {
            current_->execute(light_);
        }
    }
private:
    Command* current_ = nullptr;
    Light* light_;
};
```
#### 接口调用
```cpp
    // command
    Light* light = new Light();
    Control* control = new Control(light);
    Command* on = new CommandTurnOn();
    Command* off = new CommandTurnOff();
    control->switchover(on);
    control->execute();
    control->execute();
    control->switchover(off);
    control->execute();
    delete light;
    delete control;
    delete on;
    delete off;
    
    
/*

output:

turn on.
has been turn on.
turn off.

*/
```
## 职责链模式 Chain of Responsibility Pattern
> 用于对 请求发送者 和 处理者 解耦，可以在 发送者 不知道哪个对象会处理它的情况下发生请求；同理，也可对处理者灵活调整。
- **核心**
  处理者带有指向下一个处理者的指针。
- **概念**
  请求不去指定谁来处理，顺着责任链依次处理，直到处理成功（纯责任链），或每个都可以处理（不纯责任链）。
  确保请求一定被处理或拒绝。
- **实现**
  1. 实现部分：
    `[1]` 定义处理请求的接口，要带有一个指向下一位的指针。
    `[2]` 具体的处理者实现。
  2. 接口调用：
    `[1]` 初始化每个处理者。
    `[2]` 将他们按关系顺序，设置责任链的的顺序。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>
#include <string>

class LoggerBase
{
public:
    LoggerBase()
        : next(nullptr)
    { }
    virtual ~LoggerBase() = default;
public:
    void setNext(LoggerBase* next)
    {
        this->next = next;
    }

    virtual void logMessage(const std::string& msg) = 0;

protected:
    LoggerBase* next;

};

class SmallLogger : public LoggerBase
{
public:
    void logMessage(const std::string& msg) override
    {
        if (msg.size() <= 5)
        {
            std::cout << "Small logger." << std::endl;
            return;
        }
        if (next != nullptr)
        {
            next->logMessage(msg);
        }
    }
};

class LargeLogger : public LoggerBase
{
public:
    void logMessage(const std::string& msg) override
    {
        std::cout << "Large logger." << std::endl;
    }
};
```
#### 接口实现
```cpp
    // chain of responsibility
    LoggerBase* base = new SmallLogger();
    LoggerBase* large = new LargeLogger();
    base->setNext(large);
    base->logMessage("");
    base->logMessage("hhhhhhhhhhhhhhhhhhhhhhhh");
    delete large;
    delete base;
    
/*

output:

Small logger.
Large logger.

*/
```
## 状态模式 State Pattern
> 对于 不同状态下 行为不同 的对象，可使用状态子类去调用不同的行为。（状态由自身逻辑切换）
- **核心**
  具体行为交给状态实现。
- **概念**
  类实现带有一个状态指针，将类的不同行为委托给类的不同状态来处理。
- **实现**
  1. 实现部分：
    `[1]` 向前声明产品类。
    `[2]` 定义状态父类（包含行为接口）。以及不同的状态实现。
    `[3]` 定义产品类（包含状态指针）。
  2. 接口调用：
    `[1]` 初始化产品对象。
    `[2]` 调用产品对象的行为。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <string>

class Light;

class State
{
public:
    virtual ~State() = default;

public:
    virtual std::string getState() = 0;
    virtual void pressSwitch(Light* light) = 0;

};

class OnState : public State
{
public:
    void pressSwitch(Light* light) override;
    std::string getState() override;
};

class OffState : public State
{
public:
    void pressSwitch(Light* light) override;
    std::string getState() override;
};

class Light
{
public:
    Light()
    {
        state_ = new OffState();
    }

    ~Light()
    {
        delete state_;
    }

public:
    void pressSwitch()
    {
        state_->pressSwitch(this);
    }

    void setState(State* state)
    {
        delete state_;
        state_ = state;
    }

    std::string getState()
    {
        return state_->getState();
    }

private:
    State* state_;

};

void OnState::pressSwitch(Light* light)
{
    light->setState(new OffState());
}

std::string OnState::getState()
{
    return "on";
}

void OffState::pressSwitch(Light* light)
{
    light->setState(new OnState());
}

std::string OffState::getState()
{
    return "off";
}
```
#### 接口调用
```cpp
    // state
    Light* light = new Light();
    std::cout << light->getState() << std::endl;
    light->pressSwitch();
    std::cout << light->getState() << std::endl;
    
/*

output:

off
on

*/
```
## 观察者模式 Observer Pattern
> 可以使一个对象更新时，向全部关注它的对象发送信息。
- **核心**
  有一个 观察者类指针链表的 成员。
- **概念**
  添加一个观察它的类的指针列表，当事件更新时向这些对象发送信息。
- **实现**
  1. 实现部分：
    `[1]` 定义观察者父类。
    `[2]` 定义被观察者父类（包含一个观察者链表，一个 遍历链表并调用事件 的更新函数）。
    `[3]` 定义被观察者子类。
    `[4]` 定义观察者子类Z（包含被观察者要调用的事件函数）。
  2. 接口调用：
    `[1]` 初始化被观察者。
    `[2]` 创建观察者，并且添加到被观察者的链表中。
    `[3]` 调用被观察者的更新函数。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>
#include <memory>
#include <list>

class SubjectTemp;

class Observer
{
public:
    virtual ~Observer() = default;

    virtual void update(const SubjectTemp& subject) = 0;
};

class SubjectTemp
{
public:
    SubjectTemp(float temp) : temperature_(temp) { }
    ~SubjectTemp() = default;

    float getTemp() const
    {
        return temperature_;
    }

    void setTemp(float temp)
    {
        temperature_ = temp;
        notify();
    }

    void push(std::shared_ptr<Observer> obs)
    {
        registerObserver_.push_back(obs);
    }

private:
    void notify()
    {
        for (std::shared_ptr<Observer>& observer : registerObserver_)
        {
            observer->update(*this);
        }
    }

protected:
    std::list<std::shared_ptr<Observer>> registerObserver_;
    float temperature_;

};

class Phone : public Observer
{
public:
    Phone(int id) : id_(id) { }

    void update(const SubjectTemp& subject) override
    {
        std::cout << id_ << " phone : the temperature is " << subject.getTemp() << std::endl;
    }

protected:
    int id_;

};
```
#### 接口调用
```cpp
    // observer
    std::shared_ptr<SubjectTemp> station = std::make_shared<SubjectTemp>(28.0f);
    std::shared_ptr<Phone> phoneA = std::make_shared<Phone>(1);
    std::shared_ptr<Phone> phoneB = std::make_shared<Phone>(2);
    station->push(phoneA);
    station->push(phoneB);

    station->setTemp(22.5f);
    station->setTemp(20.5f);
    
    
/*

output:

1 phone : the temperature is 22.5
2 phone : the temperature is 22.5
1 phone : the temperature is 20.5
2 phone : the temperature is 20.5

*/
```
## 中介者模式 Mediator Pattern
> 将多个类之间的联系，转为多个类与一个中介者的联系（或多个中介者）。
- **核心**
  中介者类（中介者和类之间要有相互交流的能力）。
- **概念**
  当两个类想交流时，让一个类将消息发送给中介者去转送消息。
- **实现**
  1. 模式实现
    `[1]` 中介者父类（包含信息交流接口）。
    `[2]` 交流者父类（带有中介者父类指针）。
    `[3]` 具体中介者实现（继承自中介者父类，包含一个交流者列表，和它添加方式）。
    `[4]` 具体交流者（继承自交流者父类）。
  2. 接口调用
    `[1]` 创建中介者。
    `[2]` 创建交流者。
    `[3]` 将交流者添加到中介者父类中。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Mediator
{
public:
    virtual ~Mediator() = default;

    virtual void send(int id, const std::string& s) = 0;
};

class User
{
public:
    virtual ~User() = default;

    User(int id, std::shared_ptr<Mediator> mediator) : id_(id), mediator_(mediator)
    {
        mediator_ = mediator;
    }

    int getID()
    {
        return id_;
    }

    virtual void send(const std::string& s) = 0;
    virtual void receive(int id, const std::string& s) = 0;

protected:
    std::weak_ptr<Mediator> mediator_;
    int id_;
};

class ChatRoom : public Mediator
{
public:
    void send(int id, const std::string& s) override
    {
        for (std::shared_ptr<User>& user : userList_)
        {
            if (user->getID() != id)
            {
                user->receive(id, s);
            }
        }
    }

    void add(std::shared_ptr<User>& user)
    {
        userList_.push_back(user);
    }

protected:
    std::vector<std::shared_ptr<User>> userList_;
};

class Colleague : public User
{
public:
    Colleague(int id, std::shared_ptr<Mediator> mediator) : User(id, mediator) { }

    void send(const std::string& s) override
    {
        if (auto temp = mediator_.lock())
        {
            temp->send(id_, s);
        }
    }

    void receive(int id, const std::string& s) override
    {
        std::cout << id_ << " : received message : " << s << "--from:" << id << std::endl;
    }
};
```
#### 接口调用
```cpp
	// mediator
    std::shared_ptr<ChatRoom> chat = std::make_shared<ChatRoom>();
    std::shared_ptr<User> user1 = std::make_shared<Colleague>(1, chat);
    std::shared_ptr<User> user2 = std::make_shared<Colleague>(2, chat);
    chat->add(user1);
    chat->add(user2);
    user1->send("Hello world!");
    user2->send("What are you doing?");
    
    
/*

output:

2 : received message : Hello world!--from:1
1 : received message : What are you doing?--from:2

*/
```
## 迭代器模式 Iterator Pattern
> 例如STL标准容器的迭代器，可以给不同的低层封装一个相同的遍历接口。
- **核心**
  迭代器类。
- **概念**
  给不同的容器提供一种相同的遍历接口。
- **实现**
  1. 模式实现（也可以选择C++的迭代器实现方式）
    `[1]` 迭代器抽象类（提供：是否下一个存在，得到下一个）。
    `[2]` 容器，如链表。
    `[3]` 对应容器的迭代器（继承自迭代器抽象类）。
  2. 接口调用
    `[1]` 创建容器。
    `[2]` 创建迭代器。
    `[3]` 调用迭代器接口。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <string>

class Iterator
{
public:
    virtual ~Iterator() = default;

    virtual bool hasNext() = 0;
    virtual std::string next() = 0;
};

class List
{
public:
    struct Node
    {
        Node(const std::string& s) : s_(s), next_(nullptr) { }

        std::string s_;
        Node* next_;
    };

public:
    List()
    {
        head_ = new Node("");
        tail_ = head_;
    }

    void add(const std::string& s)
    {
        tail_->next_ = new Node(s);
        tail_ = tail_->next_;
    }

    Node* getHead()
    {
        return head_;
    }

private:
    Node* head_;
    Node* tail_;
};

class ListIterator : Iterator
{
public:
    ListIterator(List::Node* node) : node_(node) { }

    bool hasNext()
    {
        return node_->next_;
    }

    std::string next()
    {
        node_ = node_->next_;
        return node_->s_;
    }
private:
    List::Node* node_;
};
```
#### 接口调用
```cpp
    // iterator
    List list;
    list.add("hello");
    list.add("world");
    ListIterator it(list.getHead());
    while (it.hasNext())
    {
        std::cout << it.next() << " ";
    }
    
    
/*

output:

hello world

*/
```
## 访问者模式 Visitor Pattern
> 多对多的关系之间，如果有一方（元素）是固定的，只有另一方会增加功能（访问者），可以采用访问者模式。
> 
> 注意如果 元素 在后期会变动，会导致所有 访问者 都会变动。
- **核心**
  访问者带有全部元素的调用行为。
  元素的事件中，将自己传给访问者的对应函数执行。
- **概念**
  将对象和对象的操作分离，让访问者带有具体的操作逻辑。
- **实现**
  1. 模式实现
    `[1]` 向前声明元素相关类。
    `[2]` 定义访问者抽象类（包含每个元素子类的事件接口）。和其具体子类。
    `[3]` 定义元素抽象类（包含接收访问者抽象类指针的事件接口）。和其具体子类（接口中调用自己相关的函数，并将自己的this指针传进去）。
    `[4]` （可选）创建每个访问者具体的访问列表，直接遍历即可全部调用。
  2. 接口调用
    `[1]` 创建每个元素。
    `[2]` 创建每个访问者，并传参具体元素调用事件接口。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <iostream>
#include <string>
#include <memory>

class Element;
class Shop;
class Community;

class Visitor
{
public:
    virtual ~Visitor() = default;

    virtual void serveShop(Shop& shop) = 0;
    virtual void serveCommunity(Community& community) = 0;
};

class Cleaner : public Visitor
{
public:
    void serveShop(Shop& shop) override;
    void serveCommunity(Community& community) override;
};

class Repairman : public Visitor
{
public:
    void serveShop(Shop& shop) override;
    void serveCommunity(Community& community) override;
};

class Element
{
public:
    Element(const std::string& s) : name_(s) { }
    virtual ~Element() = default;

    std::string getName()
    {
        return name_;
    }

    virtual void accept(std::shared_ptr<Visitor> visitor) = 0;
protected:
    std::string name_;
};

class Shop : public Element
{
public:
    Shop(const std::string& s) : Element(s) { }

    void accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->serveShop(*this);
    }
};

class Community : public Element
{
public:
    Community(const std::string& s) : Element(s) { }

    void accept(std::shared_ptr<Visitor> visitor) override
    {
        visitor->serveCommunity(*this);
    }
};

void Cleaner::serveShop(Shop& shop)
{
    std::cout << "Cleaning the " << shop.getName() << " shop." << std::endl;
}

void Cleaner::serveCommunity(Community& community)
{
    std::cout << "Cleaning the " << community.getName() << " community." << std::endl;
}

void Repairman::serveShop(Shop& shop)
{
    std::cout << "Repairing the " << shop.getName() << " shop." << std::endl;
}

void Repairman::serveCommunity(Community& community)
{
    std::cout << "Repairing the " << community.getName() << " community." << std::endl;
}
```
#### 接口调用
```cpp
    // visitor
    std::shared_ptr<Shop> shop = std::make_shared<Shop>("LiHua");
    std::shared_ptr<Community> community = std::make_shared<Community>("JinYan");
    std::shared_ptr<Visitor> cleaner = std::make_shared<Cleaner>();
    std::shared_ptr<Visitor> repairman = std::make_shared<Repairman>();
    shop->accept(cleaner);
    community->accept(cleaner);
    community->accept(repairman);
    
    
/*

output:

Cleaning the LiHua shop.
Cleaning the JinYan community.
Repairing the JinYan community.

*/
```
## 备忘录模式 Memento Pattern
> 用于恢复到某一状态，如word撤回，游戏存档。
- **核心**
  记录原数据的备页录类。
- **概念**
  让管理者类带有一个对象的备页录数组，用于记录版本信息。不使用原对象的原因：一来防止管理者修改备忘页类，二来无法记录更多信息，所以副本一般会选择创建一个新类。（创建过程可配合**原型模式**或**friend**关键字）
- **实现**
  1. 实现部分：
    `[1]` 定义资源类。
    `[2]` 定义备忘页类。
    `[3]` 定义资源管理类（带有备忘页数组，并实现存档、回档、修改资源等操作）。
  2. 接口调用：
    `[1]` 初始化管理者。
    `[2]` 调用管理者的存档、回档、修改资源等操作。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <string>
#include <vector>

struct Text
{
    std::string str;
    int color = 0;
};

class Memento
{
public:
    Memento(const Text& text) : text_(text) { }

    Text getText()
    {
        return text_;
    }

protected:
    Text text_;
};

class TextEditor
{
public:
    TextEditor(const std::string& text, int color = 0)
    {
        text_.str = text;
        text_.color = color;
    }

    std::string getText()
    {
        return text_.str;
    }

    void setText(std::string text, int color = 0)
    {
        text_.str = text;
        text_.color = color;
    }

    void save()
    {
        history_.push_back(text_);
    }

    void undo()
    {
        if (!history_.size())
        {
            return;
        }
        Text temp = history_.back().getText();
        text_.color = temp.color;
        text_.str = temp.str;
        history_.pop_back();
    }

private:
    Text text_;
    std::vector<Memento> history_;
};
```
#### 接口调用
```cpp
    // memento
    std::unique_ptr<TextEditor> editor = std::make_unique<TextEditor>("1234");
    editor->save();
    editor->setText(editor->getText() + "56");
    std::cout << editor->getText() << std::endl;
    editor->undo();
    std::cout << editor->getText() << std::endl;
    
    
/*

output:

123456
1234

*/
```
## 解释器模式 Interpreter Pattern
> 一种理解相对困难的行为模式，对于文本解析的实现时，解释器是相当不错的方式。
- **核心**
  终结符表达式类 和 非终结符表达式类。构建语法树。
- **概念**
  定义一个语言的文法，并建立一个解释器来解释该语句的句子。当解释不成功则传给下一个解释器，成功就返回。
- **实现**
  1. 实现部分：
    `[1]` （可选）上下文类（包含外部和临时信息）。
    `[2]` 表达式父类。
    `[3]` 基于表达式父类实现 终结符表达式类 和 非终结符表达式类。
    `[4]` 基于上下文和两种表达式构建**语法树**的类。
  2. 接口调用：
    `[1]` 初始化语句，一般为字符串。
    `[2]` 构建并得到**语法树**的根节点。
    `[3]` 调用根节点的interpret接口得到值。
### 代码实现
#### 模式实现
```cpp
#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <vector>

class Expression
{
public:
    virtual ~Expression() = default;

    virtual int interpret() = 0;
};

class NumberExpression : public Expression
{
    int val_;
public:
    NumberExpression(int val) : val_(val) { }

    int interpret() override
    {
        return val_;
    }
};

class AddExpression : public Expression
{
    std::unique_ptr<Expression> a_;
    std::unique_ptr<Expression> b_;
public:
    AddExpression(std::unique_ptr<Expression> a, std::unique_ptr<Expression> b) : a_(std::move(a)), b_(std::move(b)) { }

    int interpret() override
    {
        return a_->interpret() + b_->interpret();
    }
};

std::unique_ptr<Expression> build(const std::string& expr)
{
    std::stringstream ss(expr);
    std::string temp;

    std::vector<int> vec;

    while (std::getline(ss, temp, '+'))
    {
        vec.push_back(std::stoi(temp));
    }

    std::unique_ptr<Expression> root = std::make_unique<NumberExpression>(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i)
    {
        root = std::make_unique<AddExpression>(std::move(root), std::make_unique<NumberExpression>(vec[i]));
    }

    return root;
}
```
#### 接口调用
```cpp
    // Interpreter
    std::cout << build("10+20+30+2")->interpret() << std::endl;
    
    
/*

output:

62

*/
```  
# MVC模式
> 一种常见的符合设计模式
- model
  模型：数据本身，对客户端不显示。
- view
  视图：呈现模型。根据model呈现相应内容。
- control
  控制器：用户的操作接口，取得客户端输入，翻译为对model的控制。