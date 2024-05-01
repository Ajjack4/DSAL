#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Set {
private:
    unordered_set<int> elements;

public:
    // A) Add(New element) - Place a value into the set
    void add(int element) {
        elements.insert(element);
    }

    // B) Remove(element) - Remove the value
    void remove(int element) {
        elements.erase(element);
    }

    // C) Contains(element) - Return true if element is in collection
    bool contains(int element) const {
        return elements.find(element) != elements.end();
    }

    // D) Size() - Return number of values in collection
    int size() const {
        return elements.size();
    }

    // E) Intersection of two sets
    Set intersection(const Set& other) const {
        Set result;
        for (int element : elements) {
            if (other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // F) Union of two sets
    Set unionSet(const Set& other) const {
        Set result = *this;
        for (int element : other.elements) {
            result.add(element);
        }
        return result;
    }

    // G) Difference between two sets
    Set difference(const Set& other) const {
        Set result;
        for (int element : elements) {
            if (!other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // H) Subset
    bool isSubset(const Set& other) const {
        for (int element : elements) {
            if (!other.contains(element)) {
                return false;
            }
        }
        return true;
    }

    // Iterator() - Return an iterator used to loop over collection
    vector<int> getElements() const {
        vector<int> result;
        for (int element : elements) {
            result.push_back(element);
        }
        return result;
    }
};

int main() {
    Set set1, set2;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    set2.add(3);
    set2.add(4);
    set2.add(5);

    cout << "Set 1: ";
    for (int element : set1.getElements()) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Set 2: ";
    for (int element : set2.getElements()) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Intersection: ";
    Set intersection = set1.intersection(set2);
    for (int element : intersection.getElements()) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Union: ";
    Set unionSet = set1.unionSet(set2);
    for (int element : unionSet.getElements()) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Difference (set1 - set2): ";
    Set difference = set1.difference(set2);
    for (int element : difference.getElements()) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Is Set 1 a subset of Set 2? " << (set1.isSubset(set2) ? "Yes" : "No") << endl;

    return 0;
}
