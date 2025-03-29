#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->submitEntry, &QPushButton::clicked, this, &MainWindow::handleSubmit);
    connect(ui->loadEntries, &QPushButton::clicked, this, &MainWindow::loadAllEntries);
    connect(ui->filterByDate, &QPushButton::clicked, this, &MainWindow::filterEntriesByDate);
    connect(ui->totalButton, &QPushButton::clicked, this, &MainWindow::showTotals);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleSubmit()
{
    QString categoryText = ui->category->text();
    int amountValue = ui->amount->value();
    QDate dateValue = ui->date->date();
    QString dateStr = dateValue.toString("yyyy-MM-dd");

    QString result = "Category: " + categoryText + "\n" + "Amount: " + QString::number(amountValue) + "\n" + "Date: " + dateValue.toString("yyyy-MM-dd") + "\n";

    ui->results->setText(result);

    string categoryStd = categoryText.toStdString();
    string dateStd = dateValue.toString("yyyy-MM-dd").toStdString();

    ofstream file("budget_data.csv", ios::app);

    if(file.is_open())
        {
            file << categoryStd << "," << amountValue << "," << dateStd << "\n";
            file.close();
            ui->results->setText("Entry saved to CSV!");
        }
    else
    {
        ui->results->setText("Could not open file for writing!");
        }
 }

void MainWindow::loadAllEntries()
 {
    ifstream file("budget_data.csv");
     if(!file.is_open())
    {
        ui->results->setText("Could not open the file!");
         return;
     }

     string line;
     QString displayText;

     while(getline(file, line))
     {
         displayText += QString::fromStdString(line) + "\n";
     }

     ui->results->setText(displayText);
     file.close();

 }


 void MainWindow::filterEntriesByDate()
 {
     ifstream file("budget_data.csv");
     if(!file.is_open())
     {
         ui->results->setText("Could not open file!");
     }

     QDate selectedDate = ui->date->date();
     QString selectedDateStr = selectedDate.toString("yyyy-MM-dd");

     string line;
     QString filteredResults;

     bool firstLine = true;
     while(getline(file, line))
     {
         if(firstLine)
         {
             filteredResults += QString::fromStdString(line) + "\n";
             firstLine = false;
             continue;
         }

         QString qLine = QString::fromStdString(line);
         QStringList parts = qLine.split(',');

         if(parts.size() >= 3 && parts[2].trimmed() == selectedDateStr)
         {
             filteredResults += qLine + "\n";
         }
     }

     file.close();
     ui->results->setText(filteredResults);
 }


 void MainWindow::showTotals()
 {
     ifstream file("budget_data.csv");
     if(!file.is_open())
     {
         ui->results->setText("Could not open the file!");
         return;
     }

     QDate selectedDate = ui->date->date();
     QString selectedDateStr = selectedDate.toString("yyyy-MM-dd");


     QString categoryInput = ui->category->text().trimmed();

     string line;
     int totalAmount = 0;
     bool firstLine = true;

     while(getline(file, line))
     {
         if(firstLine)
         {
             firstLine = false;
             continue;
         }

         QString qLine = QString::fromStdString(line);
         QStringList parts = qLine.split(",");

         if(parts.size() < 3) continue;

         QString category = parts[0].trimmed();
         int amount = parts[1].trimmed().toInt();
         QString date = parts[2].trimmed();

         bool dateMatches = (date == selectedDateStr);
         bool categoryMatches = (categoryInput.isEmpty() || category == categoryInput);

         if(dateMatches && categoryMatches)
         {
             totalAmount += amount;
         }

     }
     file.close();
     QString summary = "Total ";
     if(!categoryInput.isEmpty())
     {
         summary += "for category " + categoryInput + "' ";
     }

     summary += "on " + selectedDateStr + ": " + QString::number(totalAmount);

     ui->results->setText(summary);
 }
