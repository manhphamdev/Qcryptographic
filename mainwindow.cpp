#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCryptographicHash>>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_exchange_clicked()
{
    QCryptographicHash cryptoHashMd5 (QCryptographicHash::Md5);
    QCryptographicHash cryptoHashSHA256 (QCryptographicHash::Sha256);
    QCryptographicHash cryptoHashSHA512 (QCryptographicHash::Sha512);

    cryptoHashMd5.addData(ui -> edit_input ->text().toLatin1());
    cryptoHashSHA256.addData(ui -> edit_input ->text().toLatin1());
    cryptoHashSHA512.addData(ui -> edit_input ->text().toLatin1());

    ui->edit_input->setAlignment(Qt::Alignment());
    ui->edit_md5->setText(cryptoHashMd5.result().toHex().data());
    ui->edit_sha256->setText(cryptoHashSHA256.result().toHex().data());
    ui->edit_sha512->setText(cryptoHashSHA512.result().toHex().data());

}

