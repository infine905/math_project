#ifndef UI_HPP
#define UI_HPP
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
//#include <imgui_custom.hpp>


namespace UI {
    const char window_title[] = "Window";
    class Window{
        public:
            explicit Window(ImGuiIO &io);
            void Render(GLFWwindow* window);
            ImVec4 get_clear_color();
        private:
            ImGuiIO& io;
            int window_width{};
            int window_height{};
            bool show_demo_window;
            bool show_another_window;
            ImVec4 clear_color;

            static void SetOwnStyle(ImGuiStyle &mStyle);
    };
}
#endif // UI_HPP
