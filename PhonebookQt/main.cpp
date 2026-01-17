#include <QApplication>
#include "src/views/MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    app.setApplicationName("MATOBEC Contact");
    app.setOrganizationName("leStatois");
    app.setApplicationVersion("2.0 - PostgreSQL Edition");
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
