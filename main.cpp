#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "inventoryManagement.h"
#include <cstdlib>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include "GLFW/glfw3.h"
#include <iostream>
#include <string>

static void glfw_error_callback(int error, const char *description) {
  fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

// Main code
int main(int, char **) {
  // NOTE: INVENTORY MANAGEMENT SETUP
  invManage inv;
  inv.populate_stock(); // do not run this function if an item.csv file already
                        // exists!
  std::vector<invManage::Item> item_csv = inv.readDataIntoVector("item.csv");
  std::cout << "item_csv size is -> " << item_csv.size() << "\n";
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit())
    return 1;

  const static char *glsl_version = "#version 150";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on Mac

  // Create window with graphics context
  GLFWwindow *window = glfwCreateWindow(700, 700, "Inventory Management System",
                                        nullptr, nullptr);
  if (window == nullptr)
    return 1;
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

  // Setup Dear ImGui style
  // ImGui::StyleColorsDark();
  ImGui::StyleColorsClassic();
  // ImGui::StyleColorsLight();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);

  ImGui_ImplOpenGL3_Init(glsl_version);
  io.Fonts->AddFontFromFileTTF("../jetbrains.ttf", 20.0f);
  const float TEXT_BASE_HEIGHT{20.0f};
  // const float TEXT_BASE_HEIGHT = ImGui::GetTextLineHeightWithSpacing();

  // Our state
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  bool starting_window = true;
  bool main_menu = false;
  bool add_item_menu = false;
  bool login_window = false;
  bool register_window = false;
  bool delete_item_menu = false;
  bool withdraw_item_menu = false;
  float duration{0.5f};
  float display_text_timer{0.0f};
  float display_text_bool = false;
  bool display_all_menu = false;
  bool display_category_menu = false;
  bool display_search_menu = false;
  bool data_loaded = false;
  ImGuiWindowFlags window_flags =
      ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
  ImVec2 window_size = ImVec2(700, 700);
  ImVec2 window_position = ImVec2(0, 0);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    if (starting_window) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Starting Window", NULL, window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      if (ImGui::Button("(1) Login") || ImGui::IsKeyPressed(ImGuiKey_1)) {
        login_window = true;
        starting_window = false;
      }
      if (ImGui::Button("(2) Register") || ImGui::IsKeyPressed(ImGuiKey_2)) {
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
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char user_name[128]{""};
      static char user_password[128]{""};
      ImGui::Text("Time Elapsed: %i seconds",
                  static_cast<int>(ImGui::GetTime()));
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter") || ImGui::IsKeyPressed(ImGuiKey_Enter)) {
        if (inv.userValidate(user_name, user_password)) {
          main_menu = true;
          login_window = false;
        } else {
          display_text_bool = true;
          display_text_timer = 0.0f;
        }
      }
      ImGui::SameLine();
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
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
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char user_name[128]{""};
      static char user_password[128]{""};
      ImGui::InputText("username", user_name, IM_ARRAYSIZE(user_name));
      ImGui::InputText("password", user_password, IM_ARRAYSIZE(user_password));
      if (ImGui::Button("Enter") || ImGui::IsKeyPressed(ImGuiKey_Enter)) {
        inv.userName = user_name;
        inv.userPass = user_password;
        if (inv.userCreate()) { // function inv.userCreate() returns true if
                                // account is created successfully
          // false if an existing username exists.
          display_text_bool = true;
          display_text_timer = 0.0f;
        }
      }

      ImGui::SameLine();
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
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
    if (main_menu) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Main Menu", &main_menu, window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      if (ImGui::Button("(1) Add An Item") || ImGui::IsKeyPressed(ImGuiKey_1)) {
        add_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(2) Delete An Item") ||
          ImGui::IsKeyPressed(ImGuiKey_2)) {
        delete_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(3) Withdraw An Item") ||
          ImGui::IsKeyPressed(ImGuiKey_3)) {
        withdraw_item_menu = true;
        main_menu = false;
        // TODO:
        //  (1) withdraw an item by displaying the list of items first
        //  (2) then create + - bars on the right to allow user to take out the
        //  amount (2.1) should user be able to increment it in real time
        //  without needing to click "Confirm"?

        withdraw_item_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(4) Display All Items") || ImGui::IsKeyPressed(ImGuiKey_4)) {
        display_all_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(5) Display By Category") || ImGui::IsKeyPressed(ImGuiKey_5)) {
        display_category_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(6) Search A Specific Item") || ImGui::IsKeyPressed(ImGuiKey_6)) {
        display_search_menu = true;
        main_menu = false;
      }
      if (ImGui::Button("(7) Log Out/Exit") || ImGui::IsKeyPressed(ImGuiKey_7)) {
        exit(1);
//        starting_window = true;
//        main_menu = false;
      }
      ImGui::End();
    }

    // NOTE: ADD ITEM MENU
    if (add_item_menu) {
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Add Item Menu", &add_item_menu, window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char item_name[128]{""};
      static char item_category[128]{""};
      static char item_quantity[128]{""};
      ImGui::Text("Add Item Menu");
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      ImGui::InputText("Item Category", item_category,
                       IM_ARRAYSIZE(item_category));
      ImGui::InputText("Item Quantity", item_quantity,
                       IM_ARRAYSIZE(item_quantity));
      if (ImGui::Button("Add") || ImGui::IsKeyPressed(ImGuiKey_Enter)) {
        for (size_t i{0}; i < 128; i++) {
          item_name[i] = tolower(item_name[i]);
          item_category[i] = tolower(item_category[i]);
          item_quantity[i] = tolower(item_quantity[i]);
        }
        // there's gotta be a better way for inputting item_quantity...
        inv.addItem(item_name, item_category,
                    stoi(static_cast<std::string>(item_quantity)));
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
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
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
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char item_name[128]{""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      if (ImGui::Button("Confirm Deletion") ||
          ImGui::IsKeyPressed(ImGuiKey_Enter)) {
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
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
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
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char item_name[128]{""};
      static char item_quantity[128]{""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      ImGui::InputText("Item Quantity", item_quantity,
                       IM_ARRAYSIZE(item_quantity));
      if (ImGui::Button("Confirm") || ImGui::IsKeyPressed(ImGuiKey_Enter)) {
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
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        main_menu = true;
        withdraw_item_menu = false;
      }
      ImGui::End();
    }

    // NOTE: Display All Menu
    if (display_all_menu) {
      if (!data_loaded) {
        item_csv = inv.readDataIntoVector("item.csv"); // update the added items
        data_loaded = true;
      }
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display All Menu", &display_all_menu, window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 25);
      ImGui::BeginTable("table2", 3,
                        ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY,
                        outer_size);
      ImGui::TableSetupScrollFreeze(0, 1); // Make top row always visible
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();

      ImGuiListClipper clipper;
      clipper.Begin(item_csv.size());
      // size is 0 here...
      // std:: cout << item_csv.size() << "\n";
      while (clipper.Step()) {
        for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++) {
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          ImGui::Text("(%d) %s", row + 1, item_csv[row].itemName.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[row].itemCategory.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%i", item_csv[row].itemQuantity);
        }
      }
      ImGui::EndTable();
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        main_menu = true;
        display_all_menu = false;
        data_loaded = false;
      }
      ImGui::End();
    }

    // NOTE: Display Category Menu
    if (display_category_menu) {
      if (!data_loaded) {
        item_csv = inv.readDataIntoVector("item.csv");
        data_loaded = true;
      }
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display By Category Menu", &display_category_menu,window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char item_category[128]{""};
      ImGui::InputText("Category Name", item_category,
                       IM_ARRAYSIZE(item_category));
      ImVec2 outer_size = ImVec2(0.0f, TEXT_BASE_HEIGHT * 25);
      ImGui::BeginTable("table2", 3,ImGuiTableFlags_Borders | ImGuiTableFlags_ScrollY, outer_size);
      ImGui::TableSetupScrollFreeze(0, 1); // Make top row always visible
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();
      ImGuiListClipper clipper;

      //NOTE: The code here lags when a category is found.
      std::vector<invManage::Item> new_item_csv;
      for (size_t i{0}; i < item_csv.size(); i++) {
        if (item_csv[i].itemCategory == item_category)
          new_item_csv.push_back(item_csv[i]);
      }
      clipper.Begin(new_item_csv.size());
      while (clipper.Step()) {
        for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++) {
          // TODO: Need to create a separate vector<item> where it listens to
          // the item_category and only push_back the value when the item
          // matches the std::string. So probably need to add a button to allow
          // users to confirm it. Or we can have it as it was previous of the
          // code below that's commented out. Which allows real-time display but
          // sacrifices performance.
          //
          // NOTE: We can add a method similar to how we did with
          // display_all_menu() function. continually update item_category and
          // listening to the user input updates. create a
          // std::unordered_map<std::string category, std::vector<struct item> >
          // that stores all items based on their category.
          // do nothing if category does not exists on the map.
          // If the category exists on the map, display all the values from that
          // category.
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          ImGui::Text("(%d) %s", row + 1, new_item_csv[row].itemName.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", new_item_csv[row].itemCategory.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%i", new_item_csv[row].itemQuantity);
        }
      }
      ImGui::EndTable();
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        main_menu = true;
        display_category_menu = false;
        data_loaded = false;
      }
      ImGui::End();
    }
    if (display_search_menu) {
      if (!data_loaded) {
        item_csv = inv.readDataIntoVector("item.csv");
        data_loaded = true;
      }
      ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);
      ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
      ImGui::Begin("Display By Item Name Menu", &display_search_menu, window_flags);
      ImGui::Text("(%.1f FPS)",io.Framerate);
      static char item_name[128]{""};
      ImGui::InputText("Item Name", item_name, IM_ARRAYSIZE(item_name));
      for (int i{0}; i < 5; i++) {
        ImGui::Text("");
      }
      ImGui::BeginTable("table2", 3, ImGuiTableFlags_Borders);
      ImGui::TableSetupColumn("Item Name");
      ImGui::TableSetupColumn("Item Category");
      ImGui::TableSetupColumn("Item Quantity");
      ImGui::TableHeadersRow();
      for (int i{0}; i < item_csv.size(); i++) {
        if (item_csv[i].itemName == item_name) {
          ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
          ImGui::TableNextRow();
          ImGui::TableNextColumn();
          ImGui::Text("(%d) %s", i + 1, item_csv[i].itemName.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%s", item_csv[i].itemCategory.c_str());
          ImGui::TableNextColumn();
          ImGui::Text("%i", item_csv[i].itemQuantity);
        }
      }
      ImGui::EndTable();
      if (ImGui::Button("Back") || ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        main_menu = true;
        display_search_menu = false;
        data_loaded = false;
      }
      ImGui::End();
    }
    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w,
                 clear_color.z * clear_color.w, clear_color.w);
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
