#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Books {
    int price, numberOfPages, quantity, numberOfSales;
    string author;

public:
    Books(int price, int numberOfPages, int quantity, int numberOfSales, string author) {
        this->price = price;
        this->numberOfPages = numberOfPages;
        this->quantity = quantity;
        this->numberOfSales = numberOfSales;
        this->author = move(author);
    }

public:
    int getPrice() const { return price; }
    int getSales() const { return numberOfSales; }
    string getName() const { return author; }

    ~Books() = default;
};

class  BookShop {
public:
    vector <Books> books;

public:
    void addBook(const Books& addedBooks) {
        books.push_back(addedBooks);
    }

    void sortByPrice() {

        for (int j = 0; j < books.size() - 1; j++) {
            for (int i = 0; i < books.size() - 1; i++) {
                if (books[i].getPrice() < books[i + 1].getPrice()) {
                    swap(books[i], books[i + 1]);
                }
            }
        }
        cout << "Sorted by price \n";
        for (auto& i : books) {
            cout << i.getName() + '\n';
        }

        cout << "\n";
    }

    void sortBySales() {
        for (int j = 0; j < books.size() - 1; j++) {
            for (int i = 0; i < books.size() - 1; i++) {
                if (books[i].getSales() < books[i + 1].getSales()) {
                    swap(books[i], books[i + 1]);
                }
            }
        }
        cout << "Sorted by sales \n";
        for (auto& i : books) {
            cout << i.getName() + '\n';
        }

        cout << "\n";
    }
};

int main() {
    BookShop a = *new BookShop;
    a.addBook(Books(2000, 4, 5, 1000, "Orwell"));
    a.addBook(Books(500, 4, 5, 50, "Shewchenko"));
    a.addBook(Books(100, 4, 5, 200, "Franko"));
    a.addBook(Books(1000, 6, 8, 100, "Max Kidruck"));

    a.sortByPrice();
    a.sortBySales();

    return 0;
}
