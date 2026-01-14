#include <QApplication>
#include "src/views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    app.setApplicationName("MATOBEC Contact");
    app.setOrganizationName("leStatois");
    app.setApplicationVersion("1.0");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
