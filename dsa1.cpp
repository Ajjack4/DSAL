#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define the hash table size
const int TABLE_SIZE = 100;

// Define a structure for the telephone book entry
struct Entry {
    string name;
    string phoneNumber;
};

// Define a structure for the hash table
struct HashTable {
    vector<Entry> table[TABLE_SIZE]; // Use vector to handle collisions

    // Hash function to generate an index for a given key
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % TABLE_SIZE;
    }

    // Insert a new entry into the hash table
    void insert(const string& name, const string& phoneNumber) {
        int index = hashFunction(name);
        table[index].push_back({name, phoneNumber});
    }

    // Search for an entry in the hash table
    string search(const string& name) {
        int index = hashFunction(name);
        for (const Entry& entry : table[index]) {
            if (entry.name == name) {
                return entry.phoneNumber;
            }
        }
        return "Not found";
    }
};

int main() {
    // Create a hash table
    HashTable telephoneBook;

    // Insert some entries
    telephoneBook.insert("Alice", "1234567890");
    telephoneBook.insert("Bob", "2345678901");
    telephoneBook.insert("Charlie", "3456789012");

    // Search for entries
    cout << "Alice's phone number: " << telephoneBook.search("Alice") << endl;
    cout << "Bob's phone number: " << telephoneBook.search("Bob") << endl;
    cout << "Dave's phone number: " << telephoneBook.search("Dave") << endl;

    return 0;}
