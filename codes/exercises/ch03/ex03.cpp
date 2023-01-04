//
// Created by HRF on 2023/1/4.
//
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector<string> vstring;


void populate_map(ifstream &name_file, map<string, vstring> &families) {
    string textline;
    while (getline(name_file, textline)) {
        string fam_name;
        vector<string> child;
        string::size_type pos = 0, prev_pos = 0, text_size = textline.size();

        // 找出以空格分隔的所有单字
        while ((pos = textline.find_first_of(' ', pos)) != string::npos) {
            // 计算子字符串的终点
            string::size_type end_pos = pos - prev_pos;

            // 如果prev_pos并未设置，那么读到的单字就是家庭姓氏，否则就读取孩子们的名字
            if (!prev_pos)
                fam_name = textline.substr(prev_pos, end_pos);
            else
                child.push_back(textline.substr(prev_pos, end_pos));
            prev_pos = ++pos;
        }

        // 处理最后一个孩子的名字
        if (prev_pos < text_size) {
            child.push_back(textline.substr(prev_pos, pos - prev_pos));
        }

        if (!families.count(fam_name))
            families[fam_name] = child;
        else
            cerr << "Oops! We already have a " << fam_name << " family in our map!\n";
    }
}

void display_map(const map<string, vstring> &families, ostream &os) {
    auto it = families.begin(), end_it = families.end();

    while (it != end_it) {
        os << "The " << it->first << " family ";
        if (it->second.empty()) {
            os << "has no children\n";
        } else {
            os << "has " << it->second.size() << " children: ";
            auto iter = it->second.begin(), end_iter = it->second.end();
            while(iter != end_iter) {
                os << *iter << " ";
                ++iter;
            }
            os << endl;
        }
        ++it;
    }
}

void query_map(const string &family, const map<string, vstring> &families) {
    auto it = families.find(family);

    if (it == families.end()) {
        cout << "Sorry. The " << family << " is not currently entered.\n";
        return;
    }

    cout << "The " << family;
    if (it->second.empty()) {
        cout << " has no children\n";
    } else {
        cout << " has " << it->second.size() << " children: ";
        auto iter = it->second.begin(), end_iter = it->second.end();
        while(iter != end_iter) {
            cout << *iter << " ";
            ++iter;
        }
        cout << endl;
    }
}

int main() {
    map<string, vstring> families;
    ifstream name_file("files/families.txt");

    if (!name_file.is_open()) {
        cerr << "Unable to find families.txt file. Bailing Out!\n";
        return -1;
    }

    populate_map(name_file, families);

    string family_name;
    while(true) {
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;

        if (family_name == "q")
            break;
        query_map(family_name, families);
    }
    display_map(families, cout);

    return 0;
}