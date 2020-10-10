/***************************************************************************
                          table.h  -  description
                             -------------------
    begin                : Sun Apr 16 2000
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

#ifndef TABLE_H
#define TABLE_H

//Generated area. DO NOT EDIT!!!(begin)
#include <qwidget.h>
#include <qgroupbox.h>
#include <qlabel.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qbuttongroup.h>
#include <qradiobutton.h>
#include <qlineedit.h>
//Generated area. DO NOT EDIT!!!(end)

#include <qdialog.h>

/**
  *@author Josef Spillner
  */

class table : public QDialog  {
   Q_OBJECT
public slots:
	void table_ok();
	void table_show();
	void table_create();
	void table_init();
	void input();
	void combobox_1(int value);
	void combobox_2(int value);
	void combobox_3(int value);

public: 
	table(QWidget *parent=0, const char *name=0);
	~table();

protected: 
	void initDialog();
	//Generated area. DO NOT EDIT!!!(begin)
	QGroupBox *QGroupBox_1;
	QLabel *QLabel_1;
	QGroupBox *QGroupBox_2;
	QComboBox *QComboBox_1;
	QComboBox *QComboBox_2;
	QLabel *QLabel_2;
	QLabel *QLabel_3;
	QLabel *QLabel_4;
	QComboBox *QComboBox_3;
	QPushButton *QPushButton_1;
	QLabel *QLabel_5;
	QLabel *QLabel_6;
	QButtonGroup *QButtonGroup_1;
	QRadioButton *QRadioButton_1;
	QRadioButton *QRadioButton_2;
	QRadioButton *QRadioButton_3;
	QLineEdit *QLineEdit_1;
	QLabel *QLabel_7;
	QPushButton *QPushButton_2;
	QPushButton *QPushButton_3;
	//Generated area. DO NOT EDIT!!!(end)

private: 
};

#endif
