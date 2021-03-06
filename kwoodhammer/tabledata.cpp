/**********************************************************************
            --- KDevelop (KDlgEdit)  generated file ---                

            Last generated: Sun May 7 15:59:05 2000

            DO NOT EDIT!!!  This file will be automatically
            regenerated by KDevelop.  All changes will be lost.

**********************************************************************/
#include <kapp.h>
#include <kiconloader.h>
#include <qpixmap.h>
#include <qfont.h>
#include <kquickhelp.h>
#include "table.h"
#include "common.h"

void  table::initDialog(){
  KIconLoader loader;

  this->resize(350,320);
  this->setMinimumSize(350,320);
  this->setMaximumSize(350,320);
  QGroupBox_1= new QGroupBox(this,"NoName");
  QGroupBox_1->setGeometry(10,10,30,30);
  QGroupBox_1->setMinimumSize(0,0);
  QGroupBox_1->setBackgroundPixmap(loader.loadIcon("kwoodtable.xpm"));

  QLabel_1= new QLabel(this,"NoName");
  QLabel_1->setGeometry(50,10,290,30);
  QLabel_1->setMinimumSize(0,0);
  QLabel_1->setFont(QFont("helvetica", 20, 50));
  QLabel_1->setText(i18n("KWoodhammer Key Table"));

  QGroupBox_2= new QGroupBox(this,"NoName");
  QGroupBox_2->setGeometry(10,200,330,70);
  QGroupBox_2->setMinimumSize(0,0);

  QComboBox_1= new QComboBox(QGroupBox_2,"NoName");
  QComboBox_1->setGeometry(80,10,60,20);
  QComboBox_1->setMinimumSize(0,0);

  QComboBox_2= new QComboBox(QGroupBox_2,"NoName");
  QComboBox_2->setGeometry(80,40,60,20);
  QComboBox_2->setMinimumSize(0,0);

  QLabel_2= new QLabel(QGroupBox_2,"NoName");
  QLabel_2->setGeometry(10,10,50,20);
  QLabel_2->setMinimumSize(0,0);
  QLabel_2->setText(i18n("Row"));

  QLabel_3= new QLabel(QGroupBox_2,"NoName");
  QLabel_3->setGeometry(10,40,60,20);
  QLabel_3->setMinimumSize(0,0);
  QLabel_3->setText(i18n("Column"));

  QLabel_4= new QLabel(QGroupBox_2,"NoName");
  QLabel_4->setGeometry(160,40,50,20);
  QLabel_4->setMinimumSize(0,0);
  QLabel_4->setText(i18n("Letter"));

  QComboBox_3= new QComboBox(QGroupBox_2,"NoName");
  QComboBox_3->setGeometry(220,40,100,20);
  QComboBox_3->setMinimumSize(0,0);

  QPushButton_1= new QPushButton(this,"NoName");
  QPushButton_1->setGeometry(120,280,100,30);
  QPushButton_1->setMinimumSize(0,0);
  QPushButton_1->setText(i18n("OK"));

  QLabel_5= new QLabel(this,"NoName");
  QLabel_5->setGeometry(10,170,330,20);
  QLabel_5->setMinimumSize(0,0);
  QLabel_5->setText(i18n("Customize table"));

  QLabel_6= new QLabel(this,"NoName");
  QLabel_6->setGeometry(10,50,330,20);
  QLabel_6->setMinimumSize(0,0);
  QLabel_6->setText(i18n("Create table"));

  QButtonGroup_1= new QButtonGroup(this,"NoName");
  QButtonGroup_1->setGeometry(10,80,330,80);
  QButtonGroup_1->setMinimumSize(0,0);

  QRadioButton_1= new QRadioButton(QButtonGroup_1,"NoName");
  QRadioButton_1->setGeometry(10,10,90,20);
  QRadioButton_1->setMinimumSize(0,0);
  KQuickHelp::add(QRadioButton_1,i18n("<red>Trithemius<br><black>This German invented the simplest polyalphabetical encryption table."));
  QRadioButton_1->setText(i18n("Trithemius"));
  QRadioButton_1->setChecked(true);

  QRadioButton_2= new QRadioButton(QButtonGroup_1,"NoName");
  QRadioButton_2->setGeometry(10,30,90,20);
  QRadioButton_2->setMinimumSize(0,0);
  QRadioButton_2->setText(i18n("Random"));

  QRadioButton_3= new QRadioButton(QButtonGroup_1,"NoName");
  QRadioButton_3->setGeometry(10,50,90,20);
  QRadioButton_3->setMinimumSize(0,0);
  QRadioButton_3->setText(i18n("Clear"));

  QLineEdit_1= new QLineEdit(QButtonGroup_1,"NoName");
  QLineEdit_1->setGeometry(220,10,100,20);
  QLineEdit_1->setMinimumSize(0,0);

  QLabel_7= new QLabel(QButtonGroup_1,"NoName");
  QLabel_7->setGeometry(110,10,100,20);
  QLabel_7->setMinimumSize(0,0);
  QLabel_7->setText(i18n("Keyword"));

  QPushButton_2= new QPushButton(QButtonGroup_1,"NoName");
  QPushButton_2->setGeometry(110,50,100,20);
  QPushButton_2->setMinimumSize(0,0);
  QPushButton_2->setText(i18n("Create"));

  QPushButton_3= new QPushButton(QButtonGroup_1,"NoName");
  QPushButton_3->setGeometry(220,50,100,20);
  QPushButton_3->setMinimumSize(0,0);
  QPushButton_3->setText(i18n("Show"));

}
