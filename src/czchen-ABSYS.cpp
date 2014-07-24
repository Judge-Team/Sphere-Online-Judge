#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const size_t LINE_LEN = 40;
const char LNK_BLOT[] = "machula";
const size_t LNK_BLOT_LEN = sizeof (LNK_BLOT) / sizeof (LNK_BLOT[0]) - 1;

void remove_ink_blot(const char * str)
{
    string line(str);

    // Parsing input.
    const size_t plus_pos = line.find_first_of('+');
    const size_t equal_pos = line.find_first_of('=');
    const size_t lnk_pos = line.find_first_of(LNK_BLOT, 0);

#ifdef CZCHEN_DEBUG
    cout << "Input string: " << line << endl << "Plus is in " << plus_pos << ", equal is in " << equal_pos << ", lnk blot is in "<< lnk_pos << "." << endl;
#endif

    // Change to standard format ?machula? = result.
    // case 1. lnk + y = z
    // case 2. x + lnk = z
    // case 3. x + y = lnk

    string result;
    string lnk;

    if (lnk_pos < plus_pos) { // case 1
        lnk = line.substr(0, plus_pos - 1);
        int y = strtol(line.substr(plus_pos + 1, (equal_pos - 1) - (plus_pos + 1)).c_str(), NULL, 10);
        int z = strtol(line.substr(equal_pos + 1, line.size() - (equal_pos + 1)).c_str(), NULL, 10);
        ostringstream tmp;
        tmp << z - y;
        result = tmp.str();
#ifdef CZCHEN_DEBUG
        cout << "y: " << y << ", z: " << z << endl;
#endif
    } else if (equal_pos < lnk_pos) { // case 3
        int x = strtol(line.substr(0, plus_pos - 1).c_str(), NULL, 10);
        int y = strtol(line.substr(plus_pos + 1, (equal_pos - 1) - (plus_pos + 1)).c_str(), NULL, 10);
        lnk = line.substr(equal_pos + 1, line.size() - (equal_pos + 1));
        ostringstream tmp;
        tmp << x + y;
        result = tmp.str();
#ifdef CZCHEN_DEBUG
        cout << "x: " << x << ", y: " << y << endl;
#endif
    } else { // case 2
        int x = strtol(line.substr(0, plus_pos - 1).c_str(), NULL, 10);
        lnk = line.substr(plus_pos + 1, (equal_pos - 1) - (plus_pos + 1));
        int z = strtol(line.substr(equal_pos + 1, line.size() - (equal_pos + 1)).c_str(), NULL, 10);
        ostringstream tmp;
        tmp << z - x;
        result = tmp.str();
#ifdef CZCHEN_DEBUG
        cout << "x: " << x << ", z: " << z << endl;
#endif
    }

#ifdef CZCHEN_DEBUG
    cout << "lnk: " << lnk << ", result: " << result << endl;
#endif

    size_t remove_head_from_result = lnk.find_first_of(LNK_BLOT[0]) - lnk.find_first_not_of(' ');
    size_t remove_tail_from_result = lnk.find_last_not_of(' ') - (lnk.find_first_of(LNK_BLOT[0]) + LNK_BLOT_LEN - 1);

#ifdef CZCHEN_DEBUG
    cout << "remove_head_from_result: " << remove_head_from_result << ", remove_tail_from_result: " << remove_tail_from_result << endl;
#endif

    result.erase(0, remove_head_from_result);
    result.erase(result.size() - remove_tail_from_result, remove_tail_from_result);

    line.replace(lnk_pos, LNK_BLOT_LEN, result);

    cout << line << endl;

#ifdef CZCHEN_DEBUG
    cout << endl;
#endif

    return;
}

int main()
{
    int num = 0;
    char str[LINE_LEN] = {0};

    cin >> num;

    for (int i = 0; i < num;) {
        cin.getline(str, sizeof(str));
        if (0 != str[0]) {
            remove_ink_blot(str);
            ++i;
        }
    }

    return 0;
}
