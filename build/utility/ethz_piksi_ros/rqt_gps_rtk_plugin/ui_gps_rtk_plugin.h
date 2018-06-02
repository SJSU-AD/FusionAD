/********************************************************************************
** Form generated from reading UI file 'gps_rtk_plugin.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GPS_RTK_PLUGIN_H
#define UI_GPS_RTK_PLUGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GpsRtkPlugin
{
public:
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_nodeStatus_description;
    QLabel *label_nodeStatus;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_fixType_description;
    QLabel *label_fixType;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *status;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_status;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_numSatellites_description;
    QLabel *label_numSatellites;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_numSatellites_indicator;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_numRtkSatellites_description;
    QLabel *label_numRtkSatellites;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_numRtkSatellites_indicator;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_baseline_description;
    QLabel *label_baseline;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_navsatFixAlt_description;
    QLabel *label_navsatFixAlt;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_numWifiCorrections_description;
    QLabel *label_numWifiCorrections;
    QSpacerItem *horizontalSpacer_7;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_rateWifiCorrections_description;
    QLabel *label_rateWifiCorrections;
    QSpacerItem *horizontalSpacer_8;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_pingBaseStation_description;
    QLabel *label_pingBaseStation;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_ageOfCorrections_description;
    QLabel *label_ageOfCorrections;
    QSpacerItem *horizontalSpacer_18;
    QWidget *debug;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_gpsSatellites_description;
    QLabel *label_gpsSatellites;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_gpsStrength_description;
    QLabel *label_gpsStrength_description_unit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_gpsStrength;
    QSpacerItem *horizontalSpacer_11;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_sbasSatellites_description;
    QLabel *label_sbasSatellites;
    QSpacerItem *horizontalSpacer_12;
    QFrame *line_17;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_sbasStrength_description;
    QLabel *label_sbasStrength_description_unit;
    QSpacerItem *verticalSpacer;
    QLabel *label_sbasStrength;
    QSpacerItem *horizontalSpacer_13;
    QFrame *line_18;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_glonassSatellites_description;
    QLabel *label_glonassSatellites;
    QSpacerItem *horizontalSpacer_14;
    QFrame *line;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_glonassStrength_description;
    QLabel *label_glonassStrength_description_unit;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_glonassStrength;
    QSpacerItem *horizontalSpacer_15;
    QFrame *line_19;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_17;

    void setupUi(QWidget *GpsRtkPlugin)
    {
        if (GpsRtkPlugin->objectName().isEmpty())
            GpsRtkPlugin->setObjectName(QStringLiteral("GpsRtkPlugin"));
        GpsRtkPlugin->resize(618, 803);
        horizontalLayout_17 = new QHBoxLayout(GpsRtkPlugin);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_nodeStatus_description = new QLabel(GpsRtkPlugin);
        label_nodeStatus_description->setObjectName(QStringLiteral("label_nodeStatus_description"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nodeStatus_description->sizePolicy().hasHeightForWidth());
        label_nodeStatus_description->setSizePolicy(sizePolicy);
        label_nodeStatus_description->setMinimumSize(QSize(151, 21));

        horizontalLayout->addWidget(label_nodeStatus_description);

        label_nodeStatus = new QLabel(GpsRtkPlugin);
        label_nodeStatus->setObjectName(QStringLiteral("label_nodeStatus"));
        label_nodeStatus->setMinimumSize(QSize(91, 21));
        label_nodeStatus->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(label_nodeStatus);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_fixType_description = new QLabel(GpsRtkPlugin);
        label_fixType_description->setObjectName(QStringLiteral("label_fixType_description"));
        sizePolicy.setHeightForWidth(label_fixType_description->sizePolicy().hasHeightForWidth());
        label_fixType_description->setSizePolicy(sizePolicy);
        label_fixType_description->setMinimumSize(QSize(71, 21));

        horizontalLayout_2->addWidget(label_fixType_description);

        label_fixType = new QLabel(GpsRtkPlugin);
        label_fixType->setObjectName(QStringLiteral("label_fixType"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_fixType->sizePolicy().hasHeightForWidth());
        label_fixType->setSizePolicy(sizePolicy1);
        label_fixType->setMinimumSize(QSize(51, 21));
        label_fixType->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(label_fixType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(GpsRtkPlugin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        status = new QWidget();
        status->setObjectName(QStringLiteral("status"));
        gridLayout_2 = new QGridLayout(status);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_status = new QVBoxLayout();
        verticalLayout_status->setSpacing(6);
        verticalLayout_status->setObjectName(QStringLiteral("verticalLayout_status"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_numSatellites_description = new QLabel(status);
        label_numSatellites_description->setObjectName(QStringLiteral("label_numSatellites_description"));
        label_numSatellites_description->setMinimumSize(QSize(111, 21));

        horizontalLayout_3->addWidget(label_numSatellites_description);

        label_numSatellites = new QLabel(status);
        label_numSatellites->setObjectName(QStringLiteral("label_numSatellites"));
        label_numSatellites->setMinimumSize(QSize(31, 21));

        horizontalLayout_3->addWidget(label_numSatellites);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        label_numSatellites_indicator = new QLabel(status);
        label_numSatellites_indicator->setObjectName(QStringLiteral("label_numSatellites_indicator"));
        label_numSatellites_indicator->setMinimumSize(QSize(71, 21));
        label_numSatellites_indicator->setMaximumSize(QSize(71, 24));

        horizontalLayout_3->addWidget(label_numSatellites_indicator);


        verticalLayout_status->addLayout(horizontalLayout_3);

        line_3 = new QFrame(status);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_numRtkSatellites_description = new QLabel(status);
        label_numRtkSatellites_description->setObjectName(QStringLiteral("label_numRtkSatellites_description"));
        label_numRtkSatellites_description->setMinimumSize(QSize(151, 21));

        horizontalLayout_4->addWidget(label_numRtkSatellites_description);

        label_numRtkSatellites = new QLabel(status);
        label_numRtkSatellites->setObjectName(QStringLiteral("label_numRtkSatellites"));
        label_numRtkSatellites->setMinimumSize(QSize(51, 21));

        horizontalLayout_4->addWidget(label_numRtkSatellites);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_numRtkSatellites_indicator = new QLabel(status);
        label_numRtkSatellites_indicator->setObjectName(QStringLiteral("label_numRtkSatellites_indicator"));
        label_numRtkSatellites_indicator->setMinimumSize(QSize(71, 21));

        horizontalLayout_4->addWidget(label_numRtkSatellites_indicator);


        verticalLayout_status->addLayout(horizontalLayout_4);

        line_4 = new QFrame(status);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_baseline_description = new QLabel(status);
        label_baseline_description->setObjectName(QStringLiteral("label_baseline_description"));
        label_baseline_description->setMinimumSize(QSize(131, 21));

        horizontalLayout_5->addWidget(label_baseline_description);

        label_baseline = new QLabel(status);
        label_baseline->setObjectName(QStringLiteral("label_baseline"));
        label_baseline->setMinimumSize(QSize(101, 21));

        horizontalLayout_5->addWidget(label_baseline);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_status->addLayout(horizontalLayout_5);

        line_5 = new QFrame(status);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_navsatFixAlt_description = new QLabel(status);
        label_navsatFixAlt_description->setObjectName(QStringLiteral("label_navsatFixAlt_description"));
        sizePolicy.setHeightForWidth(label_navsatFixAlt_description->sizePolicy().hasHeightForWidth());
        label_navsatFixAlt_description->setSizePolicy(sizePolicy);
        label_navsatFixAlt_description->setMinimumSize(QSize(201, 21));

        horizontalLayout_6->addWidget(label_navsatFixAlt_description);

        label_navsatFixAlt = new QLabel(status);
        label_navsatFixAlt->setObjectName(QStringLiteral("label_navsatFixAlt"));
        label_navsatFixAlt->setMinimumSize(QSize(0, 21));

        horizontalLayout_6->addWidget(label_navsatFixAlt);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_status->addLayout(horizontalLayout_6);

        line_8 = new QFrame(status);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_numWifiCorrections_description = new QLabel(status);
        label_numWifiCorrections_description->setObjectName(QStringLiteral("label_numWifiCorrections_description"));
        label_numWifiCorrections_description->setMinimumSize(QSize(161, 21));

        horizontalLayout_7->addWidget(label_numWifiCorrections_description);

        label_numWifiCorrections = new QLabel(status);
        label_numWifiCorrections->setObjectName(QStringLiteral("label_numWifiCorrections"));
        label_numWifiCorrections->setMinimumSize(QSize(71, 21));

        horizontalLayout_7->addWidget(label_numWifiCorrections);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_status->addLayout(horizontalLayout_7);

        line_7 = new QFrame(status);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_rateWifiCorrections_description = new QLabel(status);
        label_rateWifiCorrections_description->setObjectName(QStringLiteral("label_rateWifiCorrections_description"));
        label_rateWifiCorrections_description->setMinimumSize(QSize(181, 21));

        horizontalLayout_8->addWidget(label_rateWifiCorrections_description);

        label_rateWifiCorrections = new QLabel(status);
        label_rateWifiCorrections->setObjectName(QStringLiteral("label_rateWifiCorrections"));
        label_rateWifiCorrections->setMinimumSize(QSize(0, 21));

        horizontalLayout_8->addWidget(label_rateWifiCorrections);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_status->addLayout(horizontalLayout_8);

        line_6 = new QFrame(status);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_status->addWidget(line_6);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_pingBaseStation_description = new QLabel(status);
        label_pingBaseStation_description->setObjectName(QStringLiteral("label_pingBaseStation_description"));
        label_pingBaseStation_description->setMinimumSize(QSize(165, 21));

        horizontalLayout_9->addWidget(label_pingBaseStation_description);

        label_pingBaseStation = new QLabel(status);
        label_pingBaseStation->setObjectName(QStringLiteral("label_pingBaseStation"));
        label_pingBaseStation->setMinimumSize(QSize(0, 21));

        horizontalLayout_9->addWidget(label_pingBaseStation);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);


        verticalLayout_status->addLayout(horizontalLayout_9);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_ageOfCorrections_description = new QLabel(status);
        label_ageOfCorrections_description->setObjectName(QStringLiteral("label_ageOfCorrections_description"));
        label_ageOfCorrections_description->setMinimumSize(QSize(165, 21));

        horizontalLayout_18->addWidget(label_ageOfCorrections_description);

        label_ageOfCorrections = new QLabel(status);
        label_ageOfCorrections->setObjectName(QStringLiteral("label_ageOfCorrections"));
        label_ageOfCorrections->setMinimumSize(QSize(0, 21));

        horizontalLayout_18->addWidget(label_ageOfCorrections);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_18);


        verticalLayout_status->addLayout(horizontalLayout_18);


        gridLayout->addLayout(verticalLayout_status, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(status, QString());
        debug = new QWidget();
        debug->setObjectName(QStringLiteral("debug"));
        gridLayout_4 = new QGridLayout(debug);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_gpsSatellites_description = new QLabel(debug);
        label_gpsSatellites_description->setObjectName(QStringLiteral("label_gpsSatellites_description"));
        sizePolicy.setHeightForWidth(label_gpsSatellites_description->sizePolicy().hasHeightForWidth());
        label_gpsSatellites_description->setSizePolicy(sizePolicy);
        label_gpsSatellites_description->setMinimumSize(QSize(111, 21));

        horizontalLayout_10->addWidget(label_gpsSatellites_description);

        label_gpsSatellites = new QLabel(debug);
        label_gpsSatellites->setObjectName(QStringLiteral("label_gpsSatellites"));
        sizePolicy.setHeightForWidth(label_gpsSatellites->sizePolicy().hasHeightForWidth());
        label_gpsSatellites->setSizePolicy(sizePolicy);
        label_gpsSatellites->setMinimumSize(QSize(51, 21));
        label_gpsSatellites->setStyleSheet(QStringLiteral(""));

        horizontalLayout_10->addWidget(label_gpsSatellites);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_10);

        line_9 = new QFrame(debug);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_9);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_gpsStrength_description = new QLabel(debug);
        label_gpsStrength_description->setObjectName(QStringLiteral("label_gpsStrength_description"));
        sizePolicy.setHeightForWidth(label_gpsStrength_description->sizePolicy().hasHeightForWidth());
        label_gpsStrength_description->setSizePolicy(sizePolicy);
        label_gpsStrength_description->setMinimumSize(QSize(111, 21));

        verticalLayout_2->addWidget(label_gpsStrength_description);

        label_gpsStrength_description_unit = new QLabel(debug);
        label_gpsStrength_description_unit->setObjectName(QStringLiteral("label_gpsStrength_description_unit"));
        sizePolicy.setHeightForWidth(label_gpsStrength_description_unit->sizePolicy().hasHeightForWidth());
        label_gpsStrength_description_unit->setSizePolicy(sizePolicy);
        label_gpsStrength_description_unit->setMinimumSize(QSize(81, 21));

        verticalLayout_2->addWidget(label_gpsStrength_description_unit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_11->addLayout(verticalLayout_2);

        label_gpsStrength = new QLabel(debug);
        label_gpsStrength->setObjectName(QStringLiteral("label_gpsStrength"));
        sizePolicy1.setHeightForWidth(label_gpsStrength->sizePolicy().hasHeightForWidth());
        label_gpsStrength->setSizePolicy(sizePolicy1);
        label_gpsStrength->setMinimumSize(QSize(0, 21));
        label_gpsStrength->setStyleSheet(QStringLiteral(""));
        label_gpsStrength->setWordWrap(true);

        horizontalLayout_11->addWidget(label_gpsStrength);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        verticalLayout->addLayout(horizontalLayout_11);

        line_13 = new QFrame(debug);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_sbasSatellites_description = new QLabel(debug);
        label_sbasSatellites_description->setObjectName(QStringLiteral("label_sbasSatellites_description"));
        sizePolicy.setHeightForWidth(label_sbasSatellites_description->sizePolicy().hasHeightForWidth());
        label_sbasSatellites_description->setSizePolicy(sizePolicy);
        label_sbasSatellites_description->setMinimumSize(QSize(121, 21));

        horizontalLayout_12->addWidget(label_sbasSatellites_description);

        label_sbasSatellites = new QLabel(debug);
        label_sbasSatellites->setObjectName(QStringLiteral("label_sbasSatellites"));
        sizePolicy.setHeightForWidth(label_sbasSatellites->sizePolicy().hasHeightForWidth());
        label_sbasSatellites->setSizePolicy(sizePolicy);
        label_sbasSatellites->setMinimumSize(QSize(51, 21));
        label_sbasSatellites->setStyleSheet(QStringLiteral(""));

        horizontalLayout_12->addWidget(label_sbasSatellites);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_12);

        line_17 = new QFrame(debug);
        line_17->setObjectName(QStringLiteral("line_17"));
        line_17->setFrameShape(QFrame::HLine);
        line_17->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_17);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_sbasStrength_description = new QLabel(debug);
        label_sbasStrength_description->setObjectName(QStringLiteral("label_sbasStrength_description"));
        sizePolicy.setHeightForWidth(label_sbasStrength_description->sizePolicy().hasHeightForWidth());
        label_sbasStrength_description->setSizePolicy(sizePolicy);
        label_sbasStrength_description->setMinimumSize(QSize(121, 21));

        verticalLayout_3->addWidget(label_sbasStrength_description);

        label_sbasStrength_description_unit = new QLabel(debug);
        label_sbasStrength_description_unit->setObjectName(QStringLiteral("label_sbasStrength_description_unit"));
        sizePolicy.setHeightForWidth(label_sbasStrength_description_unit->sizePolicy().hasHeightForWidth());
        label_sbasStrength_description_unit->setSizePolicy(sizePolicy);
        label_sbasStrength_description_unit->setMinimumSize(QSize(71, 21));

        verticalLayout_3->addWidget(label_sbasStrength_description_unit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_13->addLayout(verticalLayout_3);

        label_sbasStrength = new QLabel(debug);
        label_sbasStrength->setObjectName(QStringLiteral("label_sbasStrength"));
        sizePolicy1.setHeightForWidth(label_sbasStrength->sizePolicy().hasHeightForWidth());
        label_sbasStrength->setSizePolicy(sizePolicy1);
        label_sbasStrength->setMinimumSize(QSize(0, 21));
        label_sbasStrength->setStyleSheet(QStringLiteral(""));
        label_sbasStrength->setWordWrap(true);

        horizontalLayout_13->addWidget(label_sbasStrength);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);


        verticalLayout->addLayout(horizontalLayout_13);

        line_18 = new QFrame(debug);
        line_18->setObjectName(QStringLiteral("line_18"));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_18);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_glonassSatellites_description = new QLabel(debug);
        label_glonassSatellites_description->setObjectName(QStringLiteral("label_glonassSatellites_description"));
        label_glonassSatellites_description->setMinimumSize(QSize(161, 21));

        horizontalLayout_14->addWidget(label_glonassSatellites_description);

        label_glonassSatellites = new QLabel(debug);
        label_glonassSatellites->setObjectName(QStringLiteral("label_glonassSatellites"));
        label_glonassSatellites->setMinimumSize(QSize(51, 21));

        horizontalLayout_14->addWidget(label_glonassSatellites);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_14);


        verticalLayout->addLayout(horizontalLayout_14);

        line = new QFrame(debug);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_glonassStrength_description = new QLabel(debug);
        label_glonassStrength_description->setObjectName(QStringLiteral("label_glonassStrength_description"));
        sizePolicy.setHeightForWidth(label_glonassStrength_description->sizePolicy().hasHeightForWidth());
        label_glonassStrength_description->setSizePolicy(sizePolicy);
        label_glonassStrength_description->setMinimumSize(QSize(151, 21));

        verticalLayout_4->addWidget(label_glonassStrength_description);

        label_glonassStrength_description_unit = new QLabel(debug);
        label_glonassStrength_description_unit->setObjectName(QStringLiteral("label_glonassStrength_description_unit"));
        sizePolicy.setHeightForWidth(label_glonassStrength_description_unit->sizePolicy().hasHeightForWidth());
        label_glonassStrength_description_unit->setSizePolicy(sizePolicy);
        label_glonassStrength_description_unit->setMinimumSize(QSize(71, 21));

        verticalLayout_4->addWidget(label_glonassStrength_description_unit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_4);


        horizontalLayout_15->addLayout(verticalLayout_4);

        label_glonassStrength = new QLabel(debug);
        label_glonassStrength->setObjectName(QStringLiteral("label_glonassStrength"));
        sizePolicy1.setHeightForWidth(label_glonassStrength->sizePolicy().hasHeightForWidth());
        label_glonassStrength->setSizePolicy(sizePolicy1);
        label_glonassStrength->setMinimumSize(QSize(0, 21));
        label_glonassStrength->setStyleSheet(QStringLiteral(""));
        label_glonassStrength->setWordWrap(true);

        horizontalLayout_15->addWidget(label_glonassStrength);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);


        verticalLayout->addLayout(horizontalLayout_15);

        line_19 = new QFrame(debug);
        line_19->setObjectName(QStringLiteral("line_19"));
        line_19->setFrameShape(QFrame::HLine);
        line_19->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_19);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_5);


        gridLayout_3->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        tabWidget->addTab(debug, QString());

        verticalLayout_5->addWidget(tabWidget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);


        horizontalLayout_17->addLayout(verticalLayout_5);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_17);


        retranslateUi(GpsRtkPlugin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GpsRtkPlugin);
    } // setupUi

    void retranslateUi(QWidget *GpsRtkPlugin)
    {
        GpsRtkPlugin->setWindowTitle(QApplication::translate("GpsRtkPlugin", "GpsRtkInfo", 0));
        label_nodeStatus_description->setText(QApplication::translate("GpsRtkPlugin", "Last message (UTC):", 0));
        label_nodeStatus->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_fixType_description->setText(QApplication::translate("GpsRtkPlugin", "Fix type:", 0));
        label_fixType->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_numSatellites_description->setText(QApplication::translate("GpsRtkPlugin", "Num satellites:", 0));
        label_numSatellites->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_numSatellites_indicator->setText(QString());
        label_numRtkSatellites_description->setText(QApplication::translate("GpsRtkPlugin", "Num satellites (RTK):", 0));
        label_numRtkSatellites->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_numRtkSatellites_indicator->setText(QString());
        label_baseline_description->setText(QApplication::translate("GpsRtkPlugin", "NED baseline [m]:", 0));
        label_baseline->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_navsatFixAlt_description->setText(QApplication::translate("GpsRtkPlugin", "Navsat fix altitude (avg) [m]:", 0));
        label_navsatFixAlt->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_numWifiCorrections_description->setText(QApplication::translate("GpsRtkPlugin", "Num Wifi corrections:", 0));
        label_numWifiCorrections->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_rateWifiCorrections_description->setText(QApplication::translate("GpsRtkPlugin", "Wifi correction rate [Hz]:", 0));
        label_rateWifiCorrections->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_pingBaseStation_description->setText(QApplication::translate("GpsRtkPlugin", "Base Station ping [ms]:", 0));
        label_pingBaseStation->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_ageOfCorrections_description->setText(QApplication::translate("GpsRtkPlugin", "Age of Corrections [s]:", 0));
        label_ageOfCorrections->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        tabWidget->setTabText(tabWidget->indexOf(status), QApplication::translate("GpsRtkPlugin", "Status", 0));
        label_gpsSatellites_description->setText(QApplication::translate("GpsRtkPlugin", "GPS satellites:", 0));
        label_gpsSatellites->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_gpsStrength_description->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>GPS strength:</p></body></html>", 0));
        label_gpsStrength_description_unit->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>[dB Hz]</p></body></html>", 0));
        label_gpsStrength->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_sbasSatellites_description->setText(QApplication::translate("GpsRtkPlugin", "SBAS satellites:", 0));
        label_sbasSatellites->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_sbasStrength_description->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>SBAS strength:</p></body></html>", 0));
        label_sbasStrength_description_unit->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>[dB Hz]</p></body></html>", 0));
        label_sbasStrength->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_glonassSatellites_description->setText(QApplication::translate("GpsRtkPlugin", "GLONASS satellites:", 0));
        label_glonassSatellites->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        label_glonassStrength_description->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>GLONASS strength:</p></body></html>", 0));
        label_glonassStrength_description_unit->setText(QApplication::translate("GpsRtkPlugin", "<html><head/><body><p>[dB Hz]</p></body></html>", 0));
        label_glonassStrength->setText(QApplication::translate("GpsRtkPlugin", "N/A", 0));
        tabWidget->setTabText(tabWidget->indexOf(debug), QApplication::translate("GpsRtkPlugin", "Debug", 0));
    } // retranslateUi

};

namespace Ui {
    class GpsRtkPlugin: public Ui_GpsRtkPlugin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GPS_RTK_PLUGIN_H
