#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Book
{
public:
    string title;
    string author;
    int id;
    Book(string t, string a, int i) : title(t), author(a), id(i) {}
};

// Library class to manage books
class Library
{
private:
    vector<Book> books;

public:
    // Add a book to the library
    void addBook(string title, string author, int id)
    {
        Book book(title, author, id);
        books.push_back(book);
        cout << "Book added successfully.\n";
    }

    // Remove a book from the library by ID
    void removeBook(int id)
    {
        auto it = find_if(books.begin(), books.end(), [id](const Book& b)
        {
            return b.id == id;
        });

        if (it != books.end())
        {
            books.erase(it);
            cout << "Book removed successfully.\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    // Display the list of all books in the library
    void displayBooks()
    {
        if (books.empty())
        {
            cout << "Library is empty.\n";
        }
        else
        {
            cout << "Library books:\n";
            for (const auto& book : books)
            {
                cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author << "\n";
            }
        }
    }

    // Search for a book by title
    void searchBook(string title)
    {
        auto it = find_if(books.begin(), books.end(), [title](const Book& b)
        {
            return b.title == title;
        });

        if (it != books.end())
        {
            cout << "Book found - ID: " << it->id << ", Title: " << it->title << ", Author: " << it->author << "\n";
        }
        else
        {
            cout << "Book not found.\n";
        }
    }

    
    void menuDisplay() {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books\n";
        cout << "4. Search Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }

};

int main()
{
    Library library;

    while (true)
    {
        library.menuDisplay();
        
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string title, author;
            int id;

            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);

            cout << "Enter book author: ";
            getline(cin, author);

            cout << "Enter book ID: ";
            cin >> id;

            library.addBook(title, author, id);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter book ID to remove: ";
            cin >> id;
            library.removeBook(id);
            break;
        }
        case 3:
            library.displayBooks();
            break;
        case 4:
        {
            string title;
            cout << "Enter book title to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBook(title);
            break;
        }
        case 5:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
