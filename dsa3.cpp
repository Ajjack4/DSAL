#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subsection {
private:
    string name;
public:
    Subsection(const string& name) : name(name) {}

    void print(int depth = 0) const {
        cout << string(depth * 4, ' ') << "- " << name << endl;
    }
};

class Section {
private:
    string name;
    vector<Subsection> subsections;
public:
    Section(const string& name) : name(name) {}

    void addSubsection(const Subsection& subsection) {
        subsections.push_back(subsection);
    }

    void print(int depth = 0) const {
        cout << string(depth * 4, ' ') << "+ " << name << endl;
        for (const auto& subsection : subsections) {
            subsection.print(depth + 1);
        }
    }
};

class Chapter {
private:
    string name;
    vector<Section> sections;
public:
    Chapter(const string& name) : name(name) {}

    void addSection(const Section& section) {
        sections.push_back(section);
    }

    void print(int depth = 0) const {
        cout << string(depth * 4, ' ') << "* " << name << endl;
        for (const auto& section : sections) {
            section.print(depth + 1);
        }
    }
};

int main() {
    Chapter chapter1("Chapter 1");
    Section section1_1("Section 1.1");
    section1_1.addSubsection(Subsection("Subsection 1.1.1"));
    section1_1.addSubsection(Subsection("Subsection 1.1.2"));
    Section section1_2("Section 1.2");
    section1_2.addSubsection(Subsection("Subsection 1.2.1"));
    chapter1.addSection(section1_1);
    chapter1.addSection(section1_2);

    Chapter chapter2("Chapter 2");
    Section section2_1("Section 2.1");
    section2_1.addSubsection(Subsection("Subsection 2.1.1"));
    section2_1.addSubsection(Subsection("Subsection 2.1.2"));
    chapter2.addSection(section2_1);

    cout << "Book Structure:" << endl;
    chapter1.print();
    chapter2.print();

    return 0;
}
