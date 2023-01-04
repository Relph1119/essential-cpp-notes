//
// Created by HRF on 2023/1/4.
//
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void initialize_exclusion_set(set<string> &exs);

void pricess_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile);

void user_query(const map<string, int> &word_map);

void display_word_count(const map<string, int> &word_map, ofstream &os);


int main() {
    ifstream ifile("files/column.txt");
    ofstream ofile("files/column.map");

    if (!ifile || !ofile) {
        cerr << "Unable to open file -- bailing out!\n";
        return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set(exclude_set);

    map<string, int> word_count;
    pricess_file(word_count, exclude_set, ifile);
    user_query(word_count);
    display_word_count(word_count, ofile);

    return 0;
}

void initialize_exclusion_set(set<string> &exs) {
    static string excluded_word[25] = {
            "the", "and", "but", "that", "then", "are", "been",
            "can", "a", "cloud", "did", "for", "of",
            "had", "have", "him", "his", "her", "its", "is",
            "were", "which", "when", "with", "would"
    };
    exs.insert(excluded_word, excluded_word + 25);
}

void pricess_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile) {
    string word;
    while (ifile >> word) {
        if (exclude_set.count(word))
            continue;
        word_count[word]++;
    }
}

void user_query(const map<string, int> &word_map) {
    string search_word;
    cout << "Please enter a word to search: q to quit";
    cin >> search_word;
    while (!search_word.empty() && search_word != "q") {
        map<string, int>::const_iterator it;
        if ((it = word_map.find(search_word)) != word_map.end()) {
            cout << "Found! " << it->first
                 << " occurs " << it->second
                 << " times.\n";
        } else {
            cout << search_word << " was not found in text.\n";
        }
        cout << "\nAnother search? (q to quit) ";
        cin >> search_word;
    }
}

void display_word_count(const map<string, int> &word_map, ofstream &os) {
    auto iter = word_map.begin(), end_it = word_map.end();
    while (iter != end_it) {
        os << iter->first << " ( "
           << iter->second << " )" << endl;
        ++iter;
    }
    os << endl;
}