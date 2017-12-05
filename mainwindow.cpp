#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

#include <QStandardPaths>

#include <stdio.h>


#include "students.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _speedGroup = new QActionGroup(this);
    _speedGroup->addAction(ui->actionSlow);
    _speedGroup->addAction(ui->actionNormal);
    _speedGroup->addAction(ui->actionFast);
    _speedGroup->addAction(ui->actionUltrafast);

    connect(_speedGroup, &QActionGroup::triggered, this, &MainWindow::speedDidChange);

    ui->actionNormal->trigger();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionrandom_tree_triggered()
{
    ui->centralWidget->createRandomTree();
}

void MainWindow::on_actioninsert_triggered()
{
    int key = QInputDialog::getInt(this, "insert( tal )", "Ange talet:", rand()%512 );
    ui->centralWidget->insertKeyToSearchtree(key);

}

void MainWindow::on_actiondelete_triggered()
{
    int key = QInputDialog::getInt(this, "remeve( tal )", "Ange talet:", rand()%512 );
    ui->centralWidget->removeKeyFromSearchtree(key);
}



void MainWindow::on_insert100Random_triggered()
{
    ui->centralWidget->insertMultipleRandomKeysToSearchtree(100);
}

void MainWindow::on_remove100Random_triggered()
{
    ui->centralWidget->removeMultipleRandomKeysFromSearchtree(100);

}

void MainWindow::on_insertRemove1000RandomKeys_triggered()
{
    ui->centralWidget->insertRemoveRandomkeys(1000);
}

void MainWindow::speedDidChange(QAction *action)
{
    int durationOfDelay = 0;

    if (action==ui->actionSlow) durationOfDelay = 1000;
    else if (action==ui->actionNormal)  durationOfDelay = 200;
    else if (action==ui->actionFast)  durationOfDelay = 100;
    else if (action==ui->actionUltrafast)  durationOfDelay = 0;
    else assert(false);

    ui->centralWidget->setDurationOfDelay(durationOfDelay);

}

void MainWindow::on_actionPreOrder_triggered()
{
    ::flashPreOrder(ui->centralWidget->root() );
}

void MainWindow::on_actionInOrder_triggered()
{
    ::flashInOrder(ui->centralWidget->root() );

}

void MainWindow::on_actionPostOrder_triggered()
{
    ::flashPostOrder(ui->centralWidget->root() );

}

void MainWindow::on_actionheight_triggered()
{
    int height = ::height( ui->centralWidget->root());
    QString str = QString("height returnerade %1").arg(height);
    QMessageBox::information(this, "height", str);
}

void MainWindow::on_actionnumberOfNodes_triggered()
{
    int size = ::numberOfNodes( ui->centralWidget->root());
    QString str = QString("numberOfNodes returnerade %1").arg(size);
    QMessageBox::information(this, "numberOfNodes", str);
}

void MainWindow::on_actionsave_triggered()
{
    QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    QString filename = QFileDialog::getSaveFileName(this, "spara fil", location, "dalgoträd (*.txt)" );

    if (!filename.isEmpty()){
        FILE *fp = fopen(filename.toLatin1().data(), "w");
        if (fp){
            ui->centralWidget->saveTree(fp);
            fclose(fp);
        }
    }
}

void MainWindow::on_actionread_triggered()
{
    QString location = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);

    QString filename = QFileDialog::getOpenFileName(this, "läs fil", location, "dalgoträd (*.txt)" );

    if (!filename.isEmpty()){
        FILE *fp = fopen(filename.toLatin1().data(), "r");
        if (fp){
            ui->centralWidget->readTree(fp);
            fclose(fp);
        }
    }
}

void MainWindow::on_actionflashNodesAtIncreasingDepth_triggered()
{
    ::flashNodesAtIncreasingDepth( ui->centralWidget->root());

}

void MainWindow::on_actioncreate_random_search_tree_triggered()
{
    int size = QInputDialog::getInt(this, "create random search tree", "Antal noder (1-1024):", 256,1,1024);
    ui->centralWidget->createRandomSearchTree(size);


}
