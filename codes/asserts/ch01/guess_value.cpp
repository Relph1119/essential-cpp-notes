//
// Created by HRF on 2023/1/3.
// P7~P26 数字回答，显示某数列中的两个数字，然后要求用户回答下一个数字是什么。
//
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // 用户获得的评分
    double usr_score;

    // 显示下一组数列
    bool next_seq = true;
    // 用户猜过的总次数
    int num_tries = 0;
    // 用户答对的总次数
    int num_right = 0;

    const int seq_size = 18;
    int elem_seq[seq_size] = {
            1, 2, 3,   // Fibonacci
            3, 4, 7,   // Lucas
            2, 5, 12,  // Pell
            3, 6, 10,  // Triangular
            4, 9, 16,  // Square
            5, 12, 22, // Pentagonal
    };
    const int max_seq = 6;
    string seq_names[max_seq] = {
            "Fibonacci",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal"
    };
    int cur_tuple = 0;

    string usr_name;
    cout << "Please enter your first name: ";
    cin >> usr_name;

    cout << '\n'
         << "Hello, " << usr_name
         << ", Let's play the game!\n";

    fstream iofile("seq_data.txt", ios::in | ios::app);
    if (!iofile) {
        cerr << "Oops! Unable to save session data!\n";
    } else {
        iofile.seekp(0);
        string name;
        int nt;
        int nc;

        while (iofile >> name) {
            iofile >> nt >> nc;
            if (name == usr_name) {
                cout << "Welcome back, " << usr_name
                     << "\nYour current score is " << nc
                     << " out of " << nt << "\nGood Luck!\n";

                num_tries = nt;
                num_right = nc;
            }
        }
    }

    while (next_seq && cur_tuple < seq_size) {
        // 为用户显示数列
        cout << "The first two elements of the sequence are: "
             << elem_seq[cur_tuple] << ", "
             << elem_seq[cur_tuple + 1]
             << "\nWhat is the next element?";
        int next_elem = elem_seq[cur_tuple + 2];

        // 用户想再猜一次
        bool go_for_it = true;
        // 用户是否猜对
        bool got_it = false;

        while (!got_it && go_for_it) {
            // 用户回答的数值
            int usr_guess;
            // 读取用户所猜的答案
            cin >> usr_guess;
            num_tries++;
            if (usr_guess == next_elem) {
                got_it = true;
                num_right++;
                cout << "Very good. Yes, "
                     << next_elem
                     << " is the next element in the "
                     << seq_names[cur_tuple / 3] << " sequences.\n";
            } else {
                // 用户猜错了
                // 告诉用户答案是错的
                switch (num_tries) {
                    case 1:
                        cout << "Oops! Nice guess but not quite it.\n";
                        break;
                    case 2:
                        cout << "Hmm. Sorry. Wrong a second time.\n";
                        break;
                    case 3:
                        cout << "Ah, this is harder than it looks, isn't it?\n";
                        break;
                    default:
                        cout << "It must be getting pretty frustrating by now!\n";
                        break;
                }
                // 询问用户是否愿意再试一次
                cout << "Want to try again? (Y/N)";
                char usr_rsp;
                cin >> usr_rsp;
                if (usr_rsp == 'N' || usr_rsp == 'n')
                    go_for_it = false;
            }
        }
        cout << "Want to try another sequence? (Y/N)";
        char try_again;
        cin >> try_again;

        if (try_again == 'N' || try_again == 'n')
            next_seq = false;
        else
            cur_tuple += 3;
    }

    usr_score = (double) num_right / num_tries;

    cout << "Your score for this session is "
         << usr_score << " Bye!\n";

    iofile << usr_name << ' '
           << num_tries << ' '
           << num_right << endl;
    iofile.close();
    return 0;
}
