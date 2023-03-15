#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <vector>

#include "ascii/ascii.h"

void example1();
void example2();
void example3();
void example4();
void example_legend();
void example_legend2();
void animation();

int main() {
  setlocale(LC_ALL, "");
  
  std::cout << "Example #1:" << std::endl;
  example1();
  std::cout << std::endl;;

  std::cout <<"Example #2:" << std::endl;
  example2();
  std::cout << std::endl;;

  std::cout << "Example #3:" << std::endl;
  example3();
  std::cout << std::endl;;

  std::cout << "Example #4:" << std::endl;
  example4();
  std::cout << std::endl;;

  std::cout << "Example Legend #1:" << std::endl;
  example_legend();
  std::cout << std::endl;;

  std::cout << "Example Legend #2:" << std::endl;
  example_legend2();
  std::cout << std::endl;;

// animation();
  return 0;
}

void example1() {
  using namespace ascii;
  std::vector<double> series;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(15 * std::cos(i * (kPI * 8) / 120));
  }

  Asciichart asciichart(std::vector<std::vector<double>>{series});
  std::cout << asciichart.height(6).Plot();
}

void example2() {
  using namespace ascii;
  std::vector<double> series;
  std::vector<double> series2;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(15 * std::cos(i * (kPI * 8) / 120));
    series2.push_back(15 * std::sin(i * ((kPI * 4) / 100)));
  }
  Asciichart asciichart(std::vector<std::vector<double>>{series, series2});
  std::cout << asciichart.height(6).Plot();
}

void example3() {
  using namespace ascii;
  std::vector<double> series;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(3400 * std::cos(i * (kPI * 8) / 120));
  }

  Asciichart asciichart(std::vector<std::vector<double>>{series});
  std::cout << asciichart.height(6).Plot();
}

void example4() {
  using namespace ascii;
  std::vector<double> series;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(std::cos(i * (kPI * 8) / 120));
  }

  Asciichart asciichart(std::vector<std::vector<double>>{series});
  std::cout << asciichart.height(6).min(-1).max(1).label_precision(5).fixed_label_precision(true).Plot();
}

void animation() {
  using namespace ascii;
  std::vector<double> series;
  std::vector<double> series2;
  int height = 6;
  for (int i = 0; i < 6; i += 2) {
    series.push_back(15 * std::cos(i * (kPI * 8) / 120));
    series2.push_back(15 * std::sin(i * ((kPI * 4) / 100)));
    Asciichart asciichart(std::vector<std::vector<double>>{series, series2});
    if (i != 0) {
      for (int j = 0; j <= height; j++) {
        std::cout << "\033[A\033[2K";
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << asciichart.height(height).Plot();
  }
}

void example_legend() {
  using namespace ascii;
  std::vector<double> series;
  std::vector<double> series2;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(15 * std::cos(i * (kPI * 8) / 120));
    series2.push_back(15 * std::sin(i * ((kPI * 4) / 100)));
  }
  Asciichart asciichart(std::vector<std::vector<double>>{series, series2});
  std::cout << asciichart.show_legend(true).height(6).Plot();
}

void example_legend2() {
  using namespace ascii;
  std::vector<double> series;
  std::vector<double> series2;
  for (int i = 0; i < 100; i += 2) {
    series.push_back(15 * std::cos(i * (kPI * 8) / 120));
    series2.push_back(15 * std::sin(i * ((kPI * 4) / 100)));
  }
  Asciichart asciichart({{"A", series}, {"B", series2}});
  std::cout << asciichart.show_legend(true).height(6).Plot();
}


