/***************************************************************************
 *   Copyright (C) 2008 by pilar   *
 *   pilarb@unex.es   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "pracaoc.h"


pracAOC::pracAOC(): QWidget()
{
	mainWin=new QMainForm();
	mainWin->setupUi(this);


	ctable.resize(256);
	for(int i=0; i < 256; i++)
		ctable[i] = qRgb(i,i,i);

    imgO=new uchar[IMAGEW*IMAGEH];
    imgD=new uchar[IMAGEW*IMAGEH];
    imgDC=new uchar[IMAGED*IMAGED];
    imgAux=new uchar[IMAGEW*IMAGEH];
	
    for(int i=0; i<IMAGEW*IMAGEH;i++)
		imgO[i]=0;

    qimgOrig = new QImage(imgO,IMAGEW, IMAGEH, QImage::Format_Indexed8);
	qimgOrig->setColorTable(ctable);
	qimgOrig->setNumColors(256);

    qimgDest = new QImage(imgD,IMAGEW, IMAGEH, QImage::Format_Indexed8);
	qimgDest->setColorTable(ctable);
	qimgOrig->setNumColors(256);

    connect ( mainWin->pushButtonCargar, SIGNAL (clicked()), this, SLOT( cargar() ) );
	connect ( mainWin->pushButtonGuardar, SIGNAL (clicked()), this, SLOT( guardar() ) );
    connect ( mainWin->pushButtonSalir, SIGNAL (clicked()), this, SLOT( close() ) );
    connect ( mainWin->hSliderZoom, SIGNAL (valueChanged(int)), this, SLOT( changeScrollLimits(int) ) );
    connect ( mainWin->hSliderZoomMejorado, SIGNAL (valueChanged(int)), this, SLOT( changeScrollLimits(int) ) );
    connect (mainWin->checkBoxZoomMejorado, SIGNAL(clicked(bool)), this, SLOT( zoomMethodChanged(bool) ) );

    connect (&timer,SIGNAL(timeout()),this,SLOT(process()));
    timer.start(33);

}


pracAOC::~pracAOC()
{
}


void pracAOC::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

    painter.drawImage(QPoint(mainWin->frameOrig->x(), mainWin->frameOrig->y()), *qimgDest);
	
	painter.end();
}

void pracAOC::cargar()
{
    unsigned alignedWidth;
    QImage qimgRead(IMAGEW,IMAGEH,QImage::Format_Indexed8);
	
	QString fn = QFileDialog::getOpenFileName(this,"Elija la imagen a cargar",".", "Images (*.png *.xpm *.jpg)");
	if(qimgRead.load(fn))
	{
		QImage qimgCRead(qimgRead.width(),qimgRead.height(),QImage::Format_Indexed8);

		qimgCRead=qimgRead.convertToFormat(QImage::Format_Indexed8, ctable);

        alignedWidth = ceil(qimgCRead.width()/4.) * 4;

        for(unsigned y=0; y<IMAGEH && y<(unsigned) qimgCRead.height();y++)
            for(unsigned x=0; x<IMAGEW && x<(unsigned) qimgCRead.width(); x++)
                imgO[y*IMAGEW+x]=(qimgCRead.bits())[(y*alignedWidth+x)];

		update();
	}
}

void pracAOC::guardar()
{
    QImage qimgWrite(IMAGEW,IMAGEH,QImage::Format_Indexed8);
    QString fn = QFileDialog::getSaveFileName(this,"Elija la imagen a cargar",".", "Images (*.png *.xpm *.jpg)");
	qimgWrite.setColorTable(ctable);
    for(int y=0; y<IMAGEH;y++)
        for(int x=0; x<IMAGEW; x++)
            (qimgWrite.bits())[(y*IMAGEW+x)]=imgD[y*IMAGEW+x];

	qimgWrite.save(fn);
}

void pracAOC::process()
{
    memcpy(imgD, imgO, IMAGEW*IMAGEH);
    imageprocess::rotar(imgO, imgDC, (mainWin->dialRot->value()*M_PI)/180.);
    float s, sM;
    if(mainWin->hSliderZoom->value()>10)
        s = mainWin->hSliderZoom->value()-9;
    else
        if(mainWin->hSliderZoom->value()<10)
            s =  1./(10.-mainWin->hSliderZoom->value());
        else
            s = 1.;
    if(mainWin->hSliderZoomMejorado->value()>10)
        sM = mainWin->hSliderZoomMejorado->value()-9;
    else
        if(mainWin->hSliderZoomMejorado->value()<10)
            sM =  1./(10.-mainWin->hSliderZoomMejorado->value());
        else
            sM = 1.;
    if(!mainWin->checkBoxZoomMejorado->isChecked())
        imageprocess::zoom(imgDC, imgD, s, mainWin->horizontalScrollBar->value()-320, mainWin->verticalScrollBar->value()-240);
    else
        imageprocess::zoomMejorado(imgDC, imgD, sM, mainWin->horizontalScrollBar->value()-320, mainWin->verticalScrollBar->value()-240);
    if(mainWin->checkBoxVHor->isChecked())
    {
        memcpy(imgAux, imgD, IMAGEW*IMAGEH);
        imageprocess::volteoHorizontal(imgAux, imgD);
    }
    if(mainWin->checkBoxVVer->isChecked())
    {
        memcpy(imgAux, imgD, IMAGEW*IMAGEH);
        imageprocess::volteoVertical(imgAux, imgD);
    }

    memcpy(imgAux, imgD, IMAGEW*IMAGEH);
    if(!mainWin->checkBoxIlumMejorada->isChecked())
    {
        if(mainWin->hSliderIlum->value()>=0)
            imageprocess::iluminarLUT(tLUT, 255-mainWin->hSliderIlum->value());
        else
            imageprocess::oscurecerLUT(tLUT, -mainWin->hSliderIlum->value());
    }
    else
    {
        if(mainWin->hSliderIlumMejorada->value()>=0)
            imageprocess::iluminarLUTMejorado(tLUT, mainWin->hSliderIlumMejorada->value());
        else
            imageprocess::oscurecerLUTMejorado(tLUT, -mainWin->hSliderIlumMejorada->value());
    }

    imageprocess::aplicarTablaLUT(tLUT, imgAux, imgD);

    update();
}

void pracAOC::zoomMethodChanged(bool zM)
{
    if(!zM)
        changeScrollLimits(mainWin->hSliderZoom->value());
    else
        changeScrollLimits(mainWin->hSliderZoomMejorado->value());
}

void pracAOC::changeScrollLimits(int nz)
{
    float s;
    int nD, nMw, nMh, xC, yC;

    if(nz>10)
        s = nz-9;
    else
        if(nz<10)
            s =  1./(10.-nz);
        else
            s = 1.;

    nD = 800*s;
    xC = nD/2;
    yC = nD/2;
    nMw = nD - 320;
    nMh = nD - 240;

    if(nMw>xC)
    {
        mainWin->horizontalScrollBar->setMinimum(320);
        mainWin->horizontalScrollBar->setMaximum(nMw);
        mainWin->horizontalScrollBar->setValue(xC);
        mainWin->verticalScrollBar->setMinimum(240);
        mainWin->verticalScrollBar->setMaximum(nMh);
        mainWin->verticalScrollBar->setValue(yC);
    }
    else
    {
        mainWin->horizontalScrollBar->setMinimum(xC);
        mainWin->horizontalScrollBar->setMaximum(xC);
        mainWin->verticalScrollBar->setMinimum(yC);
        mainWin->verticalScrollBar->setMaximum(yC);
    }



}

void pracAOC::closeEvent(QCloseEvent *event)
{


}
