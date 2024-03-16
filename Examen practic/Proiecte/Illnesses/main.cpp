#include "Test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Repository repo{ "items.txt" };
    Service service{ repo };
    Test gui{ service };
    
    gui.show();
    return a.exec();
}
