#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    resize(600, 400);
    // mene bar, only one
    QMenuBar * myMenuBar = new QMenuBar();
    setMenuBar(myMenuBar);
    QMenu * fileMenu = myMenuBar->addMenu("File");
    QMenu * editMenu = myMenuBar->addMenu("Edit");

    QAction * newAction = fileMenu->addAction("New");
    fileMenu->addSeparator();
    QAction * openAction = fileMenu->addAction("Open");

    // Tool bar, multiple
    QToolBar * myToolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, myToolBar);
    myToolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    myToolBar->setFloatable(false);

    myToolBar->addAction(newAction);
    myToolBar->addAction(openAction);
    myToolBar->addSeparator();
    QAction * refrAction = myToolBar->addAction("Refresh");
    QAction * delAction = myToolBar->addAction("Delete");
    myToolBar->addSeparator();
    QPushButton * myBtn = new QPushButton("More", this);
    myToolBar->addWidget(myBtn);

    // status bar, only one
    QStatusBar * myStatusBar = new QStatusBar();
    setStatusBar(myStatusBar);
    QLabel * myQLabel1 = new QLabel("Tips", this);
    myStatusBar->addWidget(myQLabel1);
    QLabel * myQLabel2 = new QLabel("Others", this);
    myStatusBar->addPermanentWidget(myQLabel2);

    // dock widget, multiple
    QDockWidget * myDockWidget = new QDockWidget("float", this);
    addDockWidget(Qt::BottomDockWidgetArea, myDockWidget);
    myDockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    // central widget, only one
    QTextEdit * myQTextEdit = new QTextEdit();
    setCentralWidget(myQTextEdit);


}

MainWindow::~MainWindow()
{
    delete ui;
}

