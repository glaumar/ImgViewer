#include "mainwindow.h"

#include <QApplication>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument(QObject::tr("file"), QObject::tr("The file to open."));
    parser.process(app);

    MainWindow w;
    QStringList arg = parser.positionalArguments();
    if (!arg.isEmpty()){
        w.openImg(arg.constFirst());
    }
    w.show();
    return app.exec();
}
