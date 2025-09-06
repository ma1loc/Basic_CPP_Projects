# 📘 C++ Practice Task: Library & Books

## Objective
Practice C++ class implementation, object interaction, and encapsulation by modeling a **Library** that manages a collection of **Books**.

---

## Requirements

### Class: `Book`
- **Private attributes**:
  - `std::string title`
  - `std::string author`
  - `int pages`
  - `bool isBorrowed`
- **Public methods**:
  - Constructor to initialize all attributes.
  - `getTitle()`, `getAuthor()`, `getPages()`, `getBorrowedStatus()`.
  - `borrowBook()` → sets `isBorrowed = true`.
  - `returnBook()` → sets `isBorrowed = false`.
  - `printInfo()` → prints details of the book.

---

### Class: `Library`
- **Private attributes**:
  - `std::vector<Book> books`
- **Public methods**:
  - `addBook(const Book &b)` → add a book to the library.
  - `showAllBooks()` → loop through and call each book’s `printInfo()`.
  - `countBorrowedBooks()` → return number of borrowed books.

---

## Tasks
1. Create at least **4 Book objects** with different titles and authors.
2. Add them to a Library object using `addBook()`.
3. Show all books in the library with `showAllBooks()`.
4. Borrow one or two books using `borrowBook()`.
5. Show how many books are currently borrowed with `countBorrowedBooks()`.

---

## Bonus
- Add a method `findBookByTitle(std::string title)` that searches for a book and prints its details.
- Make the program interactive: allow the user to add, borrow, return, and list books.
