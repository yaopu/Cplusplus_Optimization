#include <iostream>
#include <memory>
#include <string>
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

void test_on_stack() {
  ///构造函数，顺序执行
  ///析构函数，逆序执行
  Person person("小明");
  person.show();
  PersonB person2("小李");
  person2.show();
  PersonA person3("小张");
  person3.show();
}

void test_on_heap() {
  Person *person = new Person("小明");
  person->show();
  person = new PersonA("小李");
  person->show();
  person = new PersonB("小张");
  person->show();
}

void test_by_smptr() {
  shared_ptr<Person> person = make_shared<Person>("小明");
  person->show();
  person = make_shared<PersonA>("小李"); // make_shared()
  person->show();
  person = make_shared<PersonB>("小张"); // make_shared();
  person->show();
}

int main() {
  test_on_stack();
  // test_on_heap();
  // test_by_smptr();
  return 0;
}
