#ifndef UI_HPP
#define UI_HPP
#include <vector>
#include <string>
#include <imgui.h>
#include <implot.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include "../core/task2.h"
#include "../core/task5.h"

namespace UI {
    const char window_title[] = "Window";
    class Window{
        public:
            explicit Window(ImGuiIO &io);
            void Render(GLFWwindow* window);
        private:
            ImGuiIO& io;
            int window_width{};
            int window_height{};
            bool show_demo_window;
            int task_selected;
            const char* tasks[2]{"Задача 2", "Задача 5"};

            struct {
                double x0 = -1.0;
                double y0 = 0.0;
                double h = 0.1;
                int n = 10;
            } task2;

            struct {
                double x0 = 0.0;
                double y0 = 0.0;
                double C = 1;
                double C1 = 1;
                double C2 = 1;
                double h = 0.01f;
                int n = 10000;
            } task5;
            std::vector<std::pair<double, double>> points;
            static void SetOwnStyle(ImGuiStyle &mStyle);
    };
}
#endif // UI_HPP
