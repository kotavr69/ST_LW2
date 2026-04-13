#include <iostream>
#include <string>
#include <cmath>
#define _USE_MATH_DEFINES
#include <gtest/gtest.h>

using namespace std;

class GeometryCalculator {
public:
    const double M_PI = 3.14159265358979323846;
    // Периметр квадрата
    double square_perimeter(double side) {
        if (side <= 0) {
            throw invalid_argument("Сторона не может быть <= 0");
        }
        return 4 * side;
    }

    // Площадь квадрата
    double square_area(double side) {
        if (side <= 0) {
            throw invalid_argument("Сторона не может быть <= 0");
        }
        return side * side;
    }

    // Периметр прямоугольника
    double rectangle_perimeter(double length, double width) {
        if (length <= 0 || width <= 0) {
            throw invalid_argument("Стороны не могут быть <= 0");
        }
        return 2 * (length + width);
    }

    // Площадь прямоугольника
    double rectangle_area(double length, double width) {
        if (length <= 0 || width <= 0) {
            throw invalid_argument("Стороны не могут быть <= 0");
        }
        return length * width;
    }

    // Длина окружности
    double circle_circumference(double radius) {
        if (radius <= 0) {
            throw invalid_argument("Радиус не может быть <= 0");
        }
        return 2 * M_PI * radius;
    }

    // Площадь круга
    double circle_area(double radius) {
        if (radius <= 0) {
            throw invalid_argument("Радиус не может быть <= 0");
        }
        return M_PI * radius * radius;
    }

    // Периметр треугольника
    double triangle_perimeter(double a, double b, double c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw invalid_argument("Стороны не могут быть <= 0");
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw invalid_argument("Неравенство треугольника нарушено");
        }
        return a + b + c;
    }

    // Площадь треугольника по формуле Герона
    double triangle_area_heron(double a, double b, double c) {
        double p = triangle_perimeter(a, b, c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Объём куба
    double cube_volume(double side) {
        if (side <= 0) {
            throw invalid_argument("Ребро не может быть <= 0");
        }
        return side * side * side;
    }

    // Объём сферы
    double sphere_volume(double radius) {
        if (radius <= 0) {
            throw invalid_argument("Радиус не может быть <= 0");
        }
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }

    // Меню выбора
    void menu() {
        int choice;
        cout << "=== ГЕОМЕТРИЧЕСКИЙ КАЛЬКУЛЯТОР ===" << endl;
        cout << "1 - Периметр квадрата" << endl;
        cout << "2 - Площадь квадрата" << endl;
        cout << "3 - Периметр прямоугольника" << endl;
        cout << "4 - Площадь прямоугольника" << endl;
        cout << "5 - Длина окружности" << endl;
        cout << "6 - Площадь круга" << endl;
        cout << "7 - Периметр треугольника" << endl;
        cout << "8 - Площадь треугольника (Герон)" << endl;
        cout << "9 - Объём куба" << endl;
        cout << "10 - Объём сферы" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                double s; cout << "Сторона: "; cin >> s;
                cout << "Периметр = " << square_perimeter(s) << endl;
                break;
            }
            case 2: {
                double s; cout << "Сторона: "; cin >> s;
                cout << "Площадь = " << square_area(s) << endl;
                break;
            }
            case 3: {
                double l, w; cout << "Длина и ширина: "; cin >> l >> w;
                cout << "Периметр = " << rectangle_perimeter(l, w) << endl;
                break;
            }
            case 4: {
                double l, w; cout << "Длина и ширина: "; cin >> l >> w;
                cout << "Площадь = " << rectangle_area(l, w) << endl;
                break;
            }
            case 5: {
                double r; cout << "Радиус: "; cin >> r;
                cout << "Длина окружности = " << circle_circumference(r) << endl;
                break;
            }
            case 6: {
                double r; cout << "Радиус: "; cin >> r;
                cout << "Площадь круга = " << circle_area(r) << endl;
                break;
            }
            case 7: {
                double a, b, c; cout << "Три стороны: "; cin >> a >> b >> c;
                cout << "Периметр = " << triangle_perimeter(a, b, c) << endl;
                break;
            }
            case 8: {
                double a, b, c; cout << "Три стороны: "; cin >> a >> b >> c;
                cout << "Площадь = " << triangle_area_heron(a, b, c) << endl;
                break;
            }
            case 9: {
                double s; cout << "Ребро куба: "; cin >> s;
                cout << "Объём = " << cube_volume(s) << endl;
                break;
            }
            case 10: {
                double r; cout << "Радиус: "; cin >> r;
                cout << "Объём = " << sphere_volume(r) << endl;
                break;
            }
            default:
                cout << "Неверный номер!" << endl;
            }
        }
        catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
};

class GeometryTest : public ::testing::Test {
protected:
    GeometryCalculator calc;
};

// Тест 1: Периметр квадрата
TEST_F(GeometryTest, SquarePerimeter) {
    EXPECT_DOUBLE_EQ(calc.square_perimeter(5.0), 20.0);
    EXPECT_DOUBLE_EQ(calc.square_perimeter(2.5), 10.0);
    EXPECT_DOUBLE_EQ(calc.square_perimeter(10.0), 40.0);
}

// Тест 2: Площадь квадрата
TEST_F(GeometryTest, SquareArea) {
    EXPECT_DOUBLE_EQ(calc.square_area(5.0), 25.0);
    EXPECT_DOUBLE_EQ(calc.square_area(2.5), 6.25);
    EXPECT_DOUBLE_EQ(calc.square_area(10.0), 100.0);
}

// Тест 3: Периметр прямоугольника
TEST_F(GeometryTest, RectanglePerimeter) {
    EXPECT_DOUBLE_EQ(calc.rectangle_perimeter(5.0, 3.0), 16.0);
    EXPECT_DOUBLE_EQ(calc.rectangle_perimeter(2.5, 4.0), 13.0);
    EXPECT_DOUBLE_EQ(calc.rectangle_perimeter(10.0, 10.0), 40.0);
}

// Тест 4: Площадь прямоугольника
TEST_F(GeometryTest, RectangleArea) {
    EXPECT_DOUBLE_EQ(calc.rectangle_area(5.0, 3.0), 15.0);
    EXPECT_DOUBLE_EQ(calc.rectangle_area(2.5, 4.0), 10.0);
    EXPECT_DOUBLE_EQ(calc.rectangle_area(10.0, 10.0), 100.0);
}

// Тест 5: Длина окружности
TEST_F(GeometryTest, CircleCircumference) {
    EXPECT_NEAR(calc.circle_circumference(1.0), 6.28318, 0.0001);
    EXPECT_NEAR(calc.circle_circumference(2.0), 12.56637, 0.0001);
    EXPECT_NEAR(calc.circle_circumference(0.5), 3.14159, 0.0001);
}

// Тест 6: Площадь круга
TEST_F(GeometryTest, CircleArea) {
    EXPECT_NEAR(calc.circle_area(1.0), 3.14159, 0.0001);
    EXPECT_NEAR(calc.circle_area(2.0), 12.56637, 0.0001);
    EXPECT_NEAR(calc.circle_area(3.0), 28.27433, 0.0001);
}

// Тест 7: Периметр треугольника
TEST_F(GeometryTest, TrianglePerimeter) {
    EXPECT_DOUBLE_EQ(calc.triangle_perimeter(3.0, 4.0, 5.0), 12.0);
    EXPECT_DOUBLE_EQ(calc.triangle_perimeter(5.0, 5.0, 5.0), 15.0);
    EXPECT_DOUBLE_EQ(calc.triangle_perimeter(6.0, 8.0, 10.0), 24.0);
}

// Тест 8: Площадь треугольника (Герон)
TEST_F(GeometryTest, TriangleAreaHeron) {
    EXPECT_NEAR(calc.triangle_area_heron(3.0, 4.0, 5.0), 6.0, 0.0001);
    EXPECT_NEAR(calc.triangle_area_heron(5.0, 5.0, 5.0), 10.8253, 0.0001);
    EXPECT_NEAR(calc.triangle_area_heron(6.0, 8.0, 10.0), 24.0, 0.0001);
}

// Тест 9: Объём куба
TEST_F(GeometryTest, CubeVolume) {
    EXPECT_DOUBLE_EQ(calc.cube_volume(1.0), 1.0);
    EXPECT_DOUBLE_EQ(calc.cube_volume(2.0), 8.0);
    EXPECT_DOUBLE_EQ(calc.cube_volume(3.0), 27.0);
    EXPECT_DOUBLE_EQ(calc.cube_volume(0.5), 0.125);
}

// Тест 10: Объём сферы
TEST_F(GeometryTest, SphereVolume) {
    EXPECT_NEAR(calc.sphere_volume(1.0), 4.18879, 0.0001);
    EXPECT_NEAR(calc.sphere_volume(2.0), 33.51032, 0.0001);
    EXPECT_NEAR(calc.sphere_volume(3.0), 113.09733, 0.0001);
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru");

    cout << "========================================" << endl;
    cout << "         ВЫБОР РЕЖИМА РАБОТЫ           " << endl;
    cout << "========================================" << endl;
    cout << "1 - Запустить геометрический калькулятор" << endl;
    cout << "2 - Запустить unit-тесты" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Ваш выбор: ";

    string choice;
    getline(cin, choice);

    if (choice == "2") {
        cout << endl << "Запуск unit-тестов..." << endl << endl;
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    else {
        GeometryCalculator calc;
        calc.menu();
    }

    return 0;
}