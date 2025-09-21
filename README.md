# basic_cpp_projects

This repository contains all the C++ modules from **1337 School**, implemented using the **C++98** standard.  
It covers the fundamentals and advanced concepts of **Object-Oriented Programming (OOP)** in C++.  

# C++ Concepts Learned (CPP00 - CPP02)

## 📚 Complete Overview

| **Module** | **Concept** | **Description** | **Key Features** | **Example Use Case** |
|------------|-------------|-----------------|------------------|----------------------|
| **CPP00** | **Namespaces** | Organize code and avoid naming conflicts | `namespace MySpace { }`, `using namespace std` | Preventing function/variable name collisions |
| **CPP00** | **Classes** | Blueprint for creating objects | `class ClassName { private: public: };` | Encapsulating data and methods together |
| **CPP00** | **Member Functions** | Functions defined inside classes | `void functionName();` inside class | Methods that operate on object data |
| **CPP00** | **Member Attributes** | Variables defined inside classes | `int attribute;` in private/public sections | Storing object state and data |
| **CPP00** | **Stdio Streams** | C++ input/output system | `std::cin`, `std::cout`, `std::endl` | Reading user input and displaying output |
| **CPP00** | **Initialization Lists** | Initialize member variables efficiently | `Constructor() : member(value) {}` | Setting initial values before constructor body |
| **CPP00** | **Static** | Class-level members shared by all instances | `static int count;`, `static void func();` | Counters, utility functions, shared data |
| **CPP00** | **Const** | Immutable variables and functions | `const int x = 5;`, `void func() const;` | Preventing accidental modifications |
| **CPP01** | **Memory Allocation** | Dynamic memory management | `new`, `delete`, `new[]`, `delete[]` | Creating objects/arrays at runtime |
| **CPP01** | **Pointers to Members** | Accessing class members via pointers | `&Class::member`, `(obj.*ptr)()` | Function pointers within classes |
| **CPP01** | **References** | Aliases to existing variables | `int& ref = variable;` | Avoiding copies, cleaner syntax than pointers |
| **CPP01** | **Switch Statement** | Multi-way conditional branching | `switch(var) { case 1: ... break; }` | Handling multiple discrete values efficiently |
| **CPP02** | **Ad-hoc Polymorphism** | Function/operator overloading | Multiple functions with same name, different params | `print(int)`, `print(string)`, `print(float)` |
| **CPP02** | **Operator Overloading** | Custom behavior for operators on classes | `operator+`, `operator<<`, `operator=` | Making custom classes work with +, -, *, etc. |
| **CPP02** | **Orthodox Canonical Class** | Standard class form with essential functions | Constructor, Destructor, Copy Constructor, Assignment | Proper resource management and copying |
| **CPP02** | **Fixed Point Numbers** | Alternative to floating point representation | Custom class with scaled integer representation | Financial calculations, embedded systems |

## 🔧 Implementation Patterns

| **Pattern** | **Syntax** | **Purpose** | **Best Practice** |
|-------------|------------|-------------|-------------------|
| **Constructor** | `ClassName(params) : member(value) {}` | Object initialization | Use initialization lists for efficiency |
| **Destructor** | `~ClassName() {}` | Cleanup resources | Always virtual for inheritance |
| **Copy Constructor** | `ClassName(const ClassName& other)` | Create copy of existing object | Deep copy for dynamic memory |
| **Assignment Operator** | `ClassName& operator=(const ClassName& rhs)` | Assign one object to another | Check self-assignment, return *this |
| **Const Member Function** | `void function() const {}` | Function that doesn't modify object | Use whenever function doesn't change state |
| **Static Member Function** | `static void function() {}` | Class-level function, no object needed | Access only static members |

## 🎯 Key Learning Outcomes

| **Skill** | **Description** | **Applications** |
|-----------|-----------------|------------------|
| **Object-Oriented Design** | Creating classes with proper encapsulation | Building maintainable, modular code |
| **Memory Management** | Understanding stack vs heap, preventing leaks | System programming, performance optimization |
| **Operator Overloading** | Making custom types behave like built-in types | Creating intuitive APIs and mathematical classes |
| **RAII Principle** | Resource Acquisition Is Initialization | Exception-safe code, automatic cleanup |
| **Canonical Form** | Standard class implementation pattern | Industry-standard C++ class design |

## 📋 Projects Completed

- **CPP00**: Basic C++ syntax, classes, namespaces, I/O streams
- **CPP01**: Memory management, pointers, references, file handling  
- **CPP02**: Operator overloading, fixed-point arithmetic, canonical class form

---

*These modules provided a solid foundation in C++ fundamentals, object-oriented programming, and memory management - essential skills for systems programming and software development.*
