/***************************************************************************
                          encrypt.h  -  description
                             -------------------
    begin                : Tue Apr 11 2000
    copyright            : (C) 2000 by Josef Spillner
    email                : dr_maux@maux.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ENCRYPT_H
#define ENCRYPT_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qgroupbox.h>
#include <qlineedit.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

class encrypt : public QDialog  {
   Q_OBJECT
public: 
	encrypt(QWidget *parent=0, const char *name=0);
	~encrypt();

public slots:
	void radiobutton_1();
	void radiobutton_2();
	void radiobutton_3();
	void encrypt_ok();
	void encrypt_cancel();
	void input();
	void clear();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QPushButton *QPushButton_1;
	QPushButton *QPushButton_2;
	QLabel *QLabel_1;
	QLabel *QLabel_2;
	QLabel *QLabel_3;
	QButtonGroup *QButtonGroup_1;
	QRadioButton *QRadioButton_7;
	QRadioButton *QRadioButton_8;
	QGroupBox *QGroupBox_1;
	QRadioButton *QRadioButton_2;
	QRadioButton *QRadioButton_3;
	QRadioButton *QRadioButton_1;
	QGroupBox *QGroupBox_3;
	QLineEdit *QLineEdit_1;
	QLabel *QLabel_4;
	QGroupBox *QGroupBox_2;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
