/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *category;
    QSpinBox *amount;
    QDateEdit *date;
    QPushButton *submitEntry;
    QTextEdit *results;
    QPushButton *loadEntries;
    QPushButton *filterByDate;
    QPushButton *totalButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1312, 658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        category = new QLineEdit(centralwidget);
        category->setObjectName("category");
        category->setGeometry(QRect(80, 30, 331, 71));
        amount = new QSpinBox(centralwidget);
        amount->setObjectName("amount");
        amount->setGeometry(QRect(500, 30, 131, 71));
        amount->setMaximum(999999999);
        date = new QDateEdit(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(700, 30, 241, 71));
        date->setDate(QDate(2025, 3, 24));
        submitEntry = new QPushButton(centralwidget);
        submitEntry->setObjectName("submitEntry");
        submitEntry->setGeometry(QRect(70, 130, 351, 131));
        results = new QTextEdit(centralwidget);
        results->setObjectName("results");
        results->setGeometry(QRect(30, 370, 1241, 181));
        loadEntries = new QPushButton(centralwidget);
        loadEntries->setObjectName("loadEntries");
        loadEntries->setGeometry(QRect(490, 130, 391, 131));
        filterByDate = new QPushButton(centralwidget);
        filterByDate->setObjectName("filterByDate");
        filterByDate->setGeometry(QRect(1010, 30, 201, 101));
        totalButton = new QPushButton(centralwidget);
        totalButton->setObjectName("totalButton");
        totalButton->setGeometry(QRect(1010, 170, 191, 151));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1312, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        submitEntry->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        loadEntries->setText(QCoreApplication::translate("MainWindow", "Load All Entries", nullptr));
        filterByDate->setText(QCoreApplication::translate("MainWindow", "Filter by Date", nullptr));
        totalButton->setText(QCoreApplication::translate("MainWindow", "Show Totals ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
