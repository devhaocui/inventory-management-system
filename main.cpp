#include "inventoryManagement.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**) {
  invManage inv;

  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const char* glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

  // Create window with graphics context
  GLFWwindow* window = glfwCreateWindow(800, 800, "Inventory Management System", nullptr, nullptr);
  if (window == nullptr)
    return 1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

  // Setup Dear ImGui style
  //ImGui::StyleColorsDark();
  ImGui::StyleColorsClassic();
  //ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);

  ImGui_ImplOpenGL3_Init(glsl_version);
    io.Fonts->AddFontFromFileTTF("../jetbrains.ttf", 20.0f);

    // Our state
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  bool starting_window = true;
  bool main_menu = false;
  bool add_item_menu = false;
  bool login_window = false;
  bool register_window = false;
  float duration {3.0f};
  float timer {0.0f};
  float wrong_password_text = false;

  //PERF: Inventory Management .CPP function calls
  std::vector<std::string> vec_data = inv.readDataIntoVector("user.csv");
    // Main loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (starting_window) 
    {
      ImGui::SetNextWindowSize(ImVec2(700,700), ImGuiCond_Once);
      ImGui::Begin("Starting Window");
      if (ImGui::Button("Login")) 
      {
        login_window = true;
        starting_window = false;
      }
      if (ImGui::Button("Register"))
      {
        register_window = true;
        starting_window = false;
      }
      ImGui::End();
    }

    if (login_window)
    {
      ImGui::SetNextWindowSize(ImVec2(700,700), ImGuiCond_Once);
      ImGui::Begin("Login Window");
      static char user_name[128];
      static char user_password[128];
      ImGui::Text("Time Elapsed: %i seconds", static_cast<int>(ImGui::GetTime()));
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter"))
      {
        if (inv.userValidate(user_name,user_password)) {
          main_menu = true;
          login_window = false;
        }
        else {
          wrong_password_text = true;
          timer = 0.0f;
        }
      }

      ImGui::SameLine();
      if (ImGui::Button("Back"))
      {
        login_window = false;
        starting_window = true;
      }
      if (wrong_password_text) {
        ImGui::SameLine();
        ImGui::Text("Wrong username/password!");
        timer += ImGui::GetIO().DeltaTime;
        if (timer >= duration)
          wrong_password_text = false;
      }
      ImGui::End();
    }

    if (register_window)
    {
      ImGui::SetNextWindowSize(ImVec2(700,700), ImGuiCond_Once);
      ImGui::Begin("Register Menu");
      char user_name[128];
      char user_password[128];
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter"))
      {
        //TODO: check if username exists in the file
        //TODO: if not then store username and hashed password into file
      }

      if (ImGui::Button("Back"))
      {
        register_window = false;
        starting_window = true;

      }
      ImGui::End();
      
    }

    if (main_menu)
    {
      ImGui::SetNextWindowSize(ImVec2(700,700), ImGuiCond_Once);
      ImGui::Begin("Main Menu", &main_menu);
      if (ImGui::Button("Add An Item")) 
      {
        add_item_menu = true;
        main_menu = false;
      }
      ImGui::End();
    }

    if (add_item_menu)
    {
      ImGui::SetNextWindowSize(ImVec2(700,700), ImGuiCond_Once);
      ImGui::Begin("Add Item Menu", &add_item_menu);
      char item_name[128];
      char item_category[128];
      char item_quantity[128];
      ImGui::Text("Add Item Menu");
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      ImGui::InputText("Item Category", item_category, IM_ARRAYSIZE(item_category));
      ImGui::InputText("Item Quantity", item_quantity, IM_ARRAYSIZE(item_quantity));
      if (ImGui::Button("Back")) {
        main_menu = true;
        add_item_menu = false;
      }
      ImGui::End();
    }


      // Rendering 
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
