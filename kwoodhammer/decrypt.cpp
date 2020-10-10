/***************************************************************************
                          decrypt.cpp  -  description
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
#include "decrypt.h"
#include "common.h"
#include "progress.h"
#include <qmessagebox.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int markcount;
int yline, curitem;
char s;
progress *progressw;
bool codeview = true;
char *probe;
bool groupview = false;

void decrypt::decrypt_ok()
{
	this->~decrypt();
}

void decrypt::trial()
{
	char str2[255];
	int len = (int)strlen(maintext);
	probe = (char*)realloc(probe, len + 1);
	strcpy(probe, maintext);
	progressw = new progress();
	progressw->setmaxvalue(len);
	progressw->show();
	for(int i = 0; i < len; i++)
	{
		if(!rangeletter(probe[i]))
		{
			for(int j = i; j < len; j++)
				probe[j] = probe[j + 1];
			probe[len] = 0;
			i--;
			len--;
		}
		progressw->setvalue(i);
	}
	progressw->hide();
	delete progressw;
	for(int j = 0; j < len; j++)
		for(int k = j + QSlider_2->value(); k < len; k++)
		{
			if(strncmp(&probe[j], &probe[k], QSlider_2->value()) == 0)
			{
				sprintf(str2, "Found 2 groups of letters with a distance of %i.\n", k - j);
				strcat(str2, "The keyword length could be one of the following:\n");
				for(int i = 3; i < 20; i++)
					if((k-j) % i == 0) sprintf(str2, "%s%i\n", str2, i);
				if(QMessageBox::information(this, "Detected equal", str2, QMessageBox::Ok |
					QMessageBox::Default, QMessageBox::Cancel) == QMessageBox::Cancel) return;
			}
		}
}

void decrypt::qslider_2(int value)
{
	char str[10];
	sprintf(str, "%i", value);
	QLineEdit_2->setText(str);
}

void decrypt::qslider_1(int value)
{
	char str[10];
	sprintf(str, "%i", value);
	QLineEdit_1->setText(str);
	QGroupBox_3->hide();
}

void decrypt::enabletable()
{
	QGroupBox_3->show();
	groupview = true;
}

int where_in_subst(int line, char c)
{
	int x = -1;
	for(int i = 0; i < snummax - snumodd; i++)
		if(substitution[line][i] == c) x = i;
	return x;
}

void decrypt::qslider_3(int value)
{
	char str[32];
	int x;
	yline = (value - 1) % (QSlider_1->value());
	sprintf(str, "(with key letter: %i)", yline + 1);
	QLabel_7->setText(str);
	sprintf(str, "Char %i", value);
	QLabel_6->setText(str);
	s = kwoodw->mark(value);
	sprintf(str, "%c", s);
	QLabel_10->setText(str);
	x = where_in_subst(yline, str[0]);
	curitem = x + 1;
	QComboBox_2->setCurrentItem(curitem);
}

void decrypt::switchview()
{
	codeview = !codeview;
	for(int i = 0; i < (int)strlen(maintext); i++)
	{
		if(!valid(maintext[i])) continue;
		yline = i % QSlider_1->value();
		if(where_in_subst(yline, maintext[i]) >= 0)
			maintextclear[i] = substitutionline[where_in_subst(yline, maintext[i])];
		else maintextclear[i] = '-';
	}
	kwoodw->updatetext();
}

void decrypt::qcombobox_2(int value)
{
	char str[32];
	curitem = QComboBox_2->currentItem();
	strcpy(str, QComboBox_2->text(curitem));
	if(curitem == 0) substitution[yline][where_in_substs(str[0])] = 0;
	else substitution[yline][where_in_substs(str[0])] = s;
}

decrypt::decrypt(QWidget *parent, const char *name) : QDialog(parent,name,true)
{
	char str[3];
	initDialog();
	connect(QPushButton_1, SIGNAL(clicked()), SLOT(decrypt_ok()));
	connect(QPushButton_3, SIGNAL(clicked()), SLOT(trial()));
	connect(QPushButton_4, SIGNAL(clicked()), SLOT(enabletable()));
	connect(QPushButton_5, SIGNAL(clicked()), SLOT(switchview()));
	connect(QSlider_2, SIGNAL(valueChanged(int)), SLOT(qslider_2(int)));
	connect(QSlider_1, SIGNAL(valueChanged(int)), SLOT(qslider_1(int)));
	QSlider_3->setRange(1, markcount);
	QSlider_3->setSteps(1, 1);
	QSlider_2->setSteps(1, 1);
	QSlider_1->setSteps(1, 1);
	connect(QSlider_3, SIGNAL(valueChanged(int)), SLOT(qslider_3(int)));
	connect(QComboBox_2, SIGNAL(activated(int)), SLOT (qcombobox_2(int)));
	QComboBox_2->insertItem("unknown");
	for(int i = 0; i < snummax; i++)
	{
		sprintf(str, "%c", codeline[i]);
		QComboBox_2->insertItem(str);
	}
	qslider_3(1);
	QGroupBox_3->hide();
	if(groupview) QGroupBox_3->show();
}

decrypt::~decrypt()
{
	free(probe);
}
