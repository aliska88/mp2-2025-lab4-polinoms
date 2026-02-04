#include <iostream>
#include "polynomial.h"

int main() {
  setlocale(LC_ALL, "Russian");

  Polynomial p1, p2;

  std::cout << "=== Ввод первого полинома ===\n";
  p1.input();
  std::cout << "P1 = " << p1 << "\n\n";

  std::cout << "=== Ввод второго полинома ===\n";
  p2.input();
  std::cout << "P2 = " << p2 << "\n\n";

  std::cout << "=== Результаты операций ===\n";
  Polynomial sum = p1 + p2;
  std::cout << "Сумма: " << sum << "\n";

  Polynomial diff = p1 - p2;
  std::cout << "Разность: " << diff << "\n";

  try {
    Polynomial mult = p1 * p2;
    std::cout << "Произведение: " << mult << "\n";
  } catch (const std::overflow_error& e) {
    std::cout << "Ошибка умножения: " << e.what() << "\n";
  }

  return 0;
}