#include <iostream>
#include <memory> //智能指针定义在这个头文件里
#include <vector>
using namespace std;
class Person {
public:
  string name;
  Person() {}
  Person(const char *_name) { name = _name; }
  virtual void show() { cout << name << " show in Person" << endl; }
  virtual ~Person() { cout << name << " delete in Person\n"; }
};

class PersonA : public Person {
public:
  PersonA() {}
  PersonA(const char *_name) { name = _name; }
  void show() { cout << name << " show in PersonA" << endl; }
  virtual ~PersonA() { cout << name << " delete in PersonA\n"; }
};
class PersonB : public Person {
public:
  PersonB() {}
  PersonB(const char *_name) { name = _name; }
  void show() { cout << name << " show in PersonB" << endl; }
  virtual ~PersonB() { cout << name << " delete in PersonB\n"; }
};

/*
int main() {
  //栈上
  //可以看出，分别生成了三个类，程序退出的时候，都调用了析构函数，删除了三个对象。
  //因为PersonA和PersonB是Person的派生类，所以析构的时候回调用基类Person的析构函数。
  //析构函数，先执行的类，后释放析构函数
  Person person("小明");
  person.show();

  PersonB person2("小李");
  person2.show(); //先执行子类的析构函数，再执行父类的析构函数

  PersonA person3("小张");
  person3.show();
  return 0;
}
*/

/*
int main() {
  //但是，这里我们使用的是new，申请的对象的地址是保存在堆中，需要我们手动申请空间，
  //当然，删除这个空间也需要我们手动删除。
  //但是我们没有在程序的最后进行删除对象，所以最后没有调用析构函数，这样很容易造成内存泄漏。
  //但是，一个对象何时删除，这是一个比较麻烦的事情。
  Person *person = new Person("小明"); //堆上申请
  person->show();
  person = new PersonA("小李");
  person->show();
  person = new PersonB("小张");
  person->show();
  return 0;
}
*/

//离开作用域之后，自动
int main() {
  shared_ptr<Person> person = make_shared<Person>("小明");
  person->show();
  person = make_shared<PersonA>("小李");
  person->show();
  person = make_shared<PersonB>("小张");
  person->show();
  return 0;
}
