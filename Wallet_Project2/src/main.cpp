#include "Application.h"
#include "Menu_Manager.h"
#include "Menu.h"
#include "repositories/User_Csv_Repository.h"
#include "repositories/Transaction_Csv_Repository.h"

int main() {




    Application app("data/users.csv","data/transactions.csv");
   
    MenuManager manager(&app, nullptr);

    manager.ChangeMenu(new Welcome_menu(&manager));

  
    manager.Run();

    return 0;
}
