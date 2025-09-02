# Apple Inventory System - C++ Classes Task

## Objective
Implement a small system to manage apples in a store. This will help you practice **classes, encapsulation, constructors, and member functions** in C++.

---

## Step 1: Define the `Apple` Class

**Private attributes:**
- `std::string color;` (e.g., "red", "green")
- `double weight;` (in grams)
- `bool isRipe;`  

**Public methods:**
- Constructor(s) to initialize an apple.
- Getter functions for each attribute.
- `void ripen();` → set `isRipe` to `true`.
- `void printInfo();` → prints all apple details.

---

## Step 2: Define the `AppleBasket` Class

**Private attributes:**
- `std::vector<Apple> apples;` → stores multiple apples.

**Public methods:**
- `void addApple(const Apple& a);` → add an apple to the basket.
- `void showAllApples();` → prints info of all apples.
- `int countRipeApples();` → returns how many apples are ripe.

---

## Step 3: Implement a `main` Function

- Create a few apples with different colors and weights.
- Add them to the `AppleBasket`.
- Ripen some apples.
- Print the basket info.
- Show how many apples are ripe.

---

## Step 4: Extra Challenges (Optional)

1. Add a `static int totalApples;` in the `Apple` class to count all apples created.
2. Overload the constructor to allow creating apples with default values (e.g., green, 100g, not ripe).
3. Implement a function in `AppleBasket` to remove rotten apples (simulate with `isRipe` boolean).

---

### Concepts Practiced

- Class definition
- Private vs public members
- Constructors and methods
- Working with `std::vector` of objects
- Static class members (optional)
