#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mainhub.h"


int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QApplication::setApplicationName("Huffman - Pedro Bastos");
    QApplication::setApplicationVersion("1.0");

    QQmlApplicationEngine engine;
    QQmlContext *interpreter = engine.rootContext();
    mainHub huffman(&app);
    interpreter->setContextProperty("_huffman", &huffman);
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.setApplicationDescription("These are the huffman parsers.");
    parser.addPositionalArgument("in-file.x", QCoreApplication::translate("main", "Your file will be compressed."));
    parser.addPositionalArgument("out-name.huff", QCoreApplication::translate("main", "A new name for your compressed file is saved."));
    parser.addPositionalArgument("local", QCoreApplication::translate("main", "This is the local to save the file, sir."));

    QCommandLineOption compression("c", QApplication::translate("main", "Compresses as <in-file.x>."),
                                   QApplication::translate("main", "in-file.x"));
    parser.addOption(compression);

    QCommandLineOption outName("o", QApplication::translate("main", "Saves as <out-name.huff>."),
                               QApplication::translate("main", "out-name.huff"));
    parser.addOption(outName);

    QCommandLineOption local("d", QApplication::translate("main", "Decompressed file is stored in <local>."),
                             QApplication::translate("main", "local"));
    parser.addOption(local);

    QCommandLineOption startGui({"g", "gui"}, QApplication::translate("main", "Starts graphical interface."));
    parser.addOption(startGui);

    parser.process(app);

    if(parser.isSet(startGui)){
        engine.load(QUrl(QStringLiteral("qrc:/gui.qml")));
    }
    else if(parser.isSet(compression) && parser.isSet(outName)){
        qDebug() << "Beginning compression.";
        mainHub::cCommand(parser.value(compression), parser.value(outName));
        qDebug() << "Complete.";
    }
    else if(parser.isSet(compression)){
        qDebug() << "Beginning compression.";
        mainHub::cCommand(parser.value(compression));
        qDebug() << "Complete.";
    }
    else{
       if(app.arguments().size() == 1){
           qDebug() << qPrintable(parser.helpText());
       }
       else if(parser.isSet(local)){
           qDebug() << "Beginning decompression.";
           mainHub::dCommand(app.arguments().at(1), parser.value(local));
           qDebug() << "Complete.";
       }
       else{
           qDebug() << "Beginning decompression.";
           mainHub::dCommand(app.arguments().at(1));
           qDebug() << "Complete.";
       }
    }
    return app.exec();
}
