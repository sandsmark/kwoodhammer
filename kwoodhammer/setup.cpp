/***************************************************************************
                          setup.cpp  -  description
                             -------------------
    begin                : Wed Apr 12 2000
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
#include "setup.h"
#include "common.h"
#include "kwood.h"
#include <stdio.h>
#include <qmessagebox.h>
#include <string.h>
#include <stdlib.h>

char currentbase[256];
bool letters52 = false, numbers10 = false;
int slideval = -1;

int round(float x)
{
	int r = (int)x;
	if(x-r >= 0.5) r++;
	return r;
}

QString inhome(char *file)
{
	QString fullpath;
	fullpath.sprintf("%s/share/apps/kwoodhammer/%s",
		KApplication::localkdedir().data(),
		file);
	return fullpath;
}

QString inlib(char *file)
{
	QString fullpath;
	fullpath.sprintf("%s/kwoodhammer/%s",
		KApplication::kde_datadir().data(),
		file);
	return fullpath;
}

bool validletter(int letter)
{
	if((letter > 64) && (letter < 91)) return true;
	if((letters52) && (letter > 96) && (letter < 123)) return true;
	if((numbers10) && (letter > 47) && (letter < 58)) return true;
	else return false;
}

bool rangeletter(int letter)
{
	if((letter > 64) && (letter < 91)) return true;
	if((letter > 96) && (letter < 123)) return true;
	if((letter > 47) && (letter < 58)) return true;
	else return false;
}

void stat_load(char *name)
{
	int i;
	long j;
	char str[255];
	strcpy(str, "kwoodhammerbase");
	strcat(str, name);
	strcpy(currentbase, name);
	FILE * sf;
	if(strlen(name) == 0) sf = fopen(inhome(str), "r");
	else sf = fopen(inlib(str), "r");
	if(sf == NULL) fprintf(stderr, "Error opening statistics file!\n");
	maxstatistics = 0;
	for(i = 0; i < 256; i++)
		statistics[i] = 0;
	while(!feof(sf))
	{
		fscanf(sf, "%c:%i\n", &i, &j);
		if(validletter((unsigned char)i))
		{
			statistics[(unsigned char)i] = j;
			maxstatistics += j;
		}
	}
	fclose(sf);
}

void setup::stat_save(char *name)
{
	char str[255];
	strcpy(str, "kwoodhammerbase");
	strcat(str, name);
	FILE * sf = fopen(inhome(str), "w");
	if(sf == NULL) fprintf(stderr, "Error opening statistics file!\n");
	for(int i = 0; i < 256; i++)
		if(validletter(i)) fprintf(sf, "%c:%i\n", i, statistics[i]);
	fclose(sf);
}

void stat_make()
{
	int j = 0, l = 0;
	int snum, snumsum = 0;
	long maxstatistics_save = maxstatistics;
	int snumodd_save = snumodd;
	for(int k = 0; k < 256; k++)
		substitutionline[k] = -1;
	for(int k = 0; k < 256; k++)
		codeline[k] = -1;
	for(int k = 0; k < 256; k++)
		if(validletter(k))
		{
			codeline[l] = k;
			l++;
		}
	for(int k = 0; k < 256; k++)
	{
		if(l > snummax) continue;
		if(!validletter(k) && rangeletter(k))
		{
			codeline[l] = k;
			l++;
		}
	}
	for(int i = 0; i < 256; i++)
	{
		if(validletter(i))
		{
			j++;
			if(maxstatistics == 0) snum = 1;
			else snum = 1 + round((float)snumodd * (float)statistics[i] / (float)maxstatistics);
			for(int k = snumsum; k < snumsum + snum; k++)
				substitutionline[k] = i;
			snumsum += snum;
			maxstatistics -= statistics[i];
			snumodd -= (snum - 1);
		}
	}
	snumodd = snumodd_save;
	maxstatistics = maxstatistics_save;
}

void setup::stat_add()
{
	char str[3000];
	QMultiLineEdit_1->setText(maintext);
	stat_load("");
	stat_make();
	for(int i = 0; i < QMultiLineEdit_1->numLines(); i++)
	{
		strcpy(str, QMultiLineEdit_1->textLine(i));
		for(int j = 0; j < (int)strlen(str); j++)
			if(validletter(str[j])) statistics[str[j]]++;
	}
	stat_save("");
	stat_load(currentbase);
	stat_make();
}

void setup::stat_clear()
{
	for(int i = 0; i < 256; i++)
		statistics[i] = 0;
	stat_save("");
	stat_load(currentbase);
	stat_make();
	snummax = 0;
	for(int i = 0; i < 256; i++)
		if(validletter(i)) snummax++;
	snumodd = 0;
	QSlider_1->setRange(0, 62 - snummax);
	QSlider_1->setValue(0);
}

void setup::buildtable()
{
	QMessageBox::information(this, "New char configuration",
	"The char configuration has been changed.\nCleared user statistics.\n"
 	"Recalculated standard statistics");
}

void setup::radiobutton_3()
{
	QRadioButton_3->setChecked(true);
	QRadioButton_4->setChecked(false);
	if(letters52) buildtable();
	letters52 = false;
	stat_clear();
}

void setup::radiobutton_4()
{
	QRadioButton_3->setChecked(false);
	QRadioButton_4->setChecked(true);
	if(!letters52) buildtable();
	letters52 = true;
	stat_clear();
}

void setup::radiobutton_5()
{
	QRadioButton_5->setChecked(true);
	QRadioButton_6->setChecked(false);
	QComboBox_1->setEnabled(true);
	QPushButton_10->setEnabled(true);
	QPushButton_7->setEnabled(false);
	QPushButton_8->setEnabled(false);
	QPushButton_9->setEnabled(false);
	stat_load(".german");
	stat_make();
}

void setup::radiobutton_6()
{
	QRadioButton_5->setChecked(false);
	QRadioButton_6->setChecked(true);
	QComboBox_1->setEnabled(false);
	QPushButton_10->setEnabled(false);
	QPushButton_7->setEnabled(true);
	QPushButton_8->setEnabled(true);
	QPushButton_9->setEnabled(true);
	stat_load("");
	stat_make();
}

void setup::checkbox_2()
{
	if(QCheckBox_2->isChecked() != numbers10) buildtable();
	numbers10 = QCheckBox_2->isChecked();
	stat_clear();
}

void setup::checkbox_3()
{
	if(QCheckBox_3->isChecked())
	{
		QSlider_1->setEnabled(true);
		snumodd = QSlider_1->value();
		snummax += snumodd;
		slideval = snumodd;
	}
	else
	{
		QSlider_1->setEnabled(false);
		snummax -= snumodd;
		snumodd = 0;
		slideval = -1;
	}
	stat_make();
}

void setup::slider_1(int value)
{
	char str[100];
	sprintf(str, "Use homophony (using extra chars: %i)", value);
	QCheckBox_3->setText(str);
	snummax -= snumodd;
	snumodd = value;
	snummax += snumodd;
	slideval = value;
	stat_make();
}

void setup::stat_show()
{
	char *title;
	char str[1000];
	char str2[30];
	int j = 0;
	int snum;
	strcpy(str, "");
	for(int i = 0; i < 256; i++)
	{
		if(validletter(i))
		{
			j++;
			snum = 1 + round((float)snumodd * (float)statistics[i] / (float)maxstatistics);
			sprintf(str2, "%c: %3.2f%% (%i)   ", i, 100.0 * (float)statistics[i] /
				(float)maxstatistics, snum);
			strcat(str, str2);
			if(j % 5 == 0) strcat(str, "\n");
		}
	}
	if(strcmp(currentbase, "") == 0) title = "User statistic";
	else title = "Standard statistics";
	QMessageBox::information(this, title, str);
}

void setup::setup_ok()
{
	this->~setup();
}

setup::setup(QWidget *parent, const char *name) : QDialog(parent,name,true){
	initDialog();
	if(fopen(inhome(".kwoodhammerbase"), "r") == 0)
	{
		QMessageBox::information(this, "KWoodhammer", "Creating new user statistics.");
		stat_clear();
	}
	QComboBox_1->insertItem("German", -1);
	connect(QPushButton_1, SIGNAL(clicked()), SLOT(setup_ok()));
	connect(QPushButton_2, SIGNAL(clicked()), this, SLOT(hide()));
	connect(QRadioButton_3, SIGNAL(clicked()), SLOT(radiobutton_3()));
	connect(QRadioButton_4, SIGNAL(clicked()), SLOT(radiobutton_4()));
	connect(QRadioButton_5, SIGNAL(clicked()), SLOT(radiobutton_5()));
	connect(QRadioButton_6, SIGNAL(clicked()), SLOT(radiobutton_6()));
	connect(QCheckBox_2, SIGNAL(clicked()), SLOT(checkbox_2()));
	connect(QCheckBox_3, SIGNAL(clicked()), SLOT(checkbox_3()));
	connect(QSlider_1, SIGNAL(valueChanged(int)), SLOT(slider_1(int)));
	connect(QPushButton_10, SIGNAL(clicked()), SLOT(stat_show()));
	connect(QPushButton_9, SIGNAL(clicked()), SLOT(stat_show()));
	connect(QPushButton_8, SIGNAL(clicked()), SLOT(stat_clear()));
	connect(QPushButton_7, SIGNAL(clicked()), SLOT(stat_add()));
	if(strcmp(currentbase, ".german") == 0) QRadioButton_5->animateClick();
	if(strcmp(currentbase, "") == 0) QRadioButton_6->animateClick();
	if(letters52) QRadioButton_4->animateClick();
	if(numbers10) QCheckBox_2->animateClick();
	if(slideval >= 0) QCheckBox_3->animateClick();
	if(slideval > 0) QSlider_1->setValue(slideval);
}

setup::~setup(){
}
