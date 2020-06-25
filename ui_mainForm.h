/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDial>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMainForm
{
public:
    QFrame *frameOrig;
    QPushButton *pushButtonCargar;
    QPushButton *pushButtonSalir;
    QPushButton *pushButtonGuardar;
    QDial *dialRot;
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QSlider *hSliderZoom;
    QLabel *labelRot;
    QLabel *labelZoom;
    QCheckBox *checkBoxVHor;
    QCheckBox *checkBoxVVer;
    QSlider *hSliderIlum;
    QLabel *labelIlum;
    QSlider *hSliderZoomMejorado;
    QLabel *labelZoomMejorado;
    QCheckBox *checkBoxZoomMejorado;
    QSlider *hSliderIlumMejorada;
    QLabel *labelIlumMejorada;
    QCheckBox *checkBoxIlumMejorada;

    void setupUi(QWidget *QMainForm)
    {
        if (QMainForm->objectName().isEmpty())
            QMainForm->setObjectName(QString::fromUtf8("QMainForm"));
        QMainForm->resize(887, 606);
        frameOrig = new QFrame(QMainForm);
        frameOrig->setObjectName(QString::fromUtf8("frameOrig"));
        frameOrig->setGeometry(QRect(30, 40, 640, 480));
        frameOrig->setFrameShape(QFrame::StyledPanel);
        frameOrig->setFrameShadow(QFrame::Raised);
        pushButtonCargar = new QPushButton(QMainForm);
        pushButtonCargar->setObjectName(QString::fromUtf8("pushButtonCargar"));
        pushButtonCargar->setGeometry(QRect(30, 550, 151, 41));
        pushButtonSalir = new QPushButton(QMainForm);
        pushButtonSalir->setObjectName(QString::fromUtf8("pushButtonSalir"));
        pushButtonSalir->setGeometry(QRect(710, 540, 151, 41));
        pushButtonGuardar = new QPushButton(QMainForm);
        pushButtonGuardar->setObjectName(QString::fromUtf8("pushButtonGuardar"));
        pushButtonGuardar->setGeometry(QRect(220, 550, 151, 41));
        dialRot = new QDial(QMainForm);
        dialRot->setObjectName(QString::fromUtf8("dialRot"));
        dialRot->setGeometry(QRect(730, 70, 91, 81));
        dialRot->setMaximum(359);
        horizontalScrollBar = new QScrollBar(QMainForm);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(30, 520, 641, 20));
        horizontalScrollBar->setMinimum(320);
        horizontalScrollBar->setMaximum(480);
        horizontalScrollBar->setValue(400);
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        verticalScrollBar = new QScrollBar(QMainForm);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(670, 40, 21, 481));
        verticalScrollBar->setMinimum(240);
        verticalScrollBar->setMaximum(560);
        verticalScrollBar->setValue(400);
        verticalScrollBar->setOrientation(Qt::Vertical);
        hSliderZoom = new QSlider(QMainForm);
        hSliderZoom->setObjectName(QString::fromUtf8("hSliderZoom"));
        hSliderZoom->setGeometry(QRect(710, 180, 131, 21));
        hSliderZoom->setMaximum(19);
        hSliderZoom->setSingleStep(1);
        hSliderZoom->setValue(10);
        hSliderZoom->setSliderPosition(10);
        hSliderZoom->setOrientation(Qt::Horizontal);
        labelRot = new QLabel(QMainForm);
        labelRot->setObjectName(QString::fromUtf8("labelRot"));
        labelRot->setGeometry(QRect(740, 40, 81, 31));
        labelRot->setAlignment(Qt::AlignCenter);
        labelZoom = new QLabel(QMainForm);
        labelZoom->setObjectName(QString::fromUtf8("labelZoom"));
        labelZoom->setGeometry(QRect(740, 160, 67, 21));
        labelZoom->setAlignment(Qt::AlignCenter);
        checkBoxVHor = new QCheckBox(QMainForm);
        checkBoxVHor->setObjectName(QString::fromUtf8("checkBoxVHor"));
        checkBoxVHor->setGeometry(QRect(710, 270, 151, 31));
        checkBoxVVer = new QCheckBox(QMainForm);
        checkBoxVVer->setObjectName(QString::fromUtf8("checkBoxVVer"));
        checkBoxVVer->setGeometry(QRect(710, 320, 151, 31));
        hSliderIlum = new QSlider(QMainForm);
        hSliderIlum->setObjectName(QString::fromUtf8("hSliderIlum"));
        hSliderIlum->setGeometry(QRect(710, 410, 131, 21));
        hSliderIlum->setMinimum(-255);
        hSliderIlum->setMaximum(255);
        hSliderIlum->setValue(0);
        hSliderIlum->setSliderPosition(0);
        hSliderIlum->setOrientation(Qt::Horizontal);
        labelIlum = new QLabel(QMainForm);
        labelIlum->setObjectName(QString::fromUtf8("labelIlum"));
        labelIlum->setGeometry(QRect(730, 380, 91, 41));
        labelIlum->setAlignment(Qt::AlignCenter);
        hSliderZoomMejorado = new QSlider(QMainForm);
        hSliderZoomMejorado->setObjectName(QString::fromUtf8("hSliderZoomMejorado"));
        hSliderZoomMejorado->setEnabled(false);
        hSliderZoomMejorado->setGeometry(QRect(710, 230, 131, 21));
        hSliderZoomMejorado->setMaximum(19);
        hSliderZoomMejorado->setSingleStep(1);
        hSliderZoomMejorado->setValue(10);
        hSliderZoomMejorado->setSliderPosition(10);
        hSliderZoomMejorado->setOrientation(Qt::Horizontal);
        labelZoomMejorado = new QLabel(QMainForm);
        labelZoomMejorado->setObjectName(QString::fromUtf8("labelZoomMejorado"));
        labelZoomMejorado->setEnabled(false);
        labelZoomMejorado->setGeometry(QRect(720, 210, 111, 21));
        labelZoomMejorado->setAlignment(Qt::AlignCenter);
        checkBoxZoomMejorado = new QCheckBox(QMainForm);
        checkBoxZoomMejorado->setObjectName(QString::fromUtf8("checkBoxZoomMejorado"));
        checkBoxZoomMejorado->setGeometry(QRect(850, 230, 96, 22));
        hSliderIlumMejorada = new QSlider(QMainForm);
        hSliderIlumMejorada->setObjectName(QString::fromUtf8("hSliderIlumMejorada"));
        hSliderIlumMejorada->setEnabled(false);
        hSliderIlumMejorada->setGeometry(QRect(710, 460, 131, 21));
        hSliderIlumMejorada->setMinimum(-255);
        hSliderIlumMejorada->setMaximum(255);
        hSliderIlumMejorada->setValue(0);
        hSliderIlumMejorada->setSliderPosition(0);
        hSliderIlumMejorada->setOrientation(Qt::Horizontal);
        labelIlumMejorada = new QLabel(QMainForm);
        labelIlumMejorada->setObjectName(QString::fromUtf8("labelIlumMejorada"));
        labelIlumMejorada->setEnabled(false);
        labelIlumMejorada->setGeometry(QRect(700, 430, 161, 41));
        labelIlumMejorada->setAlignment(Qt::AlignCenter);
        checkBoxIlumMejorada = new QCheckBox(QMainForm);
        checkBoxIlumMejorada->setObjectName(QString::fromUtf8("checkBoxIlumMejorada"));
        checkBoxIlumMejorada->setGeometry(QRect(850, 460, 96, 22));

        retranslateUi(QMainForm);
        QObject::connect(checkBoxZoomMejorado, SIGNAL(toggled(bool)), hSliderZoomMejorado, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxZoomMejorado, SIGNAL(toggled(bool)), hSliderZoom, SLOT(setDisabled(bool)));
        QObject::connect(checkBoxZoomMejorado, SIGNAL(toggled(bool)), labelZoomMejorado, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxZoomMejorado, SIGNAL(toggled(bool)), labelZoom, SLOT(setDisabled(bool)));
        QObject::connect(checkBoxIlumMejorada, SIGNAL(toggled(bool)), hSliderIlumMejorada, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxIlumMejorada, SIGNAL(toggled(bool)), labelIlumMejorada, SLOT(setEnabled(bool)));
        QObject::connect(checkBoxIlumMejorada, SIGNAL(toggled(bool)), hSliderIlum, SLOT(setDisabled(bool)));
        QObject::connect(checkBoxIlumMejorada, SIGNAL(toggled(bool)), labelIlum, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(QMainForm);
    } // setupUi

    void retranslateUi(QWidget *QMainForm)
    {
        QMainForm->setWindowTitle(QApplication::translate("QMainForm", "Procesamiento de im\303\241genes", 0, QApplication::UnicodeUTF8));
        pushButtonCargar->setText(QApplication::translate("QMainForm", "Cargar", 0, QApplication::UnicodeUTF8));
        pushButtonSalir->setText(QApplication::translate("QMainForm", "Salir", 0, QApplication::UnicodeUTF8));
        pushButtonGuardar->setText(QApplication::translate("QMainForm", "Guardar", 0, QApplication::UnicodeUTF8));
        labelRot->setText(QApplication::translate("QMainForm", "Rotaci\303\263n", 0, QApplication::UnicodeUTF8));
        labelZoom->setText(QApplication::translate("QMainForm", "Zoom", 0, QApplication::UnicodeUTF8));
        checkBoxVHor->setText(QApplication::translate("QMainForm", "Volteo horizontal", 0, QApplication::UnicodeUTF8));
        checkBoxVVer->setText(QApplication::translate("QMainForm", "Volteo vertical", 0, QApplication::UnicodeUTF8));
        labelIlum->setText(QApplication::translate("QMainForm", "Iluminaci\303\263n", 0, QApplication::UnicodeUTF8));
        labelZoomMejorado->setText(QApplication::translate("QMainForm", "Zoom mejorado", 0, QApplication::UnicodeUTF8));
        checkBoxZoomMejorado->setText(QString());
        labelIlumMejorada->setText(QApplication::translate("QMainForm", "Iluminaci\303\263n mejorada", 0, QApplication::UnicodeUTF8));
        checkBoxIlumMejorada->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QMainForm: public Ui_QMainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
