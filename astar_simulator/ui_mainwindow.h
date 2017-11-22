/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <renderarea.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    RenderArea *renderArea;
    QPushButton *startButton;
    QPushButton *resetButton;
    QPushButton *moveButton;
    QTextBrowser *textBrowser;
    QLabel *stepSizeLabel;
    QLineEdit *stepSize;
    QLabel *label_2;
    QTextBrowser *statusBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        renderArea = new RenderArea(centralWidget);
        renderArea->setObjectName(QStringLiteral("renderArea"));
        renderArea->setGeometry(QRect(0, 0, 400, 400));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(400, 0, 99, 30));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(400, 30, 99, 27));
        moveButton = new QPushButton(centralWidget);
        moveButton->setObjectName(QStringLiteral("moveButton"));
        moveButton->setGeometry(QRect(400, 70, 99, 27));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(400, 300, 100, 100));
        stepSizeLabel = new QLabel(centralWidget);
        stepSizeLabel->setObjectName(QStringLiteral("stepSizeLabel"));
        stepSizeLabel->setGeometry(QRect(400, 130, 100, 17));
        stepSizeLabel->setAlignment(Qt::AlignCenter);
        stepSize = new QLineEdit(centralWidget);
        stepSize->setObjectName(QStringLiteral("stepSize"));
        stepSize->setGeometry(QRect(400, 150, 100, 27));
        stepSize->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 200, 100, 17));
        label_2->setAlignment(Qt::AlignCenter);
        statusBox = new QTextBrowser(centralWidget);
        statusBox->setObjectName(QStringLiteral("statusBox"));
        statusBox->setGeometry(QRect(400, 219, 100, 81));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RRT Simulator", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0));
        moveButton->setText(QApplication::translate("MainWindow", "Move", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Draw obstacles by clicking and dragging on the field.</p></body></html>", 0));
        stepSizeLabel->setText(QApplication::translate("MainWindow", "Step Size", 0));
        stepSize->setText(QApplication::translate("MainWindow", "3", 0));
        label_2->setText(QApplication::translate("MainWindow", "Status", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
