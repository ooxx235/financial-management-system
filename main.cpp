#include "FinanceManager.h"
#include "UIHandler.h"

int main() {
    FinanceManager manager;
    UIHandler uiHandler(manager);
    uiHandler.run();
    return 0;
}
