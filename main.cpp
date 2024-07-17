#include "inventoryManagement.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <string>

static void glfw_error_callback(int error, const char* description) {
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char**) {

  // NOTE: INVENTORY MANAGEMENT SETUP
  invManage inv;
  //inv.populate_stock(); // do not run this function if an item.csv file already exists!
  std::vector<std::string> item_csv = inv.readDataIntoVector("item.csv");

  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const static char* glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac

  // Create window with graphics context
  GLFWwindow* window = glfwCreateWindow(700, 700, "Inventory Management System", nullptr, nullptr);
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
  //static const float TEXT_BASE_SIZE {20.0f};
  const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();



    // Our state
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  bool starting_window = true;
  bool main_menu = false;
  bool add_item_menu = false;
  bool login_window = false;
  bool register_window = false;
  bool delete_item_menu = false;
  bool withdraw_item_menu = false;
  float duration {0.5f};
  float display_text_timer {0.0f};
  float display_text_bool = false;
  bool display_all_menu = false;
  bool display_category_menu = false;
  bool display_search_menu = false;

  ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
  ImVec2 window_size = ImVec2(700, 700);
  ImVec2 window_position = ImVec2(0, 0);

    // Main loop
  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (starting_window) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Starting Window", NULL, window_flags);
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

    // NOTE: LOGIN WINDOW
    if (login_window) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Login Window", NULL, window_flags);
      static char user_name[128] {""};
      static char user_password[128] {""};
      ImGui::Text("Time Elapsed: %i seconds", static_cast<int>(ImGui::GetTime()));
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter")) {
        if (inv.userValidate(user_name,user_password)) {
          main_menu = true;
          login_window = false;
        }
        else {
          display_text_bool = true;
          display_text_timer = 0.0f;
        }
      }
      ImGui::SameLine();
      if (ImGui::Button("Back")) {
        login_window = false;
        starting_window = true;
      }
      if (display_text_bool) {
        ImGui::SameLine();
        ImGui::Text("Wrong username/password!");
        display_text_timer += ImGui::GetIO().DeltaTime;
        if (display_text_timer >= duration)
          display_text_bool = false;
      }
      ImGui::End();
    }

    // NOTE: REGISTER WINDOW
    if (register_window) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Register Menu", NULL, window_flags);
      static char user_name[128] {""};
      static char user_password[128] {""};
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter")) {
        inv.userName = user_name;
        inv.userPass = user_password;
        if (inv.userCreate()) { //function inv.userCreate() returns true if account is created successfully
          //false if an existing username exists.
          display_text_bool = true;
          display_text_timer = 0.0f;
        }
      }
      
      ImGui::SameLine();
      if (ImGui::Button("Back"))
      {
        register_window = false;
        starting_window = true;
      }
      if (display_text_bool) {
        ImGui::SameLine();
        ImGui::Text("User Account Created!");
        display_text_timer += ImGui::GetIO().DeltaTime;
        if (display_text_timer >= duration)
          display_text_bool = false;
        }
      ImGui::End();
    }
    // NOTE: MAIN MENU
    if (main_menu)
    {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Main Menu", &main_menu, window_flags);
      if (ImGui::Button("Add An Item")) {
        add_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Delete An Item")) {
        delete_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Withdraw An Item")) {
        withdraw_item_menu = true;
        main_menu = false;
        //TODO: 
        // (1) withdraw an item by displaying the list of items first
        // (2) then create + - bars on the right to allow user to take out the amount
        // (2.1) should user be able to increment it in real time without needing to click "Confirm"?

        withdraw_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Display All Items")) {
        // NOTE: should items be already sorted by name before displaying?
        display_all_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Display By Category")) {
        display_category_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Search A Specific Item")) {
        display_search_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("Log Out/Exit")) {
        starting_window = true;
        main_menu = false;
      }
      ImGui::End();
    }

    // NOTE: ADD ITEM MENU
    if (add_item_menu) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Add Item Menu", &add_item_menu, window_flags);
      static char item_name[128] {""};
      static char item_category[128] {""};
      static char item_quantity[128] {""};
      ImGui::Text("Add Item Menu");
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      ImGui::InputText("Item Category", item_category, IM_ARRAYSIZE(item_category));
      ImGui::InputText("Item Quantity", item_quantity, IM_ARRAYSIZE(item_quantity));
      if (ImGui::Button("Add")) {
        for (size_t i{0}; i < 128 ; i++) {
          item_name[i] = tolower(item_name[i]);
          item_category[i] = tolower(item_category[i]);
          item_quantity[i] = tolower(item_quantity[i]);
        }
        //there's gotta be a better way for inputting item_quantity...
        inv.addItem(item_name, item_category, stoi(static_cast<std::string> (item_quantity)));
        display_text_bool = true;
        display_text_timer = 0.0f;
      }
      if (display_text_bool) {
        ImGui::SameLine();
        ImGui::Text("Item has been added!");
        display_text_timer += ImGui::GetIO().DeltaTime;
        if (display_text_timer >= duration)
          display_text_bool = false;
        }
      if (ImGui::Button("Back")) {
        main_menu = true;
        add_item_menu = false;
      }
      ImGui::End();
    }

    // NOTE: DELETE ITEM MENU
    if (delete_item_menu) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Delete Item Menu", &delete_item_menu, window_flags);
      static char item_name[128] {""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      if (ImGui::Button("Confirm Deletion")) {
        inv.deleteItem(item_name);
        display_text_bool = true;
        display_text_timer = 0.0f;
      }
      if (display_text_bool) {
        ImGui::SameLine();
        ImGui::Text("Item has been deleted!");
        display_text_timer += ImGui::GetIO().DeltaTime;
        if (display_text_timer >= duration)
          display_text_bool = false;
      }
      if (ImGui::Button("Back")) {
        main_menu = true;
        delete_item_menu = false;
      }
      ImGui::End();
    }

    // NOTE: WITHDRAW ITEM MENU
    if (withdraw_item_menu) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Withdraw Item Menu", &withdraw_item_menu, window_flags);
      static char item_name[128] {""};
      static char item_quantity[128] {""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      ImGui::InputText("Item Quantity", item_quantity, IM_ARRAYSIZE(item_quantity));
      if (ImGui::Button("Confirm")) {
        inv.withdrawItem(item_name, std::stoi(item_quantity));
        display_text_bool = true;
        display_text_timer = 0.0f;
      }
      if (display_text_bool) {
        ImGui::SameLine();
        ImGui::Text("Item has been deleted!");
        display_text_timer += ImGui::GetIO().DeltaTime;
        if (display_text_timer >= duration)
          display_text_bool = false;
      }
      if (ImGui::Button("Back")) {
        main_menu = true;
        withdraw_item_menu = false;
      }
      ImGui::End();
    }
    if (display_all_menu) {
      item_csv = inv.readDataIntoVector("item.csv"); //update the added items
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display All Menu", &display_all_menu, window_flags);

      ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 100);
      ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY, outer_size);
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();
      for (int i{0}; i < item_csv.size(); i+=3) {
        ImGui::TableNextRow();
        ImGui::TableNextColumn();
        ImGui::Text("(%d) %s", (i/3) + 1 , item_csv[i].c_str());
        ImGui::TableNextColumn();
        ImGui::Text("%s", item_csv[i+1].c_str());
        ImGui::TableNextColumn();
        ImGui::Text("%s", item_csv[i+2].c_str());
      }
      ImGui::EndTable();
      if (ImGui::Button("Back")) {
        main_menu = true;
        display_all_menu = false;
      }
      ImGui::End();
    }
    if (display_category_menu) {
      item_csv = inv.readDataIntoVector("item.csv");
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display By Category Menu", &display_category_menu, window_flags);
      static char item_category[128] {""};
      ImGui::InputText("Category Name", item_category, IM_ARRAYSIZE(item_category));
      for (int i{0}; i < 1; i++) {
        ImGui::Text("");
      }
      ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders);
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();
      for (int i{0}; i < item_csv.size(); i+=3) {
        if (item_csv[i+1] == item_category) {
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          ImGui::Text("(%d) %s", (i/3) + 1 , item_csv[i].c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[i+1].c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[i+2].c_str());
        }
      }
      ImGui::EndTable();
      if (ImGui::Button("Back")) {
        main_menu = true;
        display_category_menu = false;
      }
      ImGui::End();
    }
    if (display_search_menu) {
      item_csv = inv.readDataIntoVector("item.csv");
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display By Item Name Menu", &display_search_menu, window_flags);
      static char item_name[128] {""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      for (int i{0}; i < 5; i++) {
        ImGui::Text("");
      }
      ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders);
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();
      for (int i{0}; i < item_csv.size(); i+=3) {
        if (item_csv[i] == item_name) {
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          ImGui::Text("(%d) %s", (i/3) + 1 , item_csv[i].c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[i+1].c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[i+2].c_str());
        }
      }
      ImGui::EndTable();
      if (ImGui::Button("Back")) {
        main_menu = true;
        display_search_menu= false;
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
