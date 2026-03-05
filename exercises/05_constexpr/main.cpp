#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
   // 基础情况处理
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }

    // 使用迭代法，只记录前两项的值
    unsigned long long a{0};
    unsigned long long b{1};
    unsigned long long result{0};

    // 从第 2 项开始循环累加
    for (int j{2}; j <= i; ++j) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
