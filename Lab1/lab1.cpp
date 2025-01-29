// #include <iostream>
// #include <string>
// #include <vector>
// #include <iomanip>
// #include <sstream>
// using namespace std;
//
// vector<string> split_lines;
// int i = 0;
//
// void prompt() {
//     string data_point;
//     cout << "Enter a data point (-1 to stop input):" << endl;
//     getline(cin, data_point);
//
//     if (data_point == "-1") {
//         return;
//     }
//
//     if (data_point.find(',') == string::npos) {
//         cout << "Error: No comma in string." << endl;
//         prompt();
//         return;
//     }
//
//     istringstream ss(data_point);
//     string split_line;
//     int comma_count = 0;
//
//     while (getline(ss, split_line, ',')) {
//         comma_count++;
//         split_lines.push_back(split_line);
//     }
//
//     if (comma_count != 2) {
//         cout << "Error: Too many commas in input." << endl;
//         for (int j = 0; j < comma_count; j++) {
//             split_lines.pop_back();
//         }
//         prompt();
//         return;
//     }
//
//     try {
//         stoi(split_lines[i + 1]);
//     } catch (...) {
//         cout << "Error: Comma not followed by an integer." << endl;
//
//         // at the while, allocate two values first, so second value allocated as string not int.
//         split_lines.pop_back();
//         split_lines.pop_back();
//         prompt();
//         return;
//     }
//
//     cout << "Data string: " << split_lines[i] << endl;
//     cout << "Data integer: " << stoi(split_lines[i + 1]) << endl;
//
//     i += 2;
//     prompt();
// }
//
// int main() {
//     string title, header1, header2;
//
//     // title section
//     cout << "Enter a title for the data:" << endl;
//     getline(cin, title);
//     cout << "You entered: " << title << endl;
//
//     // header1 section
//     cout << "Enter the column 1 header:" << endl;
//     getline(cin, header1);
//     cout << "You entered: " << header1 << endl;
//     // header2 section
//     cout << "Enter the column 2 header:" << endl;
//     getline(cin, header2);
//     cout << "You entered: " << header2 << endl;
//
//     // prompt section
//     prompt();
//
//     // output1
//     cout << endl;
//     cout << setw(33) << right << title << endl;
//     cout << setw(20) << left << header1 << "|" << setw(23) << right << header2 << endl;
//     cout << string(44, '-') << endl;
//
//     bool split_check = true;
//     for (const string& s : split_lines) {
//         if (split_check) {
//             cout << setw(20) << left << s;
//             split_check = false;
//         }else {
//             cout << "|" << setw(23) << right << s << endl;
//             split_check = true;
//         }
//     }
//
//     // output2
//     cout << endl;
//     for (const string& s : split_lines) {
//         if (split_check) {
//             cout << setw(20) << right << s;
//             split_check = false;
//         } else {
//             try {
//                 int num = stoi(s);
//                 cout << " " << string(stoi(s), '*') << endl;
//             } catch (...) {
//                 cout << "Error: Comma not followed by an integer." << endl;
//             }
//             split_check = true;
//         }
//     }
//     return 0;
// }