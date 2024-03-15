#ifndef UI_HPP
#define UI_HPP
#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

//#include <imgui_custom.hpp>


namespace UI {
    const char window_title[] = "Window";

    class Window{
        public:
            explicit Window(ImGuiIO &io);
            void Render();
            ImVec4 get_clear_color();
        private:
            static void SetOwnStyle(ImGuiStyle &mStyle);
            ImGuiIO& io;
            bool show_demo_window;
            bool show_another_window;
            ImVec4 clear_color;
    };
}
#endif // UI_HPP
