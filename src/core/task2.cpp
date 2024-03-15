#include "task2.h"

double dydx(double x, double y) {
    return (1.0 / (x + y));
}

std::vector<std::pair<double, double>> task2_graph(double x0, double y0, double h, int n) {
    std::vector<std::pair<double, double>> points;
    double x = x0;
    double y = y0;
    points.emplace_back(x, y);

    for (int i = 0; i < n; ++i) {
        y += h * dydx(x, y);
        x += h;
        points.emplace_back(x, y);
    }
    return points;
}
