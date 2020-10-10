/***************************************************************************
                          table.cpp  -  description
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
#include "common.h"
#include <qmessagebox.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void table::table_show()
{
	char str[3000];
	char str2[100];
	strcpy(str, "    ");
	for(int j = 0; j < snummax; j++)
	{
		sprintf(str2, "%c", substitutionline[j]);
		strcat(str, str2);
	}
	strcat(str, "\n");
	for(int i = 0; i < snummax - snumodd; i++)
	{
		sprintf(str2, "%c: ", codeline[i]);
		strcat(str, str2);
		for(int j = 0; j < snummax; j++)
		{
			sprintf(str2, "%c", substitution[i][j]);
			if(substitution[i][j] == 0)	sprintf(str2, "-");
			strcat(str, str2);;
		}
		strcat(str, "\n");
	}
	QMessageBox::information(this, "Substitution table", str);
}

int random(int max)
{
	return (int)(max*((float)rand()/(float)RAND_MAX));
}

void table::table_create()
{
	int n;
	char str[256];
	for(int i = 0; i < 256; i++)
		for(int j = 0; j < snummax; j++)
			substitution[i][j] = 0;
	if(QRadioButton_1->isChecked())
	{
		for(int i = 0; i < 256; i++)
			for(int j = 0; j < snummax; j++)
				substitution[i][j] = codeline[(i+j) % snummax];
	}
	if(QRadioButton_2->isChecked())
	{
		for(int i = 0; i < 256; i++)
		{
			strcpy(str, QLineEdit_1->text());
			for(int j = 0; j < (int)strlen(str); j++)
			{
				substitution[i][(j+i) % snummax] = codeline[where_in_substc(str[j])];
				codeline[where_in_substc(str[j])] = -codeline[where_in_substc(str[j])];
			}
			for(int j = 0; j < snummax - snumodd; j++)
			{
				if(substitution[i][j] != 0) continue;
				do
				{
					n = random(snummax);
					if(codeline[n] > 0)
					{
						substitution[i][j] = codeline[n];
						codeline[n] = -codeline[n];
						n = snummax;
					}
				} while(n != snummax);
			}
			for(int j = 0; j < 256; j++)
				if(codeline[j] < 0) codeline[j] = -codeline[j];
		}
	}
}

void table::table_ok()
{
	this->~table();
}

void table::table_init()
{
	char str[3];
	QComboBox_3->insertItem("unknown");
	for(int i = 0; i < snummax; i++)
	{
		sprintf(str, "%c", codeline[i]);
		QComboBox_3->insertItem(str);
		if(i < snummax - snumodd) QComboBox_1->insertItem(str);
	}
	for(int i = 0; i < snummax; i++)
	{
		sprintf(str, "%c", substitutionline[i]);
		QComboBox_2->insertItem(str);
	}
}

void table::input()
{
	if(allvalid(QLineEdit_1->text(), true))
		QPushButton_2->setEnabled(true);
	else QPushButton_2->setEnabled(false);
}

void table::combobox_1(int value)
{
  int x = substitution[QComboBox_1->currentItem()][QComboBox_2->currentItem()];
	if(x == 0) QComboBox_3->setCurrentItem(0);
	else QComboBox_3->setCurrentItem(where_in_substc(x) + 1);
}

void table::combobox_2(int value)
{
	combobox_1(value);
}

void table::combobox_3(int value)
{
	char str[32];
	strcpy(str, QComboBox_3->text(QComboBox_3->currentItem()));
	if(QComboBox_3->currentItem() == 0) str[0] = 0;
	substitution[QComboBox_1->currentItem()][QComboBox_2->currentItem()] = str[0];
}

table::table(QWidget *parent, const char *name) : QDialog(parent,name,true)
{
	initDialog();
	table_init();
	connect(QPushButton_1, SIGNAL(clicked()), SLOT(table_ok()));
	connect(QPushButton_2, SIGNAL(clicked()), SLOT(table_create()));
	connect(QPushButton_3, SIGNAL(clicked()), SLOT(table_show()));
	connect(QLineEdit_1, SIGNAL(textChanged(const char *)), SLOT(input()));
	connect(QComboBox_1, SIGNAL(activated(int)), SLOT(combobox_1(int)));
	connect(QComboBox_2, SIGNAL(activated(int)), SLOT(combobox_2(int)));
	connect(QComboBox_3, SIGNAL(activated(int)), SLOT(combobox_3(int)));
}

table::~table()
{
}
