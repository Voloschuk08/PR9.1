#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9.1/PR9.1.cpp"
#include "../PR9.1/var.cpp"
#include "../PR9.1/dod.cpp"
#include "../PR9.1/sum.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nsVar;
using namespace nsDod;
using namespace nsSum;

namespace UnitTest91 {
    TEST_CLASS(UnitTest91) {
public:
    TEST_METHOD(TestDod) {
        // Ініціалізація глобальних змінних
        x = 2.0; // Значення аргументу
        n = 1;
        a = 1.0 / x; // Перший член ряду

        // Обчислюємо наступний член ряду за допомогою функції dod()
        dod();

        // Очікуваний результат. Обчислюємо наступний член ряду аналітично.
        double expected_a = (1.0 / x) * ((2 * n - 1.0) / ((2 * n + 1) * x * x));

        // Перевірка на рівність з певною точністю (1e-5)
        Assert::AreEqual(expected_a, a, 1e-5, L"Incorrect term calculation");
    }

    // Тест перевіряє обчислення суми ряду до заданої точності
    TEST_METHOD(TestSum) {
        // Ініціалізація глобальних змінних
        x = 2.0;
        eps = 1e-5;
        sum(); // Обчислюємо суму ряду

        // Значення функції log((x + 1) / (x - 1)), яку перевіряємо
        double expected_value = log((x + 1) / (x - 1));
        Assert::AreEqual(expected_value, 2 * s, 1e-5, L"Incorrect series sum calculation");
    }
    };
}
