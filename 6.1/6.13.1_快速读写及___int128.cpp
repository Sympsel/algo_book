#include <iostream>
using namespace std;


inline int _read() {
    int ret{}, flag{1};
    char ch{_getchar_nolock()};
    while (ch < '0' || ch > '9') {
        if (ch == '-') flag = -1;
        // ch = getchar_unlocked();
        ch = _getchar_nolock();
    }

    while (ch >= '0' && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = _getchar_nolock();
    }
    return ret * flag;
}

inline void _print(long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }

    if (x > 9) _print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int n{_read()};
    int ret{};
    while (n--) {
        ret += _read();
    }
    _print(ret);
    putchar('\n');
    return 0;
}