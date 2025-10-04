# Exercise 00: Polymorphism - Complete Understanding Guide

## 1. What is Polymorphism?

**Polymorphism** means "many forms". In C++, it allows objects of different classes to be treated as objects of a common base class, while still maintaining their specific behavior.

### The Core Problem It Solves

Imagine you have a zoo with many animals. Without polymorphism:
```cpp
Dog dog;
Cat cat;
Bird bird;

dog.makeSound();   // Need to know it's a Dog
cat.makeSound();   // Need to know it's a Cat
bird.makeSound();  // Need to know it's a Bird
```

With polymorphism:
```cpp
Animal* animals[3];
animals[0] = new Dog();
animals[1] = new Cat();
animals[2] = new Bird();

for (int i = 0; i < 3; i++)
    animals[i]->makeSound();  // Each calls the correct sound!
```

## 2. The `virtual` Keyword - The Heart of Polymorphism

### What Does `virtual` Do?

When you declare a function as `virtual` in a base class:
```cpp
class Animal {
    virtual void makeSound() const;  // Virtual function
};
```

You're telling C++: **"Look at the actual object type at runtime, not the pointer type"**

### With vs Without Virtual

#### WITHOUT virtual (WrongAnimal example):
```cpp
class WrongAnimal {
    void makeSound() const;  // NOT virtual
};

class WrongCat : public WrongAnimal {
    void makeSound() const;  // Overrides, but not polymorphically
};

// Usage:
WrongAnimal* ptr = new WrongCat();
ptr->makeSound();  // Calls WrongAnimal::makeSound() ❌
                   // Uses POINTER TYPE (WrongAnimal*)
```

#### WITH virtual (Animal example):
```cpp
class Animal {
    virtual void makeSound() const;  // Virtual
};

class Cat : public Animal {
    void makeSound() const;  // Polymorphic override
};

// Usage:
Animal* ptr = new Cat();
ptr->makeSound();  // Calls Cat::makeSound() ✅
                   // Uses ACTUAL OBJECT TYPE (Cat)
```

## 3. Virtual Destructor - Critical for Memory Safety

### The Problem Without Virtual Destructor

```cpp
class Animal {
    ~Animal() { }  // NOT virtual
};

class Dog : public Animal {
    private:
        Brain* brain;  // Dynamically allocated
    public:
        ~Dog() { delete brain; }
};

// Memory leak happens here:
Animal* ptr = new Dog();
delete ptr;  // Only calls Animal::~Animal()
             // Dog::~Dog() NEVER CALLED
             // brain is NEVER deleted = MEMORY LEAK
```

### The Solution: Virtual Destructor

```cpp
class Animal {
    virtual ~Animal() { }  // Virtual destructor
};

class Dog : public Animal {
    private:
        Brain* brain;
    public:
        ~Dog() { delete brain; }
};

// Correct cleanup:
Animal* ptr = new Dog();
delete ptr;  // Calls Dog::~Dog() first, then Animal::~Animal()
             // brain is properly deleted ✅
```

### Rule of Thumb
**If a class has ANY virtual function, it MUST have a virtual destructor.**

## 4. How Polymorphism Works Under the Hood

### The Virtual Table (vtable)

When you use `virtual`, C++ creates a hidden table of function pointers:

```
Animal vtable:
┌─────────────────────┐
│ makeSound() ────────┼──> Animal::makeSound()
│ ~Animal()   ────────┼──> Animal::~Animal()
└─────────────────────┘

Dog vtable:
┌─────────────────────┐
│ makeSound() ────────┼──> Dog::makeSound()
│ ~Animal()   ────────┼──> Dog::~Dog()
└─────────────────────┘
```

Each object has a hidden pointer (vptr) pointing to its class's vtable.

```cpp
Animal* ptr = new Dog();
ptr->makeSound();
```

**What happens:**
1. ptr points to a Dog object
2. Dog object has vptr pointing to Dog's vtable
3. Lookup makeSound() in Dog's vtable
4. Call Dog::makeSound()

**Cost:** One extra pointer per object + one indirection per virtual call

## 5. When to Use Polymorphism

### Use Cases

1. **Collections of Related Objects**
   ```cpp
   std::vector<Animal*> zoo;
   zoo.push_back(new Dog());
   zoo.push_back(new Cat());
   zoo.push_back(new Bird());
   
   for (Animal* animal : zoo)
       animal->makeSound();  // Each makes its own sound
   ```

2. **Plugin Systems / Extensibility**
   ```cpp
   class Shape {
       virtual void draw() = 0;  // Pure virtual
   };
   
   // Can add new shapes without changing existing code
   class Circle : public Shape { void draw() { ... } };
   class Square : public Shape { void draw() { ... } };
   ```

3. **Strategy Pattern**
   ```cpp
   class SortStrategy {
       virtual void sort(int* arr, int size) = 0;
   };
   
   class QuickSort : public SortStrategy { ... };
   class MergeSort : public SortStrategy { ... };
   ```

### When NOT to Use It

1. **Performance-Critical Code**: Virtual calls have overhead
2. **Simple Inheritance**: If you never use base class pointers
3. **Value Semantics**: When you copy objects by value, not pointers

## 6. Key Concepts Demonstrated in Ex00

### Orthodox Canonical Form with Inheritance

Every class needs:
```cpp
class Dog : public Animal {
    public:
        Dog();                              // Default constructor
        Dog(const Dog& copy);               // Copy constructor
        Dog& operator=(const Dog& copy);    // Assignment operator
        ~Dog();                             // Destructor (virtual in base)
};
```

### Proper Copy Constructor
```cpp
Dog::Dog(const Dog& copy) : Animal(copy)  // Call base copy constructor!
{
    // Copy Dog-specific members
}
```

### Proper Assignment Operator
```cpp
Dog& Dog::operator=(const Dog& copy) {
    if (this != &copy) {
        Animal::operator=(copy);  // Call base assignment!
        // Copy Dog-specific members
    }
    return *this;
}
```

## 7. Common Mistakes and How to Avoid Them

### Mistake 1: Forgetting Virtual Destructor
```cpp
// BAD
class Animal {
    ~Animal() { }  // Not virtual = memory leaks
};
```

### Mistake 2: Slicing
```cpp
Dog dog;
Animal animal = dog;  // SLICING! Only Animal part is copied
animal.makeSound();   // Calls Animal::makeSound(), not Dog's
```
**Solution:** Use pointers or references
```cpp
Animal* animal = &dog;  // ✅
Animal& animal = dog;   // ✅
```

### Mistake 3: Not Calling Base Class Constructors
```cpp
// BAD
Dog::Dog(const Dog& copy) {  // Doesn't call Animal(copy)
    // ...
}

// GOOD
Dog::Dog(const Dog& copy) : Animal(copy) {
    // ...
}
```

### Mistake 4: Virtual in Constructor/Destructor
```cpp
class Animal {
    Animal() {
        init();  // If init() is virtual, it won't call derived version!
    }
    virtual void init() { }
};
```
Virtual calls in constructors/destructors don't work polymorphically because the derived object doesn't exist yet (or is already destroyed).

## 8. The Purpose of WrongAnimal/WrongCat

The Wrong classes demonstrate what happens **without** polymorphism:

```cpp
WrongAnimal* ptr = new WrongCat();
ptr->makeSound();  // Calls WrongAnimal::makeSound()
                   // NOT WrongCat::makeSound()
```

This shows you **why** the `virtual` keyword is essential. Without it:
- Function calls are resolved at **compile time** based on pointer type
- With it, they're resolved at **runtime** based on actual object type

## 9. Memory Management in Polymorphism

### The Delete Chain
```cpp
Animal* ptr = new Dog();
delete ptr;
```

With virtual destructor, the call chain is:
1. `Dog::~Dog()` - cleans up Dog-specific resources
2. `Animal::~Animal()` - cleans up Animal resources

Without virtual destructor:
1. `Animal::~Animal()` only - **Dog resources leak!**

## 10. Quick Reference

### Checklist for Polymorphic Classes

- ✅ Base class has virtual destructor
- ✅ Functions you want to override are virtual
- ✅ All classes have Orthodox Canonical Form
- ✅ Copy constructors call base class copy constructor
- ✅ Assignment operators call base assignment operator
- ✅ Always use pointers/references for polymorphism
- ✅ Delete through base class pointers safely
- ✅ Test with different object types through base pointers

### Key Terminology

- **Virtual function**: Function that can be overridden, resolved at runtime
- **Pure virtual**: `= 0`, makes class abstract, must be overridden
- **Override**: Derived class provides its own implementation
- **Polymorphism**: Same interface, different behaviors
- **Dynamic binding**: Function call resolved at runtime
- **Static binding**: Function call resolved at compile time (default)
- **vtable**: Virtual function table, how polymorphism is implemented
- **Slicing**: Losing derived class data when copying to base class value

## Summary

Polymorphism lets you write flexible, extensible code where:
- You can treat different objects uniformly through a common interface
- Each object maintains its specific behavior
- New types can be added without changing existing code
- The `virtual` keyword is what makes it all work
- Virtual destructors prevent memory leaks
- There's a small runtime cost for the flexibility gained

The exercise teaches you that inheritance without polymorphism (WrongAnimal) is limited, while inheritance with polymorphism (Animal) gives you powerful abstractions.