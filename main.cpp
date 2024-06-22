#include "mainwindow.h"
#include <QWebEngineView>
#include <QApplication>
#include <QUrl>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
     //QWebEngineView *view = new QWebEngineView;
     //QUrl url(QStringLiteral("c.html"));
     //view->load(QUrl(QFileInfo("file:///home/mhh/whisper/c.html").absoluteFilePath()));
   //  view->show();
    return a.exec();
}
