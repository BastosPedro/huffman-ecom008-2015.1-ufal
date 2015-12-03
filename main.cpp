#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "hub.h"


/*int main(int argc, char *argv[]) {

    QTime timer;

    QApplication app(argc, argv);
    QApplication::setApplicationName("Huffman huffman = new huffman(huffman)");
    QApplication::setApplicationVersion("0.5");

    QQmlApplicationEngine engine;
    QQmlContext *interpreter = engine.rootContext();
    hub huffman(&app);
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
        timer.start();
        hub::cCommand(parser.value(compression), parser.value(outName));
    }
    else if(parser.isSet(compression)){
        timer.start();
        hub::cCommand(parser.value(compression));
    }
    else{
       if(app.arguments().size() == 1){
           qDebug() << qPrintable(parser.helpText());
       }
       else if(parser.isSet(local)){
           hub::dCommand(app.arguments().at(1), parser.value(local));
       }
       else{
           hub::dCommand(app.arguments().at(1));

       }
    }
    return app.exec();
    //return 0;
}*/

/*int main(){
    qDebug() << "Beginning compression:\n";
    QTime timer;
    timer.start();

    fileinfo* roma = new fileinfo;
    roma->setPath("/home/pedro/Documents/samples/whatever.bmp");
    roma->byteFrequency();

    tree* invicta = new tree(roma);

    invicta->toVector(invicta->getRoot());
    roma->setBitString(invicta->getVector());
    invicta->representation(invicta->getRoot());

    printer::printAll(invicta, invicta->getRoot(), roma);
    printer::printRepresentation(invicta);

    invicta->buildHeader(roma->getPath(), roma->getBitString(), roma->getTrash());
    roma->deliverPackageC(invicta->getHeader(), "/home/pedro/Documents/samples/qbosta.huff");

    qDebug() << "Complete:" << timer.elapsed()/1000 << " seconds\n";
    return 0;
}*/
int main(){
    QString path = "/home/pedro/Documents/samples/test.huff";
    QString dir = "";
    if(path.contains(".huff")){
        std::cout << "Beginning decompression:\n";

        QTime timer;
        timer.start();

        if(dir == ""){
            dir = QFileInfo(path).absolutePath();
        }
        fileinfo* delenda = new fileinfo;
        delenda->setPath(path);
        delenda->decodeHeader(path);
        tree* cartago = new tree(delenda->getRepTree());
        cartago->decodeTheCode(delenda->getBinaryFile(), delenda->getTrash());
        //delenda->deliverPackageD();

        std::cout << "Complete:" << timer.elapsed()/1000 << " seconds";
    }
    else{
        std::cout << "Wrong file, please insert a .huff one.";
    }
    return 0;
}
