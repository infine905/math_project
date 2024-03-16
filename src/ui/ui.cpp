#include "ui.hpp"

namespace UI {
    Window::Window(ImGuiIO &io) : io(io) {
        io = ImGui::GetIO();
        show_demo_window = false;
        //task_selected = 1;
    }

    void Window::Render(GLFWwindow* window) {

        SetOwnStyle(ImGui::GetStyle());
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        glfwGetWindowSize(window, &window_width, &window_height);

        if(show_demo_window)
            ImGui::ShowDemoWindow();

        ImGui::SetNextWindowPos(ImVec2(0,0));
        ImGui::SetNextWindowSize(ImVec2((float)(window_width * 0.25), (float)window_height));
        if (ImGui::Begin(window_title, (bool*)true, (ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar)))
        {
            ImGui::Checkbox("Demo Window", &show_demo_window);
            ImGui::Combo("Задача", &task_selected, tasks, 2);
            if (task_selected == 0) {
                ImGui::InputDouble("x0", &task2.x0, 0.1, 0.0, "%.1f");
                ImGui::InputDouble("y0", &task2.y0, 0.1, 0.0, "%.1f");
                ImGui::InputDouble("h", &task2.h, 0.01, 0.0, "%.3f");
                ImGui::InputInt("n", &task2.n, 100);
            } else if (task_selected == 1) {
                ImGui::InputDouble("x0", &task5.x0, 0.0, 0.0, "%.1f");
                ImGui::InputDouble("y0", &task5.y0, 0.0, 0.0, "%.1f");
                ImGui::InputDouble("C", &task5.C, 0.0, 0.0, "%.1f");
                ImGui::InputDouble("C1", &task5.C1, 0.0, 0.0, "%.1f");
                ImGui::InputDouble("C2", &task5.C2, 0.0, 0.0, "%.1f");
                ImGui::InputDouble("h", &task5.h, 0.0, 0.0, "%.3f");
                ImGui::InputInt("n", &task5.n, 100);
            } else { }
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        ImGui::SetNextWindowPos(ImVec2((float)(window_width * 0.25),0));
        ImGui::SetNextWindowSize(ImVec2((float)(window_width * 0.75), (float)(window_height*1)));
        ImGui::Begin("Another Window", (bool*)true, (ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar));
        {
            if (task_selected == 0) {
                points = task2_graph(task2.x0, task2.y0, task2.h, task2.n);
                if (ImPlot::BeginPlot("Решение Дифференциального Уравнения", ImVec2(ImGui::GetWindowWidth(), ImGui::GetWindowHeight()))) {
                    std::vector<float> x_values, y_values;
                    for (const auto &p: points) {
                        x_values.push_back(p.first);
                        y_values.push_back(p.second);
                    }
                    ImPlot::PlotLine("y(x)", x_values.data(), y_values.data(), points.size());
                    ImPlot::EndPlot();
                }
            } else if (task_selected == 1) {
                if (ImPlot::BeginPlot("Решение Дифференциального Уравнения", ImVec2(ImGui::GetWindowWidth(), ImGui::GetWindowHeight())))
                {
                    points = task5_graph(task5.x0, task5.y0, task5.C, task5.C1, task5.C2, task5.h, task5.n);
                    std::vector<float> x_values, y_values;
                    for (const auto &p: points) {
                        x_values.push_back(p.first);
                        y_values.push_back(p.second);
                    }
                    ImPlot::SetupAxisScale(ImAxis_X1, ImPlotScale_Linear);
                    ImPlot::PlotLine("y(x)", x_values.data(), y_values.data(), points.size());
                    ImPlot::EndPlot();
                }
            } else {}
        } ImGui::End();
        ImGui::Render();
    }

    void Window::SetOwnStyle(ImGuiStyle &mStyle) {
        mStyle.WindowMinSize        = ImVec2( 160, 20 );
        mStyle.FramePadding         = ImVec2( 4, 2 );
        mStyle.ItemSpacing          = ImVec2( 6, 2 );
        mStyle.ItemInnerSpacing     = ImVec2( 6, 4 );
        mStyle.Alpha                = 1.f;
        mStyle.WindowRounding       = 0.0f;
        mStyle.FrameRounding        = 2.0f;
        mStyle.IndentSpacing        = 6.0f;
        mStyle.ItemInnerSpacing     = ImVec2( 2, 4 );
        mStyle.ColumnsMinSpacing    = 50.0f;
        mStyle.GrabMinSize          = 14.0f;
        mStyle.GrabRounding         = 16.0f;
        mStyle.ScrollbarSize        = 12.0f;
        mStyle.ScrollbarRounding    = 16.0f;

        ImGuiStyle& style = mStyle;
        style.Colors[ImGuiCol_Text]                  = ImVec4(0.86f, 0.93f, 0.89f, 0.78f);
        style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.86f, 0.93f, 0.89f, 0.28f);
        style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
        style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 1.00f, 1.00f);
        style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
        style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
        style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.20f, 0.22f, 0.27f, 0.75f);
        style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.20f, 0.22f, 0.27f, 0.47f);
        style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.09f, 0.15f, 0.16f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
        style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.71f, 0.22f, 0.27f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
        style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_Button]                = ImVec4(0.47f, 0.77f, 0.83f, 0.14f);
        style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
        style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_Header]                = ImVec4(0.92f, 0.18f, 0.29f, 0.76f);
        style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.92f, 0.18f, 0.29f, 0.86f);
        style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_Separator]             = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
        style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
        style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.47f, 0.77f, 0.83f, 0.04f);
        style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.92f, 0.18f, 0.29f, 0.78f);
        style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
        style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.86f, 0.93f, 0.89f, 0.63f);
        style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.92f, 0.18f, 0.29f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.92f, 0.18f, 0.29f, 0.43f);
        style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.20f, 0.22f, 0.27f, 0.9f);
    }
}