#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QDoubleValidator>
#include <cmath>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QDoubleValidator(this));
    ui->lineEdit_3->setValidator(new QDoubleValidator(this));
    ui->widget->xAxis->setRange(-10, 10);
    ui->widget->yAxis->setRange(-10, 10);
    ui->widget->addGraph();
    x.push_back(0);
    y.push_back(1);
    x.push_back(1);
    y.push_back(2);
    x.push_back(3);
    y.push_back(1);
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);

    /*double x_min = 0;
    double x_max = 0;
    double a = -10;
    double b = 10;

    std::cout << "--ok--\n";
    x_min = std::min(a, b);
    x_max = std::min(a, b);

    int m = 10;
    double d = (x_max - x_min) / m;
    QVector<double> x;
    QVector<double> y;
    char str[] = "x^2\0";

    double Y = 0;
    double X = x_min;
    for(int i = 0; i < m; i++){
        std::cout << "--in cycle--\n";
        int j = 0;
        int n = 260;
        int flag = calculate(str, &n, X, 1, &j, &Y);
        std::cout << "-- flag = " << flag << " ---" << std::endl;
        if(flag == 0){
            x.append(X);
            y.append(Y);
            std::cout << "--appended X Y--" << std::endl;
        }
        X += d;
    }
    ui->widget->xAxis->setRange(x_min, x_max);
    ui->widget->yAxis->setRange(x_min, x_max);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->textBrowser->setPlainText("");
    update_precalc();
}


void MainWindow::add_symbol_textbrowser2(const QString& string)
{
    if(ui->radioButton->isChecked())
    {

        QString strr = ui->lineEdit->displayText();
        strr = strr + string;
        if(strr.length() <= 260)
            ui->lineEdit->setText(strr);
    }
    else
    {
        QString strr = ui->textBrowser_2->toPlainText();
        strr = strr + string;
        if(strr.length() <= 260)
            ui->textBrowser_2->setPlainText(strr);
        update_precalc();
    }
}

void MainWindow::clear_textBrowser2()
{
    ui->textBrowser_2->setPlainText("");
}


void MainWindow::del_textBrowser2()
{
    QString str ;
    if(ui->radioButton->isChecked())
        str = ui->lineEdit->displayText();
    else
        str= ui->textBrowser_2->toPlainText();
    if(str.endsWith("cos(") || str.endsWith("sin(") || str.endsWith("tan(") || str.endsWith("log("))
        str.chop(4);
    else if(str.endsWith("acos(") || str.endsWith("asin(") || str.endsWith("atan(") || str.endsWith("sqrt("))
        str.chop(5);
    else if(str.endsWith("ln("))
        str.chop(3);
    else
        str.chop(1);

    if(ui->radioButton->isChecked())
        ui->lineEdit->setText(str);
    else
        ui->textBrowser_2->setPlainText(str);
}

int MainWindow::update_precalc()
{
    QByteArray arr = ui->textBrowser_2->toPlainText().toLocal8Bit();
    char* str = arr.data();


    bool x_ok = 0;
    double x_var = ui->textBrowser->toPlainText().toDouble(&x_ok);
    int x_set = x_ok ? 1 : 0;
    double res = 0;
    int i = 0;
    int n = 260;
    int flag = calculate(str, &n, x_var, x_set, &i, &res);
    if(flag == 0)
        ui->textBrowser_3->setPlainText(QString::number(res).replace(".", ","));
    else if(arr.length() == 0)
        ui->textBrowser_3->setPlainText("");
    else
        ui->textBrowser_3->setPlainText("error" + QString::number(flag));
    return flag;
}


void MainWindow::save_to_x(){
    if(update_precalc() == 0){
        ui->textBrowser->setPlainText(ui->textBrowser_3->toPlainText());
    }
}

void MainWindow::on_pushButton_clicked()
{
    add_symbol_textbrowser2(QString("1"));
}


void MainWindow::on_pushButton_2_clicked()
{
    add_symbol_textbrowser2(QString("2"));

}


void MainWindow::on_pushButton_3_clicked()
{
    add_symbol_textbrowser2(QString("3"));

}


void MainWindow::on_pushButton_4_clicked()
{
    add_symbol_textbrowser2(QString("4"));

}


void MainWindow::on_pushButton_5_clicked()
{
    add_symbol_textbrowser2(QString("5"));

}


void MainWindow::on_pushButton_6_clicked()
{
    add_symbol_textbrowser2(QString("6"));

}


void MainWindow::on_pushButton_9_clicked()
{
    add_symbol_textbrowser2(QString("7"));

}


void MainWindow::on_pushButton_8_clicked()
{
    add_symbol_textbrowser2(QString("8"));

}


void MainWindow::on_pushButton_7_clicked()
{
    add_symbol_textbrowser2(QString("9"));

}


void MainWindow::on_pushButton_10_clicked()
{
    add_symbol_textbrowser2(QString("0"));

}


void MainWindow::on_pushButton_15_clicked()
{
    add_symbol_textbrowser2(QString(","));

}


void MainWindow::on_pushButton_17_clicked()
{
    add_symbol_textbrowser2(QString("x"));

}


void MainWindow::on_pushButton_24_clicked()
{
    add_symbol_textbrowser2(QString(")"));
}


void MainWindow::on_pushButton_23_clicked()
{
    add_symbol_textbrowser2(QString("("));

}


void MainWindow::on_pushButton_19_clicked()
{
    add_symbol_textbrowser2(QString("mod"));

}


void MainWindow::on_pushButton_20_clicked()
{
    add_symbol_textbrowser2(QString("^"));

}


void MainWindow::on_pushButton_11_clicked()
{
    add_symbol_textbrowser2(QString("+"));

}


void MainWindow::on_pushButton_12_clicked()
{
    add_symbol_textbrowser2(QString("-"));

}


void MainWindow::on_pushButton_13_clicked()
{
    add_symbol_textbrowser2(QString("*"));

}


void MainWindow::on_pushButton_14_clicked()
{
    add_symbol_textbrowser2(QString("/"));

}


void MainWindow::on_pushButton_18_clicked()
{
    if(update_precalc() == 0){
        ui->textBrowser_4->append(ui->textBrowser_2->toPlainText() + QString("=") + ui->textBrowser_3->toPlainText());
        //add_symbol_textbrowser2(QString("="));
        ui->textBrowser_2->setPlainText(ui->textBrowser_3->toPlainText());
        update_precalc();
    }

}


void MainWindow::on_pushButton_25_clicked()
{
    add_symbol_textbrowser2(QString("e"));
}


void MainWindow::on_pushButton_16_clicked()
{
    clear_textBrowser2();
    update_precalc();
}


void MainWindow::on_pushButton_21_clicked()
{
    del_textBrowser2();
    update_precalc();
}


void MainWindow::on_pushButton_42_clicked()
{
    add_symbol_textbrowser2("acos(");
}


void MainWindow::on_pushButton_40_clicked()
{
    add_symbol_textbrowser2("asin(");
}


void MainWindow::on_pushButton_41_clicked()
{
    add_symbol_textbrowser2("atan(");
}


void MainWindow::on_pushButton_38_clicked()
{
    add_symbol_textbrowser2("sqrt(");
}


void MainWindow::on_pushButton_33_clicked()
{
    add_symbol_textbrowser2("cos(");
}


void MainWindow::on_pushButton_34_clicked()
{
    add_symbol_textbrowser2("sin(");
}


void MainWindow::on_pushButton_28_clicked()
{
    add_symbol_textbrowser2("tan(");
}


void MainWindow::on_pushButton_31_clicked()
{
    add_symbol_textbrowser2("ln(");
}


void MainWindow::on_pushButton_30_clicked()
{
    add_symbol_textbrowser2("log(");
}


void MainWindow::on_pushButton_22_clicked()
{
    save_to_x();
    update_precalc();
}


void MainWindow::on_pushButton_27_clicked()
{
    x.clear();
    y.clear();
    std::cout << "--in func--\n";
    bool ok = true;
    double x_min = 0;
    double x_max = 0;
    double a = ui->lineEdit_2->text().toDouble(&ok);
    double b = 0;
    if(ok)
        b = ui->lineEdit_3->text().toDouble(&ok);
    if(ok)
    {
        std::cout << "--ok--\n";
        x_min = std::min(a, b);
        x_max = std::min(a, b);
    }
    int m = 10;
    double d = (x_max - x_min) / m;
    QByteArray arr = ui->lineEdit->text().toLocal8Bit();
    char* str = arr.data();

    double Y = 0;
    double X = x_min;
    for(int i = 0; ok && i < m; i++)
    {
        std::cout << "--in cycle--\n";
        int j = 0;
        int n = 260;
        int flag = calculate(str, &n, X, 1, &j, &Y);
        std::cout << "-- flag = " << flag << " ---" << std::endl;
        if(flag == 0)
        {
            x.append(X);
            y.append(Y);
            std::cout << "--appended X Y--" << std::endl;
        }
        X += d;
    }
    //ui->widget->xAxis->setRange(x_min, x_max);
    //ui->widget->yAxis->setRange(x_min, x_max);
    //ui->widget->addGraph();
    //ui->widget->replot();
    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y, true);
    ui->widget->graph(0)->setName("new");
    //ui->widget->graph(0)->
    ui->widget->replot();
    //ui->widget->rescaleAxes()
    std::cout << x.length() << "  " << y.length() << std::endl;
    std::cout << "--done--" << std::endl;
}

