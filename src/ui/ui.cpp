#include "ui.hpp"

namespace UI {
    Window::Window(ImGuiIO &io) : io(io) {
        io = ImGui::GetIO();
        show_demo_window = false;
        show_another_window = false;
        clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
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
        ImGui::Begin(window_title, (bool*)true, (ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar));
        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Text("This is some useful text.");
            ImGui::Checkbox("Demo Window", &show_demo_window);
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
            ImGui::ColorEdit3("clear color", (float*)&clear_color);

            if (ImGui::Button("Button"))
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();
        }

        if (show_another_window) {
            ImGui::SetNextWindowPos(ImVec2((float)(window_width * 0.25),0));
            ImGui::SetNextWindowSize(ImVec2((float)(window_width * 0.75), (float)window_height));
            ImGui::Begin("Another Window", &show_another_window, (ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar));
            {
                ImGui::Text("Hello from another window!");
                if (ImGui::Button("Close Me"))
                    show_another_window = false;
            } ImGui::End();
        }
        ImGui::Render();
    }

    void Window::SetOwnStyle(ImGuiStyle &mStyle) {
        mStyle.WindowMinSize        = ImVec2( 160, 20 );
        mStyle.FramePadding         = ImVec2( 4, 2 );
        mStyle.ItemSpacing          = ImVec2( 6, 2 );
        mStyle.ItemInnerSpacing     = ImVec2( 6, 4 );
        mStyle.Alpha                = 0.95f;
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

    ImVec4 Window::get_clear_color() {
        return clear_color;
    }
}

